/*
 * DCMOTOR_program.c
 *
 * Created: 1/6/2023 2:57:16 PM
 *  Author: Omar Mustafa
 */ 

#include "DCMOTOR_interface.h"

void HDCMOTOR_Void_SetupMotorDriver()
{
	MGPIO_VoidSetPinDirection(DCMOTOR_PORT, IN1_Pin, GPIO_OUTPUT);
	MGPIO_VoidSetPinDirection(DCMOTOR_PORT, IN2_Pin, GPIO_OUTPUT);
	MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN1_Pin, GPIO_LOW);
	MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN2_Pin, GPIO_LOW);
}

void HDCMOTOR_Void_MotorDirection(u8 Copy_u8_Direction)
{
	if (Copy_u8_Direction == CLOCKWISE)
	{
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN1_Pin, GPIO_HIGH);
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN2_Pin, GPIO_LOW);
	}
	else if (Copy_u8_Direction == ANTI_CLOCKWISE)
	{
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN1_Pin, GPIO_LOW);
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN2_Pin, GPIO_HIGH);
	}
	else
	{
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN1_Pin, GPIO_LOW);
		MGPIO_VoidSetPinValue(DCMOTOR_PORT, IN2_Pin, GPIO_LOW);
	}
}