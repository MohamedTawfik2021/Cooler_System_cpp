/* 
* LED.h
*
* Created: 13-Jan-23 6:23:27 AM
* Author: Moham
*/


#ifndef __LED_H__
#define __LED_H__

#include "StdTypes.h"
#include "BitMath.h"
#include "DIO.h"

typedef enum LedStatus
{
	OFF=0,
	ON
}LedStatus;

class LED
{
//variables
private:
	LedStatus status;
    PIN led;
//functions
public:
	LED(PinID);
    void LED_ON();
	void LED_OFF();
	LedStatus Get_LED_Status();

}; //LED

#endif //__LED_H__
