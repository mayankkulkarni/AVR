/*Wave generation in normal mode
 * duty cycle = 25%
 * COM mode is clear on match
 */


#include<avr/io.h>
#include<util/delay.h>

int main()
{
	DDRB = DDRB | (1<<3);
	OCR0 = 64;
	TCNT0 = 0x00;
	TCCR0 = 0x16;
	while(1);
	return 0;
}

