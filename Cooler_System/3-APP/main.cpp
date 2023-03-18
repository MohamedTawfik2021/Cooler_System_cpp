/*
 * Cooler_System.cpp
 *
 * Created: 17-Jan-23 2:09:25 AM
 * Author : Moham
 */ 

#define F_CPU   8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


#include "DIO.h"
#include "Timer.h"

#include "LCD.h"
#include "LED.h"
#include "DC_MOTOR.h"
#include "LM35.h"

/*Global Variables*/
  u8   temprature=0;
  LCD lcd1;
  u8  fan_duty=50;
  char temp_buffer[7];
  char speed_buffer[7];
  
/*Local Functions Prototype*/  
void Display();

int main(void)
{
	LM35 temp_sensor(ADC0);
	DC_MOTOR fan;
//	fan.Motor_Duty(50);
//	fan.Motor_RUN();
	fan.Motor_STOP();
	
	LED green_led(PIN_2B);
	LED yellow_led(PIN_1B);
	LED red_led(PIN_0B);
	
	
	
    while (1) 
    {		

		temprature = temp_sensor.GetTemperature();
		
		if (temprature<20)
		{
            green_led.LED_ON();
			yellow_led.LED_OFF();
			red_led.LED_OFF();	
			fan.Motor_STOP();
			fan_duty = 0;
			lcd1.LCD_Clear();
			Display();		
			_delay_ms(100);
			
		} 
		else if (temprature>=20 && temprature<30)
		{
			green_led.LED_ON();
			yellow_led.LED_ON();
			red_led.LED_OFF();
			fan.Motor_Duty(50);
			fan.Motor_RUN();
			fan_duty = 50;
			lcd1.LCD_Clear();
			Display();		
			_delay_ms(100);
		}
		else if (temprature>=30)
		{
			green_led.LED_ON();
			yellow_led.LED_ON();
			red_led.LED_ON();
			fan.Motor_Duty(100);
			fan_duty =100;
			lcd1.LCD_Clear();
			Display();		
			_delay_ms(100);
		}
	}
	
}

void Display()
{
		itoa((u32)temprature, temp_buffer, 10);
		itoa((u32)fan_duty, speed_buffer, 10);
		
		lcd1.LCD_Cursor_pos(0,0);
		lcd1.LCD_String(7,"Temp = ");
		lcd1.LCD_String(3,temp_buffer);
		lcd1.LCD_String(2,"C");
		
		lcd1.LCD_Cursor_pos(1,0);
		lcd1.LCD_String(6,"Fan = ");
		lcd1.LCD_String(4,speed_buffer);
		lcd1.LCD_String(2,"%");
		_delay_ms(100);
}