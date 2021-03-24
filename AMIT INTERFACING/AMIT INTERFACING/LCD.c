/*
 * LCD.c
 *
 * Created: 2/23/2021 5:17:01 PM
 *  Author: VAIO
 */ 

/*
1- MACROS
2-IMPLEMENTATION OF FUNCTION
*/
#include "LCD.h"

void LCD_Init(void){
	/*define directions for command pins*/
	DIO_SetPin_Direction(LCD_CMD_PORT,LCD_RS,LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CMD_PORT,LCD_RW,LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CMD_PORT,LCD_EN,LCD_OUTPUT);
	
	/*define directions for data pins*/
	DIO_SetPin_Direction(LCD_DATA_PORT,LCD_D4,LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT,LCD_D5,LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT,LCD_D6,LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT,LCD_D7,LCD_OUTPUT);
	
	_delay_ms(100); /*LCD CONTROLLER IS SLOWER THAN MICROCONTROLLER SPEED*/
	
	
	LCD_WRITE_CMD(0x02);
	LCD_WRITE_CMD(0x33);
	LCD_WRITE_CMD(0x32);
	LCD_WRITE_CMD(0x28);
	LCD_WRITE_CMD(0x0C);
	LCD_WRITE_CMD(0x01);
	LCD_WRITE_CMD(0x06);
}


void LCD_WRITE_CMD(Uint8t cmd){
	/* RS IS LOGIC 0 TO WRITE INSIDE CONTROL REGISTER*/
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_RS,LCD_LOW);
	
	/*RW IS LOGIC 0 TO WRITE INSIDE LCD*/
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_RW,LCD_LOW);
	
	/*TO BE SURE OF ENABLE BEFORE START OPERATION*/
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	
	/*SEND HIGH NIPPLE OF OF COMMAND (4 BITS LIKE 7 SEG)*/
	PORTA= (cmd & 0xF0) | (PORTA & 0x0F);
	
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	
	/*SEND LOW NIPPLE OF OF COMMAND (4 BITS LIKE 7 SEG)*/
	PORTA = (cmd << 4) | (PORTA & 0x0F);
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	
	/* DELAY FOR 2 MILLISECONDS*/
	_delay_ms(2);
		
}

void LCD_WRITE_DTA(Uint8t dta){
		/* RS IS LOGIC 0 TO WRITE INSIDE DATA REGISTER*/
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_RS,LCD_HIGH);
		
		/*RW IS LOGIC 0 TO WRITE INSIDE LCD*/
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_RW,LCD_LOW);
		
		/*TO BE SURE OF ENABLE BEFORE START OPERATION*/
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
		
		/*SEND HIGH NIPPLE OF OF COMMAND (4 BITS LIKE 7 SEG)*/
		PORTA= (dta & 0xF0) | (PORTA & 0x0F);
		
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
		
		/*SEND LOW NIPPLE OF OF COMMAND (4 BITS LIKE 7 SEG)*/
		PORTA = (dta << 4) | (PORTA & 0x0F);
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CMD_PORT,LCD_EN,LCD_LOW);
		
		/* DELAY FOR 2 MILLISECONDS*/
		_delay_ms(2);
}

void LCD_CLEAR(void){
	
	LCD_WRITE_CMD(0x01);
	
	
}

void LCD_WRITE_STR(Uint8t* str){
	
	
	while(*str != '\0')
	{
		LCD_WRITE_DTA(*str);
		str++;
	}
	}
	
void LCD_WRITE_NBR(Uint32t numbr)
{
	Uint8t num[10];
	ltoa(numbr, (Uint8t*)num, 10);
	LCD_WRITE_STR(num);
}
