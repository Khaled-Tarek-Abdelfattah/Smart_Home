/*
 * Servo_Motor.h
 *
 * Created: 12/7/2021 8:33:55 PM
 *  Author: hp
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "Pwm.h"
#include "Dio.h"

#define SERVOMOTOR_DIR_PORT				PORTD_DIR_REG
#define SERVOMOTOR_OUTPUT_PORT			PORTD_OUTPUT_REG

void ServoMotor_Init();
void ServoMotor_Work();

#endif /* SERVO_MOTOR_H_ */