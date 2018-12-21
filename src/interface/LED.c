#include <avr/io.h>

/* LED pinout
RX1 - PORTC0
RX2 - PORTC1
BAND - PORTC2
CH1 - PORTC3
CH2 - PORTC4
CH3 - PORTC5
CH4 - PORTD0
CH5 -	PORTD1
CH6 - PORTD2
CH7 -PORTD3
CH8 - PORTD4 */

void init_led_indication()
{
	DDRC ^= (1 << PORTC1) | (1 << PORTC0); // rx module indication
	DDRC ^= (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5);
	DDRD ^= (1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4);
}

void set_ch_led(int channel)
{
	PORTC &= ~(1 << PORTC3) & ~(1 << PORTC4) & ~(1 << PORTC5);
	PORTD &= ~(1 << PORTD0) & ~(1 << PORTD1) & ~(1 << PORTD2) & ~(1 << PORTD3) & ~(1 << PORTD4);
	switch (channel)
	{
		case 1:
		PORTC |= (1 << PORTC3);
		break;
		case 2:
		PORTC |= (1 << PORTC4);
		break;
		case 3:
		PORTC |= (1 << PORTC5);
		break;
		case 4:
		PORTD |= (1 << PORTD0);
		break;
		case 5:
		PORTD |= (1 << PORTD1);
		break;
		case 6:
		PORTD |= (1 << PORTD2);
		break;
		case 7:
		PORTD |= (1 << PORTD3);
		break;
		case 8:
		PORTD |= (1 << PORTD4);
		break;
	}
}

void set_band_led(char band)
{
	PORTC ^= 1 << PORTC2;
	switch (band)
	{
		case 'A':
		break;
		case 'B':
		break;
		case 'E':
		break;
		case 'F':
		break;
	}
}

void set_rx_module_led(int n)
{
	if (n == 1)
	{
		PORTC &= ~(1 << PORTC0);
		PORTC |= 1 << PORTC1;
		return;
	}
	else
	{
		PORTC &= ~(1 << PORTC1);
		PORTC |= 1 << PORTC0;
	}
}