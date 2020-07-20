/*
 * MMINIT.h
 *
 * Created: 07/03/2020 20:47:09
 * Author : Megaforce
 */ 

#ifndef MMINIT_H_
#define MMINIT_H_

#include <avr/io.h>	
#include <avr/interrupt.h>

#define F_CPU 16000000UL //nastavi takrt oscilatorja na 16mhz
#define BAUD1 9600UL	
#define BAUD0 9600UL

#define LED_1 0
#define LED_2 1
#define LED_3 2
#define LED_4 3

#define BTN_OK	3
#define BTN_ESC	2
#define BTN_A	4
#define BTN_B	5

void init_IO();
void LED1_On();
void LED2_On();
void LED3_On();
void LED4_On();

void LED1_Off();
void LED2_Off();
void LED3_Off();
void LED4_Off();

void LED1_Tgl();
void LED2_Tgl();
void LED3_Tgl();
void LED4_Tgl();

void LED_SetLEDs(char LED_mask);
void LED_ClrLEDs(char LED_mask);

char is_LED1_On();
char is_LED2_On();
char is_LED3_On();
char is_LED4_On();

char is_BTN_OK_Pressed();
char is_BTN_ESC_Pressed();
char is_BTN_Pressed(char BTN_pin_number);
char is_BTN_Released(char BTN_pin_number);

char KBD_Read();
char KBD_GetKey();

#endif /* MMINIT_H_ */
