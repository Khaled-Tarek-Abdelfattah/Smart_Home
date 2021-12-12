
#ifndef LCD_H_
#define LCD_H_

#include "Std_Types.h"
#include "LCD_config.h"
#include "Dio.h"
#include "util/delay.h"

#define	Clear_Display			(0x01U)
#define Return_Home				(0x02U)
#define Display_On				(0x0CU|(LCD_Cursor<<1U)|(LCD_Cursor_Blink))
#define Display_Off				(0x08U)
#define Shift_Display_Left		(0x18U)
#define Shift_Display_Right		(0x1CU)
#define Shift_Cursor_Left		(0x10U)
#define Shift_Cursor_Right		(0x14U)
#define Function_Set			(0x20|(LCD_8bit_Mode<<4U)|(LCD_TWO_FOUR_LINES<<3U)|(LCD_5x10_Mode<<2U))

#define LCD_DDRAM_CONST         (0x80U)

#define LCD_1ST_LINE_BASE       (0x00U)
#define LCD_2ND_LINE_BASE       (0x40U)
#define LCD_3RD_LINE_BASE       (0x10U)
#define LCD_4TH_LINE_BASE       (0x50U)

void LCD_init();
void LCD_SendInstruction(uint8 instruction);
void LCD_CharDisplay(uint8 character);
void LCD_Clear(void);
void LCD_RowCol_Select(uint8 Row, uint8 Col);

void LCD_StringDisplay (char *string);
void LCD_IntegerDisplay (uint8 num);
void LCD_Cursor_ShiftLeft();
void LCD_Cursor_ShiftRight();
void LCD_Display_ShiftLeft();
void LCD_Display_ShiftRight();
#endif /* LCD_H_ */