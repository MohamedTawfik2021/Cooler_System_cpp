/* 
* DIO.cpp
*
* Created: 10-Jan-23 11:24:09 AM
* Author: Moham
*/


#include "DIO.h"
//Local Function Prototype
void Set_PortA_Pins(u8 pin ,Direction state);
void Set_PortB_Pins(u8 pin ,Direction state);
void Set_PortC_Pins(u8 pin ,Direction state);
void Set_PortD_Pins(u8 pin ,Direction state);


PIN::PIN()
{
	
} //PIN
PORT::PORT()
{
	
} //PORT

// PIN Parametrized constructor
PIN::PIN(PinID p ,Direction state)
{

	DIO_Init_Pin(p ,state);
	
} //PIN

// PORT Parametrized constructor
PORT::PORT(PortID port, u8 mask)
{
	DIO_Init_Port(port, mask);
	
} //PORT


/******************************************************************************
* \Syntax          : void DIO_Init_Pin(PinID,Direction)
* \Description     : Define a Pin and Set the direction
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PIN_ID , Direction State
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PIN::DIO_Init_Pin(PinID p ,Direction state)
{
   switch(p)
   {
/*************PORT-A***************/		   
	 case PIN_0A:
		this->port=PortA;
		this->pin =0;
		Set_PortA_Pins(0,state);
		break;
	 case PIN_1A:
		this->port=PortA;
		this->pin =1;
	    Set_PortA_Pins(1,state);
	    break;
	 case PIN_2A:
		this->port=PortA;
		this->pin =2;
	    Set_PortA_Pins(2,state);
	    break;
	 case PIN_3A:
		this->port=PortA;
		this->pin =3;
	    Set_PortA_Pins(3,state);
	    break;	
	 case PIN_4A:
		this->port=PortA;
		this->pin =4;
	    Set_PortA_Pins(4,state);
	    break;	
	 case PIN_5A:
		this->port=PortA;
		this->pin =5;
		Set_PortA_Pins(5,state);
		break;
	 case PIN_6A:
		this->port=PortA;
		this->pin =6;
		Set_PortA_Pins(6,state);
		break;
	 case PIN_7A:
		this->port=PortA;
		this->pin =7;
		Set_PortA_Pins(7,state);
		break;
	 	
/*************PORT-B***************/	   
	 case PIN_0B:
		this->port=PortB;
		this->pin =0;
		Set_PortB_Pins(0,state);
		break;
	 case PIN_1B:
		this->port=PortB;
		this->pin =1;
		Set_PortB_Pins(1,state);
		break;
	 case PIN_2B:
		this->port=PortB;
		this->pin =2;
		Set_PortB_Pins(2,state);
		break;
	 case PIN_3B:
		this->port=PortB;
		this->pin =3;
		Set_PortB_Pins(3,state);
		break;
	 case PIN_4B:
		this->port=PortB;
		this->pin =4;
		Set_PortB_Pins(4,state);
		break;
	 case PIN_5B:
		this->port=PortB;
		this->pin =5;
		Set_PortB_Pins(5,state);
		break;
	 case PIN_6B:
		this->port=PortB;
		this->pin =6;
		Set_PortB_Pins(6,state);
		break;
	 case PIN_7B:
		this->port=PortB;
		this->pin =7;
		Set_PortB_Pins(7,state);
		break;
	    
	 	
/*************PORT-C***************/	   
	 case PIN_0C:
		this->port=PortC;
		this->pin =0;
		Set_PortC_Pins(0,state);
		break;
	 case PIN_1C:
		this->port=PortC;
		this->pin =1;
		Set_PortC_Pins(1,state);
		break;
	 case PIN_2C:
		this->port=PortC;
		this->pin =2;
		Set_PortC_Pins(2,state);
		break;
	 case PIN_3C:
		this->port=PortC;
		this->pin =3;
		Set_PortC_Pins(3,state);
		break;
	 case PIN_4C:
		this->port=PortC;
		this->pin =4;
		Set_PortC_Pins(4,state);
		break;
	 case PIN_5C:
		this->port=PortC;
		this->pin =5;
		Set_PortC_Pins(5,state);
		break;
	 case PIN_6C:
		this->port=PortC;
		this->pin =6;
		Set_PortC_Pins(6,state);
		break;
	 case PIN_7C:
		this->port=PortC;
		this->pin =7;
		Set_PortC_Pins(7,state);
		break;
	 	
/*************PORT-D***************/	   
	 case PIN_0D:
		this->port=PortD;
		this->pin =0;
		Set_PortD_Pins(0,state);
		break;
	 case PIN_1D:
		this->port=PortD;
		this->pin =1;
		Set_PortD_Pins(1,state);
		break;
	 case PIN_2D:
		this->port=PortD;
		this->pin =2;
		Set_PortD_Pins(2,state);
		break;
	 case PIN_3D:
		this->port=PortD;
		this->pin =3;
		Set_PortD_Pins(3,state);
		break;
	 case PIN_4D:
		this->port=PortD;
		this->pin =4;
		Set_PortD_Pins(4,state);
		break;
	 case PIN_5D:
		this->port=PortD;
		this->pin =5;
		Set_PortD_Pins(5,state);
		break;
	 case PIN_6D:
		this->port=PortD;
		this->pin =6;
		Set_PortD_Pins(6,state);
		break;
	 case PIN_7D:
		this->port=PortD;
		this->pin =7;
		Set_PortD_Pins(7,state);
		break;
	      	   
	   
   }
	
}

