/*
 * Servo_motor.c
 *
 * Created: 12/9/2021 2:23:07 PM
 *  Author: hp
 */ 

#include "Servo_motor.h"

void ServoMotor_Init()
{
	DioDirectionSet(PORTD_DIR_REG,DIO_PIN5,DIO_OUTPUT);
	Pwm_Init(&gPwm1_configuration);
	*TIMER1_INP_CAP_REG = 2499;
}
void ServoMotor_Rotate90()
{
	*TIMER1_CMP_A_Reg = 400;
	_delay_ms(1500);
}
void ServoMotor_Rotate0()
{
	*TIMER1_CMP_A_Reg = 175;	
	_delay_ms(1500);
}
void ServoMotor_Rotateneg90()
{
	*TIMER1_CMP_A_Reg = 65;	
	_delay_ms(1500);
}
