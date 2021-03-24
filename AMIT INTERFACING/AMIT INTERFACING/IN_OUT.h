/*
 * IN_OUT.h
 *
 * Created: 2/3/2021 5:49:34 PM
 *  Author: VAIO
 */ 


#ifndef IN_OUT_H_
#define IN_OUT_H_
/*Macros*/
#include "CPU_CONFIGURATION.h"
/*Buzzer functions*/
void BUZZER_Init(void);
void BUZZER_ON(void);
void BUZZER_OFF(void);
void BUZZER_TGL(void);
/*Relay functions*/
void RELAY_Init(void);
void RELAY_ON(void);
void RELAY_OFF(void);
void RELAY_TGL(void);

#endif /* IN_OUT_H_ */