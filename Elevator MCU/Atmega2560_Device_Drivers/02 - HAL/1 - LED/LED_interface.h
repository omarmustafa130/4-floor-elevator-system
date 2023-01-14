/*
 * LED_interface.h
 *
 * Created: 1/6/2023 2:54:59 PM
 *  Author: Omar Mustafa
 */ 

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../Library/STD_TYPES.h"
#include "../../01 - MCAL/1 - GPIO_DRIVER/GPIO_interface.h"

#define LEDS_PORT GPIO_PORTB
#define LED_OFF		GPIO_LOW
#define	LED_ON		GPIO_HIGH

enum LEDS_t {ELV_UPLED, ELV_DWNLED};

void HLED_Void_AttachLED(enum LEDS_t LED);
void HLED_Void_LEDState(enum LEDS_t LED, u8 LED_State);


#endif /* LED_INTERFACE_H_ */