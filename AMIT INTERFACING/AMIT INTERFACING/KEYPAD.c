/*
 * KEYPAD.c
 *
 * Created: 2/24/2021 4:26:42 PM
 *  Author: VAIO
 */ 

#include "KEYPAD.h"

const Uint8t KEYPAD[4][4] =
{
	{'/','=','0','*'},
	{'C','9','8','7'},
	{'+','6','5','4'},
	{'-','3','2','1'}
};


void KEYPAD_Init(void)/*Initialize keypad*/
{
	/*Define direction for output pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN0, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN1, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN2, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_OUT_PIN3, KEYPAD_OUTPUT);
	/*Define direction for input pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN0, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN1, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN2, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_INP_PIN3, KEYPAD_INPUT);
	/*Activate internal pull-up resistor*/
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_INP_PIN0);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_INP_PIN1);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_INP_PIN2);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_INP_PIN3);
	/*All output should be normally high*/
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_OUT_PIN0, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_OUT_PIN1, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_OUT_PIN2, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_OUT_PIN3, KEYPAD_HIGH);
}
Uint8t KEYPAD_READ(void)/*Read keypad value*/
{
	Uint8t LOC_COL = 0; /*Counter for columns*/
	Uint8t LOC_ROW = 0; /*Counter for rows*/
	Uint8t temp = 0;    /*To get reading from keypad*/
	Uint8t val = 0;     /*To check value inside array 2D*/
	for(LOC_COL = COL_INIT; LOC_COL <= COL_FINAL; LOC_COL++)
	{
		DIO_SetPin_Value(KEYPAD_PORT, LOC_COL, KEYPAD_LOW);
		for (LOC_ROW = ROW_INIT; LOC_ROW <= ROW_FINAL; LOC_ROW++)
		{
			temp = DIO_GetPin_Value(KEYPAD_PORT, LOC_ROW);
			if(temp == 0)/*Active LOW*/
			{
				val = KEYPAD[LOC_ROW - ROW_INIT][LOC_COL - COL_INIT];
				while (temp == 0)
				{
					temp = DIO_GetPin_Value(KEYPAD_PORT, LOC_ROW);
				}
				_delay_ms(10);
			}
		}
		DIO_SetPin_Value(KEYPAD_PORT, LOC_COL, KEYPAD_HIGH);
	}
	return val;
}