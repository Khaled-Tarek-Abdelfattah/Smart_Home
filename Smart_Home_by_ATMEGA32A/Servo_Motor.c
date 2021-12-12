/*
 * Servo_Motor.c
 *
 * Created: 12/7/2021 8:33:35 PM
 *  Author: hp
 */ 
#include "Servo_Motor.h"


void ServoMotor_Init()
{
	DioDirectionSet(SERVOMOTOR_DIR_PORT,DIO_PIN5,DIO_OUTPUT);
	DioDirectionSet(SERVOMOTOR_DIR_PORT,DIO_PIN6,DIO_OUTPUT);
	Pwm_Init(&gPwm2_configuration);
}
void ServoMotor_Work()
{
	DioChannelWrite(SERVOMOTOR_OUTPUT_PORT,DIO_PIN6,DIO_HIGH);
	DioChannelWrite(SERVOMOTOR_OUTPUT_PORT,DIO_PIN5,DIO_LOW);
}