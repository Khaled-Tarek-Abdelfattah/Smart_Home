/*
 * Gpt_Lcfg.c
 *
 * Created: 10/12/2021 12:59:39 PM
 *  Author: hp
 */ 

#include "Gpt.h"

const Gpt_ConfigType gaStrGpt0_Configuration =
{
	GPT_TIMER0,
	GPT_CTC_MODE,
	GPT_PRESCALE1024,
	GPT_INT_ENABLE,
	200U							
};

const Gpt_ConfigType gaStrGpt1_Configuration =
{
	GPT_TIMER1,
	GPT_CTC_MODE,
	GPT_PRESCALE1024,
	GPT_INT_ENABLE,
	46875U
};
const Gpt_ConfigType gaStrGpt2_Configuration =
{
	GPT_TIMER2,
	GPT_NORMAL_MODE,
	GPT_EXTERNALCLK_FALLING_EDGE,    /* In timer two it's equivalent to prescaler 256 */
	GPT_INT_ENABLE,
	0U					/*!Comment: Normal mode so no compare value */
};