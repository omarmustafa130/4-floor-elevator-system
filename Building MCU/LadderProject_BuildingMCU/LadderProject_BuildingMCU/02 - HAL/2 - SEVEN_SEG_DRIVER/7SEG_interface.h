/*
 * _7SEG_interface.h
 *
 * Created: 1/6/2023 2:56:40 PM
 *  Author: Omar Mustafa
 */ 


#ifndef SevenSEG_INTERFACE_H_
#define SevenSEG_INTERFACE_H_

#include "../../Library/STD_TYPES.h"
#include "../../01 - MCAL/1 - GPIO_DRIVER/GPIO_interface.h"

#define SevenSEG_PORT GPIO_PORTF

#define ZERO	63
#define ONE		6
#define TWO		91
#define THREE	79
#define FOUR	102

extern u8 SevenSEG_VALUE [5];
void H7SEG_Void_Setup7SEG();
void H7SEG_Void_7SEGState(u8 SevenSEG_VALUE);




#endif /* SevenSEG_INTERFACE_H_ */