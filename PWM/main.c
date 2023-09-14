/*
 * PWM
 * Author: OmarElsherif
 */

// Include drivers
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "TIMER_Interface.h"
#include <avr/delay.h>

// Main function
void main(void)
{
	// Set PWM OCO0 pin direction a soutput
	DIO_VoidSetPinDirection(1, 3, 1);

	// Initialzie the Timer
	TIMER_VoidInit();

	// Program loop
	while(1)
	{
		// Set various values of PWM duty cycles
		TIMER_VoidPWMDutyCycle(0);
		_delay_ms(1000);
		TIMER_VoidPWMDutyCycle(52);
		_delay_ms(1000);
		TIMER_VoidPWMDutyCycle(127);
		_delay_ms(1000);
	}
}
