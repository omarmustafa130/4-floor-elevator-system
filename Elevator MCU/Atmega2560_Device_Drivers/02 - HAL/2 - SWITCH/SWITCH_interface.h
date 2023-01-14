/*
 * SWITCH_interface.h
 *
 * Created: 1/6/2023 2:56:11 PM
 *  Author: Omar Mustafa
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "../../Library/STD_TYPES.h"
#include "../../01 - MCAL/1 - GPIO_DRIVER/GPIO_interface.h"
#include "../../01 - MCAL/3 - EXTI_DRIVER/EXTI_interface.h"

#define SWITCH_PORT1 GPIO_PORTD
#define SWITCH_PORT2 GPIO_PORTE

enum SWITCH_t {SW_EMERGENCY, SW_GND, SW_L1, SW_L2, SW_L3, SW_L4};

void HSwitch_Void_AttachSwitch(enum SWITCH_t Switch, void (*Local_Callback)(void));


#endif /* SWITCH_INTERFACE_H_ */