/*
 * PWM
 * Author: OmarElsherif
 */

// Include drivers
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Config.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/TIMER_Interface.h"
#include <avr/delay.h>

// Main function
void main(void)
{
	// Set PWM OCO0 pin direction as output
	DIO_VoidSetPinDirection(PORT_B, PIN3, OUTPUT);

	// Initialzie the Timer
	TIMER0_VoidInit();

	// Program loop
	while(1)
	{
		// Set various values of PWM duty cycles
		TIMER0_VoidPWMDutyCycle(0);
		_delay_ms(1000);
		TIMER0_VoidPWMDutyCycle(52);
		_delay_ms(1000);
		TIMER0_VoidPWMDutyCycle(127);
		_delay_ms(1000);
	}
}
