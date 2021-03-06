/*
 * SEV_SEG.h
 *
 * Created: 2/22/2021 2:25:46 PM
 *  Author: VAIO
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_

/* WHAT SHIULD I DO HERE:
1-MACROS
2-USER-DEFINED DATA TYPES (STRUCTURE, UNION,ENUMERATION)
3- GLOBAL VARIABLES (IF EXSIT)
4-FUNCTION PROTOTYPES
*/

#include "SEV_SEG_CONFIG.h"

void SEVSEG_Init(void); /*INITIALIZATION FUNCTION OF MODULE TO DEFINE PIN DIRECTION*/
void SEVSEG_ENB1(void); /* ENABLE FIRST SEVEN SEGMENT*/
void SEVSEG_DIS1(void); /*DISABLE FIRST SEVEN SEGMENT*/
void SEVSEG_ENB2(void);	/*ENABLE SECOND SEVEN SEGMENT*/
void SEVSEG_DIS2(void);	/*DISABLE SECOND SEVEN SEGMENT*/
void SEVSEG_DISPLAY(Uint8t data); /* DISPLAY VALUE FROM 0 TO 99 */
#endif /* SEV_SEG_H_ */