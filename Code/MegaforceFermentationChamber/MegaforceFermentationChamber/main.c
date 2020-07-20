/*
 * MegaforceFermentationChamber.c
 *
 * Created: 20. 07. 2020 15:30:23
 * Author : Megaforce
 */ 

#include <avr/io.h>
#include "MMINIT.h"
#include "TimeHandler.h"

short days,temp;

int main(void)
{	
	short days = 0;
	short hours = 0;
    init_IO();
	init_TH();
	LCD_Init();
	startUp();
	sei();
	
    while (1) 
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	LED1_Tgl();
}