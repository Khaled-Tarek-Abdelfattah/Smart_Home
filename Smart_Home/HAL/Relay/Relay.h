/*
 * Relay.h
 *
 * Created: 12/11/2021 9:11:07 PM
 *  Author: hp
 */ 


#ifndef RELAY_H_
#define RELAY_H_


#include "ATMEGA32A_Config.h"
#include "Dio.h"

#define RELAY_DIR_REG    (PORTA_DIR_REG)
#define RELAY_OUT_REG    (PORTA_OUTPUT_REG)
#define RELAY_PIN        (DIO_PIN2)

typedef enum
{
	RELAY_OFF,
	RELAY_ON
}RelayStateEnum_t;


void Relay_Init(void);
void Relay_StateSet(RelayStateEnum_t state);

#endif /* RELAY_H_ */