/*
 * DCMOTOR_interface.h
 *
 * Created: 1/6/2023 2:57:30 PM
 *  Author: Omar Mustafa
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "../../Library/STD_TYPES.h"
#include "../../01 - MCAL/1 - GPIO_DRIVER/GPIO_interface.h"

#define DCMOTOR_PORT GPIO_PORTF

#define IN1_Pin	0
#define IN2_Pin	1
#define ENA_Pin	2

#define STOP			0
#define ANTI_CLOCKWISE	1
#define CLOCKWISE		2



void HDCMOTOR_Void_SetupMotorDriver();
void HDCMOTOR_Void_MotorDirection(u8 Copy_u8_Direction);






#endif /* DCMOTOR_INTERFACE_H_ */