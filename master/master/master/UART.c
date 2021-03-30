/*
* UART.c
*
* Created: 3/12/2021 3:40:47 PM
*  Author: karim
*/

#include "UART.h"


void UART_Init(void)
{
	/*Baud rate value variable*/
	Uint16t UBRR_Val = 0;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN);
	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val = (((FRQ) / (16 * BAUDRATE)) - 1);//00000000 11110101 00111001
	UBRRL = UBRR_Val;//00111001
	UBRRH = UBRR_Val >> 8;//11110101
}
void UART_Transmit(Uint8t data)
{
	UDR = data;
	while(GET_BIT(UCSRA, TXC) != 1);
}
Uint8t UART_Receive(void)
{
	while(GET_BIT(UCSRA, RXC) != 1);
	return UDR;
}
void UART_Transmit_Str(Uint8t* str)
{
	while (*str != '\0')
	{
		UART_Transmit(*str);
		str++;
	}
}
Uint8t* UART_Receive_Str(void)
{
	static Uint8t* str;
	while (UART_Receive() != '\0')
	{
		*str = UART_Receive();
		str++;
	}
	return str;
}


UART_Status UART_PRO_Transmit(Uint8t data)
{
	UDR = data;
	while(GET_BIT(UCSRA, TXC) != 1);
	if(GET_BIT(UCSRA, FE) != 1 && GET_BIT(UCSRA, DOR) != 1 && GET_BIT(UCSRA, PE) != 1)
	{
		return UART_OK;
	}
	else
	{
		return UART_NOK;
	}
}
UART_Status UART_PRO_Receive(Uint8t* data)
{
	while(GET_BIT(UCSRA, RXC) != 1);
	*data = UDR;
	if(GET_BIT(UCSRA, FE) != 1 && GET_BIT(UCSRA, DOR) != 1 && GET_BIT(UCSRA, PE) != 1)
	{
		return UART_OK;
	}
	else
	{
		return UART_NOK;
	}
}
