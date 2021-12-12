/*
 * Pwm_Lcfg.c
 *
 * Created: 10/17/2021 6:58:21 PM
 *  Author: Khaled Tarek
 */ 

#include "Pwm.h"

const Pwm_ConfigType gPwm0_configuration =
{
	PWM_CHANNEL0,
	PWM_FAST_MODE,
	PWM_PRESCALE64,
	PWM_HIGH,
	1U,
	2U,
	64,
};
const Pwm_ConfigType gPwm1_configuration =
{
	PWM_CHANNEL1,
	PWM_FAST_MODE,
	PWM_PRESCALE64,
	PWM_LOW,
	1U,
	80U,
	256,
};

const Pwm_ConfigType gPwm2_configuration =
{
	PWM_CHANNEL2,
	PWM_FAST_MODE,
	PWM_PRESCALE64,
	PWM_HIGH,
	1U,
	50U,
	64,
};
