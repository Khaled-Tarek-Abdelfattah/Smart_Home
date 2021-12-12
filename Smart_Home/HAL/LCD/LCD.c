#include "LCD.h"
#include <stdlib.h>

void LCD_init(){
	
	_delay_ms(20);
	
	DioDirectionSet(LCD_CTRL_DIR_REG, LCD_RS, DIO_OUTPUT);
	DioDirectionSet(LCD_CTRL_DIR_REG, LCD_RW, DIO_OUTPUT);
	DioDirectionSet(LCD_CTRL_DIR_REG, LCD_EN, DIO_OUTPUT);
	
	#if LCD_8bit_Mode
	DioPortWrite(LCD_DATA_DIR_REG,0xFF);
	#else 
	*LCD_DATA_DIR_REG|=0xF0;
	LCD_SendInstruction(Return_Home);
	#endif
	
	LCD_SendInstruction(Function_Set);
	LCD_SendInstruction(Display_On);
	LCD_Clear();
}
void LCD_SendInstruction(uint8 instruction){
	DioChannelWrite(LCD_CTRL_OUT_REG, LCD_RS, DIO_LOW);
	DioChannelWrite(LCD_CTRL_OUT_REG, LCD_RW, DIO_LOW);
	
	#if LCD_8bit_Mode
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	DioPortWrite(LCD_DATA_OUT_REG,instruction);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#else
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	*LCD_DATA_OUT_REG &= 0x0FU;
	*LCD_DATA_OUT_REG |= (instruction & 0xF0U);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	instruction&=0x0F;
	*LCD_DATA_OUT_REG &= 0x0FU;
	*LCD_DATA_OUT_REG |= ((instruction<<4) & 0xF0U);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#endif
}
void LCD_CharDisplay(uint8 character){
	DioChannelWrite(LCD_CTRL_OUT_REG, LCD_RS, DIO_HIGH);
	DioChannelWrite(LCD_CTRL_OUT_REG, LCD_RW, DIO_LOW);
	
	#if LCD_8bit_Mode
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	DioPortWrite(LCD_DATA_OUT_REG,character);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#else
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	*LCD_DATA_OUT_REG &= 0x0FU;
	*LCD_DATA_OUT_REG |= (character & 0xF0U);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	*LCD_DATA_OUT_REG &= 0x0FU;
	*LCD_DATA_OUT_REG |= ((character << 4U) & 0xF0U);
	_delay_ms(2);
	DioChannelWrite(LCD_CTRL_OUT_REG,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#endif
}

void LCD_StringDisplay(char * string){
	while (*string != '\0')
	{
		LCD_CharDisplay(*string);
		string++;
	}
}

void LCD_RowCol_Select(uint8 Row, uint8 Col)
{
	uint8 u8LocalLineAddress = 0U;
	
	switch(Row)
	{
		case 0:
		/* !Comment: When Writing To LCD 1st Col The Base Address is 0x00 */
		u8LocalLineAddress = Col | LCD_1ST_LINE_BASE;
		break;
		case 1:
		/* !Comment: When Writing To LCD 2nd Col The Base Address is 0x40 */
		u8LocalLineAddress = Col | LCD_2ND_LINE_BASE;
		break;
		case 2:
		/* !Comment: When Writing To LCD 1st Col The Base Address is 0x10 */
		u8LocalLineAddress = Col | LCD_3RD_LINE_BASE;
		break;
		case 3:
		/* !Comment: When Writing To LCD 1st Col The Base Address is 0x50 */
		u8LocalLineAddress = Col | LCD_4TH_LINE_BASE;
		break;
		default:
		break;
	}
	LCD_SendInstruction(LCD_DDRAM_CONST | u8LocalLineAddress);
	_delay_ms(2);
}

void LCD_IntegerDisplay(uint8 num){
	char Integer_ascii [17];
	itoa(num,Integer_ascii,10);
	LCD_StringDisplay(Integer_ascii);
}

void LCD_Cursor_ShiftLeft(){
	LCD_SendInstruction(Shift_Cursor_Left);
	_delay_ms(2);
}
void LCD_Cursor_ShiftRight(){
	LCD_SendInstruction(Shift_Cursor_Right);
	_delay_ms(2);
}
void LCD_Display_ShiftLeft(){
	LCD_SendInstruction(Shift_Display_Left);
	_delay_ms(2);
}
void LCD_Display_ShiftRight(){
	LCD_SendInstruction(Shift_Display_Right);
	_delay_ms(2);
}

void LCD_Clear(){
	LCD_SendInstruction(Clear_Display);
}