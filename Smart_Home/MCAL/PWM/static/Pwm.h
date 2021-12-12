/*
 * Pwm.h
 *
 * Created: 10/17/2021 6:59:44 PM
 *  Author: Khaled Tarek
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "ATMEGA32A_Config.h"
#include "Macros.h"
#include "Pwm_Pcfg.h"

typedef uint16 Pwm_PeriodType;

typedef enum
{
	PWM_CHANNEL0,
	PWM_CHANNEL1,
	PWM_CHANNEL2
}Pwm_ChannelType;

typedef enum
{
	PWM_LOW = 0x20U,
	PWM_HIGH = 0x30U,
}Pwm_OutputStateType;

typedef enum
{
	PWM_NOCLK,
	PWM_PRESCALE1,
	PWM_PRESCALE8,
	PWM_PRESCALE64,
	PWM_PRESCALE256,
	PWM_PRESCALE1024,
	PWM_EXTERNALCLK_FALLING_EDGE,
	PWM_EXTERNALCLK_RISING_EDGE,
}Pwm_prescaleType;

typedef enum
{
	PWM_PHASECORRECTION_MODE = 0x40U,
	PWM_FAST_MODE = 0x48U,
}Pwm_ModeType;

typedef struct 
{
	Pwm_ChannelType PwmChannel;
	Pwm_ModeType PwmMode;
	Pwm_prescaleType PwmClkDiv;
	Pwm_OutputStateType PwmOutType;
	Pwm_PeriodType PwmPeriod;
	uint16 PwmDuty;
	uint16 TimerClk;
}Pwm_ConfigType;

extern const Pwm_ConfigType gPwm0_configuration;
extern const Pwm_ConfigType gPwm1_configuration;
extern const Pwm_ConfigType gPwm2_configuration;

void Pwm_Init(const Pwm_ConfigType *ConfigPtr);
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber,Pwm_OutputStateType OutputType,uint16 DutyCycle);



#endif /* PWM_H_ */