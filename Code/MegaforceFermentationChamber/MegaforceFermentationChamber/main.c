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
	startUp();
	mainScreenTime();
	mainScreenTemp();
	fermentationScreen();
	sei();
	
	
	
	
    while (1) 
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	
	if(days != 0)
		LED1_Tgl();
	else
	{
		disable_TH();
		main();
	}
		days --;		
}