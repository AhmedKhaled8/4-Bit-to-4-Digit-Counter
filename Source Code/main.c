#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "SEVEN_SEG.h"
#include "Button.h"

int main(void)
{
	int number = 0;
	init_seven_seg();
	Button_init('D', 3);
	char button_reading;
    while (1) 
    {
		button_reading = Button_read('D', 3);
		if (button_reading == 1)
		{
			number++;
			if (number == 100)
			{
				number = 0;
			}
			_delay_ms(300);
		}
		write_seven_segment(number);
    }
}

