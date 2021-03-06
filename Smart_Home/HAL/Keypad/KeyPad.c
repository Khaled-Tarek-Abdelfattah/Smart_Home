/*
 * KeyPad.c
 *
 * Created: 11/14/2021 9:34:40 PM
 *  Author: Khaled Tarek
 */ 

#include "KeyPad.h"
#include "util/delay.h"

void Keypad_Init()
{
	*KEYPAD_DIR_PORT = 0xF0;
	*KEYPAD_DATA_ROW_PORT = 0xF0;
	*KEYPAD_DATA_COLUMN_PORT &= 0xF0;
}
uint8 Keypad_getStatus()
{
	*KEYPAD_DATA_ROW_PORT = 0xF0;
	uint8 buffer = 16;
	if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3))
	{
		*KEYPAD_DATA_ROW_PORT = 0x80;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3));
			buffer =  1U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x40;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3));
			buffer =  4U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x20;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3));
			buffer =  7U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x10;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN3));
			buffer =  '*';
		}
	}
	if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2))
	{
		*KEYPAD_DATA_ROW_PORT = 0x80;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2));
			buffer =  2U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x40;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2));
			buffer =  5U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x20;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2));
			buffer =  8U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x10;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN2));
			buffer =  0U;
		}
	}
	if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1))
	{
		*KEYPAD_DATA_ROW_PORT = 0x80;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1));
			buffer =  3U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x40;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1));
			buffer =  6U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x20;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1));
			buffer =  9U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x10;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN1));
			buffer =  '#';
		}
	}
	if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0))
	{
		*KEYPAD_DATA_ROW_PORT = 0x80;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0));
			buffer =  65U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x40;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0));
			buffer =  66U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x20;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0));
			buffer =  67U;
		}
		*KEYPAD_DATA_ROW_PORT = 0x10;
		_delay_ms(5);
		if (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0))
		{
			while (READ_BIT(*KEYPAD_DATA_COLUMN_PORT,KEYPAD_PIN0));
			buffer =  68U;
		}
	}
	
	return buffer;
}
