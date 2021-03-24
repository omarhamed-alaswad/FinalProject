/*
 * TIMER0.c
 *
 * Created: 3/17/2021 1:27:35 PM
 *  Author: VAIO
 */ 
#include "TIMER0.h"

Uint32t NUM_OVF=0;
Uint32t NUM_CTC=0;
Uint32t INITIAL_VALUE=0;
void TIMER0_INIT(void){
	/*chose mode of operation*/
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	CLR_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
	#endif
/*enable peripheral interrupt*/
/*SET_BIT(TIMSK,TOIE0);*/  /* for normal mode*/
SET_BIT(TIMSK,OCIE0); /*for comp mode*/
/*enable global interrupt*/
sei();
/* SET_BIT(SREG,7);*/
	
}
void TIMER0_START(void){
	#if TIMER0_PRESCALER == PRE_CLK1024
	SET_BIT(TCCR0,CS02);	CLR_BIT(TCCR0,CS01);	SET_BIT(TCCR0,CS00);

#endif

	#if TIMER0_PRESCALER == PRE_CLK64
	CLR_BIT(TCCR0,CS02);	SET_BIT(TCCR0,CS01);	SET_BIT(TCCR0,CS00);

	#endif
	
	#if TIMER0_PRESCALER == PRE_CLK256
	SET_BIT(TCCR0,CS02);	CLR_BIT(TCCR0,CS01);	CLR_BIT(TCCR0,CS00);

	#endif	


#if TIMER0_PRESCALER == PRE_CLK8
CLR_BIT(TCCR0,CS02);	SET_BIT(TCCR0,CS01);	CLR_BIT(TCCR0,CS00);		
	#endif	
}
void TIMER0_STOP(void){
	
	CLR_BIT(TCCR0,CS02);	CLR_BIT(TCCR0,CS01);	CLR_BIT(TCCR0,CS00);
	
}
void TIMER0_OVF_SETDELAY(Uint32t delay){
	#if  WAVE_GENERATION_MODE == NORMAL_MODE
	Uint8t Tick= (1*1024)/16;
	Uint8t Total_Tick=(delay*1000) / Tick;
	NUM_OVF=Total_Tick / 256;
	INITIAL_VALUE=265-(Total_Tick % 256);
	TCNT0=INITIAL_VALUE;
	NUM_OVF++; /*round up*/
	#endif
}

void TIMER0_CTC_SETDELAY(Uint32t delay,Uint8t ocr){
	#if WAVE_GENERATION_MODE == CTC_MODE
	
		Uint8t Tick= (1*1024)/16;
		Uint8t Total_Tick=(delay*1000) / Tick;
		OCR0=ocr;
		NUM_CTC=Total_Tick / OCR0;
		NUM_CTC++; /*round up*/
	#endif
}


void TIMER0_FASTPWM_Init (void){
	/*define directions*/
	SET_BIT(DDRB,PB3);
	/*CHOSE FAST PWM MODE WAVE GENERATION*/
	SET_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00);
	/*CHOOSE IF ITS INVERTING OR NON-INVERTING*/
	#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR0,COM01);	CLR_BIT(TCCR0,COM00);
	#elif PWM_MODE == INVERTING
	SET_BIT(TCCR0,COM01);	SET_BIT(TCCR0,COM00);
	#else #warning "wrong mode"
#endif
	
}

void TIMER0_FASTPWM_SETDUTY(Uint8t dutycycle){
		#if PWM_MODE == NON_INVERTING
		OCR0 = ((256 * dutycycle)/100)-1;
		#elif PWM_MODE == INVERTING
		OCR0 = 256-(((256 * dutycycle)/100)-1);
		#else #warning "wrong mode"
		#endif
}

void TIMER0_FASTPWM_START(void){
	
	SET_BIT(TCCR0,CS02); CLR_BIT(TCCR0,CS01);  CLR_BIT(TCCR0,CS00);
}