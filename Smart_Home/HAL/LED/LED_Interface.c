#include "LED_Interface.h"
#include "Dio.h"

void Led_Init(LedEnum_t led){
	switch(led){
		case LED_0:
			DioDirectionSet(PORTC_DIR_REG,DIO_PIN2,DIO_OUTPUT);
			break;
		case LED_1:
			DioDirectionSet(PORTC_DIR_REG,DIO_PIN7,DIO_OUTPUT);
			break;
		case LED_2:
			DioDirectionSet(PORTD_DIR_REG,DIO_PIN3,DIO_OUTPUT);
			break;
		default:
		break;
	}
}

void Led_State(LedEnum_t led,Led_State_t state){
	switch(led){
		case LED_0:
			switch(state){
				case LED_ON:
					DioChannelWrite(PORTC_OUTPUT_REG,DIO_PIN2,DIO_HIGH);
					break;
				case LED_OFF:
					DioChannelWrite(PORTC_OUTPUT_REG,DIO_PIN2,DIO_LOW);
					break;
			}
			break;
		case LED_1:
			switch(state){
				case LED_ON:
					DioChannelWrite(PORTC_OUTPUT_REG,DIO_PIN7,DIO_HIGH);
					break;
				case LED_OFF:
					DioChannelWrite(PORTC_OUTPUT_REG,DIO_PIN7,DIO_LOW);
					break;
			}
			break;
		case LED_2:
			switch(state){
				case LED_ON:
					DioChannelWrite(PORTD_OUTPUT_REG,DIO_PIN3,DIO_HIGH);
					break;
				case LED_OFF:
					DioChannelWrite(PORTD_OUTPUT_REG,DIO_PIN3,DIO_LOW);
					break;
		}
		break;
	}
}
void Led_Toggle(LedEnum_t led){
	switch(led){
		case LED_0:
			DioChannelToggle(PORTC_OUTPUT_REG,DIO_PIN2);
			break;
		case LED_1:
			DioChannelToggle(PORTC_OUTPUT_REG,DIO_PIN7);
			break;
		case LED_2:
			DioChannelToggle(PORTD_OUTPUT_REG,DIO_PIN3);
			break;
		default:
		    break;
	}
	
}
