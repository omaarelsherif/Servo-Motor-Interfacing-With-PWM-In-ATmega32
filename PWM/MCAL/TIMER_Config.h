/*
*    TIMER_Config.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Header file contains configurations for TIMER driver 
*/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

// Include DIO configurations
#include "DIO_Config.h"

// Macros to define TCCR0 register pins
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define WGM00   6
#define COM00	4
#define COM01	5

// Macros to define TIMSK register pins
#define TOIE0    0

// Macros to define TCCR1A register pins
#define WGM10    0
#define WGM11    1

// Macros to define TCCR1B register pins
#define CS10     0
#define CS11     1
#define CS12     2
#define WGM12    3
#define WGM13    4

// Macros to define TIMSK register pins
#define TOIE1      2
#define TICIE1     5

#endif
