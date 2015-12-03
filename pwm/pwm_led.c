/*
 * pwm_led.c
 *
 *  Created on: 20-Jul-2015
 *      Author: root
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initPWM()
{
	TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	DDRB |= (1<<PB3);
}

void setDuty(uint8_t duty)
{
	OCR0 = duty;
}

int main(void)
{
	uint8_t bright = 0;
	initPWM();
	while(1)
	{
		for(bright = 0;bright < 255;bright++)
		{
			setDuty(bright);
			_delay_loop_2(3200);
		}
		for(bright = 255;bright > 0;bright--)
		{
			setDuty(bright);
			_delay_loop_2(3200);
		}
	}
}


