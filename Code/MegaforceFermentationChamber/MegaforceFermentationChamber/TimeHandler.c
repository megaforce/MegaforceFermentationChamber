/*
 * TimeHandler.c
 *
 * Created: 20. 07. 2020 15:49:52
 *  Author: Megaforce
 */ 
#include "TimeHandler.h"
#include "MMINIT.H"
#include <AVR/io.h>

void init_TH()
{
	//Timer3 is in charge of keeping track of time remaining for the fermentation process 
	TCCR3A = (1 << WGM32); // Enables Timer3 to run in CTC mode
	OCR3A = 62500; // Number of ticks required to have timer keep track of time in seconds
	TCCR3A 	= (0 << COM3A1) | (0 << COM3A0); //Sets normal port operation, OC3A disconnected
	//OC3A is disconnected since TH doesn't require an external output
	TCCR3B = (1 << CS32); // Sets the pre-scaler to /256
	TIMSK3 = (1 << OCIE3A); // Enables the output compare A
}

void disable_TH()
{
	TCCR3B = (0 << CS32) | (0 << CS31) | (0 << CS30); //Sets clock source to none effectively disabling timer1
}
