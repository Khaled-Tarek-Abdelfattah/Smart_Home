#ifndef DIO_H_
#define DIO_H_
#include "Std_Types.h"
#include "Macros.h"
#include "ATMEGA32A_Config.h"
typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}Dio_PortEnum_t;

typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}Dio_PinEnum_t;

typedef enum
{
	DIO_LOW,
	DIO_HIGH,
}Dio_PinStateEnum_t;

typedef enum
{
	DIO_INPUT,
	DIO_OUTPUT
}Dio_PinDirEnum_t;

void DioDirectionSetPort(volatile uint8 *port,Dio_PinDirEnum_t dir);
void DioDirectionSet(volatile uint8 *port,Dio_PinEnum_t pin,Dio_PinDirEnum_t dir);
void DioChannelWrite(volatile uint8 * port,Dio_PinEnum_t pin,Dio_PinStateEnum_t state);
void DioPortWrite(volatile uint8 * port,uint8 data);
void DioChannelToggle(volatile uint8 * port,Dio_PinEnum_t pin);
Dio_PinStateEnum_t DioChannelRead(volatile uint8 * port,Dio_PinEnum_t pin);

#endif