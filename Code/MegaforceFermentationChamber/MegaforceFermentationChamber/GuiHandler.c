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

void GuiTemplate()
{
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
	
	/* ALES*/
	//Body
	UG_DrawLine(150,150,150,200,C_WHITE);
	UG_DrawLine(180,150,180,200,C_WHITE);
	UG_DrawLine(150,200,180,200,C_WHITE);
	//Handle
	UG_DrawLine(180,160,190,160,C_WHITE);
	UG_DrawLine(190,160,190,180,C_WHITE);
	UG_DrawLine(180,180,190,180,C_WHITE);
	
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	UG_PutString(200,155,"ALES");
	UG_SetForecolor(C_WHITE);
	UG_PutString(200,170,"TEMP: 18-22");
	UG_PutString(200,185,"TIME: 12 - 28");
	
	
	/* Lagers*/
	//Body
	UG_DrawLine(150,90,150,140,C_WHITE);
	UG_DrawLine(180,90,180,140,C_WHITE);
	UG_DrawLine(150,140,180,140,C_WHITE);
	//Handle
	UG_DrawLine(180,100,190,100,C_WHITE);
	UG_DrawLine(190,100,190,120,C_WHITE);
	UG_DrawLine(180,120,190,120,C_WHITE);
	
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	UG_PutString(200,95,"LAGERS");
	UG_SetForecolor(C_WHITE);
	UG_PutString(200,110,"TEMP: 8-12");
	UG_PutString(200,125,"TIME: 21 - 28");
	
	
	/* Stouts*/
	//Body
	UG_DrawLine(150,30,150,80,C_WHITE);
	UG_DrawLine(180,30,180,80,C_WHITE);
	UG_DrawLine(150,80,180,80,C_WHITE);
	//Handle
	UG_DrawLine(180,40,190,40,C_WHITE);
	UG_DrawLine(190,40,190,60,C_WHITE);
	UG_DrawLine(180,60,190,60,C_WHITE);
	
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	UG_PutString(200,35,"STOUTS/PORTERS");
	UG_SetForecolor(C_WHITE);
	UG_PutString(200,50,"TEMP: 18-22");
	UG_PutString(200,65,"TIME: 14 - 21");
	
	//Beer
	for (int i = 0; i < 170; i++)
	{	
		if(199 - i > 160)
			UG_DrawLine(179,199-i,151,199-i,C_SANDY_BROWN);
		if(199 - i < 140 && 199 - i > 100)
			UG_DrawLine(179,199-i,151,199-i,C_GOLDEN_ROD);
		if (199 -i < 161 && 199 - i > 150 || 199 -i < 101 && 199 - i > 90 || 199 -i < 41 && 199 - i > 30)
			UG_DrawLine(179,199-i,151,199-i,C_WHITE);	
		
	}
	
	
}
void startUp()
{
	LCD_Init();
	
	UG_FontSelect(&RFONT_16X26);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);

	UG_PutString(30,50,"MEGAFORCE");
	UG_PutString(30,70,"FERMENTATOR");
	UG_PutString(30,90,"CHAMBER");
	UG_FontSelect(&RFONT_8X12);
	UG_PutString(135,130,"MADE FOR OME");
	UG_PutString(135,145,"-FE 2nd. year");
	UG_PutString(135,160,"DESIGNED FOR USE");
	UG_PutString(135,175," WITH MISKO 2");
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
			_delay_ms(700);
		}
	for (int i = 0; i < 10; i++)
		{
			UG_DrawLine(31,150-i,89,150-i,C_LAVENDER);
			_delay_ms(700);
		}
		
	
	
}
void mainScreenTime()
{	
	LCD_Init();	
	
	GuiTemplate();
	
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
	
	GuiTemplate();
	
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
				convertToRealTime();
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
	char text[20];
	
	long tmp = globalTime;		
	
	sprintf(text,"Days: %d",(tmp/(86400))); //Days
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,70,text);	
	
	tmp = tmp % (86400); //Hours
	memset(text, 0, sizeof text);
	
	sprintf(text,"Hours: %d",(tmp/ 3600));
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,100,text);	
	
	tmp = tmp % 3600; //Mins	
		
	memset(text, 0, sizeof text);
	
	sprintf(text,"Mins: %d",(tmp/ 60));
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,130,text);
	
	tmp = tmp % 60; //Sec
	memset(text, 0, sizeof text);
	
	sprintf(text,"Sec: %d",tmp);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,160,text);
	memset(text, 0, sizeof text);
	

	sprintf(text,"TARGET TEMPERATURE: %d",temp);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,10,text);
	memset(text, 0, sizeof text);
	
	sprintf(text,"FERMENTATION TEMPERATURE: %d",ADC_temp);
	UG_SetForecolor(C_WHITE);
	UG_PutString(35,40,text);
	memset(text, 0, sizeof text);
		
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);
	
	UG_PutString(170,70,"Don't worry ");
	UG_PutString(170,85,"about your beer!");
	UG_PutString(170,100,"MISKO is taking ");
	UG_PutString(170,115,"care of it!");
	UG_PutString(170,130,"Crack open");
	UG_PutString(170,145,"a cold one");
	UG_PutString(170,160,"while waiting!");
	
	UG_FontSelect(&RFONT_8X12);
	UG_SetForecolor(C_RED);
	UG_SetBackcolor(C_BLACK);	
	UG_PutString(35,200,"DO NOT OPEN THE CHAMBER IF NOT NECESSARY!");
	
	return;
	
}