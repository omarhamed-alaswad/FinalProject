/*
 * CPU_CONFIGURAION.h
 *
 * Created: 1/29/2021 3:36:23 PM
 *  Author: VAIO
 */ 


#ifndef CPU_CONFIGURAION_H_
#define CPU_CONFIGURAION_H_

#undef  F_CPU /*To cancel using internal oscillator*/
#define F_CPU 16000000/*To define external oscillator*/

#include <avr/io.h>/*Library for all input and output and interrupts defined*/
#include <util/delay.h>/*To define delay function*/
#include <avr/interrupt.h>/*To define ISR functions*/

#include "STD_TYPES.h"/*Standard data types*/
#include "BIT_MATH.h"/*Bit math macros like functions*/




#endif /* CPU_CONFIGURAION_H_ */