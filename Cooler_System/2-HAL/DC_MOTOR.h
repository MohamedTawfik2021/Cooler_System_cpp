/* 
* DC_MOTOR.h
*
* Created: 16-Jan-23 4:04:39 AM
* Author: Moham
*/


#ifndef __DC_MOTOR_H__
#define __DC_MOTOR_H__

#include "StdTypes.h"
#include "DIO.h"
#include "Timer.h"

typedef enum Rotation
{
	NEG=0,
	POS
}Rotation;

class DC_MOTOR
{
//variables
public:
protected:
private:
	PIN IN1;
	PIN IN2;
	PWM EN;

//functions
public:
	DC_MOTOR();
	void Motor_RUN();
	void Motor_STOP();
	void Motor_Direction(Rotation);
	void Motor_Duty(u8);
	
}; //DC_MOTOR

#endif //__DC_MOTOR_H__
