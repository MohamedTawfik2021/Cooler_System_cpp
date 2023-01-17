/* 
* LCD.cpp
*
* Created: 13-Jan-23 12:37:17 AM
* Author: Moham
*/


#include "LCD.h"

// default constructor
LCD::LCD()
{
	LCD::LCD_Init();
} //LCD


void LCD::LCD_Init(void)
{
//Set directions as a output for control and Data pins
	lcd_data_port.DIO_Init_Port(LCD_DATA_PORT,0xFF);
	lcd_rs.DIO_Init_Pin(LCD_RS,OUT);
	lcd_rw.DIO_Init_Pin(LCD_RW,OUT);
	lcd_en.DIO_Init_Pin(LCD_E,OUT);
	
	_delay_ms(40);
	LCD_cmnd(CMND_FUNCTION_SET_CMND);

	_delay_us(40);

	LCD_cmnd(CMND_DISPLAY_ON_CURSOR_OFF);

	_delay_us(40);

	LCD_cmnd(CMND_DISPLAY_CLEAR);

	_delay_ms(2);

	LCD_cmnd(CMND_ENTRY_MODE_SET);
}

void LCD::LCD_cmnd(u8 cmnd)
{

	//RS = 0 register of the commands
	lcd_rs.DIO_CLR_Pin();

	//RW = 0 write on the lcd
	lcd_rw.DIO_CLR_Pin();

	//PUT command on the LCD_DATA PORT
	lcd_data_port.DIO_Write_Port(cmnd);

	//Latching  E = High
	lcd_en.DIO_SET_Pin();

	//delay
	_delay_ms(1);

	//latching E = low
	lcd_en.DIO_CLR_Pin();
	
}

void LCD::LCD_write(u8 data)
{
	
	//RS = 1 register of the Data
	lcd_rs.DIO_SET_Pin();

	//RW = 0 write on the lcd
	lcd_rw.DIO_CLR_Pin();

	//PUT data on the LCD_DATA PORT
	lcd_data_port.DIO_Write_Port(data);

	//Latching  E = High
	lcd_en.DIO_SET_Pin();

	//delay
	_delay_ms(1);

	//latching E = low
	lcd_en.DIO_CLR_Pin();

}

void LCD::LCD_String (u8 length , char *str)		/* Send string to LCD function */
{
	
	for(u8 i=0; i<length ;i++)
	{
		
		LCD_write(str[i]);
	}
}

void LCD::LCD_Clear()
{
	LCD_cmnd(0x01);		/* clear display */
	LCD_cmnd(0x02);
	
	//LCD_cmnd(0x80);		/* cursor at home position */
}

void LCD::LCD_String_xy (u8 row, u8 pos, u8 length ,char *str)     /* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_cmnd((pos & 0x0F)|0x80);	    /* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_cmnd((pos & 0x0F)|0xC0);   	/* Command of first row and required position<16 */
	LCD_String(length ,str);	              	/* Call LCD string function */
}

void LCD::LCD_Cursor_pos(u8 row , u8 col)
{
	if (row == 0 && col<16)
	LCD_cmnd((col & 0x0F)|0x80);	    /* Command of first row and required position<16 */
	else if (row == 1 && col<16)
	LCD_cmnd((col & 0x0F)|0xC0);   	     /* Command of first row and required position<16 */

}
