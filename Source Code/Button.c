#include "DIO.h"
#include "Button.h"


void Button_init(unsigned char port_name, unsigned char pin_number)
{
    // set button on port "port_name" on pin "pin_number" to be input
    DIO_setPINDir(port_name, pin_number, 0); 
}

unsigned char Button_read(unsigned char port_name, unsigned char pin_number)
{
    unsigned char button_value = 0;
    button_value = DIO_read(port_name, pin_number);
    return button_value;
}