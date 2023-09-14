/*
*    TIMER_Interface.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Header file contains functions prototypes for TIMER driver 
*/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "STD_TYPES.h"

// Function prototypes
void TIMER0_VoidInit(void);
void TIMER1_VoidInit(void);
void TIMER0_VoidPWMDutyCycle(u8 Duty);
void __vector_6(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

#endif
