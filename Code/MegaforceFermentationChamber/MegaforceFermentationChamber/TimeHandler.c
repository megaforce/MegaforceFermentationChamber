/*
 * TimeHandler.c
 *
 * Created: 20. 07. 2020 15:49:52
 *  Author: Megaforce
 */ 
#include "TimeHandler.h"
#include "MMINIT.H"
#include "Globals.h"

void init_TH()
{
	//Timer1 is in charge of keeping track of time remaining for the fermentation process 
	TCCR1A |= (1 << WGM12); // Enables Timer1 to run in CTC mode
	OCR1A = 62500; // Number of ticks required to have timer keep track of time in seconds
	TCCR1A 	|= (0 << COM1A1) | (0 << COM1A0); //Sets normal port operation, OC1A disconnected
	//OC1A is disconnected since TH doesn't require an external output
	TCCR1B |= (1 << CS12); // Sets the pre-scaler to /256
	TIMSK1 |= (1 << OCIE1A); // Enables the output compare A
}

void disable_TH()
{
	TCCR1B = (0 << CS12) | (0 << CS11) | (0 << CS10); //Sets clock source to none effectively disabling timer1
}

void convertToRealTime()
{
	globalTime = days * 86400;
}