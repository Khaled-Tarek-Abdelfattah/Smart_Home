/*
 * DC_Motor.h
 *
 * Created: 10/15/2021 1:30:05 AM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Dio.h"
#include "ATMEGA32A_Config.h"


/*SolimanCode*/
#define DCMOTOR_ENABLE_DIR_REG    (PORTA_DIR_REG)
#define DCMOTOR_ENABLE_OUT_REG    (PORTA_OUTPUT_REG)
#define DCMOTOR_ENABLE_PIN        (DIO_PIN5)

#define DCMOTOR_IN1_DIR_REG       (PORTA_DIR_REG)
#define DCMOTOR_IN1_OUT_REG       (PORTA_OUTPUT_REG)
#define DCMOTOR_IN1_PIN           (DIO_PIN6)

#define DCMOTOR_IN2_DIR_REG       (PORTA_DIR_REG)
#define DCMOTOR_IN2_OUT_REG       (PORTA_OUTPUT_REG)
#define DCMOTOR_IN2_PIN           (DIO_PIN7)
/**/

typedef enum
{
	DC_MOTOR_TURN_CW,
	DC_MOTOR_TURN_CCW
}DcMotor_RotationDirType;

typedef enum
{
	DC_MOTOR_SPEED_LOW,
	DC_MOTOR_SPEED_MID,
	DC_MOTOR_SPEED_HIGH
}DcMotor_SpeedType;

void DcMotor_Init(void);
void DcMotor_On(void);
void DcMotor_Off(void);
#endif /* DC_MOTOR_H_ */