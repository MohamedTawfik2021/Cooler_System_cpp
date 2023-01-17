/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer1
 *       Module:  General Purpose timer
 *
 *  Description:  Timer1.h   
 *  
 *********************************************************************************************************************/
#ifndef TIMER1_H
#define TIMER1_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "StdTypes.h"
//#include "Timer1_cfg.h"
#include "DIO.h"

#ifndef F_CPU
#define F_CPU   8000000UL
#endif

typedef enum edge
{
	Falling=0,
	Rising
}edge;


class TIMER
{
//variables

//functions
public:
	TIMER();
	
	/*Delay Mode API*/
	void T1_Delay_Sec(f32 time);
	void T1_Delay_mSec(f32 time);
	void T1_Delay_uSec(f32 time);

	/*Periodic Tasks Mode API*/
	void T1_PeriodicTask1(f32 period_ms , void (*callback)(void));
	void T1_PeriodicTask2(f32 period_ms , void (*callback)(void));
	void T1_PeriodicTask3(f32 period_ms , void (*callback)(void));	
	
}; //Timer

class PWM
{
private:
	PIN OC1B;
//functions
public:

	PWM();
		
	/*PWM Modes API*/
	void T1_FastPWM      (f32 freq, f32 duty);
	void T1_PhasePWM     (f32 freq, f32 duty);
	void T1_PhaseFreqPWM (f32 freq, f32 duty);
	
}; //PWM

class PULSE_CAPTURE
{
//functions
public:	
	PULSE_CAPTURE();
	
   /*Pulse Capture Mode API*/
	u8 T1_PulseCapture(u32*freq , f32*duty);
	
}; //Pulse_Capture


class EVENT_CAPTURE
{
//functions
public:	
	EVENT_CAPTURE();
	
	/*Input Capture Mode API*/
	void T1_StartCapture(edge trigger , u16*ticks , f32*time_ms );
	
}; //Event_Capture

class COUNTER
{
//functions
public:	
	COUNTER();
	
	/*Counter Mode API*/
	u16 T1_GetCounts(void);
	
}; //Counter

#endif //__TIMER_H__

/**********************************************************************************************************************
 *  END OF FILE: TIMER1_H
 *********************************************************************************************************************/