/*
 * HC_05.c
 *
 * Created: 12/4/2021 7:39:23 PM
 *  Author: hp
 */ 
#include "HC-05.h"

void Hc_05_Init()
{
	Uart_Init(&gStrUart_Configuration);
}

uint8 Hc_05_Receive()
{
	return Uart_Receive();
}
void Hc_05_StringReceive(uint8 ReceiveBuff)
{
	Uart_StringReceive(&ReceiveBuff);
}
