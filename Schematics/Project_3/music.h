#ifndef __music__
#define __music__

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>

#define XTAL_FRQ 8000000lu
#define SIZE 25
#define SIZE2 44

#define SET_BIT(p,i) ((p) |=  (1 << (i)))
#define CLR_BIT(p,i) ((p) &= ~(1 << (i)))
#define GET_BIT(p,i) ((p) &   (1 << (i)))

#define convert(freq) (((1/freq)/2)* 100000)

#define WDR() asm volatile("wdr"::)
#define NOP() asm volatile("nop"::)
#define RST() for(;;);


typedef struct {
	unsigned short freq;
	unsigned short duration;
} Note;

extern Note song1[SIZE];
extern Note song2[SIZE2];

void ini_avr(void);
void wait_avr(unsigned short msec);
void delay_us(unsigned short count);
void play_note(unsigned short freq, unsigned short duration);
void play_music(Note song[], int length);


#endif