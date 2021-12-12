/*
 * ADC.h
 *
 * Created: 10/10/2021 1:39:43 PM
 *  Author: Khaled Tarek
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_Pcfg.h"
#include "ATMEGA32A_Config.h"
#include "Macros.h"

typedef enum
{
	ADC_GROUP0,	
}Adc_GroupType;

typedef enum
{
	ADC_REF_AREF = 0x00U,
	ADC_REF_AVCC = 0x40U,
	ADC_REF_2_56V = 0xC0U,
}Adc_RefType;

typedef enum 
{
	ADC_ALIGN_RIGHT = 0x00U,
	ADC_ALIGN_LEFT = 0x20U,
}Adc_ResultAlignmentType;

typedef enum
{
	ADC_8_BIT,
	ADC_10_BIT
}Adc_ResolutionType;

typedef enum 
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7,
}Adc_ChannelType;

typedef enum
{
	ADC_INT_DESABLE = 0x00U,
	ADC_INT_ENABLE = 0x08U,
}Adc_IntStateType;

typedef enum
{
	ADC_BUSY,
	ADC_COMPLETED,
}Adc_StatusType;
typedef enum
{
	ADC_CON_MODE_CONTINUOUS     = 0x00U,
	ADC_CON_MODE_ONESHOT        = 0x01U,
	ADC_CON_MODE_TRIGGER        = 0x02U
}Adc_ConModeType;

typedef enum
{
	ADC_PRESCALE_2 = 0x01U,
	ADC_PRESCALE_4,
	ADC_PRESCALE_8,
	ADC_PRESCALE_16,
	ADC_PRESCALE_32,
	ADC_PRESCALE_64,
	ADC_PRESCALE_128
}Adc_PrescaleType;

typedef enum
{
	ADC_FREERUNNING				= 0x00U,
	ADC_ANALOG_COMPARATOR       = 0x20U,
	ADC_EXT_INTERRUPT0          = 0x40U,
	ADC_TIMER0_CMP_MATCH        = 0x60U,
	ADC_TIMER0_OVF              = 0x80U,
	ADCE_TIMER1_CMP_MATCH_B     = 0xA0U,
	ADC_TIMER1_OVF              = 0xC0U,
	ADC_TIMER1_CAPTURE_EVENT    = 0xE0U
}Adc_TriggerSourceType;

typedef struct
{
	Adc_GroupType AdcGroup;
	Adc_RefType RefVoltage;
	Adc_ResolutionType ResResolution;
	Adc_ResultAlignmentType ResAlignment;
	Adc_ChannelType ChannelNum;
	Adc_IntStateType IntState;
	Adc_ConModeType ConvMode;
	Adc_PrescaleType ClkDivFactor;
	Adc_TriggerSourceType TriggerSource;
}Adc_ConfigType;


typedef uint16 Adc_ValueType;

void Adc_Init(const Adc_ConfigType * ConfigPtr);
void Adc_StartGroupConversion(Adc_GroupType Group);
void Adc_StopGroupConversion(Adc_GroupType Group);
void Adc_ReadChannel(const Adc_ConfigType * ConfigPtr,Adc_ValueType * DataBufferPtr);
extern const Adc_ConfigType gTemAdc_Configuration;
extern const Adc_ConfigType gPotAdc_Configuration;

#endif /* ADC_H_ */