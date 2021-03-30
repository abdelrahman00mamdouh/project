/*
 * slave.c
 *
 * Created: 3/28/2021 11:52:47 PM
 * Author : Abdelrahman
 */ 

#include "SPI.h"
#include "LED.h "
#include "LCD.h"
#include "MOTOR.h"

int main(void)
{
	SPI_Init();
	led2_Init();
	LCD0_Init();
	MOTOR1_Init();
	MOTOR1_ENABLE();
	Uint8t data=0;
	
    /* Replace with your application code */
    while (1) 
	
    {	
		
		SPI_Receive();
	    data=SPI_Receive();
	   switch (data){
		   case 7:
			LCD0_4WRITE_STRNG("led on");
		    led2_ON();
			_delay_ms(100);
			LCD0_CLR();
	    break;
		 case 8:
			 LCD0_4WRITE_STRNG("led off");
			 led2_OFF();
			_delay_ms(100);
			LCD0_CLR();
		break;
		 	case 10:
			 	 LCD0_4WRITE_STRNG("motor one on");
				  MOTOR1_CW();
			 	 _delay_ms(100);
			 	 LCD0_CLR();
		 	break;
			  	case 11:
				  	 LCD0_4WRITE_STRNG("motor one off");
				  	MOTOR1_DISABLE();
				  	 _delay_ms(100);
				  	 LCD0_CLR();
			  	break;
    }
		data=0;
	}
	}

