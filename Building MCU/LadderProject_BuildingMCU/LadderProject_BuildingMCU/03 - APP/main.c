/*
 * Atmega2560_Device_Drivers.c
 *
 * Created: 1/5/2023 11:00:35 PM
 *  Author: Omar Mustafa
 */ 

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../01 - MCAL/1 - GPIO_DRIVER/GPIO_private.h"
#include "../01 - MCAL/1 - GPIO_DRIVER/GPIO_interface.h"
#include "../01 - MCAL/3 - EXTI_DRIVER/EXTI_interface.h"
#include "../01 - MCAL/4 - UART_DRIVER/UART_interface.h"
#include "../02 - HAL/1 - LED_DRIVER/LED_interface.h"
#include "../02 - HAL/3 - SWITCH_DRIVER/SWITCH_interface.h"
#include "../02 - HAL/2 - SEVEN_SEG_DRIVER/7SEG_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void SW_EMERGENCY_Function(void);
void SW_GND_Function(void);
void SW_L1_Function(void);
void SW_L2_Function(void);
void SW_L3_Function(void);
void SW_L4_Function(void);
void UART0_FUNCTION(void);
static u8 current_level=0;



int main(void)
{
    /* Replace with your application code */
	HLED_Void_AttachLED(ELV_UPLED);
	HLED_Void_AttachLED(ELV_DWNLED);
	H7SEG_Void_Setup7SEG();
	//H7SEG_Void_7SEGState(127);
	HSwitch_Void_AttachSwitch(SW_EMERGENCY, SW_EMERGENCY_Function);

	HSwitch_Void_AttachSwitch(SW_GND, SW_GND_Function);
	HSwitch_Void_AttachSwitch(SW_L1, SW_L1_Function);
	HSwitch_Void_AttachSwitch(SW_L2, SW_L2_Function);
	HSwitch_Void_AttachSwitch(SW_L3, SW_L3_Function);
	HSwitch_Void_AttachSwitch(SW_L4, SW_L4_Function);
	MUART_voidSetCallback(UART0, UART0_FUNCTION);
	UART_Init(UART0);
	UART_Init(UART2);

    while (1) 
    {
		//current_level = UART_ReceiveByte(UART0);
	}
}

void SW_EMERGENCY_Function(void)
{
	UART_SendByte(6, UART0);
}
void SW_GND_Function(void)
{
	UART_SendByte(0, UART0);
}
void SW_L1_Function(void)
{	
	UART_SendByte(1, UART0);
}

void SW_L2_Function(void)
{
	UART_SendByte(2, UART0);
}
void SW_L3_Function(void)
{
	UART_SendByte(3, UART0);
}
void SW_L4_Function(void)
{	
	UART_SendByte(4, UART0);	
}

void UART0_FUNCTION(void)
{
	
	current_level=UART_ReceiveByte(UART0);
	H7SEG_Void_7SEGState(SevenSEG_VALUE[current_level]);
}