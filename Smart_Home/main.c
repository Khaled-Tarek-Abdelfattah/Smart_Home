/*
 * Smart_Home.c
 *
 * Created: 12/11/2021 7:13:22 PM
 * Author : hp
 */ 

#include "eeprom.h"
#include "Temp_Sensor.h"
#include "DC_Motor.h"
#include "Relay.h"
#include "LED_Interface.h"
#include "Servo_motor.h"
#include "UART.h"
#include "DimmingLed.h"
#include "Pot.h"

int main(void)
{
    /* Replace with your application code */
	ServoMotor_Init();
	ServoMotor_Rotate90();
	Relay_Init();
	Uart_Init(&gStrUart_Configuration);
	DimmingLed_Init();
	Pot_Init();
	uint8 bleutoothVar = 0;
    while (1) 
    {
		Uart_Receive(&bleutoothVar);
		if (bleutoothVar==49)/*Send 1*/
		{
			ServoMotor_Rotate0();/*Open door*/
		}
		if (bleutoothVar==50)/*Send 2*/
		{
			ServoMotor_Rotate90();/*close door*/
		}
		if(bleutoothVar==51)/*Send 3*/
		{
			Relay_StateSet(RELAY_ON);
		}
		else if(bleutoothVar==52)/*Send 4*/
		{
			Relay_StateSet(RELAY_OFF);
		}
    }
}

