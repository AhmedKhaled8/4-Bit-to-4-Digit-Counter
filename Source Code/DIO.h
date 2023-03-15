#ifndef DIO_H_
#define DIO_H_

void DIO_setPINDir(unsigned char port_name, unsigned char pin_number, unsigned char direction);
void DIO_write(unsigned char port_name, unsigned char pin_number, unsigned char output_value);
unsigned char DIO_read(unsigned char port_name, unsigned char pin_number);
void DIO_toggle(unsigned char port_name, unsigned char pin_number);
void DIO_set_port_direction(unsigned char port_name, unsigned char direction);
void DIO_write_port(unsigned char portname,unsigned char portvalue);
unsigned char DIO_read_port(unsigned char port_name);
void DIO_write_low_nibble(unsigned char port_name, unsigned char value);
void DIO_write_high_nibble(unsigned char port_name, unsigned char value);

#endif