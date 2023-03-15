#include <avr/io.h>
#include "DIO.h"
#include "STD_MACROS.h"

void DIO_setPINDir(unsigned char port_name, unsigned char pin_number, unsigned char direction)
{
    switch(port_name)
    {
        case 'A':
            if(direction == 1)
            {
                SET_BIT(DDRA, pin_number);
            }
            else
            {
                CLR_BIT(DDRA, pin_number);
            }
        break;
        
        case 'B':
            if(direction == 1)
            {
                SET_BIT(DDRB, pin_number);
            }
            else
            {
                CLR_BIT(DDRB, pin_number);
            }
        break;


        case 'C':
            if(direction == 1)
            {
                SET_BIT(DDRC, pin_number);
            }
            else
            {
                CLR_BIT(DDRC, pin_number);
            }
        break;


        case 'D':
            if(direction == 1)
            {
                SET_BIT(DDRD, pin_number);
            }
            else
            {
                CLR_BIT(DDRD, pin_number);
            }
        break;

        default:
        break;

    }
}

void DIO_write(unsigned char port_name, unsigned char pin_number, unsigned char output_value)
{
    switch(port_name)
    {
        case 'A':
            if(output_value == 1)
            {
                SET_BIT(PORTA, pin_number);
            }
            else
            {
                CLR_BIT(PORTA, pin_number);
            }
        break;

        case 'B':
            if(output_value == 1)
            {
                SET_BIT(PORTB, pin_number);
            }
            else
            {
                CLR_BIT(PORTB, pin_number);
            }
        break;

        case 'C':
            if (output_value == 1)
            {
                SET_BIT(PORTC, pin_number);
            }
            else
            {
                CLR_BIT(PORTC, pin_number);
            }
        break;

        case 'D':
            if(output_value == 1)
            {
                SET_BIT(PORTD, pin_number);
            }
            else
            {
                CLR_BIT(PORTD, pin_number);
            }
        break;

        default:
        break;
    }
}


unsigned char DIO_read(unsigned char port_name, unsigned char pin_number)
{
    unsigned char return_value = 0;
    switch(port_name)
    {
        case 'A':
            return_value = READ_BIT(PINA, pin_number);
        break;

        case 'B':
            return_value = READ_BIT(PINB, pin_number);    
        break;

        case 'C':
            return_value = READ_BIT(PINC, pin_number);
        
        case 'D':
            return_value = READ_BIT(PIND, pin_number);

        default:
        break;
    }
    return return_value;
}

void DIO_toggle(unsigned char port_name, unsigned char pin_number)
{
    switch(port_name)
    {
        case 'A':
            TOG_BIT(PORTA, pin_number);
        break;

        case 'B':
            TOG_BIT(PORTB, pin_number);
        break;

        case 'C':
            TOG_BIT(PORTC, pin_number);
        break;

        case 'D':
            TOG_BIT(PORTD, pin_number);
        break;

        default:
        break;
    }
}

void DIO_set_port_direction(unsigned char port_name, unsigned char direction)
{
    switch(port_name)
    {
        case 'A':
            DDRA = direction;
        break;
        
        case 'B':
            DDRB = direction;
        break;

        case 'C':
            DDRC = direction;
        break;

        case 'D':
            DDRD = direction;
        break;

        default:
        break;
    }
}
void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;
		default:
		break ;
	}
}

unsigned char DIO_read_port(unsigned char port_name)
{
    unsigned char return_value = 0;
    switch(port_name)
    {
        case 'A':
            return_value = PINA;
        break;

        case 'B':
            return_value = PINB;
        break;

        case 'C':
            return_value = PINC;
        break;

        case 'D':
            return_value = PIND;
        break;

        default:
        break;
    }
    return return_value;
}


void DIO_write_low_nibble(unsigned char port_name, unsigned char value)
{
    value &= 0x0f;
    switch(port_name)
    {
        case 'A':
            PORTA &= 0xf0;
            PORTA |= value;
        break;

        case 'B':
            PORTB &= 0xf0;
            PORTB |= value;
        break;

        case 'C':
            PORTC &= 0xf0;
            PORTC |= value;
        break;

        case 'D':
            PORTD &= 0xf0;
            PORTD |= value;
        break;

        default:
        break;
    }

}

void DIO_write_high_nibble(unsigned char port_name, unsigned char value)
{
    value <<= 4;
    switch(port_name)
    {
        case 'A':
            PORTA &= 0x0f;
            PORTA |= value;
        break;

        case 'B':
            PORTB &= 0x0f;
            PORTB |= value;
        break;

        case 'C':
            PORTC &= 0x0f;
            PORTC |= value;
        break;

        case 'D':
            PORTD &= 0x0f;
            PORTD |= value;
        break;

        default:
        break;
    }

}