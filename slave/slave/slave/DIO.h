/*
 * DIO.h
 *
 * Created: 3/24/2021 12:04:16 AM
 *  Author: VAIO
 */ 


#ifndef DIO_H_
#define DIO_H_



/*Macros*/
#include "DIO_CONFIG.h"
#include "CPU_CONFIGURATION.h"
/*Function Prototypes*/
void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction);
/*
If direction is defined as output
Set - Clear
Toggle
*/
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t value);
void DIO_TglPin_Value(Uint8t port, Uint8t pin);
/*
If Direction defined as input
Read(Get value)
*/
Uint8t DIO_GetPin_Value(Uint8t port, Uint8t pin);

/*ACTIVATE INTERNAL PULL-UP RESISTOR*/
void DIO_SetPullUp(Uint8t port, Uint8t pin);


#endif /* DIO_H_ */