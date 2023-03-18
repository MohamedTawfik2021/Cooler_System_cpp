/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ADC.c
 *        \brief  Analog to Digital Converter program
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
#include "ADC.h"

// default constructor
ADC_INPUT::ADC_INPUT()
{

	
} //ADC
ADC_INPUT::ADC_INPUT(ADC_Channel channel)
{    
	 this->channel=channel;
	 ADC_Init(channel);
	 
} //ADC

/******************************************************************************
* \Syntax          : void ADC_Init()        
* \Description     : ADC Initialization                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : void                                 
*******************************************************************************/
 void ADC_INPUT::ADC_Init(ADC_Channel channel)
{
	 this->channel=channel;
	 
	ADMUX |= (1<<REFS0);		                                        /*Vref: Avcc, ADC channel: 0 */
#if (INT_ENABLE == 0)
    ADCSRA |=((1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)) ;		        /*Enable ADC, P=freq/128  */
#else
	ADCSRA |=((1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)) ;  /*Enable ADC,Enable Interrupt, P=freq/128  */
#endif
	
}

/******************************************************************************
* \Syntax          : u16 ADC_Read(Adc_Input channel)        
* \Description     : Read The ADC Data Register                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ADC_INPUT   ADC Channel Input                    
* \Parameters (out): None                                                      
* \Return value:   : u16 Sample Digital value
*                                                                     
*******************************************************************************/
u16 ADC_INPUT::ADC_ChannelRead()
{

	ADMUX|=(channel & 0x0f);		   /* set input channel */
	ADCSRA |= (1<<ADSC);		       /* start conversion */
	
	while (!(ADCSRA & (1<<ADIF)));	   /*monitor end of conversion interrupt flag */
	ADCSRA|= (1<<ADIF);
 			
	return ADCW;  	                   /*return ADC Word_(digital value)*/
}

void ADC_INPUT::Set_Channel(ADC_Channel channel)
{
	this->channel = channel;
}
/**********************************************************************************************************************
 *  END OF FILE: ADC.c
 *********************************************************************************************************************/
