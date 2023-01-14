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
#include "../02 - HAL/1 - LED/LED_interface.h"
#include "../02 - HAL/2 - SWITCH/SWITCH_interface.h"
#include "../02 - HAL/3 - SEVEN_SEGMENT/7SEG_interface.h"
#include "../02 - HAL/4 - DC_MOTOR/DCMOTOR_interface.h"

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
static u8 c=0;


int main(void)
{
    /* Replace with your application code */
	HLED_Void_AttachLED(ELV_UPLED);
	HLED_Void_AttachLED(ELV_DWNLED);
	H7SEG_Void_Setup7SEG();
	H7SEG_Void_7SEGState(SevenSEG_VALUE[current_level]);
	HSwitch_Void_AttachSwitch(SW_EMERGENCY, SW_EMERGENCY_Function);
	HSwitch_Void_AttachSwitch(SW_GND, SW_GND_Function);
	HSwitch_Void_AttachSwitch(SW_L1, SW_L1_Function);
	HSwitch_Void_AttachSwitch(SW_L2, SW_L2_Function);
	HSwitch_Void_AttachSwitch(SW_L3, SW_L3_Function);
	HSwitch_Void_AttachSwitch(SW_L4, SW_L4_Function);
	HDCMOTOR_Void_SetupMotorDriver();
	MUART_voidSetCallback(UART0, UART0_FUNCTION);
	UART_Init(UART0);
	UART_Init(UART2);
    while (1) 
    {
	}
}
void SW_EMERGENCY_Function(void)
{
	UART_SendByte(5, UART2);
}
void SW_GND_Function(void)
{
	u8 counter = current_level;
	u8 upward_flag = 0;

	if (current_level>0)
	{
		upward_flag = 1;
		HLED_Void_LEDState(ELV_DWNLED, LED_ON);
	}
	
	if (upward_flag == 1)
	{
		HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
		while (counter>0)
		{
			
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter--;
			
		}
	}
	_delay_ms(1500);
	H7SEG_Void_7SEGState(ZERO);
	_delay_ms(1500);
	HDCMOTOR_Void_MotorDirection(STOP);
	HLED_Void_LEDState(ELV_UPLED, LED_OFF);
	HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
	current_level=0;
	UART_SendByte(5, UART2);
}
void SW_L1_Function(void)
{	
	u8 counter = current_level;
	u8 upward_flag = 0;
	if (current_level<1)
	{
		HLED_Void_LEDState(ELV_UPLED, LED_ON);
	}
	else if (current_level>1)
	{
		upward_flag = 1;
		HLED_Void_LEDState(ELV_DWNLED, LED_ON);
	}
	
	if(upward_flag == 0)
	{
		HDCMOTOR_Void_MotorDirection(CLOCKWISE);
		while (counter<=1)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter++;
			
		}
	}
	else
	{
		HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
		while (counter>=1)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter--;
			
		}
	}
	_delay_ms(1500);
	HDCMOTOR_Void_MotorDirection(STOP);

	HLED_Void_LEDState(ELV_UPLED, LED_OFF);
	HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
	
	current_level=1;
	UART_SendByte(1, UART2);
}

void SW_L2_Function(void)
{
	u8 counter = current_level;
	u8 upward_flag = 0;
	if (current_level<2)
	{
		HLED_Void_LEDState(ELV_UPLED, LED_ON);
	}
	else if (current_level>2)
	{
		upward_flag = 1;
		HLED_Void_LEDState(ELV_DWNLED, LED_ON);
	}
	
	if(upward_flag == 0)
	{
		HDCMOTOR_Void_MotorDirection(CLOCKWISE);
		while (counter<=2)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter++;
			
		}
	}
	else
	{
		HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
		while (counter>=2)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter--;
			
		}
	}
	_delay_ms(1500);
	HDCMOTOR_Void_MotorDirection(STOP);
	HLED_Void_LEDState(ELV_UPLED, LED_OFF);
	HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
	
	current_level=2;
	UART_SendByte(2, UART2);
}
void SW_L3_Function(void)
{
	u8 counter = current_level;
	u8 upward_flag = 0;
	if (current_level<3)
	{
		HLED_Void_LEDState(ELV_UPLED, LED_ON);
	}
	else if (current_level>3)
	{
		upward_flag = 1;
		HLED_Void_LEDState(ELV_DWNLED, LED_ON);
	}
	
	if(upward_flag == 0)
	{
		HDCMOTOR_Void_MotorDirection(CLOCKWISE);
		while (counter<=3)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter++;
			
		}
	}
	else
	{
		HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
		while (counter>=3)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter--;
			
		}
	}
	_delay_ms(1500);
	HDCMOTOR_Void_MotorDirection(STOP);
	HLED_Void_LEDState(ELV_UPLED, LED_OFF);
	HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
	
	current_level=3;
	UART_SendByte(3, UART2);
}
void SW_L4_Function(void)
{	
	u8 counter = current_level;
	u8 upward_flag = 0;
	if (current_level<4)
	{	
		HLED_Void_LEDState(ELV_UPLED, LED_ON);
	}
	else if (current_level>4)
	{
		upward_flag = 1;
		HLED_Void_LEDState(ELV_DWNLED, LED_ON);
	}
	
	if(upward_flag == 0)
	{	
		HDCMOTOR_Void_MotorDirection(CLOCKWISE);
		while (counter<=4)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter++;
			
		}
	}
	else
	{
		HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
		while (counter>=4)
		{
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
			counter--;
			
		}
	}
	_delay_ms(1500);
	HDCMOTOR_Void_MotorDirection(STOP);
	HLED_Void_LEDState(ELV_UPLED, LED_OFF);
	HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
	
	current_level=4;	
	UART_SendByte(4, UART2);
}

void UART0_FUNCTION(void)
{
		c= UART_ReceiveByte(UART0);
		u8 counter = current_level;
		u8 upward_flag = 0;
		if (current_level<c)
		{
			HLED_Void_LEDState(ELV_UPLED, LED_ON);
		}
		else if (current_level>c)
		{
			upward_flag = 1;
			HLED_Void_LEDState(ELV_DWNLED, LED_ON);
		}
		else
			upward_flag = 2;
		if(upward_flag == 0)
		{
			HDCMOTOR_Void_MotorDirection(CLOCKWISE);
			while (counter<c)
			{
				_delay_ms(1500);
				H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
				counter++;
				
			}
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[c]);
			_delay_ms(1500);
		}
		else if (upward_flag == 1)
		{
			HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
			while (counter>c)
			{
				_delay_ms(1500);
				H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
				counter--;
				
			}
			_delay_ms(1500);
			H7SEG_Void_7SEGState(SevenSEG_VALUE[c]);
			_delay_ms(1500);
		}
		else 
		{
			HDCMOTOR_Void_MotorDirection(ANTI_CLOCKWISE);
			while (counter>0)
			{
				_delay_ms(1500);
				H7SEG_Void_7SEGState(SevenSEG_VALUE[counter]);
				counter--;
						
			}
			_delay_ms(1500);
			H7SEG_Void_7SEGState(ZERO);
			_delay_ms(1500);
		}
		
		HDCMOTOR_Void_MotorDirection(STOP);
		HLED_Void_LEDState(ELV_UPLED, LED_OFF);
		HLED_Void_LEDState(ELV_DWNLED, LED_OFF);
		
		current_level=c;	
		if (current_level!=0)
			UART_SendByte(c, UART2);
		else
			UART_SendByte(5, UART2);
}