/*
 * Gpt.h
 *
 * Created: 10/12/2021 1:00:07 PM
 *  Author: hp
 */ 


#ifndef GPT_H_
#define GPT_H_

#include "Gpt_Pcfg.h"
#include "ATMEGA32A_Config.h"
#include "Macros.h"

typedef enum
{
	GPT_TIMER0,
	GPT_TIMER1,
	GPT_TIMER2
}Gpt_ChannelType;

typedef enum
{
	GPT_NORMAL_MODE = 0x00U,
	GPT_CTC_MODE = 0x08U,
}Gpt_ModeType;

typedef enum 
{
	GPT_NOCLK,
	GPT_PRESCALE1,
	GPT_PRESCALE8,
	GPT_PRESCALE64,
	GPT_PRESCALE256,
	GPT_PRESCALE1024,
	GPT_EXTERNALCLK_FALLING_EDGE,
	GPT_EXTERNALCLK_RISING_EDGE,
}Gpt_PrescaleType;

typedef enum
{
	GPT_RUNNING,
	GPT_OV_CMP
}Gpt_StatusType;

typedef enum
{
	GPT_INT_DISABLE,
	GPT_INT_ENABLE
}Gpt_IntStateType;

typedef uint16 Gpt_ValueType; 

typedef struct
{
	Gpt_ChannelType	 GptNo;
	Gpt_ModeType     GptMode;
	Gpt_PrescaleType GptClkDivision;
	Gpt_IntStateType GptIntState;
	Gpt_ValueType    GptCmpValue;
}Gpt_ConfigType;

extern const Gpt_ConfigType gaStrGpt0_Configuration;
extern const Gpt_ConfigType gaStrGpt1_Configuration;
extern const Gpt_ConfigType gaStrGpt2_Configuration;

void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
Gpt_StatusType Gpt_StatusGet(Gpt_ChannelType Channel);

#endif /* GPT_H_ */