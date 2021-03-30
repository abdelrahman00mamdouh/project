/*
 * LCD.h
 *
 * Created: 2/13/2021 3:28:26 PM
 *  Author: Abdelrahman
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFIG.h"

void LCD0_Init(void);

void LCD0_4Write_CMD (Uint8t command);
void LCD0_4Write_CHR (Uint8t character);
void LCD0_4WRITE_STRNG (Uint8t* str);
void LCD0_4WRITE_NMBR (Uint32t number) ;
void LCD_4WRITE_CSTM_CHR (Uint8t loc, Uint8t *msg);

void LCD0_CLR (void);

void LCD0_CURS_ON (void);
void LCD0_CURS_OFF (void);
void LCD0_CURS_BLNK (void);

void LCD0_HOME (void);

void LCD0_DISP_INC_R (void);
void LCD0_DISP_INC_L (void);

void LCD0_4B2ND_LINE (void);


#endif /* LCD_H_ */