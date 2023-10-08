/*
*    TIMER_Program.c
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Code file contains the code for TIMER driver 
*/

// Include header files
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "TIMER_Register.h"
#include "TIMER_Config.h"

// Global variables
u8 flag = 0;
u16 OV_Counter = 0;
u16 Ton = 0;
u16 Ttotal = 0;

// Function to initialize Timer0
void TIMER0_VoidInit(void)
{
    // Select fast pwm mode
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    // Select non inverted mode
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);

    // Set prescaler value to 256
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

    // Set preload value
    TCNT0 = 256;

    // Enable OV interrupt
    SET_BIT(TIMSK, TOIE0);

    // Enable GIE
    SET_BIT(SREG, PIN7);
}

// Function to initialize Timer1
void TIMER1_VoidInit(void)
{
    // Enable input capture noice canceler
    CLR_BIT(TCCR1B, PIN7);

    // Set raising edge
	SET_BIT(TCCR1B, PIN1);

    // Select overflow mode
    CLR_BIT(TCCR1A, WGM10);
    CLR_BIT(TCCR1A, WGM11);
    CLR_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1B, WGM13);

    // Set prescaler to 256
    CLR_BIT(TCCR1B, CS10);
    CLR_BIT(TCCR1B, CS11);
    SET_BIT(TCCR1B, CS12);

    // Enable OV interrupt
    SET_BIT(TIMSK, TOIE1);

    // Enable ICU interrupt
    SET_BIT(TIMSK, TICIE1);

    // Enable GIE
    SET_BIT(SREG, PIN7);
}

// Function to set pwm duty cucle
void TIMER0_VoidPWMDutyCycle(u8 Duty)
{
	OCR0 = Duty;
}

// ICU ISR
void __vector_6(void)
{
    if(flag == 0)
    {
        TCNT1 = 0;
        OV_Counter = 0;
        // Set fallinng edge
	    CLR_BIT(TCCR1B, PIN6);
        flag = 1;
    }
    // Calcaulate T ON
    else if(flag == 1)
    {
        Ton = ICR1 + (OV_Counter * 65535);
        // Set raising edge
	    SET_BIT(TCCR1B, 1);
        flag = 2;
    }
    // Calcaulate T total
    else if(flag == 2)
    {
        Ttotal = ICR1 + (OV_Counter * 65535);
        flag = 3;
    }
}

// Timer1 OV ISR
void __vector_9(void)
{
    // Increase overflow counter
    OV_Counter++;
}

// Timer0 ISR
void __vector_11(void)
{
    static u16 counter = 0;
    counter++;
    if(counter == 123)
    {
		TCNT0 = 238;
		DIO_VoidTogglePin(PORT_A, PIN0);
		counter = 0;
    }
}
