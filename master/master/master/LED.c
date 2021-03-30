/*
 * LED.c
 *
 * Created: 2/6/2021 5:11:23 PM
 *  Author: Abdelrahman
 */ 

/*
1-macros
2-implementation of functions
*/

#include "LED.h"

void led0_Init	(void){
	
	/*define direction*/
	//SET_BIT (led0_DDR,led0_pin); 
	DIO_SETPIN_DIRECTION (led0_port,led0_pin,led0_output);
}
void led0_ON	(void){
	/*activate pin*/
	//SET_BIT (led0_port,led0_pin);
	DIO_SETPIN_VALUE (led0_port,led0_pin,led0_output);
}
void led0_OFF	(void){
	/*deactivate pin*/
	//CLR_BIT(led0_port,led0_pin);
	DIO_SETPIN_VALUE (led0_port,led0_pin,led0_output);
}
void led0_TGL	(void){
	/*toggle */
	//TGL_BIT(led0_port,led0_pin);
	DIO_TGLPIN(led0_port,led0_pin);
}


void led1_Init	(void){
		/*define direction*/
		//SET_BIT (led1_DDR,led1_pin);
		DIO_SETPIN_DIRECTION (led1_port,led1_pin,led1_output);
}
void led1_ON	(void){
	/*activate pin*/
	//SET_BIT (led1_port,led1_pin);
}
void led1_OFF	(void){
	/*deactivate pin*/
	//CLR_BIT(led1_port,led1_pin);
}
void led1_TGL	(void){
	/*toggle */
	//TGL_BIT(led1_port,led1_pin);
	DIO_TGLPIN(led1_port,led1_pin);
}

void led2_Init	(void){
		/*define direction*/
		//SET_BIT (led2_DDR,led2_pin);
		DIO_SETPIN_DIRECTION (led2_port,led2_pin,led2_output);
}
void led2_ON	(void){
		/*activate pin*/
	//	SET_BIT (led2_port,led2_pin);
}
void led2_OFF	(void){
	/*deactivate pin*/
	//CLR_BIT(led2_port,led2_pin);
}
void led2_TGL	(void){
	/*toggle */
	//TGL_BIT(led2_port,led2_pin);
	DIO_TGLPIN(led2_port,led2_pin);
}