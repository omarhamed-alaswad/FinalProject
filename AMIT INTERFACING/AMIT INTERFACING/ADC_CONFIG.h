/*
 * ADC_CONFIG.h
 *
 * Created: 3/15/2021 3:10:09 PM
 *  Author: VAIO
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#include "CPU_CONFIGURATION.h"
/*DEFINE ADC REGISTERS ADRESES IN MEMORY*/
#define	ADMUX (*(volatile Uint8t*)(0x27))
#define	ADCSRA (*(volatile Uint8t*)(0x26))
#define	ADCH (*(volatile Uint8t*)(0x25))
#define	ADCL (*(volatile Uint8t*)(0x24))
#define	ADC (*(volatile Uint16t*)(0x24))

/*define names for channels*/

#define ADC0 0
#define  ADC1 1
#define  ADC2 2
#define ADC3 3
#define  ADC4 4
#define  ADC5 5
#define ADC6 6
#define  ADC7 7
#define  ADC8 8
#endif /* ADC_CONFIG_H_ */