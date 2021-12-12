#include "BUZZER.h"

void Buzzer_init(){
	DioDirectionSet(BUZZER_DIR_PORT,Buzzer_Pin,DIO_OUTPUT);
}
void Buzzer_SetState(Dio_PinStateEnum_t state){
	switch(state){
		case DIO_LOW:
			DioChannelWrite(BUZZER_OUTPUT_PORT,Buzzer_Pin,DIO_LOW);
			break;
		case DIO_HIGH:
			DioChannelWrite(BUZZER_OUTPUT_PORT,Buzzer_Pin,DIO_HIGH);
			break;
	}
}
