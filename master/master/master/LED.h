/*
 * LED.h
 *
 * Created: 2/6/2021 5:11:01 PM
 *  Author: Abdelrahman
 */ 


#ifndef LED_H_
#define LED_H_

/*
1-macros
2-user defined data types(if exist){struct,uniuon,enum}
3-global variables (if exist)
4-functions prototypes
*/

#include "LED_CONFIG.h"

void led0_Init	(void);
void led0_ON	(void);
void led0_OFF	(void);
void led0_TGL	(void);

void led1_Init	(void);
void led1_ON	(void);
void led1_OFF	(void);
void led1_TGL	(void);

void led2_Init	(void);
void led2_ON	(void);
void led2_OFF	(void);
void led2_TGL	(void);

#endif /* LED_H_ */