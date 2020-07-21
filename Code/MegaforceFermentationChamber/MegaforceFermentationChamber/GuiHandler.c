/*
 * GuiHandler.c
 *
 * Created: 20. 07. 2020 22:48:04
 *  Author: Megaforce
 */ 
#include <util/delay.h>
#include "GuiHandler.h"
#include "MMINIT.h"
#include "ADCHandler.h"


void startUp()
{
	LCD_Init();
	
	UG_FontSelect(&RFONT_16X26);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);

	UG_PutString(30,50,"MEGAFORCE");
	UG_PutString(30,70,"FERMENTATOR");
	UG_PutString(30,90,"CHAMBER");
	
	_delay_ms(50);
	//Body
	UG_DrawLine(30,140,30,220,C_WHITE);
	UG_DrawLine(90,140,90,220,C_WHITE);
	UG_DrawLine(30,220,90,220,C_WHITE);
	//Handle
	UG_DrawLine(90,160,110,160,C_WHITE);
	UG_DrawLine(90,190,110,190,C_WHITE);
	UG_DrawLine(110,160,110,190,C_WHITE);
	//Beer
	for (int i = 0; i < 70; i++)
		{
			UG_DrawLine(31,219-i,89,219-i,C_SANDY_BROWN);
			_delay_ms(500);
		}
	for (int i = 0; i < 10; i++)
		{
			UG_DrawLine(31,150-i,89,150-i,C_LAVENDER);
			_delay_ms(500);
		}
	
	
}
void mainScreenTime()
{	
	LCD_Init();	
		
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	
	UG_PutString(30,50,"OK - Confirm");
	UG_PutString(30,70,"A - Increase");
	UG_PutString(30,90,"B - Decrease");
	UG_PutString(30,110,"ESC - Reset");
	
	UG_DrawLine(30,140,130,140,C_WHITE);
	UG_DrawLine(30,160,130,160,C_WHITE);
	UG_DrawLine(30,140,30,160,C_WHITE);
	UG_DrawLine(130,140,130,160,C_WHITE);

	UG_DrawLine(30,180,130,180,C_WHITE);
	UG_DrawLine(30,200,130,200,C_WHITE);
	UG_DrawLine(30,180,30,200,C_WHITE);
	UG_DrawLine(130,180,130,200,C_WHITE);	
	
	char text[20];
	
	sprintf(text,"Temp: %d",temp);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,185,text);
	
	while(1)
	{			
		sprintf(text,"Days: %d",days);
		UG_SetForecolor(C_WHITE);
		UG_PutString(35,145,text);
		
		KBD_Read();
		switch(KBD_GetKey())
		{
			case 2:
				days = 0;
				temp = 0;
				mainScreenTime();
			break;
			
			case 3: 
				return;
			break;
			
			case 4:
				days++;
			break;
			
			case 5:
				if(days-1 < 0)
					days = 0;
				else
					days--;
			break;
		}
	}
}

void mainScreenTemp()
{	
	LCD_Init();
	
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	
	UG_PutString(30,50,"OK - Confirm");
	UG_PutString(30,70,"A - Increase");
	UG_PutString(30,90,"B - Decrease");
	UG_PutString(30,110,"ESC - Reset");
	
	UG_DrawLine(30,180,130,180,C_WHITE);
	UG_DrawLine(30,200,130,200,C_WHITE);
	UG_DrawLine(30,180,30,200,C_WHITE);
	UG_DrawLine(130,180,130,200,C_WHITE);
	
	UG_DrawLine(30,140,130,140,C_WHITE);
	UG_DrawLine(30,160,130,160,C_WHITE);
	UG_DrawLine(30,140,30,160,C_WHITE);
	UG_DrawLine(130,140,130,160,C_WHITE);
	
	char text[20];	
	
		sprintf(text,"Days: %d",days);
		UG_SetForecolor(C_WHITE);
		UG_PutString(35,145,text);
		
	
	while(1)
	{
		sprintf(text,"Temp: %d",temp);
		UG_SetForecolor(C_WHITE);
		UG_PutString(35,185,text);
		
		KBD_Read();
		switch(KBD_GetKey())
		{
			case 2:
				days = 0;
				temp = 0;
				mainScreenTime();
			break;
			
			case 3:
				return;
			break;
			
			case 4:
			temp++;
			break;
			
			case 5:
			if(temp-1 < 0)
			temp = 0;
			else
			temp--;
			break;
		}
	}
}

void fermentationScreen()
{
	init_TH();
	LCD_Init();
	
	char text[20];
	
	sprintf(text,"Days: %d",days);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,145,text);

	sprintf(text,"Temp: %d",temp);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,185,text);
	
	return;
	
}