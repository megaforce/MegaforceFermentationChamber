/*
 * MegaforceFermentationChamber.c
 *
 * Created: 20. 07. 2020 15:30:23
 * Author : Megaforce
 */ 

#include "MMINIT.h"
#include "TimeHandler.h"
#include "ADCHandler.h"
#include "PWMHandler.h"
#include "Globals.h"

int main(void)
{	
	days = 0;
	temp = 0;
    init_IO();
	sei();
	startUp();
	mainScreenTime();
	mainScreenTemp();
	init_TH();
	LCD_Init();
	init_ADC();
	init_PWM();
	fermentationScreen();
	
    while (1) 
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	
	if(globalTime -1 != 0)
		fermentationScreen();
	else
	{
		disable_TH();
		disable_ADC();
		disable_PWM();
		main();
	}
		globalTime --;		
}

ISR(ADC_vect)
{
	ADC_res = ADC;
	if(ADC_res >= 512)
	{		
		OCR4A=0;
		OCR3A = 1000;		
		
	}
	if (ADC_res < 512)
	{	
		OCR4A=500;	
		OCR3A=0;	
	}
	
	startConversion();
}