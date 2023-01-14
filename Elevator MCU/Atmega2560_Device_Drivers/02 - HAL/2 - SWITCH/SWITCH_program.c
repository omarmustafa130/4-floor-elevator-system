/*
 * SWITCH_program.c
 *
 * Created: 1/6/2023 2:55:50 PM
 *  Author: Omar Mustafa
 */ 
#include "../../01 - MCAL/3 - EXTI_DRIVER/EXTI_interface.h"
#include "SWITCH_interface.h"

void HSwitch_Void_AttachSwitch(enum SWITCH_t Switch, void (*Local_Callback)(void))
{
	if (Switch<4)
		MGPIO_VoidSetPinDirection(SWITCH_PORT1, Switch, GPIO_INPUT_PULLUP);
	else
		MGPIO_VoidSetPinDirection(SWITCH_PORT2, Switch, GPIO_INPUT_PULLUP);
	MEXTI_voidEnable(Switch,rising_edge);
	MEXTI_voidSetCallback(Switch, Local_Callback);

	
}
