/*
 * pwm.c
 *
 *  Created on: 21-Jul-2015
 *      Author: root
 */


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

void timer(uint8_t o);

int main()
{
	uint8_t cnt = 5;
	DDRB |= (1<<3);
	DDRA |= (1<<2) | (1<<3);
	PORTA |= (1<<2) | (0<<3);
	while(1)
	{
		if(OCR0 <= 255)
		{
		timer(cnt);
		_delay_ms(20);
		cnt++;
		}
		else
		{
			TCCR0 = 0x0;
			PORTB = (0<<3);
			_delay_ms(100);
		}
	}
}

void timer(uint8_t o)
{
	DDRB |= (1<<3);
	OCR0 = o;
	TCCR0 = 0x69;
}

