/*
 * DIO_CONFIG.h
 *
 * Created: 2/12/2021 2:10:05 PM
 *  Author: Abdelrahman
 */ 

/*
1-macros
2-address of registers
3-renaming port names
4-renaming pin names
5-renaming status
*/




/*DIO address registers*/
#ifndef ATMEGA_REGISTER_SUMMARY_H_
#define ATMEGA_REGISTER_SUMMARY_H_

#include "CPU_CONFIGURATION.h" /*macros*/
/*
#define PORTA (*(volatile uint8_t*)(0x3B)) 
#define DDRA  (*(volatile uint8_t*)(0x3A)) 
#define PINA  (*(volatile uint8_t*)(0x39)) 

#define PORTB (*(volatile uint8_t*)(0x38)) 
#define DDRB  (*(volatile uint8_t*)(0x37)) 
#define PINB  (*(volatile uint8_t*)(0x36)) 

#define PORTC (*(volatile uint8_t*)(0x35)) 
#define DDRC  (*(volatile uint8_t*)(0x34)) 
#define PINC  (*(volatile uint8_t*)(0x33)) 

#define PORTD (*(volatile uint8_t*)(0x32)) 
#define DDRD  (*(volatile uint8_t*)(0x31)) 
#define PIND  (*(volatile uint8_t*)(0x30)) 
*/

/*renaming ports*/


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


/*renaming pin names*/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


/*renaming pin status*/
#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1


/*renaming port status*/
#define DIO_PORT_INPUT  0x00 //0b00000000
#define DIO_PORT_OUTPUT 0xFF //0b11111111

#define DIO_PORT_LOW	0x00 //0b00000000
#define DIO_PORT_HIGH	0xFF //0b11111111


#endif /* DIO_CONFIG_H_ */