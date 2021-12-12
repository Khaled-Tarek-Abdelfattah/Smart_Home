/*
 * DC_Motor.c
 *
 * Created: 10/15/2021 1:30:21 AM
 *  Author: Abdelaziz Moustafa
 */ 

#include "DC_Motor.h"
#include "Pwm.h"

void DcMotor_Init(void)
{

	/*soliman code*/
	DioDirectionSet(DCMOTOR_IN1_DIR_REG , DCMOTOR_IN1_PIN, DIO_OUTPUT);	
	DioDirectionSet(DCMOTOR_IN2_DIR_REG , DCMOTOR_IN2_PIN, DIO_OUTPUT);	
	DioDirectionSet(DCMOTOR_ENABLE_DIR_REG , DCMOTOR_ENABLE_PIN, DIO_OUTPUT);	
	/**/
}

void DcMotor_On()
{
	DioChannelWrite(DCMOTOR_ENABLE_OUT_REG, DCMOTOR_ENABLE_PIN, DIO_HIGH);
	DioChannelWrite(DCMOTOR_IN1_OUT_REG, DCMOTOR_IN1_PIN , DIO_LOW);
	DioChannelWrite(DCMOTOR_IN2_OUT_REG, DCMOTOR_IN2_PIN , DIO_HIGH);
}
void DcMotor_Off()
{
	/*
	Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN1_PIN, DIO_LOW);
	Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN2_PIN, DIO_LOW);
	Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN2_PIN, DIO_LOW);
	Pwm_SetDutyCycle(PWM_CHANNEL_1, 0U);
	*/
	DioChannelWrite(DCMOTOR_ENABLE_OUT_REG, DCMOTOR_ENABLE_PIN, DIO_LOW);
	DioChannelWrite(DCMOTOR_IN1_OUT_REG, DCMOTOR_IN1_PIN , DIO_LOW);
	DioChannelWrite(DCMOTOR_IN2_OUT_REG, DCMOTOR_IN2_PIN , DIO_LOW);
}