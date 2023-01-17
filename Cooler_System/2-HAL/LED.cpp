/* 
* LED.cpp
*
* Created: 13-Jan-23 6:23:27 AM
* Author: Moham
*/


#include "LED.h"


LED::LED(PinID pin)
{
	led.DIO_Init_Pin(pin,OUT);
	LED_OFF();
} //LED

void LED::LED_OFF()
{
	led.DIO_CLR_Pin();
	status = OFF;
}

void LED::LED_ON()
{
	led.DIO_SET_Pin();
	status = ON;
}

LedStatus LED::Get_LED_Status()
{
	return status;
}