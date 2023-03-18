/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ADC.h
 *       Module:  Analog to Digital Converter
 *
 *  Description:  ADC header file    
 *  
 *********************************************************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

#include <avr/io.h>
#include "StdTypes.h"
#include "ADC_cfg.h"

typedef enum 
{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	
}ADC_Channel;

class ADC_INPUT
{
	//variables
	private:
		ADC_Channel channel;

	//functions
	public:
		ADC_INPUT();
		ADC_INPUT(ADC_Channel);
		void Set_Channel(ADC_Channel);
		void ADC_Init(ADC_Channel);
		u16 ADC_ChannelRead();

}; //ADC




#endif  /* ADC_H */

/**********************************************************************************************************************
 *  END OF FILE: ADC.h
 *********************************************************************************************************************/



