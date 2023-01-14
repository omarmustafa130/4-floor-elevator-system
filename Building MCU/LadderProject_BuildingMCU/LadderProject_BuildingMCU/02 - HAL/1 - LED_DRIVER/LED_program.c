/*
 * LED_program.c
 *
 * Created: 1/6/2023 2:55:32 PM
 *  Author: Omar Mustafa
 */ 

#include "LED_interface.h"


void HLED_Void_AttachLED(enum LEDS_t LED)
{
	MGPIO_VoidSetPinDirection(LEDS_PORT, LED, GPIO_OUTPUT);
	MGPIO_VoidSetPinValue(LEDS_PORT, LED, GPIO_LOW);	
};
void HLED_Void_LEDState(enum LEDS_t LED, u8 LED_State)
{
	MGPIO_VoidSetPinValue(LEDS_PORT, LED, LED_State);
};