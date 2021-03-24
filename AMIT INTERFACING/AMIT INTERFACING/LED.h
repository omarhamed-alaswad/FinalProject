/*
 * LED.h
 *
 * Created: 1/31/2021 5:05:02 PM
 *  Author: VAIO
 */ 


#ifndef LED_H_
#define LED_H_
#include "LED_CONFIG.h"

/*
1- Macros
2- User-defined Data types
3- Global variables
4- Function prototypes
*/
#include "LED_CONFIG.h"
/*LED-0 Functions*/
void LED0_Init(void);
void LED0_ON(void);
void LED0_OFF(void);
void LED0_TGL(void);
/*LED-1 Functions*/
void LED1_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_TGL(void);
/*LED-2 Functions*/
void LED2_Init(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_TGL(void);
#endif /* LED_H_ */