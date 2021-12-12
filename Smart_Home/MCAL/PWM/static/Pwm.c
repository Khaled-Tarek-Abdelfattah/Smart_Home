/*
 * Pwm.c
 *
 * Created: 10/17/2021 6:59:32 PM
 *  Author: Khaled Tarek
 */ 

#include "Pwm.h"


static void Pwm_Timer1InitReg(void);
static uint16 gu16TimerTopValue = 0U;

void Pwm_Init(const Pwm_ConfigType *ConfigPtr)
{
	switch(ConfigPtr->PwmChannel)
	{
		case PWM_CHANNEL0:
		*TIMER0_CTRL_REG = 0x00U;
		*TIMER0_CMP_REG = 0x00U;
		*TIMER0_COUNTER_REG = 0x00U;
		
		*TIMER0_CTRL_REG |= ConfigPtr->PwmMode;
		*TIMER0_CTRL_REG |= ConfigPtr->PwmOutType;
		*TIMER0_CTRL_REG |= ConfigPtr->PwmClkDiv; 
		switch(ConfigPtr->PwmOutType)
		{
			case PWM_LOW:
			*TIMER0_CMP_REG = (uint8) ((ConfigPtr->PwmDuty * TIMER0_RESOLUTION)/100U);
			break;
			case PWM_HIGH:
			*TIMER0_CMP_REG = (uint8) (((100U-ConfigPtr->PwmDuty) * TIMER0_RESOLUTION)/100U);
			break;
			default:
			break;
		}
		break;
		case PWM_CHANNEL1:
		Pwm_Timer1InitReg();
		switch(ConfigPtr->PwmMode)
		{
			case PWM_FAST_MODE:
			CLEAR_BIT(*TIMER1_CTRL_A_REG,TIMER1_WAVEFORM_GEN_MODE0);
			SET_BIT(*TIMER1_CTRL_A_REG,TIMER1_WAVEFORM_GEN_MODE1);
			SET_BIT(*TIMER1_CTRL_B_REG,TIMER1_WAVEFORM_GEN_MODE2);
			SET_BIT(*TIMER1_CTRL_B_REG,TIMER1_WAVEFORM_GEN_MODE3);
			break;
			case PWM_PHASECORRECTION_MODE:
			SET_BIT(*TIMER1_CTRL_A_REG,TIMER1_WAVEFORM_GEN_MODE0);
			SET_BIT(*TIMER1_CTRL_A_REG,TIMER1_WAVEFORM_GEN_MODE1);
			CLEAR_BIT(*TIMER1_CTRL_B_REG,TIMER1_WAVEFORM_GEN_MODE2);
			SET_BIT(*TIMER1_CTRL_B_REG,TIMER1_WAVEFORM_GEN_MODE3);
			break;
			default:
			break;
		}
		gu16TimerTopValue = (uint16)(F_CPU / (ConfigPtr->TimerClk * (1000.0 / ConfigPtr->PwmPeriod))) - 1U;
		*(uint16*)TIMER1_INP_CAP_LOW_REG = gu16TimerTopValue;
		switch(ConfigPtr->PwmOutType)
		{
			case PWM_LOW:
			CLEAR_BIT(*TIMER1_CTRL_A_REG, 6U);
			SET_BIT(*TIMER1_CTRL_A_REG, 7U);
			*(uint16*)TIMER1_CMP_A_LOW_REG = (uint16) ((ConfigPtr->PwmDuty * gu16TimerTopValue)/100U);
			break;
			case PWM_HIGH:
			SET_BIT(*TIMER1_CTRL_A_REG, 6U);
			SET_BIT(*TIMER1_CTRL_A_REG, 7U);
			*(uint16*)TIMER1_CMP_A_LOW_REG = (uint16) (((100U - ConfigPtr->PwmDuty) * gu16TimerTopValue)/100U);
			break;
			default:
			break;
		}
		*TIMER1_CTRL_B_REG |= ConfigPtr->PwmClkDiv;
		break;
		case PWM_CHANNEL2:
		*TIMER2_CTRL_REG = 0x00U;
		*TIMER2_CMP_REG = 0x00U;
		*TIMER2_COUNTER_REG = 0x00U;
		
		*TIMER2_CTRL_REG |= ConfigPtr->PwmMode;
		*TIMER2_CTRL_REG |= ConfigPtr->PwmOutType;
		*TIMER2_CTRL_REG |= ConfigPtr->PwmClkDiv;
		switch(ConfigPtr->PwmOutType)
		{
			case PWM_LOW:
			*TIMER2_CMP_REG = (uint8) ((ConfigPtr->PwmDuty * TIMER2_RESOLUTION)/100U);
			break;
			case PWM_HIGH:
			*TIMER2_CMP_REG = (uint8) (((100U-ConfigPtr->PwmDuty) * TIMER2_RESOLUTION)/100U);
			break;
			default:
			break;
		}
		break;
	}
}
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber,Pwm_OutputStateType OutputType,uint16 DutyCycle)
{
	switch(ChannelNumber)
	{
		case PWM_CHANNEL0:
		switch(OutputType)
		{
			case PWM_LOW:
			*TIMER0_CMP_REG = (uint8) ((DutyCycle * TIMER0_RESOLUTION)/100U);
			break;
			case PWM_HIGH:
			*TIMER0_CMP_REG = (uint8) (((100U-DutyCycle) * TIMER0_RESOLUTION)/100U);
			break;
			default:
			break;
		}
		break;
		case PWM_CHANNEL1:
		switch(OutputType)
		{
			case PWM_LOW:
			*(uint16*)TIMER1_CMP_A_LOW_REG = (uint16) ((DutyCycle * gu16TimerTopValue)/100U);
			break;
			case PWM_HIGH:
			*(uint16*)TIMER1_CMP_A_LOW_REG = (uint16) (((100U - DutyCycle) * gu16TimerTopValue)/100U);
			break;
			default:
			break;
		}
		break;
		case PWM_CHANNEL2:
		switch(OutputType)
		{
			case PWM_LOW:
			*TIMER2_CMP_REG = (uint8) ((DutyCycle * TIMER2_RESOLUTION)/100U);
			break;
			case PWM_HIGH:
			*TIMER2_CMP_REG = (uint8) (((100U-DutyCycle) * TIMER2_RESOLUTION)/100U);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

static void Pwm_Timer1InitReg(void)
{
	*TIMER1_CMP_B_HIGH_REG = 0x00U;
	*TIMER1_CMP_B_LOW_REG = 0x00U;
	*TIMER1_CTRL_A_REG = 0x00U;
	*TIMER1_CTRL_B_REG = 0x00U;
	*TIMER_INTERRUPT_MASK_REG &= (0xC3U);
}