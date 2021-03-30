/*
 * master.c
 *
 * Created: 3/28/2021 11:49:19 PM
 * Author : Abdelrahman
 */ 



#include "UART.h"
#include "SPI.h"
#include "led.h"

int main(void)
 { Uint8t data=0;
	UART_Init();
	SPI_Init();
	
	while (1)
	{
		data=UART_Receive();
		if(data=='1'){
			SPI_Transmit(7);
		}
			else if(data=='2'){
				SPI_Transmit(8);
			}
			else if(data=='5'){
				SPI_Transmit(10);
			}
			else if(data=='6'){
				SPI_Transmit(11);
			}
		data=0;
	    
    }
	return 0;
}

