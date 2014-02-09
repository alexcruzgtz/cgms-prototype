/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <p24fxxxx.h>
#include "Drivers/GenericTypeDefs.h"

#ifndef __OSCILLATOR_H
#define __OSCILLATOR_H


/*-----------------------------------------------------------------------------------------*/
#define FOSC	(8000000)
#define FCY		 4000000//(FOSC/2)

/*.........................................................................................*/

//Oscillator Selection bits.
#define _FRCDIV			7		//Fast RC Oscillator with Postscaler (FRCDIV)
#define _LPRC			5		//Low-Power RC Oscillator (LPRC)
#define _SOSC			4		//Low-Power RC Oscillator (LPRC)
#define _OSCPLL			3		//Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
#define _OSC			2		//Primary Oscillator (XT, HS, EC)
#define _FRCPLL			1		//Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
#define _FRC			0		//Fast RC Oscillator (FRC)

//CPU Peripheral Clock Ratio Select bits
#define _DOZE_1_128		7		//1:128
#define _DOZE_1_64		6		//1:64
#define _DOZE_1_32		5		//1:32
#define _DOZE_1_16		4		//1:16
#define _DOZE_1_8		3		//1:8
#define _DOZE_1_4		2		//1:4
#define _DOZE_1_2		1		//1:2
#define _DOZE_1_1		0		//1:1

//FRC Postcaler Select bits
#define _RCDIV_31K		7		//31.25 kHz (divide-by-256)
#define _RCDIV_125K		6		//125 kHz (divide-by-64)
#define _RCDIV_250K		5		//250 kHz (divide-by-32)
#define _RCDIV_500K		4		//500 kHz (divide-by-16)
#define _RCDIV_1M		3		//1 MHz (divide-by-8)
#define _RCDIV_2M		2		//2 MHz (divide-by-4)
#define _RCDIV_4M		1		//4 MHz (divide-by-2)
#define _RCDIV_8M		0		//8 MHz (divide-by-1)

//Reference Oscillator Divisor Select bits
#define _RODIV_32768	0xF
#define _RODIV_16384	0xE
#define _RODIV_8192		0xD
#define _RODIV_4096		0xC
#define _RODIV_2048		0xB
#define _RODIV_1024		0xA
#define _RODIV_512		0x9
#define _RODIV_256		0x8
#define _RODIV_128		0x7
#define _RODIV_64		0x6
#define _RODIV_32		0x5
#define _RODIV_16		0x4
#define _RODIV_8		0x3
#define _RODIV_4		0x2
#define _RODIV_2		0x1
#define _RODIV_1		0x0

/*.............OSCCON Oscillator Control Register .........................................*/
#define OSC_CurrentOsc			OSCCONbits.COSC
#define OSC_NewOsc				OSCCONbits.NOSC	
#define OSC_CLKLOCK_ON			OSCCONbits.CLKLOCK=SET;
#define OSC_CLKLOCK_OFF		OSCCONbits.CLKLOCK=CLEAR;
#define OSC_IOLOCK_ON			OSCCONbits.IOLOCK=SET;
#define OSC_IOLOCK_OFF			OSCCONbits.IOLOCK=CLEAR;
#define OSC_PllLock_Status		OSCCONbits.LOCK
#define OSC_CLKFail_Status		OSCCONbits.CF
#define OSC_CLEAR_CLKFAIL		OSCCONbits.CF=CLEAR;
#define	OSC_POSCSLEEP_ON		OSCCONbits.POSCEN=SET;		//Primary Oscillator continues to operate during Sleep mode
#define OSC_POSCSLEEP_OFF		OSCCONbits.POSCEN=CLEAR;	//Primary Oscillator disabled during Sleep mode
#define OSC_32KSOSC_ENABLE		OSCCONbits.SOSCEN=SET;
#define OSC_32KSOSC_DISABLE		OSCCONbits.SOSCEN=CLEAR;
#define OSC_OscSwitch_Status	OSCCONbits.OSWEN
#define OSC_OSCSWITCH_START		OSCCONbits.OSWEN=SET;
#define OSC_OSCSWITCH_FINISH	OSCCONbits.OSWEN=CLEAR;

/*.............CLKDIV Clock Divider Resgister .............................................*/
#define OSC_RECOVERONISR_ON			CLKDIVbits.ROI=SET;
#define OSC_RECOVERONISR_OFF		CLKDIVbits.ROI=CLEAR;
#define OSC_PeripheralClkRatio		CLKDIVbits.DOZE
#define OSC_PERIPHCLKRATIO_ENABLE	CLKDIVbits.DOZEN=SET;	//DOZE<2:0> bits specify the CPU peripheral clock ratio
#define OSC_PERIPHCLKRATIO_DISABLE	CLKDIVbits.DOZEN=CLEAR;	//CPU peripheral clock ratio set to 1:1
#define OSC_FRCPostscaler			CLKDIVbits.RCDIV

/*.............OSCTUN FRC Oscillator Tuner Resgister ......................................*/
#define OSC_OscTune					OSCTUNbits.TUN
/*011111 = Maximum frequency deviation
011110 =
.
.
.
000001 =
000000 = Center frequency, oscillator is running at factory calibrated frequency
111111 =
.
.
.
100001 =
100000 = Minimum frequency deviation*/

/*.............REFOCON Reference Oscillator Control Resgister .............................*/
#define OSC_REFOSC_ENABLE			REFOCONbits.ROEN=SET;
#define OSC_REFOSC_DISABLE			REFOCONbits.ROEN=CLEAR;
#define OSC_REFOSCSLEEP_ENABLE		REFOCONbits.ROSSLP=SET;
#define OSC_REFOSCSLEEP_DISABLE		REFOCONbits.ROSSLP=CLEAR;
#define OSC_REFOSC_SOURCE_POSC		REFOCONbits.ROSEL=SET;
#define OSC_REFOSC_SOURCE_SYSCLK	REFOCONbits.ROSEL=CLEAR;
#define OSC_RefOsc_Divisor			REFOCONbits.RODIV


/*-----------------------------------------------------------------------------------------*/
void Oscillator_Init(void);


/*-----------------------------------------------------------------------------------------*/
#endif
