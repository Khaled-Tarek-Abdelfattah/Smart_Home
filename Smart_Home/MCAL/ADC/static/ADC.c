/*
 * ADC.c
 *
 * Created: 10/10/2021 1:39:55 PM
 *  Author: Khaled Tarek
 */ 
#include "ADC.h"

static Adc_StatusType Adc_ConvStateGet(void);

void Adc_Init(const Adc_ConfigType * ConfigPtr)
{
	*ADC_MUX_REG = 0x00U;
	*ADC_CTRL_STATUS_A_REG = 0x00U;
	*SPECIAL_FUNC_IO_REG &= 0x1FU;
	
	switch(ConfigPtr->AdcGroup)
	{
		case ADC_GROUP0:
		/* !Comment: set the reference voltage */
		*ADC_MUX_REG |= ConfigPtr->RefVoltage;
		switch(ConfigPtr->ConvMode)
		{
			case  ADC_CON_MODE_ONESHOT:
			CLEAR_BIT(*ADC_CTRL_STATUS_A_REG,ADC_AUTO_TRIGGERED_BIT);
			break;
			case  ADC_CON_MODE_CONTINUOUS:
			SET_BIT(*ADC_CTRL_STATUS_A_REG,ADC_AUTO_TRIGGERED_BIT);
			*SPECIAL_FUNC_IO_REG |= ADC_FREERUNNING;
			break;
			case  ADC_CON_MODE_TRIGGER:
			SET_BIT(*ADC_CTRL_STATUS_A_REG,ADC_AUTO_TRIGGERED_BIT);
			*SPECIAL_FUNC_IO_REG |= ConfigPtr->TriggerSource;
			break;
		}
		switch(ConfigPtr->ResResolution)
		{
			case ADC_8_BIT:
			*ADC_MUX_REG |= ADC_ALIGN_LEFT;
			break;
			case ADC_10_BIT:
			*ADC_MUX_REG |= ConfigPtr->ResAlignment;
			break;
			default:
			break;
		}
		*ADC_CTRL_STATUS_A_REG |= ConfigPtr->IntState;
		*ADC_CTRL_STATUS_A_REG |= ConfigPtr->ClkDivFactor;
		break;
		default:
		break;
	}
	/*!Comment:  */
	/*!Comment: Enable the ADC bit before starting conversion */
	SET_BIT(*ADC_CTRL_STATUS_A_REG,ADC_ENABLE_BIT);
}
void Adc_StartGroupConversion(Adc_GroupType Group)
{
	switch (Group)
	{
		case ADC_GROUP0:
		SET_BIT(*ADC_CTRL_STATUS_A_REG,ADC_START_CONV_BIT);
		break;
		default:
		break;
	}
}
void Adc_StopGroupConversion(Adc_GroupType Group)
{
	switch (Group)
	{
		case ADC_GROUP0:
		CLEAR_BIT(*ADC_CTRL_STATUS_A_REG,ADC_START_CONV_BIT);
		break;
		default:
		break;
	}
}
void Adc_ReadChannel(const Adc_ConfigType * ConfigPtr,Adc_ValueType * DataBufferPtr)
{
	switch(ConfigPtr->AdcGroup)
	{
		case ADC_GROUP0:
		/* !Comment: Clear the channel selection bits in the ADMUX register */
		*ADC_MUX_REG &= 0xE0U;
		/* !Comment: Select the required channel to read the result from it */
		*ADC_MUX_REG |= ConfigPtr->ChannelNum;
		
		while(Adc_ConvStateGet() == ADC_BUSY )
		{
			/* Stuck on the loop */
		}
		
		switch(ConfigPtr->ResResolution)
		{
			case ADC_8_BIT:
			*DataBufferPtr = *ADC_DATA_HIGH_REG;
			break;
			case ADC_10_BIT:
			*DataBufferPtr = (uint16)((*(uint16*)ADC_DATA_LOW_REG>>6U));
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
	/*!Comment: Interrupt flag cleared by putting logic one on it */
	SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_INT_FLAG_BIT);
}
static Adc_StatusType Adc_ConvStateGet(void)
{
	Adc_StatusType eLocalAdcState = ADC_BUSY;
	if(READ_BIT(*ADC_CTRL_STATUS_A_REG, ADC_INT_FLAG_BIT))
	{
		eLocalAdcState = ADC_COMPLETED;
	}
	else
	{
		/* Do Nothing */
	}
	return (eLocalAdcState);
}