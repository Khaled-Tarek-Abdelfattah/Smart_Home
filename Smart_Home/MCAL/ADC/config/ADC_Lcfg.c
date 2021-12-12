/*
 * ADC_Lcfg.c
 *
 * Created: 10/10/2021 1:39:31 PM
 *  Author: Khaled Tarek
 */ 
#include "ADC.h"
const Adc_ConfigType gTemAdc_Configuration =
{
	ADC_GROUP0,
	ADC_REF_AVCC,
	ADC_10_BIT,
	ADC_ALIGN_LEFT,
	ADC_CHANNEL_0,
	ADC_INT_DESABLE,
	ADC_CON_MODE_CONTINUOUS,
	ADC_PRESCALE_128,
	0U,
};

const Adc_ConfigType gPotAdc_Configuration =
{
	ADC_GROUP0,
	ADC_REF_AVCC,
	ADC_10_BIT,
	ADC_ALIGN_RIGHT,
	ADC_CHANNEL_1,
	ADC_INT_DESABLE,
	ADC_CON_MODE_CONTINUOUS,
	ADC_PRESCALE_128,
	0U,
};