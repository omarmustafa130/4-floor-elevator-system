/*
 * _7SEG_program.c
 *
 * Created: 1/6/2023 2:56:57 PM
 *  Author: Omar Mustafa
 */ 

#include "7SEG_interface.h"
u8 SevenSEG_VALUE [5]= {63,6,91,79,102};
void H7SEG_Void_Setup7SEG()
{
	MGPIO_VoidSetPortDirection(SevenSEG_PORT, GPIO_OUTPUT);
}

void H7SEG_Void_7SEGState(u8 SevenSEG_VALUE)

{
	MGPIO_VoidSetPortValue(SevenSEG_PORT, SevenSEG_VALUE);	
}