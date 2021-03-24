/*
 * ADC.h
 *
 * Created: 3/15/2021 3:10:20 PM
 *  Author: VAIO
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_CONFIG.h"

void ADC_Init(Uint8t channel);
Uint16t ADC_Read(void);




#endif /* ADC_H_ */