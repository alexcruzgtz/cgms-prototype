/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __TIMERS_H
#define __TIMERS_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>


/*-----------------------------------------------------------------------------------------*/

/*Timers input clock depend on Fcy
For 4Mhz -> Tcy=250ns. If Tperiod = 1ms, cycles = Tperiod/Tcy = 4000
For 20Mhz ->Cycles= 20000*/
#define _1ms_At4MHZ				4000
#define _1ms_At20Mhz			20000


/*... Timer 1 ...*/
#define TMR1_ON					T1CONbits.TON = SET;
#define TMR1_OFF				T1CONbits.TON = CLEAR;
#define TMR1_STOP_INIDLE		T1CONbits.TSIDL = SET;
#define TMR1_CONTINUE_INIDLE	T1CONbits.TSIDL = CLEAR;
#define TMR1_GATEDACC_ENABLE	T1CONbits.TGATE = SET;
#define TMR1_GATEDACC_DISABLE	T1CONbits.TGATE = CLEAR;
#define TMR1_InputPrescaleDiv	T1CONbits.TCKPS 			//11=1:256, 10=1:64, 01=1:8, 00=1:1
#define TMR1_EXTCLKSYNCH_ON		T1CONbits.TSYNC = SET;
#define TMR1_EXTCLKSYNCH_OFF	T1CONbits.TSYNC = CLEAR;
#define TMR1_EXTCLK_SOURCE		T1CONbits.TCS = SET;		//External clock from pin T1CK (on the rising edge)
#define TMR1_INTCLK_SOURCE		T1CONbits.TCS = CLEAR;		//Internal clock (FCY)
#define TMR1_Time				TMR1
#define TMR1_Period				PR1


/*... Timer 2 ...*/
#define TMR2_ON					T2CONbits.TON = SET;
#define TMR2_OFF				T2CONbits.TON = CLEAR;
#define TMR2_STOP_INIDLE		T2CONbits.TSIDL = SET;
#define TMR2_CONTINUE_INIDLE	T2CONbits.TSIDL = CLEAR;
#define TMR2_GATEDACC_ENABLE	T2CONbits.TGATE = SET;
#define TMR2_GATEDACC_DISABLE	T2CONbits.TGATE = CLEAR;
#define TMR2_InputPrescaleDiv	T2CONbits.TCKPS 			//11=1:256, 10=1:64, 01=1:8, 00=1:1
#define TMR2_32b_MODE			T2CONbits.T32 = SET;
#define TMR2_16b_MODE			T2CONbits.T32 = CLEAR;
#define TMR2_EXTCLK_SOURCE		T2CONbits.TCS = SET;		//External clock from pin T1CK (on the rising edge)
#define TMR2_INTCLK_SOURCE		T2CONbits.TCS = CLEAR;		//Internal clock (FCY)
#define TMR2_Time				TMR2
#define TMR2_Period				PR2


/*... Timer 3 ...*/
#define TMR3_ON					T3CONbits.TON = SET;
#define TMR3_OFF				T3CONbits.TON = CLEAR;
#define TMR3_STOP_INIDLE		T3CONbits.TSIDL = SET;
#define TMR3_CONTINUE_INIDLE	T3CONbits.TSIDL = CLEAR;
#define TMR3_GATEDACC_ENABLE	T3CONbits.TGATE = SET;
#define TMR3_GATEDACC_DISABLE	T3CONbits.TGATE = CLEAR;
#define TMR3_InputPrescaleDiv	T3CONbits.TCKPS 			//11=1:256, 10=1:64, 01=1:8, 00=1:1
#define TMR3_EXTCLK_SOURCE		T3CONbits.TCS = SET;		//External clock from pin T1CK (on the rising edge)
#define TMR3_INTCLK_SOURCE		T3CONbits.TCS = CLEAR;		//Internal clock (FCY)
#define TMR3_Time				TMR3
#define TMR3_Period				PR3

/*... Timer 4 ...*/
#define TMR4_ON					T4CONbits.TON = SET;
#define TMR4_OFF				T4CONbits.TON = CLEAR;
#define TMR4_STOP_INIDLE		T4CONbits.TSIDL = SET;
#define TMR4_CONTINUE_INIDLE	T4CONbits.TSIDL = CLEAR;
#define TMR4_GATEDACC_ENABLE	T4CONbits.TGATE = SET;
#define TMR4_GATEDACC_DISABLE	T4CONbits.TGATE = CLEAR;
#define TMR4_InputPrescaleDiv	T4CONbits.TCKPS 			//11=1:256, 10=1:64, 01=1:8, 00=1:1
#define TMR4_32b_MODE			T4CONbits.T32 = SET;
#define TMR4_16b_MODE			T4CONbits.T32 = CLEAR;
#define TMR4_EXTCLK_SOURCE		T4CONbits.TCS = SET;		//External clock from pin T1CK (on the rising edge)
#define TMR4_INTCLK_SOURCE		T4CONbits.TCS = CLEAR;		//Internal clock (FCY)
#define TMR4_Time				TMR4
#define TMR4_Period				PR4


/*... Timer 5 ...*/
#define TMR5_ON					T5CONbits.TON = SET;
#define TMR5_OFF				T5CONbits.TON = CLEAR;
#define TMR5_STOP_INIDLE		T5CONbits.TSIDL = SET;
#define TMR5_CONTINUE_INIDLE	T5CONbits.TSIDL = CLEAR;
#define TMR5_GATEDACC_ENABLE	T5CONbits.TGATE = SET;
#define TMR5_GATEDACC_DISABLE	T5CONbits.TGATE = CLEAR;
#define TMR5_InputPrescaleDiv	T5CONbits.TCKPS 			//11=1:256, 10=1:64, 01=1:8, 00=1:1
#define TMR5_EXTCLK_SOURCE		T5CONbits.TCS = SET;		//External clock from pin T1CK (on the rising edge)
#define TMR5_INTCLK_SOURCE		T5CONbits.TCS = CLEAR;		//Internal clock (FCY)
#define TMR5_Time				TMR5
#define TMR5_Period				PR5


/*-----------------------------------------------------------------------------------------*/