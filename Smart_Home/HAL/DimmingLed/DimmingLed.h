/*
 * DimmingLed.h
 *
 * Created: 12/11/2021 9:39:40 PM
 *  Author: hp
 */ 


#ifndef DIMMINGLED_H_
#define DIMMINGLED_H_

#include "Dio.h"
#include "Pwm.h"

typedef enum
{
	DIMMING_LOW = 10U,
	DIMMING_MEDIUM = 40U,
	DIMMING_HIGH = 70U,
	DIMMING_VERYHIGH = 100U,
}Dimming_LevelsEnum;

void DimmingLed_Init();

void DimmingLed_Intenesty(uint8 Dimming_LevelsEnum);



#endif /* DIMMINGLED_H_ */