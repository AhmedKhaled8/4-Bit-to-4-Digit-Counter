#include "SEVEN_SEG.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void init_seven_seg()
{
	DIO_setPINDir('B', 0, 1);
	DIO_setPINDir('B', 1, 1);
	DIO_setPINDir('B', 2, 1);
	DIO_setPINDir('B', 4, 1);
	DIO_setPINDir('B', 5, 1);
	DIO_setPINDir('B', 6, 1);
	DIO_setPINDir('A', 2, 1);
	DIO_setPINDir('A', 3, 1);
		
	DIO_write('B', 0, 0);
	DIO_write('B', 1, 0);
	DIO_write('B', 2, 0);
	DIO_write('B', 4, 0);
		
	DIO_write('B', 5, 0);
	DIO_write('B', 6, 0);
	DIO_write('A', 2, 0);
	DIO_write('A', 3, 0);
}

void write_seven_segment(int number)
{
	int d1, d2, d3, d4; // the digits of the number d1d2d3d4
	int remainder;
	d1 = number / 1000;
	write_number(d1, 1);
	
	remainder = number % 1000;
	d2 = remainder / 100;
	write_number(d2, 2);
	
	remainder = remainder % 100;
	d3 = remainder / 10;
	write_number(d3, 3);
	
	d4 = remainder % 10;
	write_number(d4, 4);
}

void write_number(int number, char location)
{
	// open the enable
	switch(location)
	{
		case 1:
			DIO_write('B', 5, 1);
		break;
		
		case 2:
			DIO_write('B', 6, 1);	
		break;
		
		case 3:
			DIO_write('A', 2, 1);
		break;
		
		case 4:
			DIO_write('A', 3, 1);
		break;
		
		default:
		break;	
	}
	
	// Write the number
	switch(number)
	{
		case 0:
			DIO_write('B', 0, 0);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 0);
		break;
	
		case 1:
			DIO_write('B', 0, 1);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 0);
		break;
		
		case 2:
			DIO_write('B', 0, 0);
			DIO_write('B', 1, 1);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 0);
		break;
		
		case 3:
			DIO_write('B', 0, 1);
			DIO_write('B', 1, 1);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 0);
		break;
		
		case 4:
			DIO_write('B', 0, 0);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 1);
			DIO_write('B', 4, 0);
		break;
		
		case 5:
			DIO_write('B', 0, 1);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 1);
			DIO_write('B', 4, 0);
		break;
		
		case 6:
			DIO_write('B', 0, 0);
			DIO_write('B', 1, 1);
			DIO_write('B', 2, 1);
			DIO_write('B', 4, 0);
		break;
		
		case 7:
			DIO_write('B', 0, 1);
			DIO_write('B', 1, 1);
			DIO_write('B', 2, 1);
			DIO_write('B', 4, 0);
		break;
		
		case 8:
			DIO_write('B', 0, 0);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 1);
		break;
		
		case 9:
			DIO_write('B', 0, 1);
			DIO_write('B', 1, 0);
			DIO_write('B', 2, 0);
			DIO_write('B', 4, 1);
		break;
		
		default:
		break;
	}
	_delay_ms(5);
	
	//close the enable
	switch(location)
	{
		case 1:
		DIO_write('B', 5, 0);
		break;
		
		case 2:
		DIO_write('B', 6, 0);
		break;
		
		case 3:
		DIO_write('A', 2, 0);
		break;
		
		case 4:
		DIO_write('A', 3, 0);
		break;
		
		default:
		break;		
	}
}


