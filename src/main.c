#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#include "interface/LED.h"
#include "interface/buttons.h"


int main(void)
{
	init_led_indication();
	init_buttons();

	while (1)
	{
		if (button1_press())
		{
			// change band
		}
		if (button2_press())
		{
			// changec channel or auto scan
		}
	}
}

