/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  TIMER1.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

#include "Timer.h"

// default constructor
TIMER::TIMER()
{
} //Timer

PWM::PWM()
{
//	PIN OC1A(PIN_5D,OUT);
	OC1B.DIO_Init_Pin(PIN_4D,OUT);
	
} //PWM

PULSE_CAPTURE::PULSE_CAPTURE()
{
	/*Normal Mode & rising trigger*/
	/* Pre_scaler = 1 */
	TCCR1A=0x00;
	TCCR1B=0x41;
	
} //Pulse Capture

EVENT_CAPTURE::EVENT_CAPTURE()
{
	/*Normal Mode & falling trigger */
	/* Pre_scaler = 1024*/
	TCCR1A=0x00;
	TCCR1B=0x05;
	
} //Event Capture

COUNTER::COUNTER()
{
	TCCR1A=0;            /* Normal Mode*/
	TCCR1B = 0x06;       /* External clock on T1 pin - Falling edge*/
	PORTB|=(1<<PB1);	 /* Turn ON Pull-UP resistor */
	TCNT1=0;             /* Reset T/C register*/
	
}

/******************************************************************************
* \Syntax          : void Timer1_Delay_Sec(f32 time)
* \Description     : Delay Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : f32 time
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void TIMER::T1_Delay_Sec(f32 time)
{
	TCCR1A=0x00;                                   /* Select Normal Operation Mode=0 */
	TCCR1B=0x05;                                   /* Select CPU_clk/1024[T_tick=128us] */
	TCNT1 = (u16)(65536-(time*1000000/128));       /* Load Counter Register with start value */
	while((TIFR&(1<<TOV1))==0);                    /* wait until the time elapsed */
	TIFR |= (1<<TOV1);                             /* Clear Flag */
}

/******************************************************************************
* \Syntax          : void Timer1_Delay_mSec(f32 time)
* \Description     : Delay milli-Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : f32 time
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void TIMER::T1_Delay_mSec(f32 time)
{
	TCCR1A=0x00;                          /* Select CTC Operation Mode=4 */
	TCCR1B=0x0B;                          /* Select CPU_clk/64[T_tick=8us]*/
	OCR1A = (u16)(time*1000/8);           /* Load OCR Register with TOP value */
	while(! (TIFR&(1<<OCF1A)) );          /* wait until the time elapsed */
	TIFR |= (1<<OCF1A);                   /* Clear Flag */
	
}

/******************************************************************************
* \Syntax          : void Timer1_Delay_uSec(f32 time)
* \Description     : Delay micro-Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : f32 time
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void TIMER::T1_Delay_uSec(f32 time)
{
	TCCR1A=0x00;                          /* Select CTC Operation Mode=4 */
	TCCR1B=0x0A;                          /* Select CPU_clk/8[T_tick=1us] */
	OCR1A = (u16)time;                    /* Load OCR Register with TOP value */
	while(! (TIFR&(1<<OCF1A)) );          /* wait until the time elapsed */
	TIFR |= (1<<OCF1A);                   /* Clear Flag */
}

/******************************************************************************
* \Syntax          : void Timer1_FastPWM (f32 freq, u8 duty)
* \Description     : Delay Timer1 Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : (f32 freq, u8 duty)
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void PWM::T1_FastPWM (f32 freq, f32 duty)
{
	/*Fast PWM & Pre_scaler = 1*/
	/*WGM=15 / COM1B=2*/
	TCCR1A = 0x23;
	TCCR1B = 0x19;
//	DDRD|=(1<<4);   OC1B
	
	OCR1A = (u16)(F_CPU/freq)-1;
	OCR1B = (u16)(OCR1A*duty/100);

}

/******************************************************************************
* \Syntax          : void Timer1_PhasePWM (f32 freq, f32 duty)
* \Description     : Delay Timer1 Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : (f32 freq, f32 duty)
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void PWM::T1_PhasePWM (f32 freq, f32 duty)
{
	/*Phase Correct & Pre_scaler = 8*/
	/*WGM=11 / COM1B=2*/
	TCCR1A = 0x23;
	TCCR1B = 0x12;
//	DDRD|=(1<<4);   OC1B
	
	OCR1A = (u16)(F_CPU/(2*8*freq));
	OCR1B = (u16)(OCR1A*duty/100);
}



/******************************************************************************
* \Syntax          : void Timer1_PhaseFreqPWM (f32 freq, f32 duty)
* \Description     : Delay Timer1 Seconds
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : (f32 freq, f32 duty)
* \Parameters (out): None
* \Return value:   : Void
*
*******************************************************************************/
void PWM::T1_PhaseFreqPWM (f32 freq, f32 duty)
{
	/*Phase_Freq Correct & Pre_scaler = 8*/
	/*WGM=9/ COM1B=2*/
	TCCR1A = 0x21;
	TCCR1B = 0x12;
//	DDRD|=(1<<4);   OC1B
	OCR1A = (u16)(F_CPU/2*8*freq);
	OCR1B = (u16)(OCR1A*duty/100);
}

