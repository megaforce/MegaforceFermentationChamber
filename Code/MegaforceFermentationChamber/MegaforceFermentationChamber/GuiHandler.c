/*
 * GuiHandler.c
 *
 * Created: 20. 07. 2020 22:48:04
 *  Author: Megaforce
 */ 
#include <util/delay.h>
#include "GuiHandler.h"



void startUp()
{
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
	
	UG_FontSelect(&RFONT_16X26);
	UG_SetForecolor(C_GREEN);
	UG_SetBackcolor(C_BLACK);

	UG_PutString(130,140,"READY");
	UG_PutString(130,160,"FOR");
	UG_PutString(130,180,"BEER!!");
	_delay_ms(5000);
	mainScreenTime();
}
void mainScreenTime()
{	
	LCD_Init();	
}

void mainScreenTemp()
{	
	LCD_Init();	
}
void updateMain()
{

}
void fermentationScreen(){}