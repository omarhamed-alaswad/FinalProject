/*
 * TIMER0_CONFIG.h
 *
 * Created: 3/17/2021 1:26:24 PM
 *  Author: VAIO
 */ 

#include "CPU_CONFIGURATION.h"
#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define TCNT0 (*(volatile Uint8t*)(0x52))
#define TCCR0 (*(volatile Uint8t*)(0x53))
#define TIFR (*(volatile Uint8t*)(0x58))
#define TIMSK (*(volatile Uint8t*)(0x59))
#define OCR0  (*(volatile Uint8t*)(0x5C))

#define NORMAL_MODE				0
#define PASECORRECT_MODE		1
#define CTC_MODE				2
#define FAST_PWM_MODE			3

#define NON_INVERTING			1
#define INVERTING				0


#define PRE_NOCLK				0
#define PRE_CLK8				1
#define PRE_CLK64				2
#define PRE_CLK256				3
#define PRE_CLK1024				4


#define WAVE_GENERATION_MODE	CTC_MODE
#define PWM_MODE				NON_INVERTING
#define TIMER0_PRESCALER		PRE_CLK1024


#endif /* TIMER0_CONFIG_H_ */