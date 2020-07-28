/*
 * PWMHandler.c
 *
 * Created: 23. 07. 2020 15:50:54
 *  Author: Megaforce
 */ 

#include "PWMHandler.h"

void init_PWM_IO()
{
	//PD1 - OC4A and PD2 - OC4B
	
	PORTD &= 0xFC;
	DDRD |= (1 << PORTD0); //Output D1 - OCR3A is connected to it
	DDRD |= (1 << PORTD1); //Output D2 - OCR4A is connected to it
}


void init_PWM_CH1()
{
	
	TCCR4A |= (1 << COM4A1) | (0 << COM4B1) | (0 << COM4A0) | (0 << COM4B0); // Clear OC4A on compare match when up-counting.
	TCCR4A |= (1 << WGM41) | (1 << WGM40); //PWM, PhaseCorrect, 10-bit
	TCCR4B |= (0 << WGM43) | (0 << WGM42);
	TCCR4B = (0 << ICNC4) | (0 << ICES4); // disable input Capture Noise Canceler and use falling edge as trigger
	TCCR4B |= (1 << CS41); //Prescaler /8
}
void init_PWM_CH2()
{
	TCCR3A |= (1 << COM3A1) | (0 << COM3B1) | (0 << COM3A0) | (0 << COM3B0); // Clear OC3A on compare match when up-counting.
	TCCR3A |= (1 << WGM31) | (1 << WGM30); //PWM, PhaseCorrect, 10-bit
	TCCR3B |= (0 << WGM33) | (0 << WGM32);
	TCCR3B = (0 << ICNC3) | (0 << ICES3); // disable input Capture Noise Canceler and use falling edge as trigger
	TCCR3B |= (1 << CS31); //Prescaler /8
}

void disable_PWM()
{
	TCCR4B |= (0 << CS42) | (0 << CS41) | (0 << CS40); //Disconnect the clock source
	TCCR3B |= (0 << CS32) | (0 << CS31) | (0 << CS30); //Disconnect the clock source
}

void init_PWM()
{
	init_PWM_IO();
	init_PWM_CH1();
	init_PWM_CH2();
}