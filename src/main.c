#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#include "interface/LED.h"


int main(void)
{
	init_led_indication();



	int i = 1;
	while (1)
	{
		set_ch_led(i);
		set_rx_module_led(i % 2);
		set_band_led('A');
		_delay_ms(100);
		i++;
		if (i > 8) i = 1;
	}
}

