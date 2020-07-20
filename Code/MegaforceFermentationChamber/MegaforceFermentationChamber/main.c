/*
 * MegaforceFermentationChamber.c
 *
 * Created: 20. 07. 2020 15:30:23
 * Author : Megaforce
 */ 

#include <avr/io.h>
#include "MMINIT.h"
#include "TimeHandler.h"
static int x = 5;
int main(void)
{
    init_IO();
	init_TH();
	sei();
    while (1) 
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	LED1_Tgl();
	x--;
	if(x == 0){
		disable_TH();
		LED3_On();
	}
}