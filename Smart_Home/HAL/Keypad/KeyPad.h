/*
 * KeyPad.h
 *
 * Created: 11/14/2021 9:34:27 PM
 *  Author: hp
 */ 

#include "Dio.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_DIR_PORT					PORTC_DIR_REG
#define KEYPAD_DATA_ROW_PORT			PORTC_OUTPUT_REG
#define KEYPAD_DATA_COLUMN_PORT			PORTC_INPUT_REG

typedef enum
{
	KEYPAD_PIN0,
	KEYPAD_PIN1,
	KEYPAD_PIN2,
	KEYPAD_PIN3,
	KEYPAD_PIN4,
	KEYPAD_PIN5,
	KEYPAD_PIN6,
	KEYPAD_PIN7,
}Keypad_PinEnum;

typedef enum
{
	KEYPAD_IDLE,
	KEYPAD_PRESSED,
}Keypad_StatusType;

typedef uint8 keypadReturnType;

void Keypad_Init();
uint8 Keypad_getStatus();

#endif /* KEYPAD_H_ */