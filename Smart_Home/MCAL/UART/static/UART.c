/*
 * UART.c
 *
 * Created: 10/25/2021 7:24:10 PM
 *  Author: Khaled Tarek
 */ 

#include "UART.h"

void Uart_Init(const Uart_ConfigType *ConfigPtr)
{
	switch(ConfigPtr->Channel)
	{
		case UART_CHANNEL_0:
			*UART_CTRL_STATUS_A_REG = 0x00;
			*UART_CTRL_STATUS_B_REG = 0x00;
			*UART_CTRL_STATUS_C_REG = 0x00;
	
			*UART_CTRL_STATUS_A_REG |= (ConfigPtr->Speed<<UART_DOUBLE_SPEED_BIT);
			
			*UART_CTRL_STATUS_B_REG |= (ConfigPtr->IntState<<UART_INT_STATE_BITS);
			if (ConfigPtr->DataBits == UART_9_DATA_BITS)
			{
				SET_BIT(*UART_CTRL_STATUS_B_REG,UART_CHAR_SIZE_BIT);
			}
			else
			{
				/* Do Nothing */
			}
			SET_BIT(*UART_CTRL_STATUS_C_REG,UART_REGISTER_SELECT_BIT);
			*UART_CTRL_STATUS_C_REG |= (ConfigPtr->OperationMode<<UART_MODE_SELECT_BIT);
			*UART_CTRL_STATUS_C_REG |= (ConfigPtr->Parity<<UART_PARITY_SELECT_BITS);
			*UART_CTRL_STATUS_C_REG |= (ConfigPtr->StopBits<<UART_STOP_BITS_SELECT_BIT);
			*UART_CTRL_STATUS_C_REG |= (ConfigPtr->DataBits<<UART_DATA_BITS_NUM);
			*UART_CTRL_STATUS_B_REG |= (ConfigPtr->Mode << UART_COMM_TYPE_BIT);
			if (ConfigPtr->OperationMode == UART_SYNCH_MODE)
			{
				*UART_CTRL_STATUS_C_REG |= ConfigPtr->ClkPolarity;
			}
			else
			{
				/* Do Nothing */
			}
			/* !Comment: Set the UART Baudrate */
			/* !Comment: Select to write on UBRRH by Clearing the register select bit */
			CLEAR_BIT(*UART_CTRL_STATUS_C_REG, UART_REGISTER_SELECT_BIT);
			switch(ConfigPtr->Speed)
			{
				case UART_NORMAL_MODE:
					*UART_BAUDRATE_HIGH_REG = (uint8)((uint16)(F_CPU/(16.0 * ConfigPtr->Baudrate) - 1) >> 8U);
					*UART_BAUDRATE_LOW_REG  = (uint8)(F_CPU/(16.0 * ConfigPtr->Baudrate) - 1 );
					break;
				case UART_DOUBLE_SPEED_MODE:
					*UART_BAUDRATE_HIGH_REG = ((uint16)(F_CPU/(8.0 * ConfigPtr->Baudrate) - 1) >> 8U);
					*UART_BAUDRATE_LOW_REG  = (uint8)(F_CPU/(8.0 * ConfigPtr->Baudrate) - 1);
					break;
				default:
					break;
			}
			
			break;
			default:
			break;
	}
	
}
void Uart_Transmit(const uint8 Data)
{
	while(Uart_StatusGet(UART_TX) != UART_TX_COMPLETE)
	{
		/* Do Nothing */
	}
	*UART_DATA_REG = Data;
}
void Uart_Receive(uint8 *ReceiveBuff)
{
	while(Uart_StatusGet(UART_RX) != UART_RX_COMPLETE)
	{
		/* Do Nothing */
	}
	*ReceiveBuff = *UART_DATA_REG;
}
void Uart_StringTransmit(const uint8 *Str)
{
	while(*Str != '\0')
	{
		Uart_Transmit(*Str);
		Str++;
	}
}

void Uart_StringReceive(uint8 *ReceiveBuff)
{
	uint8 u8LocalIndex = 0U;
	Uart_Receive(&ReceiveBuff[u8LocalIndex]);
	while(ReceiveBuff[u8LocalIndex] != '\0')
	{
		u8LocalIndex++;
		Uart_Receive(&ReceiveBuff[u8LocalIndex]);
	}
	ReceiveBuff[u8LocalIndex] = '\0';
}

Uart_StatusType Uart_StatusGet(Uart_ModeType Mode)
{
	Uart_StatusType u8LocalUartState = UART_BUSY;
	switch(Mode)
	{
		case UART_TX:
		if(READ_BIT(*UART_CTRL_STATUS_A_REG, UART_DATA_REG_EMPTY_FLAG) == 1U)
		{
			u8LocalUartState = UART_TX_COMPLETE;
		}
		else
		{
			/* Do Nothing */
		}
		break;
		case UART_RX:
		if(READ_BIT(*UART_CTRL_STATUS_A_REG, UART_RX_COMPLETE_FLAG))
		{
			u8LocalUartState = UART_RX_COMPLETE;
		}
		else
		{
			/* Do Nothing */
		}
		break;
		default:
		break;
	}
	return (u8LocalUartState);
}
