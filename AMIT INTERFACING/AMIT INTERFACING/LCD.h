/*
 * LCD.h
 *
 * Created: 2/23/2021 5:16:51 PM
 *  Author: VAIO
 */ 


#ifndef LCD_H_
#define LCD_H_
/*
1- Macros
2- User-defined Data types
3- Global variables
4- Function prototypes
*/
#include "LCD_CONFIG.h"

void LCD_Init(void); /*initialization*/
void LCD_WRITE_CMD(Uint8t cmd); /* write command inside control reg*/
void LCD_WRITE_DTA(Uint8t dta); /* write data inside data reg*/
void LCD_CLEAR(void);	/* clear data in display screen*/
void LCD_WRITE_STR(Uint8t* str); /* write string on screen */
void LCD_WRITE_NBR(Uint32t numbr);








#endif /* LCD_H_ */