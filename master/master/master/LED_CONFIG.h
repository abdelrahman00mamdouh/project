/*
 * LED_CONFIG.h
 *
 * Created: 2/6/2021 5:10:08 PM
 *  Author: Abdelrahman
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

/*
1-macros
2-renaming port names
3-renaming pin names
4-renaming status
*/

#include "CPU_CONFIGURATION.h" 

/*led 0*/


#define  led0_port	DIO_PORTC
#define  led0_pin	DIO_PIN2
#define  led0_output DIO_PIN_OUTPUT
#define  led0_HIGH	DIO_PIN_HIGH
#define  led0_LOW	DIO_PIN_LOW

/*led 1*/

#define  led1_port	DIO_PORTC
#define  led1_pin	DIO_PIN7
#define	 led1_output DIO_PIN_OUTPUT
#define  led1_HIGH	DIO_PIN_HIGH
#define  led1_LOW	DIO_PIN_LOW

/*led 2*/

#define  led2_port	DIO_PORTD
#define  led2_pin	DIO_PIN3
#define	 led2_output DIO_PIN_OUTPUT
#define  led2_HIGH	DIO_PIN_HIGH
#define  led2_LOW	DIO_PIN_LOW


#endif /* LED_CONFIG_H_ */