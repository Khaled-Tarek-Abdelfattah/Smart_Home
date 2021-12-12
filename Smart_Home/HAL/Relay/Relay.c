/*
 * Relay.c
 *
 * Created: 12/11/2021 9:10:52 PM
 *  Author: hp
 */ 
#include "Relay.h"

void Relay_Init(void)
{
	DioDirectionSet(RELAY_DIR_REG, RELAY_PIN, DIO_OUTPUT);
}
void Relay_StateSet(RelayStateEnum_t state)
{
	DioChannelWrite(RELAY_OUT_REG, RELAY_PIN, state);
}