/******************************************************************************
* \Syntax          : Input Capture Mode APIs
* \Description     : Input Capture Time and Events Measurements
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*******************************************************************************/
u16 sample_ticks=0;

void EVENT_CAPTURE::T1_StartCapture(edge trigger,u16*ticks,f32*time_ms )
{
	switch(trigger)
	{
		case Rising:
		TCCR1B|= (1<<ICES1);
		break;
		case Falling:
		TCCR1B&= ~(1<<ICES1);
		break;
	}
	TCNT1=0;
	TIFR = (1<<ICF1);
	*ticks = sample_ticks;
	*time_ms  = (sample_ticks*1024/F_CPU)*1000;
	
}

ISR(TIMER1_CAPT_vect)
{
	sample_ticks=ICR1;
}

/******************************************************************************
* \Syntax          : Pulse Capture Mode APIs
* \Description     : Measure Pulse Frequency and Duty_Cycle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*******************************************************************************/
u8 PULSE_CAPTURE::T1_PulseCapture(u32*freq , f32*duty)
{
	u16 a,b,c,high,period;
	
	/* Turn ON Pull-UP resistor */
	
	TCCR1A = 0;
	TCNT1=0;
	TIFR = (1<<ICF1);				        /* clear ICP flag (Input Capture flag) */

	TCCR1B|= (1<<ICES1);					/* rising edge */
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;						        /* take value of capture register */
	TIFR = (1<<ICF1);				        /* clear ICP flag (Input Capture flag) */
		
	TCCR1B&= ~(1<<ICES1);			        /* falling edge */
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;						        /* take value of capture register */
	TIFR = (1<<ICF1);				        /* clear ICP flag (Input Capture flag) */
		
	TCCR1B|= (1<<ICES1);					/* rising edge */
	while ((TIFR&(1<<ICF1)) == 0);
	c = ICR1;						        /* take value of capture register */
	TIFR = (1<<ICF1);				        /* clear ICP flag (Input Capture flag) */

	TCCR1B = 0;				                /* stop the timer */
		
	if(a<b && b<c)					        /* check for valid condition, to avoid timer overflow reading */
	{
		high=b-a;
		period=c-a;
			
		 *freq  = F_CPU/(period);		             /* calculate frequency */
		 *duty  = ((f32)high/(f32) period)*100;	 /* calculate duty cycle */
		 return 1;
	}
	else return 0;
}

/******************************************************************************
* \Syntax          : Periodic Tasks APIs
* \Description     : Implement Periodic Functions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : period , Ptr*task
* \Parameters (out): None
* \Return value:   :
*
*******************************************************************************/
void static (*ovcallback)(void);       /*Declare Pointer to Function_1*/
void static (*compAcallback)(void);    /*Declare Pointer to Function_2*/
void static (*compBcallback)(void);    /*Declare Pointer to Function_3*/

void TIMER::T1_PeriodicTask1(f32 period_ms , void (*callback)(void))
{
	
	TCCR1A=0x00;                                   /* Select CTC Operation Mode=4 */
    TCCR1B=0x0D;                                   /* Select CPU_clk/1024[T_tick=128us] */
	OCR1A = (u16)(period_ms/1000*F_CPU/1024);      /* Load OCR Register with TOP value */
	TIMSK|=(1<<OCIE1A);                            /* Enable Compare Match A Interrupt */
	TCNT1 = 0;                                     /*RESET the Timer*/
    compAcallback = callback;                 
}
void TIMER::T1_PeriodicTask2(f32 period_ms , void (*callback)(void))
{
	TCCR1A=0x00;                                   /* Select CTC Operation Mode=4 */
    TCCR1B=0x0D;                                   /* Select CPU_clk/1024[T_tick=128us] */
	OCR1B = (u16)(period_ms/1000*F_CPU/1024);      /* Load OCR Register with TOP value */
	TIMSK|=(1<<OCIE1B);                       
	TCNT1 = 0;
	compBcallback = callback;
}

void TIMER::T1_PeriodicTask3(f32 period_ms , void (*callback)(void))
{
	
	TCCR1A=0x00;                                      /* Select Normal Operation Mode=0 */
    TCCR1B=0x05;                                      /* Select CPU_clk/1024[T_tick=128us] */
    TCNT1 = (u16)(65536-(period_ms/1000*F_CPU/1024)); /* Load Counter Register with start value */ 
	TIMSK|=(1<<TOIE1);
	TCNT1 = 0;
	ovcallback=callback;
}

ISR(TIMER1_OVF_vect)
{
	ovcallback();
}

ISR(TIMER1_COMPA_vect)
{
	compAcallback();
}
ISR(TIMER1_COMPB_vect)
{
	compBcallback();
}

/******************************************************************************
* \Syntax          : Counter APIs
* \Description     : External Clocks on T1
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : u16 Number of Counts
*
*******************************************************************************/
u16 COUNTER::T1_GetCounts()
{
   return TCNT1;
}

/**********************************************************************************************************************
 *  END OF FILE: Timer1.c
 *********************************************************************************************************************/