/******************************************************************************
* \Syntax          : void DIO_Set_Pin(PinID)
* \Description     : Set PIN in HIGH State
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PIN_ID
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PIN::DIO_SET_Pin()
{
	if (port == PortA)
	{
		SET_BIT(PORTA,pin);
	}
	else if (port == PortB)
	{
		SET_BIT(PORTB,pin);
	}
	else if (port == PortC)
	{
		SET_BIT(PORTC,pin);
	}
	else if (port == PortD)
	{
		SET_BIT(PORTD,pin);
	}
}

/******************************************************************************
* \Syntax          : void DIO_CLR_Pin()
* \Description     : Set PIN in LOW State
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PIN_ID
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PIN::DIO_CLR_Pin()
{
	if (port == PortA)
	{
		CLR_BIT(PORTA,pin);
	}
	else if (port == PortB)
	{
		CLR_BIT(PORTB,pin);
	}
	else if (port == PortC)
	{
		CLR_BIT(PORTC,pin);
	}
	else if (port == PortD)
	{
		CLR_BIT(PORTD,pin);
	}
	
}

/******************************************************************************
* \Syntax          : void DIO_Togg_Pin()
* \Description     : Toggle PIN State
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PIN_ID
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PIN::DIO_TOG_Pin()
{
	if (port == PortA)
	{
		TOG_BIT(PORTA,pin);
	}
	else if (port == PortB)
	{
		TOG_BIT(PORTB,pin);
	}
	else if (port == PortC)
	{
		TOG_BIT(PORTC,pin);
	}
	else if (port == PortD)
	{
		TOG_BIT(PORTD,pin);
	}
	
}

/******************************************************************************
* \Syntax          : u8 DIO_Read_Pin()
* \Description     : Read PIN State
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PIN_ID
* \Parameters (out): None
* \Return value:   : PIN State
*
*******************************************************************************/
u8 PIN::DIO_Read_Pin()
{
	u8 pin_state=0;
	if (port == PortA)
	{
		pin_state = GET_BIT(PINA,pin);
	}
	else if (port == PortB)
	{
		pin_state = GET_BIT(PINB,pin);
	}
	else if (port == PortC)
	{
		pin_state = GET_BIT(PINC,pin);
	}
	else if (port == PortD)
	{
		pin_state = GET_BIT(PIND,pin);
	}
	
	return pin_state;
}


/******************************************************************************
* \Syntax          : void DIO_Init_Port(PortID port, u8 mask)
* \Description     : Set PORT Directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PORT_ID
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void PORT::DIO_Init_Port(PortID port, u8 mask)
{
	this->port = port;
	this->mask = mask;
		
	switch(port)
	{
		case PortA:
		DDRA=mask;
		break;
		case PortB:
		DDRB=mask;
		break;
		case PortC:
		DDRC=mask;
		break;
		case PortD:
		DDRD=mask;
		break;
	}
	
}

/******************************************************************************
* \Syntax          : void DIO_Write_Port(u8 value)  
* \Description     : Set PORT State Value                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PORT_ID                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PORT::DIO_Write_Port(u8 value)
{
 switch(port)
	{
	  case PortA:
		PORTA=value;
		break;
	  case PortB:
		PORTB=value;
		break;
	  case PortC:
	    PORTC=value;
		break;
	  case PortD:
		PORTD=value;
		break;
    }	
		
	
}

/******************************************************************************
* \Syntax          : u8 DIO_Read_Port()     
* \Description     : Read PORT State                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PORT_ID                 
* \Parameters (out): None                                                      
* \Return value:   : PORT State
*                                                                     
*******************************************************************************/
u8 PORT::DIO_Read_Port() 
{   u8 port_state=0x00;
	 switch(port)
	{
	  case PortA:
		port_state = PINA;
		break;
	  case PortB:
		port_state = PINB;
		break;
	  case PortC:
	    port_state = PINC;
		break;
	  case PortD:
		port_state = PIND;
		break;
    }	
	return port_state;
	
}
/**********************************************************************************************************************
 *  DIO Local Methods Implementation
 *********************************************************************************************************************/

void Set_PortA_Pins(u8 pin ,Direction state)
{
	switch(state)
	{
		case OUT:
		SET_BIT(DDRA,pin);
		break;
		case IN_UP:
		CLR_BIT(DDRA,pin);
		SET_BIT(PORTA,pin);
		break;
		case IN_FREE:
		CLR_BIT(DDRA,pin);
		break;
	}
	
}
void Set_PortB_Pins(u8 pin ,Direction state)
{
	switch(state)
	{
		case OUT:
		SET_BIT(DDRB,pin);
		break;
		case IN_UP:
		CLR_BIT(DDRB,pin);
		SET_BIT(PORTB,pin);
		break;
		case IN_FREE:
		CLR_BIT(DDRB,pin);
		break;
	}
	
}
void Set_PortC_Pins(u8 pin ,Direction state)
{
	
	switch(state)
	{
		case OUT:
		SET_BIT(DDRC,pin);
		break;
		case IN_UP:
		CLR_BIT(DDRC,pin);
		SET_BIT(PORTC,pin);
		break;
		case IN_FREE:
		CLR_BIT(DDRC,pin);
		break;
	}
	
}
void Set_PortD_Pins(u8 pin ,Direction state)
{
	switch(state)
	{
		case OUT:
		SET_BIT(DDRD,pin);
		break;
		case IN_UP:
		CLR_BIT(DDRD,pin);
		SET_BIT(PORTD,pin);
		break;
		case IN_FREE:
		CLR_BIT(DDRD,pin);
		break;
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/