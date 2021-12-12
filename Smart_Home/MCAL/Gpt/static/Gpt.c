/*
 * Gpt.c
 *
 * Created: 10/12/2021 12:59:54 PM
 *  Author: hp
 */ 

#include "Gpt.h"

static void Gpt_Timer1InitReg(void);

void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	switch(ConfigPtr->GptNo)
	{
		case GPT_TIMER0:
		/*!Comment: first initialize timer0 control reg */
		*TIMER0_CTRL_REG = 0x00U;
		*TIMER0_CMP_REG = 0x00U;
		*TIMER_INTERRUPT_MASK_REG &= (0xFCU);
		/*!Comment: Start initialization */
		switch(ConfigPtr->GptMode)
		{
			case GPT_NORMAL_MODE:
			*TIMER0_CTRL_REG |= GPT_NORMAL_MODE;
			*TIMER_INTERRUPT_MASK_REG |= (ConfigPtr->GptIntState<<TIMER0_OV_INT_ENABLE);
			break;
			case GPT_CTC_MODE:
			*TIMER0_CTRL_REG |= GPT_CTC_MODE;
			*TIMER_INTERRUPT_MASK_REG |= (ConfigPtr->GptIntState<<TIMER0_CMPMATCH_INT_ENABLE);
			*TIMER0_CMP_REG |= (ConfigPtr->GptCmpValue-1);
			break;
			default:
			break;
		}
		*TIMER0_CTRL_REG |= ConfigPtr->GptClkDivision;
		*TIMER0_COUNTER_REG = 0x00U;
		break;
		case GPT_TIMER1:
		Gpt_Timer1InitReg();
		switch(ConfigPtr->GptMode)
		{
			case GPT_NORMAL_MODE:
			*TIMER1_CTRL_B_REG |= GPT_NORMAL_MODE;
			*TIMER_INTERRUPT_MASK_REG |= ((ConfigPtr->GptIntState)<<TIMER1_OV_INT_ENABLE);
			break;
			case GPT_CTC_MODE:
			*TIMER1_CTRL_B_REG |= GPT_CTC_MODE;
			*TIMER_INTERRUPT_MASK_REG |= ((ConfigPtr->GptIntState)<<TIMER1_CMP_A_INT_ENABLE);
			*(uint16*)TIMER1_CMP_A_LOW_REG = (ConfigPtr->GptCmpValue - 1);
			break;
			default:
			break;
		}
		*TIMER1_CTRL_B_REG |= ConfigPtr->GptClkDivision;
		*(uint16*)TIMER1_COUNT_LOW_REG = 0x0000U;
		break;
		case GPT_TIMER2:
		*TIMER2_CTRL_REG = 0x00U;
		*TIMER2_CMP_REG = 0x00U;
		*TIMER_INTERRUPT_MASK_REG &= (0x3FU);
		/*!Comment: Start initialization */
		switch(ConfigPtr->GptMode)
		{
			case GPT_NORMAL_MODE:
			*TIMER2_CTRL_REG |= GPT_NORMAL_MODE;
			*TIMER_INTERRUPT_MASK_REG |= ((ConfigPtr->GptIntState)<<TIMER2_OV_INT_ENABLE);
			break;
			case GPT_CTC_MODE:
			*TIMER2_CTRL_REG |= GPT_CTC_MODE;
			*TIMER_INTERRUPT_MASK_REG |= ((ConfigPtr->GptIntState)<<TIMER2_CMPMATCH_INT_ENABLE);
			*TIMER2_CMP_REG |= (ConfigPtr->GptCmpValue-1);
			break;
			default:
			break;
		}
		SET_BIT(*SPECIAL_FUNCTION_REG,2U);
		*TIMER2_CTRL_REG |= ConfigPtr->GptClkDivision;
		*TIMER2_COUNTER_REG = 0x00U;
		break;
		default:
		break;
	}
}
Gpt_StatusType Gpt_StatusGet(Gpt_ChannelType Channel)
{
	Gpt_StatusType localEnumGptStatus = GPT_RUNNING;
	switch(Channel)
	{
		case GPT_TIMER0:
		switch(gaStrGpt0_Configuration.GptMode)
		{
			case GPT_NORMAL_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OV_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				/* !Comment: Clear The TOV bit */
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OV_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			case GPT_CTC_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_CMPMATCH_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				/* !Comment: Clear The OCF bit */
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_CMPMATCH_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			default:
			break;
		}
		break;
		case GPT_TIMER1:
		switch(gaStrGpt1_Configuration.GptMode)
		{
			case GPT_NORMAL_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG,TIMER1_OV_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG,TIMER1_OV_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			case GPT_CTC_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG,TIMER1_CMP_A_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG,TIMER1_CMP_A_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			default:
			break;
		}
		break;
		case GPT_TIMER2:
		switch(gaStrGpt0_Configuration.GptMode)
		{
			case GPT_NORMAL_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OV_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				/* !Comment: Clear The TOV bit */
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OV_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			case GPT_CTC_MODE:
			if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_CMPMATCH_FLAG))
			{
				localEnumGptStatus = GPT_OV_CMP;
				/* !Comment: Clear The OCF bit */
				SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_CMPMATCH_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
	return (localEnumGptStatus);
}

static void Gpt_Timer1InitReg(void)
{
	*TIMER1_CMP_B_HIGH_REG = 0x00U;
	*TIMER1_CMP_B_LOW_REG = 0x00U;
	*TIMER1_CTRL_A_REG = 0x00U;
	*TIMER1_CTRL_B_REG = 0x00U;
	*TIMER_INTERRUPT_MASK_REG &= (0xC3U);
}