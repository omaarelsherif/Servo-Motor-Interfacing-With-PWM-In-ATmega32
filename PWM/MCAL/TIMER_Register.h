/*
*    TIMER_Register.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Header file contains registers addresses for TIMER driver 
*/

#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H

#include "../LIB/STD_TYPES.h"

// Macros to define registers addreses for timer0
#define TCCR0     *((volatile u8 *) 0x53)
#define TCNT0     *((volatile u8 *) 0x52)
#define OCR0      *((volatile u8 *) 0x5C)
#define TIMSK     *((volatile u8 *) 0x59)
#define TIFR      *((volatile u8 *) 0x58)
#define SREG      *((volatile u8 *) 0x5F)

// Macros to define registers addreses for timer1
#define TCCR1A     *((volatile u8 *) 0x4F)
#define TCCR1B     *((volatile u8 *) 0x4E)
#define TCNT1      *((volatile u16 *) 0x4C)
#define ICR1       *((volatile u16 *) 0x46)

#endif
