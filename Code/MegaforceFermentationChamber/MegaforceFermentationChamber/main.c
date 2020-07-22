/*
 * MegaforceFermentationChamber.c
 *
 * Created: 20. 07. 2020 15:30:23
 * Author : Megaforce
 */ 

#include <avr/io.h>
#include "MMINIT.h"
#include "TimeHandler.h"
#include "Globals.h"

int main(void)
{	
	days = 0;
	temp = 0;
    init_IO();
	init_ADC();
	startUp();
	mainScreenTime();
	mainScreenTemp();
	fermentationScreen();
	sei();
	
	
	
	
    while (1) 
    {
		
    }
}

ISR(TIMER3_COMPA_vect)
{
	
	if(days -1 != 0)
		LED1_Tgl();
	else
	{
		disable_TH();
		main();
	}
		days --;		
}

ISR(ADC_vect)
{
	ADC_res = ADC;
}
