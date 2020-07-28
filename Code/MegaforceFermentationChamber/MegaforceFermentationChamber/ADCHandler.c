/*
 * ADCHandler.c
 *
 * Created: 21. 07. 2020 10:42:43
 *  Author: Megaforce
 */ 
#include "ADCHandler.h"
#include "Globals.h"

void init_ADC()
{
	ADMUX |= (1 << REFS0) | (0 << MUX0) | (0 << MUX1) | (0 << MUX2) | (0 << MUX3); //Select AVCC as reference and set ADC0 channel
	ADCSRA |= (1 << ADEN) ; //Enable ADC
	ADCSRA |= (1 << ADIE) ; //Enable ADC interrupt 
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); //Set prescaler to /128
	DIDR0 |= (1 << ADC0D) ; //Enable ADC0
	startConversion();
}

void startConversion()
{
	ADCSRA |= (1 << ADSC); //Sets the ADC Start Conversion bit
}

void disable_ADC()
{
	ADCSRA &= 0x7F; //Set ADEN to 0
	DIDR0 &= 0xFE; // Disable ADC0 with mask so other ADC's stay intact
}