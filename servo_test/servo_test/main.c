/*
 * servo_test.c
 *
 * Created: 6/20/2016 12:27:10 PM
 * Author : egflo
 */ 


#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "keypad.c"
#include "avr.h"
#include "avr.c"


int main(void)
{
	DDRA = 0x01; //Makes RC0 output pin
	PORTA = 0x00;
	while(1)
	{
		char c = get_value(get_key());
		if(c == 'A')
		{
			//Rotate Motor to 0 degree
			PORTA = 0x01;
			 _delay_us(1000);
			PORTA = 0x00;
			
		}
		
		if(c == 'B')
		{
			//Rotate Motor to 90 degree
			PORTA = 0x01;
			 _delay_us(1500);
			PORTA = 0x00;				
		}
		
		if(c == 'C')
		{
			//Rotate Motor to 180 degree
			PORTA = 0x01;
			_delay_us(2000);
			PORTA = 0x00;			
			
		}


	}
}
