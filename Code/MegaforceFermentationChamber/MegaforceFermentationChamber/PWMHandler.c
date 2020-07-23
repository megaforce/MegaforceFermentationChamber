/*
 * PWMHandler.c
 *
 * Created: 23. 07. 2020 15:50:54
 *  Author: Megaforce
 */ 

#include "PWMHandler.h"

void init_PWM()
{
	DDRB |= (1 << DDB1); //Enable B1 - OCR1A is connected to it
	OCR1A = 0xFFFF;	//Set PWM to 100% cuz I can
	TCCR1A |= (1 << COM1A1);	//Clear OC1A/OC1B on Compare Match - non invrting
	TCCR1A |= (1 << WGM11) | (1 << WGM10);	//Set 10bit phase corrected PWM Mode
	TCCR1B |= (1 << CS11);	//Set prescaler to /8
}
void disable_PWM()
{
	OCR1A = 0; //Set PWM to 0%
	TCCR1B |= (0 << CS12) | (0 << CS11) | (0 << CS10); //Disconnect the clock source
}
