/* 
* DIO.h
*
* Created: 10-Jan-23 11:24:09 AM
* Author: Moham
*/


#ifndef __DIO_H__
#define __DIO_H__

#include <avr/io.h>
#include "StdTypes.h"
#include "BitMath.h"



typedef enum
{
	PortA=0,
	PortB,
	PortC,
	PortD
}PortID;


typedef enum
{
	PIN_0A=0,
	PIN_1A,
	PIN_2A,
	PIN_3A,
	PIN_4A,
	PIN_5A,
	PIN_6A,
	PIN_7A,

	PIN_0B,
	PIN_1B,
	PIN_2B,
	PIN_3B,
	PIN_4B,
	PIN_5B,
	PIN_6B,
	PIN_7B,

	PIN_0C,
	PIN_1C,
	PIN_2C,
	PIN_3C,
	PIN_4C,
	PIN_5C,
	PIN_6C,
	PIN_7C,

	PIN_0D,
	PIN_1D,
	PIN_2D,
	PIN_3D,
	PIN_4D,
	PIN_5D,
	PIN_6D,
	PIN_7D,

}PinID;


typedef enum
{
	IN_FREE=0,
	IN_UP,
	OUT

}Direction;


class PIN
{
	//variables
	private:
	PortID port;
	u8 pin;
	Direction state;

	//functions
	public:
	PIN();
	PIN(PinID,Direction);
	void DIO_Init_Pin(PinID,Direction);
	void DIO_SET_Pin();
	void DIO_CLR_Pin();
	void DIO_TOG_Pin();
	u8   DIO_Read_Pin();
	
}; //PIN


class PORT
{
	//variables
	private:
	PortID port;
	u8 mask;
	
	//functions
	public:
	PORT();
	PORT(PortID port, u8 mask);
	void DIO_Init_Port(PortID port, u8 mask);
	void DIO_Write_Port(u8 value);
	u8   DIO_Read_Port();

}; //PORT


#endif //__DIO_H__
