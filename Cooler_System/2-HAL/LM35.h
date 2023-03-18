/* 
* LM35.h
*
* Created: 18-Mar-23 6:14:15 PM
* Author: Moham
*/


#ifndef __LM35_H__
#define __LM35_H__

#include <avr/io.h>
#include "StdTypes.h"
#include "ADC.h"

class LM35
{
//variables
private:
	ADC_INPUT sensor;

//functions
public:
	LM35(ADC_Channel);
	u8 GetTemperature();
protected:
private:


}; //LM35

#endif //__LM35_H__
