#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "ATMEGA32A_Config.h"

#define LCD_RS					(DIO_PIN1)
#define LCD_RW					(DIO_PIN2)
#define LCD_EN					(DIO_PIN3)

#define LCD_CTRL_DIR_REG        (PORTB_DIR_REG)
#define LCD_CTRL_OUT_REG        (PORTB_OUTPUT_REG)

#define LCD_DATA_DIR_REG        (PORTA_DIR_REG)
#define LCD_DATA_OUT_REG        (PORTA_OUTPUT_REG)

#define LCD_Cursor				0U			/*1 for enable, 0 for disable*/
#define LCD_Cursor_Blink		0U			/*1 for enable, 0 for disable*/
#define LCD_8bit_Mode			0U			/*1 for 8 bit mode, 0 for 4 bit mode*/
#define LCD_5x10_Mode			0U  	    /*1 for enable, 0 for disable*/
#define LCD_TWO_FOUR_LINES		1U			/*1 for two lines 0 for one line(16*2 LCD),1 for four lines 0 for two line(16*4 LCD)*/


#if ( LCD_5x10_Mode && LCD_TWO_FOUR_LINES )
#pragma GCC error "You cannot Have Two/four Lines LCD with 5 * 10"
#endif

#endif /* LCD_CONFIG_H_ */