#include <p18f4550.h>

#ifndef __TIMER0CFG_H
#define __TIMER0CFG_H

#define MACRO_ENABLE_TMR0						T0CONbits.TMR0ON=0x01;
#define MACRO_DISABLE_TMR0						T0CONbits.TMR0ON=0x00;

#define MACRO_SET_8BITS_TMR0 					T0CONbits.T08BIT=0x01;
#define MACRO_SET_16BITS_TMR0 					T0CONbits.T08BIT=0x00;

#define MACRO_SELECT_EXTERNAL_CLK_SOURCE_TMR0	T0CONbits.T0CS=0x01;
#define MACRO_SELECT_INTERNAL_CLK_SOURCE_TMR0	T0CONbits.T0CS=0x00;

#define MACRO_SELECT_FALLING_EDGE_TMR0			T0CONbits.T0SE=0x01;
#define MACRO_SELECT_RISING_EDGE_TMR0			T0CONbits.T0SE=0x00;

#define MACRO_PRESCALER_NOT_ASSIGNED_TMR0		T0CONbits.PSA=0x01;
#define MACRO_PRESCALER_ASSIGNED_TMR0			T0CONbits.PSA=0x00;

#define	MACRO_PRESCALER_1_256_TMR0				T0CONbits.T0PS2=0x01;\
												T0CONbits.T0PS1=0x01;\
												T0CONbits.T0PS0=0x01;
#define	MACRO_PRESCALER_1_128_TMR0				T0CONbits.T0PS2=0x01;\
												T0CONbits.T0PS1=0x01;\
												T0CONbits.T0PS0=0x00;
#define	MACRO_PRESCALER_1_64_TMR0				T0CONbits.T0PS2=0x01;\
												T0CONbits.T0PS1=0x00;\
												T0CONbits.T0PS0=0x01;
#define	MACRO_PRESCALER_1_32_TMR0				T0CONbits.T0PS2=0x01;\
												T0CONbits.T0PS1=0x00;\
												T0CONbits.T0PS0=0x00;
#define	MACRO_PRESCALER_1_16_TMR0				T0CONbits.T0PS2=0x00;\
												T0CONbits.T0PS1=0x01;\
												T0CONbits.T0PS0=0x01;
#define	MACRO_PRESCALER_1_8_TMR0 				T0CONbits.T0PS2=0x00;\
												T0CONbits.T0PS1=0x01;\
												T0CONbits.T0PS0=0x00;
#define	MACRO_PRESCALER_1_4_TMR0 				T0CONbits.T0PS2=0x00;\
												T0CONbits.T0PS1=0x00;\
												T0CONbits.T0PS0=0x01;
#define	MACRO_PRESCALER_1_2_TMR0 				T0CONbits.T0PS2=0x00;\
												T0CONbits.T0PS1=0x00;\
												T0CONbits.T0PS0=0x00;											
											
#define	CONSTANT_1ms_HIGH_NIBBLE				0x2f
#define CONSTANT_1ms_LOW_NIBBLE					0xf8			
extern void Initialize_Timer0(void);



#endif