/*
 * Music_test.c
 *
 * Created: 5/8/2016 3:41:22 PM
 * Author : egflo
 */ 

#define F_CPU 8000000lu

#include <avr/io.h>
#include <util/delay.h>


#define SPEAKER_PORT	PORTB
#define SPEAKER_DDR  	DDRB
#define SPEAKER_PIN  	3

void PLAYNOTE(float duration, float frequency);

int main(void)
{

	PLAYNOTE(400,880);
	PLAYNOTE(400,932);
	PLAYNOTE(400,988);
	PLAYNOTE(400,1047);
	PLAYNOTE(400,1109);
	PLAYNOTE(400,1175);
	PLAYNOTE(400,1244);
	PLAYNOTE(400,1319);
	PLAYNOTE(400,1397);
	PLAYNOTE(400,1480);
	PLAYNOTE(400,1568);
	PLAYNOTE(400,1660);

}



void PLAYNOTE(float duration, float frequency)
{

	long int i,cycles;
	float half_period;
	float wavelength;
	
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	half_period = wavelength/2;

	
	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0;i<cycles;i++)
	{
		_delay_ms(half_period);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(half_period);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}