/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __OSCILLATOR_H
#define __OSCILLATOR_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>


/*-----------------------------------------------------------------------------------------*/
#define FOSC	(8000000)
#define FCY		 4000000//(FOSC/2)

/*.........................................................................................*/

//Oscillator Selection bits.
#define _FRCDIVN		7		//Fast RC Oscillator Divided by n
#define _FRCDIV16		6		//Fast RC Oscillator Divided by 16
#define _LPRC			5		//Low-Power RC Oscillator (LPRC)
#define _SOSC			4		//Secundary Oscillator
#define _POSCPLL		3		//Primary Oscillator with PLL
#define _POSC			2		//Primary Oscillator (XT, HS, EC)
#define _FRCPLL			1		//Fast RC Oscillator Divided by N and PLL
#define _FRC			0		//Fast RC Oscillator (FRC)

//Processor Clock Reduction
#define _DOZE_128		7		//FCY/128
#define _DOZE_64		6		//FCY/64
#define _DOZE_32		5		//FCY/32
#define _DOZE_16		4		//FCY/16
#define _DOZE_8			3		//FCY/8
#define _DOZE_4			2		//FCY/4
#define _DOZE_2			1		//FCY/2
#define _DOZE_1			0		//FCY/1

//FRC Postcaler Select bits
#define _RCDIV_256		7		//31.25 kHz (FRC/256)
#define _RCDIV_64		6		//125 kHz (FRC/64)
#define _RCDIV_32		5		//250 kHz (FRC/32)
#define _RCDIV_16		4		//500 kHz (FRC/16)
#define _RCDIV_8		3		//1 MHz (FRC/8)
#define _RCDIV_4		2		//2 MHz (FRC/4)
#define _RCDIV_2		1		//4 MHz (FRC/2)
#define _RCDIV_1		0		//8 MHz (FRC/1)


/*.............OSCCON Oscillator Control Register .........................................*/
#define OSC_CurrentOsc				OSCCONbits.COSC
#define OSC_NewOsc					OSCCONbits.NOSC	
#define OSC_CLKLOCK_ON				OSCCONbits.CLKLOCK = SET;
#define OSC_CLKLOCK_OFF				OSCCONbits.CLKLOCK = CLEAR;
#define OSC_IOLOCK_ON				OSCCONbits.IOLOCK = SET;
#define OSC_IOLOCK_OFF				OSCCONbits.IOLOCK = CLEAR;
#define OSC_PllLock_Status			OSCCONbits.LOCK
#define OSC_CLKFail_Status			OSCCONbits.CF
#define OSC_CLEAR_CLKFAIL			OSCCONbits.CF=CLEAR;
#define OSC_SOSC_ENABLED			OSCCONbits.LPOSCEN = SET;
#define OSC_SOSC_DISABLED			OSCCONbits.LPOSCEN = CLEAR;
#define OSC_OscSwitch_Status		OSCCONbits.OSWEN
#define OSC_OSCSWITCH_START			OSCCONbits.OSWEN = SET;


/*.............CLKDIV Clock Divider Resgister .............................................*/
#define OSC_RECOVERONISR_ON			CLKDIVbits.ROI = SET;
#define OSC_RECOVERONISR_OFF		CLKDIVbits.ROI = CLEAR;
#define OSC_ProscClkReduction		CLKDIVbits.DOZE
#define OSC_DOZE_ENABLED			CLKDIVbits.DOZEN = SET;	//DOZE<2:0> bits specify the CPU peripheral clock ratio
#define OSC_DOZE_DISABLED			CLKDIVbits.DOZEN = CLEAR;	//CPU peripheral clock ratio set to 1:1
#define OSC_FRCPostscaler			CLKDIVbits.FRCDIV
#define OSC_PLLOutputDiv			CLKDIVbits.PLLPOST		//11 = Output/8, 10 = Reserved, 01 = Output/4 (default), 00 = Output/2
#define OSC_PLLInputDiv				CLKDivbits.PLLPRE		//[4:0] input/33..input/2


/*.............PLLFBD PLL Feedback Divisor Register .......................................*/
#define OSC_PLLFeedbackDiv			PLLFBDbits.PLLDIV		/*[8:0]
															  111111111 = 513
															  •
															  000110000 = 50 (default)
															  •
															  000000010 = 4
															  000000001 = 3*/


/*.............OSCTUN FRC Oscillator Tuner Resgister ......................................*/
#define OSC_FRCOscTune				OSCTUNbits.TUN			//[5:0]
									/*111111 = Center frequency -0.375% (7.345 MHz)
									  •
									  100001 = Center frequency -11.625% (6.52 MHz)
									  100000 = Center frequency -12% (6.49 MHz)
									  011111 = Center frequency +11.625% (8.23 MHz)
									  011110 = Center frequency +11.25% (8.20 MHz)
									  •
									  000001 = Center frequency +0.375% (7.40 MHz)*/


/*.............ACLKCON Auxiliary Clock Divisor Control Resgister .............................*/
#define OSC_ACLKSOURCE_AUX			ACLKCONbits.SELACLK = SET;
#define OSC_ACLKSOURCE_PLL			ACLKCONbits.SELACLK = CLEAR;
#define OSC_AClk_Mode				ACLKCONbits.AOSCMD		/*[1:0]11 = EC External Clock Mode Select
																   10 = XT Oscillator Mode Select
																   01 = HS Oscillator Mode Select
																   00 = Auxiliary Oscillator Disabled (default)*/
#define OSC_AClkDiv					ACLKCONbits.APSTSCLR 	//[2:0] 111-Divided by 1 ... 000-Divided by 256
#define OSC_ACLK_SOURCE_PRIMARY		ACLKCONbits.ASCRSEL = SET;
#define OSC_ACLK_SOURCE_AUXOSC		ACLKCONbits.ASCRSEL = CLEAR;



/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
#endif
