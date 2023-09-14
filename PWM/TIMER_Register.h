/*
*    TIMER_Register.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Header file contains registers addresses for TIMER driver 
*/

#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H

#include "STD_TYPES.h"

// Macros to define registers addreses
#define TCCR0     *((volatile u8 *) 0x53)
#define TCNT0     *((volatile u8 *) 0x52)
#define OCR0      *((volatile u8 *) 0x5C)
#define TIMSK     *((volatile u8 *) 0x59)
#define TIFR      *((volatile u8 *) 0x58)
#define SREG      *((volatile u8 *) 0x5F)

#endif
