/*
 * MMINIT.c
 *
 * Created: 07/03/2020 20:47:09
 * Author : Megaforce
 */ 

#include "MMINIT.h"

int tmp = 0;

void init_IO()
{
	PORTD |= 0x3C;
	DDRD &= 0xC3;
	
	PORTE=0;
	DDRE=0x0F;	
}

void LED1_On()
{
	PORTE |= (1<<LED_1);
}

void LED2_On()
{
	PORTE |= (1<<LED_2);
}

void LED3_On()
{
	PORTE |= (1<<LED_3);
}

void LED4_On()
{
	PORTE |= (1<<LED_4);
}

void LED1_Off()
{
	PORTE &= (0<<LED_1);
}

void LED2_Off()
{
	PORTE &= (0<<LED_2);
}

void LED3_Off()
{
	PORTE &= (0<<LED_3);
}

void LED4_Off()
{
	PORTE &= (0<<LED_4);
}

void LED1_Tgl()
{
	PORTE ^= (1<<LED_1);
}
void LED2_Tgl()
{
	PORTE ^= (1<<LED_2);
}

void LED3_Tgl()
{
	PORTE ^= (1<<LED_3);
}

void LED4_Tgl()
{
	PORTE ^= (1<<LED_4);
}

void LED_SetLEDs(char LED_mask)
{
	PORTE |= LED_mask;
}

void LED_ClrLEDs(char LED_mask)
{
	PORTE &= LED_mask;
}

char is_LED1_On()
{	
	return (PINE & (1<<LED_1));	
}

char is_LED2_On()
{
	return (PINE & (1<<LED_2));	
}

char is_LED3_On()
{
	return (PINE & (1<<LED_3));	
}

char is_LED4_On()
{
	return (PINE & (1<<LED_4));	
}

char is_BTN_OK_Pressed()
{	
	return !(PIND & (1<<BTN_OK));
}
char is_BTN_ESC_Pressed()
{	
	return !(PIND & (1<<BTN_ESC));
}

char is_BTN_Pressed(char BTN_pin_number)
{
	return !(PIND & (1<<BTN_pin_number));	
}

char is_BTN_Released(char BTN_pin_number)
{
	return (PIND & (1<<BTN_pin_number));
}

char KBD_Read()
{    int nova;
static int stara;
    nova =(PIND>>2) & 0x0F; // Vzame portD in ga primerja z masko
    if (((nova ^ stara) & stara) & 0x01)
     tmp=BTN_ESC;			
	if (((nova ^ stara) & stara) & 0x02)
     tmp=BTN_OK;			
	if (((nova ^ stara) & stara) & 0x04) 
    tmp=BTN_A;			
	if (((nova ^ stara) & stara) & 0x08) 
    tmp=BTN_B;
  stara = nova;
}
char KBD_GetKey()
{   int vr;
    vr = tmp;
    tmp = 0;
    return vr;
}
