/*
 * Project_3.c
 *
 * Created: 5/8/2016 10:18:31 AM
 * Author : egflo
 */ 

#include <avr/io.h>
#include "music.h"
#include "music.c"
#include "lcd.c"
#include "lcd.h"
#include <string.h>
#include <util/delay.h>
#include "keypad.h"
#include "keypad.c"

#define C6  661
#define D6  588
#define E6  524
#define F6  495
#define G6  441
#define A6  393
#define B6  350
#define C7  330


int main(void)
{
    /* Replace with your application code */
	ini_lcd();
	
	char status[50];
	char buffer[50];
	char buffer2[50];
    
	while (1) 
	{
		pos_lcd(0,0);
		strcpy(buffer, "Pick #1 or #4 to");
		puts_lcd2(buffer);
		pos_lcd(1,0);
		strcpy(buffer2,"Pick A Song");
		puts_lcd2(buffer2);
		
		
		char key = get_value(get_key());
		_delay_ms(500);
		
		if(key == '1')
		{
			clr_lcd();
			pos_lcd(0,0);
			strcpy(status,"Playing Song 1");
			puts_lcd2(status);
			strcpy(status,"Random Song");
			pos_lcd(1,0);
			puts_lcd2(status);
			play_music(song1, SIZE);
		}
		
		else if(key == '4')
		{
			clr_lcd();
			pos_lcd(0,0);
			strcpy(status,"Playing Song 2");
			puts_lcd2(status);
			strcpy(status,"Twinkle Little *");
			pos_lcd(1,0);
			puts_lcd2(status);
			
			play_music(song2, SIZE2);
		
			
		}
		_delay_ms(500);
		clr_lcd();
		
	}
}

