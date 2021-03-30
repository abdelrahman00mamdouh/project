/*
* LCD.c
*
* Created: 2/13/2021 3:28:55 PM
*  Author: Abdelrahman
*/

#include "LCD.h"

void LCD0_Init(void){
	
	#if LCD_MODE == LCD_4BIT_MODE
	/*define direction control pins*/
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_RS,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_RW,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_EN,LCD_OUTPUT);
	/*define direction for data pins*/
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA4,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA5,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA6,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA7,LCD_OUTPUT);
	/*define commands needed to choose for 4-bit mode*/
	LCD0_4Write_CMD(0x33);		/*receiving data*/
	LCD0_4Write_CMD(0x32);		/*define working in 4 bit mode*/
	LCD0_4Write_CMD(0x28);		/*define working in 4 bit mode*/
	LCD0_4Write_CMD(0x02);		/*return home*/
	LCD0_4Write_CMD(0x0C);		/*display on,cursor off*/
	LCD0_4Write_CMD(0x01);		/*clear screen*/
	//LCD0_4Write_CMD(0x1C);		/*increment cursor right*/
	//LCD0_4Write_CMD(0x18);		/*increment cursor left*/
	//LCD0_4Write_CMD(0xC0);		/*write in second line*/
	
	#elif LCD_MODE == LCD_8BIT_MODE
	
	/*define direction control pins*/
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_RS,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_RW,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PORT,LCD_EN,LCD_OUTPUT);
	/*define direction for data pins*/
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA0,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA1,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA2,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA3,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA4,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA5,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA6,LCD_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DTA_PORT,LCD_DTA7,LCD_OUTPUT);
	/*define commands needed to choose for 8-bit mode*/
	LCD0_4Write_CMD(0x33);		/*receiving data*/
	LCD0_4Write_CMD(0x38);		/*define working in 4 bit mode*/
	LCD0_4Write_CMD(0x02);		/*return home*/
	LCD0_4Write_CMD(0x0C);		/*display on,cursor on*/
	LCD0_4Write_CMD(0x01);		/*clear screen*/
	LCD0_4Write_CMD(0x1C);		/*increment cursor right*/
	LCD0_4Write_CMD(0x18);		/*increment cursor left*/
	LCD0_4Write_CMD(0xC0);		/*write in second line*/
	
	#else
	#warning "error,please check mode"
	#endif
	
}

void LCD0_4Write_CMD (Uint8t command){
	
	/*register select pin will select command register*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_RS,LCD_LOW);
	/*read/write pin will be write on LCD*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_RW,LCD_LOW);
	/*be sure that enable is disabled*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*send high nibble of command without changing old PORTA pins (0-3)*/
	PORTA =(command & 0xF0)|(PORTA & 0x0F);
	/*send high pulse for 1 ms*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*send low nibble of the command without changing old PORTA pins (4-7)*/
	PORTA =(command << 4)|(PORTA & 0x0F);
	/*send high pulse for 1 ms*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*wait controller to finish command*/
	_delay_ms(5);
	
}
void LCD0_4Write_CHR (Uint8t character){
	
	/*register select pin will select character register*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_RS,LCD_HIGH);
	/*read/write pin will be write on LCD*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_RW,LCD_LOW);
	/*be sure that enable is disabled*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*send high nibble of character without changing old PORTA pins (0-3)*/
	PORTA =(character & 0xF0)|(PORTA & 0x0F);
	/*send high pulse for 1 ms*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*send low nibble of the command without changing old PORTA pins (4-7)*/
	PORTA =(character << 4)|(PORTA & 0x0F);
	/*send high pulse for 1 ms*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PORT,LCD_EN,LCD_LOW);
	/*wait controller to finish command*/
	_delay_ms(5);
	
}
void LCD0_4WRITE_STRNG (Uint8t* str){
	
	while (*str !='\0')
	{
		LCD0_4Write_CHR(*str);
		_delay_ms(10);
		str++;
	}
}
void LCD0_4WRITE_NMBR (Uint32t number) {
	Uint8t num[10];
	ltoa (number,(Uint8t*)num,10);
	LCD0_4WRITE_STRNG(num);
}
void LCD_4WRITE_CSTM_CHR (Uint8t loc, Uint8t *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD0_4Write_CMD (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)					/* Write 8 byte for generation of 1 character */
		LCD0_4Write_CHR(msg[i]);
	}
}

void LCD0_CLR (void){
	
	LCD0_4Write_CMD(0x01);		/*clear screen*/
	
}

void LCD0_CURS_ON (void){
	
	LCD0_4Write_CMD(0x0E); /*display on,cursor on*/
	
}
void LCD0_CURS_OFF (void){
	
	LCD0_4Write_CMD(0x0C); /*display on,cursor off*/
}
void LCD0_CURS_BLNK (void){
	
	LCD0_4Write_CMD(0x0F); /*display on,cursor BLINK*/

}
void LCD0_DISP_INC_R (void){
	
	LCD0_4Write_CMD(0x1C);		/*increment cursor right*/
	
}
void LCD0_DISP_INC_L (void){
	
	LCD0_4Write_CMD(0x18);		/*increment cursor left*/
	
}

void LCD0_HOME (void){
	LCD0_4Write_CMD(0x02);
}


void LCD0_4B2ND_LINE (void){
	
	LCD0_4Write_CMD(0xC0);			/*write in first line*/
	
}
