/*
 * Servo_motor.h
 *
 * Created: 12/9/2021 2:22:45 PM
 *  Author: hp
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_
#include "Pwm.h"
#include "Dio.h"
#include "util/delay.h"

void ServoMotor_Init();
void ServoMotor_Rotate90();
void ServoMotor_Rotate0();
void ServoMotor_Rotateneg90();



#endif /* SERVO_MOTOR_H_ */