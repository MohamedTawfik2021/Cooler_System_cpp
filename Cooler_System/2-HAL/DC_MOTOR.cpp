/* 
* DC_MOTOR.cpp
*
* Created: 16-Jan-23 4:04:39 AM
* Author: Moham
*/

#include "DC_MOTOR_cfg.h"
#include "DC_MOTOR.h"

// default constructor
DC_MOTOR::DC_MOTOR()
{
	IN1.DIO_Init_Pin(MOTOR1_IN1,OUT);
	IN2.DIO_Init_Pin(MOTOR1_IN2,OUT);
	EN.T1_PhasePWM(50,100);
	
} //DC_MOTOR

void DC_MOTOR::Motor_RUN()
{
	IN1.DIO_SET_Pin();
	IN2.DIO_CLR_Pin();
}
void DC_MOTOR::Motor_STOP()
{
	IN1.DIO_CLR_Pin();
	IN2.DIO_CLR_Pin();
}

void DC_MOTOR::Motor_Direction(Rotation dir)
{
	if(dir == POS)
	{
	   IN1.DIO_SET_Pin();
	   IN2.DIO_CLR_Pin();
	}
	else
	{
		IN1.DIO_CLR_Pin();
		IN2.DIO_SET_Pin();
	}
}

void DC_MOTOR::Motor_Duty(u8 duty)
{
	EN.T1_PhasePWM(50,duty);
}