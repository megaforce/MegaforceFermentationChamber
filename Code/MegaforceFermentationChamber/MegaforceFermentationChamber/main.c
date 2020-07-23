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

ISR(TIMER3_COMPA_vect)
{
	
	if(days -1 != 0)
		fermentationScreen();
	else
	{
		disable_TH();
		disable_ADC();
		disable_PWM();
		main();
	}
		days --;		
}

ISR(ADC_vect)
{
	ADC_res = ADC;
	if(ADC_res > 512)
	{
		LED1_Off();
		LED2_On();
		OCR1A = 0xFFFF;
	}
	else
	{
		OCR1A = 0;
		LED1_On();
		LED2_Off();
	}
	startConversion();
}