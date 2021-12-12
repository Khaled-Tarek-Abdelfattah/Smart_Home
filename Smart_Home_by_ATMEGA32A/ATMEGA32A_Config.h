
#ifndef ATMEGA32A_CONFIG_H_
#define ATMEGA32A_CONFIG_H_
#include "std_Types.h"
#define  F_CPU								(16000000U)

#define NULL_PTR							((void*)0)

#define PORTA_DIR_REG						((volatile uint8*)0x3AU)
#define PORTA_INPUT_REG						((volatile uint8*)0x39U)
#define PORTA_OUTPUT_REG					((volatile uint8*)0x3BU)

#define PORTB_DIR_REG						((volatile uint8*)0x37U)
#define PORTB_INPUT_REG						((volatile uint8*)0x36U)
#define PORTB_OUTPUT_REG					((volatile uint8*)0x38U)

#define PORTC_DIR_REG						((volatile uint8*)0x34U)
#define PORTC_INPUT_REG						((volatile uint8*)0x33U)
#define PORTC_OUTPUT_REG					((volatile uint8*)0x35U)

#define PORTD_DIR_REG						((volatile uint8*)0x31U)
#define PORTD_INPUT_REG						((volatile uint8*)0x30U)
#define PORTD_OUTPUT_REG					((volatile uint8*)0x32U)

/* External Interrupts Registers */
#define MCU_CTRL_REG						((volatile uint8*)0x55U)  /* MCUCR */
#define MCU_CTRL_STATUS_REG					((volatile uint8*)0x54U)  /* MCUCSR */
#define GENRAL_INT_CTRL_REG					((volatile uint8*)0x5BU)  /* GICR */
#define AVR_STATUS_REG						((volatile uint8*)0x5FU)  /* SREG */

#define INT0_ISC00							(0U)
#define INT0_ISC01						    (1U)
#define INT1_ISC10						    (2U)
#define INT1_ISC11							(3U)
#define INT2_ISC2						    (6U)

#define INT0_ENABLE_BIT						(6U)
#define INT1_ENABLE_BIT					    (7U)
#define INT2_ENABLE_BIT						(5U)
#define GLOBALE_INTERRUPTS_ENABLE_BIT		(7U)

/* Timer0 Registers */
#define TIMER0_CTRL_REG						((volatile uint8*)0x53U)
#define TIMER0_COUNTER_REG					((volatile uint8*)0x52U)
#define TIMER0_CMP_REG						((volatile uint8*)0x5CU)

/* Timer1 Registers*/
#define TIMER1_CTRL_A_REG					((volatile uint8*)0x4FU)
#define TIMER1_CTRL_B_REG					((volatile uint8*)0x4EU)
#define TIMER1_COUNT_LOW_REG				((volatile uint8*)0x4CU)
#define TIMER1_COUNT_HIGH_REG				((volatile uint8*)0x4DU)
#define TIMER1_CMP_A_LOW_REG				((volatile uint8*)0x4AU)
#define TIMER1_CMP_A_HIGH_REG				((volatile uint8*)0x4BU)
#define TIMER1_CMP_B_LOW_REG				((volatile uint8*)0x48U)
#define TIMER1_CMP_B_HIGH_REG				((volatile uint8*)0x49U)
#define TIMER1_INP_CAP_LOW_REG				((volatile uint8*)0x46U)
#define TIMER1_INP_CAP_HIGH_REG				((volatile uint8*)0x47U)

/* Timer1 Registers*/
#define TIMER2_CTRL_REG						((volatile uint8*)0x45U)
#define TIMER2_COUNTER_REG					((volatile uint8*)0x44U)
#define TIMER2_CMP_REG						((volatile uint8*)0x43U)
#define SPECIAL_FUNCTION_REG				((volatile uint8*)0x50U)

/* Special timers Registers */
#define TIMER_INTERRUPT_MASK_REG			((volatile uint8*)0x59U)
#define TIMER_INTERRUPT_FLAG_REG			((volatile uint8*)0x58U)

/* UART Registers */
#define UART_DATA_REG						((volatile uint8 *)0x2CU)  /* UDR */
#define UART_CTRL_STATUS_A_REG				((volatile uint8 *)0x2BU)  /* UCSRA */
#define UART_CTRL_STATUS_B_REG				((volatile uint8 *)0x2AU)  /* UCSRB */
#define UART_CTRL_STATUS_C_REG				((volatile uint8 *)0x40U)  /* UCSRC */
#define UART_BAUDRATE_LOW_REG				((volatile uint8 *)0x29U)  /* UBBRL */
#define UART_BAUDRATE_HIGH_REG				((volatile uint8 *)0x40U)  /* UBBRH */


#endif /* ATMEGA32A_CONFIG_H_ */