/*
 * Pot.c
 *
 * Created: 10/10/2021 6:00:47 PM
 *  Author: Khaled Tarek
 */ 
#include "Pot.h"

void Pot_Init(void)
{
	Adc_Init(&gPotAdc_Configuration);
}

uint16 Pot_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	uint16 u16LocalAdcResult = 0U;
	uint16 u16LocalAdcPrecision = 0U;
	switch(gPotAdc_Configuration.ResResolution)
	{
		case ADC_8_BIT:
		u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
		break;
		case ADC_10_BIT:
		u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
		break;
		default:
		break;
	}
	Adc_StartGroupConversion(gPotAdc_Configuration.AdcGroup);
	Adc_ReadChannel(&gPotAdc_Configuration, &u16LocalAdcReading);
	u16LocalAdcResult = ((u16LocalAdcReading*5)/u16LocalAdcPrecision);
	return (u16LocalAdcResult);
}

void Pot_Stop(void)
{
	Adc_StopGroupConversion(gPotAdc_Configuration.AdcGroup);
}