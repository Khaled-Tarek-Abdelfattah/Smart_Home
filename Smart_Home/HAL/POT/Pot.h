/*
 * Pot.h
 *
 * Created: 10/10/2021 6:00:09 PM
 *  Author: Khaled Tarek
 */ 


#ifndef POT_H_
#define POT_H_


#include "Adc.h"

#define POT_PIN                        (ADC_CHANNEL_1)

#define ADC_TEN_BIT_PRECISION          (1023U)
#define ADC_EIGHT_BIT_PRECISION        (255U)

void Pot_Init(void);
uint16 Pot_ValueGet(void);
void Pot_Stop(void);


#endif /* POT_H_ */