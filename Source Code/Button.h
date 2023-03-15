#ifndef BUTTON_H_
#define BUTTON_H_

void Button_init(unsigned char port_name, unsigned char pin_number);
unsigned char Button_read(unsigned char port_name, unsigned char pin_number);

#endif /* BUTTON_H_ */