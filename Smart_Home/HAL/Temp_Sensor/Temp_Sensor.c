/*
 * Temp_Sensor.c
 *
 * Created: 10/10/2021 6:04:12 PM
 *  Author: Khaled Tarek
 */ 

#include "Temp_Sensor.h"

void TempSensor_Init(void)
{
	Adc_Init(&gTemAdc_Configuration);
}
uint8 TempSensor_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	uint16 u16LocalAdcPrecision = 0U;
	uint8 u8LocalTemp = 0U;
	Adc_StartGroupConversion(gTemAdc_Configuration.AdcGroup);
	Adc_ReadChannel(&gTemAdc_Configuration, &u16LocalAdcReading);
	switch(gTemAdc_Configuration.ResResolution)
	{
		case ADC_10_BIT:
		u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
		break;
		case ADC_8_BIT:
		u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
		break;
		default:
		break;
	}
	/* !Comment: Temperature Sensor equation */
	u8LocalTemp = (((u16LocalAdcReading * ADC_5_VOLT_REF*100) / u16LocalAdcPrecision)) ;
	
	return (u8LocalTemp);
}

void TempSensor_Stop(void)
{
	Adc_StopGroupConversion(gTemAdc_Configuration.AdcGroup);
}
