/*
 * CPU_CONFIGURATION.h
 *
 * Created: 2/6/2021 2:39:25 PM
 *  Author: Abdelrahman
 */ 


#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

#undef F_CPU	/*Neglect internal oscillator*/
#define F_CPU 16000000	/*define external oscillator*/

#include <avr/io.h>	/*predefined - define input &output*/
#include <util/delay.h>		/*predefined - delay function*/
#include <avr/interrupt.h>	/*predefined - interrupt vectors*/

#include "Bit_Math.h"	/*user defined - bit manipulation*/
#include "Std_Types.h"	/*user defined - standard types*/
#include "DIO.h"


#endif /* CPU_CONFIGURATION_H_ */