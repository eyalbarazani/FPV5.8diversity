#include <avr/io.h>

void init_buttons()
{
	DDRD &= ~(1 << PORTD5);
	DDRB &= ~(1 << PORTB0);
	PORTD |= (1 << PORTD5);
	PORTB |= (1 << PORTB0)
}

uint8_t button1_press()
{
	if (PIND & (1 << PORTD5))
	{
		return 0;
	}
	return 1;
}

uint8_t button2_press()
{
	if (PINB & (1 << PORTB0))
	{
		return 0;
	}
	return 1;
}