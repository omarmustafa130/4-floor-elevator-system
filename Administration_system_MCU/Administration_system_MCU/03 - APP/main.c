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
#include "../02 - HAL/1 - LCD_DRIVER/LCD_CONFIG.h"

#include "../02 - HAL/1 - LCD_DRIVER/LCD_INT.h"

#define F_CPU 8000000UL
#include <util/delay.h>


static u8 current_level=0;

int main(void)
{

	UART_Init(UART2);
	
LCD_Vid_8BitInit();
	LCD_Vid_SendString("HI", 0,0);
	_delay_ms(1000);
	LCD_Vid_ClearScreen();
	MGPIO_VoidSetPortDirection(GPIO_PORTA, GPIO_OUTPUT);
	
    while (1) 
    {		
			_delay_ms(1000);
			current_level = UART_ReceiveByte(UART2);
			switch (current_level)
			{
				case 6:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("EMERGENCY!!", 0,0);
					break;
				case 1:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("Elevator in F1", 0,0);
					break;
				case 2:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("Elevator in F2", 0,0);
					break;
				case 3:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("Elevator in F3", 0,0);
					break;
				case 4:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("Elevator in F4", 0,0);
					break;
				case 5:
					LCD_Vid_ClearScreen();
					LCD_Vid_SendString("Elevator in F0", 0,0);
					break;
			
				default:
					break;

			}
	}
}


