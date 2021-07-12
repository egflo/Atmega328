#include "music.h"
#include <util/delay.h>

#define A 114
#define B 101
#define C 95
#define D 85
#define E 76
#define F 72
#define G 64

void
ini_avr(void)
{
	//WDTCR = 15;
}

void
wait_avr(unsigned short msec)
{
	TCCR0 = 2;
	while (msec--) {
		TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 8) * 0.00001);  
		SET_BIT(TIFR, TOV0);
		WDR();
		while (!GET_BIT(TIFR, TOV0));
	}
	TCCR0 = 0;
}


void 
play_note(unsigned short freq, unsigned short duration) {
	
	SET_BIT(DDRB, 3);
	int i;
	for(i = 0; i < duration; i++ )
	{
		SET_BIT(PORTB,3);
		wait_avr(freq);
		CLR_BIT(PORTB,3);
	    wait_avr(freq);		
		
	}
}

void
play_music(Note song[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		play_note(song[i].freq, song[i].duration);
		wait_avr(5000);
	}
	
}

Note song2[SIZE2] =
{
	{C,200},
	{C,200},
	{G,200},
	{G,200},
	{A,200},
	{A,200},
	{G,400},
		
	{F,200},
	{F,200},
	{E,200},
	{E,200},
	{D,200},
	{D,200},
	{C,400},
		
	{G,200},
	{G,200},
	{F,200},
	{F,200},
	{E,200},
	{E,200},
	{D,500},
		
	{G,200},
	{G,200},
	{F,200},
	{F,200},
	{E,200},
	{E,200},
	{D,500},
			
	{C,200},
	{C,200},
	{G,200},
	{G,200},	
	{A,200},
	{A,200},
	{G,500},
			
	{F,200},
	{F,200},
	{E,200},
	{E,200},	
	{D,200},
	{D,200},	
	{C,500}
	
};


Note song1[SIZE] =
	{
		{G, 400},
		{G, 400},	
		{A, 400},
		{G, 400*2},
		{C, 400},		
		{B, 400},			
		
		{D, 400},				
		{D, 400},				
		{E, 400*2},
		{D, 400},
		{A, 400},	
		{G, 400},	
		{D, 400},	
		{D, 400},	
		{D, 400},		
		{B, 400},
		{G, 400},
		{F, 400},		
		{E, 400*2},		
		{C, 400},
		{C, 400},
		{B, 400},
		{G, 400},
		{A, 400},
		{G, 400}
	};
