
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "Dio.h"
typedef enum
{
	LED_0,
	LED_1,
	LED_2,
}LedEnum_t;
typedef enum
{
	LED_OFF,
	LED_ON,
}Led_State_t;

void Led_Init(LedEnum_t led);

void Led_State(LedEnum_t led,Led_State_t state);

void Led_Toggle(LedEnum_t led);

#endif /* LED_INTERFACE_H_ */