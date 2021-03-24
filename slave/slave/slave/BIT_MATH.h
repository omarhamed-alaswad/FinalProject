/*
 * BIT_MATH.h
 *
 * Created: 3/24/2021 12:07:34 AM
 *  Author: VAIO
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define SET_BIT(REG,BIT)	 REG |= (1<<BIT)   /*Put Logic(1) inside specific bit*/
#define CLR_BIT(REG,BIT)	 REG &=~ (1<<BIT)  /*Put Logic(0) inside specific bit*/
#define GET_BIT(REG,BIT)	 ((REG>>BIT)&1)    /*Get value of specific bit*/
#define TGL_BIT(REG,BIT)     REG ^= (1<<BIT)   /*Toggle state of pin*/

#endif /* BIT_MATH_H_ */