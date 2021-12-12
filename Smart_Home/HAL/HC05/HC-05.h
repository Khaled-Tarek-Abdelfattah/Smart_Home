/*
 * HC_05.h
 *
 * Created: 12/4/2021 7:39:42 PM
 *  Author: hp
 */ 


#ifndef HC_05_H_
#define HC_05_H_

#include "UART.h"

void Hc_05_Init();
void Hc_05_Receive(uint8 buffer);

void Hc_05_StringReceive(uint8 ReceiveBuff);




#endif /* HC-05_H_ */