/* 
* LCD.h
*
* Created: 13-Jan-23 12:37:17 AM
* Author: Moham
*/


#ifndef __LCD_H__
#define __LCD_H__

#ifndef  F_CPU
#define  F_CPU 8000000UL
#endif

#include "StdTypes.h"
#include <util/delay.h>
#include "DIO.h"

/** LCD Data Pins     */
#define LCD_DATA_PORT      PortC

/*LCD Control Pins */
#define LCD_CONTROL_PORT   PortD
#define LCD_RS             PIN_0D
#define LCD_RW             PIN_1D
#define LCD_E              PIN_2D

/*LCD Control Instruction Commands */
#define CMND_FUNCTION_SET_CMND         0x38
#define CMND_DISPLAY_ON_CURSOR_OFF     0x0c
#define CMND_DISPLAY_CLEAR             0x01
#define CMND_ENTRY_MODE_SET            0x06
#define CMND_RETURN_HOME               0X02


class LCD 
{
//variables
public:
protected:
private:
	//Define control and Data pins with Defaults
	PORT lcd_data_port;
	PIN  lcd_rs;
	PIN  lcd_rw;
	PIN  lcd_en;

//functions
public:
	LCD();
	void LCD_Init(void);
	void LCD_cmnd(u8 cmnd);
	void LCD_write(u8 data);
	void LCD_String(u8 length ,char *str); // string[length]
	void LCD_String_xy (u8 row, u8 pos,u8 length , char *str) ;  // string[length]
	void LCD_Cursor_pos(u8 row , u8 col);
	void LCD_Clear();	
	

}; //LCD

#endif //__LCD_H__
