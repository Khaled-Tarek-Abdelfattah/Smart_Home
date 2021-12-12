#include "Dio.h"
#include "ATMEGA32A_Config.h"
#include "Macros.h"
void DioDirectionSetPort(volatile uint8 *port,Dio_PinDirEnum_t dir)
{
	switch(dir)
	{
		case DIO_INPUT:
		*port = 0x00;
		break;
		case DIO_OUTPUT:
		*port = 0xFF;
		break;
		default:
		break;
	}
}

void DioDirectionSet(volatile uint8 * port,Dio_PinEnum_t pin,Dio_PinDirEnum_t dir){
	switch(dir){
		case DIO_INPUT:
			CLEAR_BIT(*port,pin);
			break;
		case DIO_OUTPUT:
			SET_BIT(*port,pin);
			break;
		default:
			break;
	}
}
void DioChannelWrite(volatile uint8 * port,Dio_PinEnum_t pin,Dio_PinStateEnum_t state){
	switch(pin){
		case DIO_PIN0:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN0);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN0);
					break;
				}
			break;
		case DIO_PIN1:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN1);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN1);
					break;
			}
			break;
		case DIO_PIN2:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN2);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN2);
					break;
			}
			break;
		case DIO_PIN3:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN3);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN3);
					break;
			}
			break;
		case DIO_PIN4:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN4);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN4);
					break;
			}
			break;
		case DIO_PIN5:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN5);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN5);
					break;
			}
			break;
		case DIO_PIN6:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN6);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN6);
					break;
			}
			break;
		case DIO_PIN7:
			switch(state){
				case DIO_HIGH:
					SET_BIT(*port,DIO_PIN7);
					break;
				case DIO_LOW:
					CLEAR_BIT(*port,DIO_PIN7);
					break;
			}
			break;
		default:
			break;
	}
	
}
void DioPortWrite(volatile uint8 *port,uint8 data){
	*port = data;
}
void DioChannelToggle(volatile uint8 * port,Dio_PinEnum_t pin){
	switch(pin){
		case DIO_PIN0:
			TOGGLE_BIT(*port,DIO_PIN0);
			break;
		case DIO_PIN1:
			TOGGLE_BIT(*port,DIO_PIN1);
			break;
		case DIO_PIN2:
			TOGGLE_BIT(*port,DIO_PIN2);
			break;
		case DIO_PIN3:
			TOGGLE_BIT(*port,DIO_PIN3);
			break;
		case DIO_PIN4:
			TOGGLE_BIT(*port,DIO_PIN4);
			break;
		case DIO_PIN5:
			TOGGLE_BIT(*port,DIO_PIN5);
			break;
		case DIO_PIN6:
			TOGGLE_BIT(*port,DIO_PIN6);
			break;
		case DIO_PIN7:
			TOGGLE_BIT(*port,DIO_PIN7);
			break;
		default:
			break;
	}
	
}
Dio_PinStateEnum_t DioChannelRead(volatile uint8 * port,Dio_PinEnum_t pin){
	switch(pin){
		case DIO_PIN0:
			return READ_BIT(*port,DIO_PIN0);
			break;
		case DIO_PIN1:
			return READ_BIT(*port,DIO_PIN1);
			break;
		case DIO_PIN2:
			return READ_BIT(*port,DIO_PIN2);
			break;
		case DIO_PIN3:
			return READ_BIT(*port,DIO_PIN3);
			break;
		case DIO_PIN4:
			return READ_BIT(*port,DIO_PIN4);
			break;
		case DIO_PIN5:
			return READ_BIT(*port,DIO_PIN5);
			break;
		case DIO_PIN6:
			return READ_BIT(*port,DIO_PIN6);
			break;
		case DIO_PIN7:
			return READ_BIT(*port,DIO_PIN7);
			break;
		default:
			return DIO_LOW;
			break;
	}
}