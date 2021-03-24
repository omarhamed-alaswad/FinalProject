/*
 * TIMER0.h
 *
 * Created: 3/17/2021 1:27:13 PM
 *  Author: VAIO
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_CONFIG.h"

void TIMER0_INIT(void);
void TIMER0_START(void);
void TIMER0_STOP(void);
void TIMER0_OVF_SETDELAY(Uint32t delay);
void TIMER0_CTC_SETDELAY(Uint32t delay,Uint8t ocr);
void TIMER0_FASTPWM_Init (void);
void TIMER0_FASTPWM_SETDUTY(Uint8t dutycycle);
void TIMER0_FASTPWM_START(void);






#endif /* TIMER0_H_ */