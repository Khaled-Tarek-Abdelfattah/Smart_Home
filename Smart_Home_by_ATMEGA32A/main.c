/*
 * Smart_Home_by_ATMEGA32A.c
 *
 * Created: 11/14/2021 9:33:05 PM
 * Author : Khaled Tarek
 */ 

#include "LCD.h"
#include "KeyPad.h"
#include "util/delay.h"
#include "HC-05.h"
#include "LED_Interface.h"
#include "Servo_Motor.h"


int main(void)
{
	Keypad_Init();
	LCD_init();
	_delay_ms(20);
	uint16 keypadVar = 16;
	while(1)
	{
		keypadVar = Keypad_getStatus();
		if (keypadVar!= 16)
		{
			if (keypadVar>47||keypadVar<58)
			{
				LCD_IntegerDisplay(keypadVar);
				_delay_ms(20);
			}
			else
			{
				LCD_CharDisplay(keypadVar);
				_delay_ms(20);
			}
		}
	}
}

/*LCD_init();
Led_Init(LED_2);
Keypad_Init();
while(1)
{
uint8 temp = 16;
if (temp==16)
{
Led_State(LED_2,LED_ON);
}
temp = Keypad_getStatus();
if (temp!=16)
{
if (temp<58)
{
LCD_IntegerDisplay(temp);
}
else
{
LCD_CharDisplay(temp);
}
}
_delay_ms(300);
}*/
/*Uart_Init(&gStrUart_Configuration);
Led_Init(LED_0);
Led_Init(LED_1);
Led_Init(LED_2);
LCD_init();
uint8 buffer = 0;

while(1)
{
LCD_CharDisplay(buffer);
buffer = Hc_05_Receive();
if (buffer==49)
{
Led_State(LED_0,LED_ON);
Led_State(LED_1,LED_OFF);
Led_State(LED_2,LED_OFF);
}
if (buffer==50)
{
Led_State(LED_0,LED_OFF);
Led_State(LED_1,LED_ON);
Led_State(LED_2,LED_OFF);
}
if (buffer==51)
{
Led_State(LED_0,LED_OFF);
Led_State(LED_1,LED_OFF);
Led_State(LED_2,LED_ON);
}
_delay_ms(200);
LCD_Clear();
}
*/