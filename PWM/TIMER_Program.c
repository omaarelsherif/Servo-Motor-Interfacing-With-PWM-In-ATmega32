/*
*    TIMER_Program.c
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 13-9-2023
*    Desc: Code file contains the code for TIMER driver 
*/

// Include header files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Register.h"
#include "TIMER_Config.h"
#include "DIO_Interface.h"

// Function to initialize the ADC
void TIMER_VoidInit(void)
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
    SET_BIT(SREG, 7);
}

// Function to set pwm duty cucle
void TIMER_VoidPWMDutyCycle(u8 Duty)
{
	OCR0 = Duty;
}

// ISR
void __vector_11(void)
{
    static u16 counter = 0;
    counter++;
    if(counter == 123)
    {
		TCNT0 = 238;
		DIO_VoidTogglePin(0, 0);
		counter = 0;
    }
}
