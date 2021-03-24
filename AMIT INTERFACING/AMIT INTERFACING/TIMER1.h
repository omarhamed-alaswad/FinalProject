/*
 * TIMER1.h
 *
 * Created: 3/18/2021 2:16:50 AM
 *  Author: VAIO
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_CONFIG.h"

void TIMER1_FASTPWM_ICR_Init(void);
void TIMER1_FASTPWM_ICR_SETDUTY(Uint8t dutycycle);
void TIMER1_FASTPWM_ICR_START(void);



#endif /* TIMER1_H_ */