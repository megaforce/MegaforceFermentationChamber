/*
 * ADCHandler.c
 *
 * Created: 21. 07. 2020 10:42:43
 *  Author: Megaforce
 */ 
#include <avr/io.h>
#include "ADCHandler.h"
#include "Globals.h"

void init_ADC()
{
	ADMUX |= 0x40; //Sets voltage reference to AVCC and A0 as input
	ADCSRA = (1 << ADEN); //Enables ADC
	ADCSRA |= 0x07; // Sets pre-scaler to /128 
	ADMUX = (0 << ADLAR); //Right adjustment to match the data register (LSB match)
	DIDR0 |= 0XFE; //Disables all inputs except ADC0D
	ADCSRA = (0 << ADATE); //Disables auto-trigger
	ADCSRA = (1 << ADIE); //Enables interrupts 
}

void startConversion()
{
	ADCSRA = (1 << ADSC); //Sets the ADC Start Conversion bit
}

void disable_ADC()
{
	
}