/*
 * PWMHandler.c
 *
 * Created: 23. 07. 2020 15:50:54
 *  Author: Megaforce
 */ 

#include "PWMHandler.h"

void init_PWM()
{
	DDRB |= (1 << DDB1);
	OCR1A = 0xFFFF;	// set PWM for 50% duty cycle at 10bit
	TCCR1A |= (1 << COM1A1);	// set non-inverting mode
	TCCR1A |= (1 << WGM11) | (1 << WGM10);	// set 10bit phase corrected PWM Mode
	TCCR1B |= (1 << CS11);	// set prescaler to 8 and starts PWM
}
void disable_PWM()
{
	OCR1A = 0;
	TCCR1B |= (0 << CS12) | (0 << CS11) | (0 << CS10);
}
