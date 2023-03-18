/* 
* LM35.cpp
*
* Created: 18-Mar-23 6:14:15 PM
* Author: Moham
*/


#include "LM35.h"

// default constructor
LM35::LM35(ADC_Channel channel)
{
	sensor.Set_Channel(channel);
	sensor.ADC_Init(channel);
	
} //LM35

u8 LM35::GetTemperature(void)
{
	u16 digital_read = sensor.ADC_ChannelRead();
	f32 analog_read = digital_read *4.88;
	
	return ((u8)(analog_read/10));
}