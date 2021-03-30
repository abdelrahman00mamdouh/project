/*
 * DIO.h
 *
 * Created: 2/12/2021 2:10:36 PM
 *  Author: Abdelrahman
 */ 

/*
1-macros
2-user defined data types(if exist){struct,uniuon,enum}
3-global variables (if exist)
4-functions prototypes
*/

#ifndef DIO_H_
#define DIO_H_

#include "DIO_CONFIG.h"

/*pin state*/


void DIO_SETPIN_DIRECTION	(Uint8t port,Uint8t pin,Uint8t direction);
void DIO_SETPIN_VALUE		(Uint8t port,Uint8t pin,Uint8t status);
void DIO_TGLPIN			(Uint8t port,Uint8t pin);
Uint8t DIO_READPIN_VALUE	(Uint8t port,Uint8t pin);

/*port state*/

void DIO_SETPORT_DIRECTION	(Uint8t port,Uint8t direction);
void DIO_SETPORT_VALUE		(Uint8t port,Uint8t status);
void DIO_TGLEPORT			(Uint8t port);
Uint8t DIO_READPORT_VALUE	(Uint8t port);

/*pull up resistor*/
void DIO_SET_PULL_UP	(Uint8t port,Uint8t pin);

#endif /* DIO_H_ */