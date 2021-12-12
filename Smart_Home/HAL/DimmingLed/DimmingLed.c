/*
 * DimmingLed.c
 *
 * Created: 12/11/2021 9:39:54 PM
 *  Author: hp
 */ 
#include "DimmingLed.h"
void DimmingLed_Init()
{
	DioDirectionSet(PORTD_DIR_REG,DIO_PIN3,DIO_INPUT);
	DioDirectionSet(PORTB_DIR_REG,DIO_PIN3,DIO_OUTPUT);
	Pwm_Init(&gPwm0_configuration);
}

void DimmingLed_Intenesty(uint8 Dimming_LevelsEnum)
{
	Pwm_SetDutyCycle(PWM_CHANNEL0,PWM_HIGH,Dimming_LevelsEnum);
}



