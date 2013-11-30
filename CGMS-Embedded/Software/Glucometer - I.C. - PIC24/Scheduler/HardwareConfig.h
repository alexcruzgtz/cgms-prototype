/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"
#include "GenericTypeDefs.h"
#include "PPS.h"

#ifndef __CONFIG_MCU
#define __CONFIG_MCU


/*-----------------------------------------------------------------------------------------*/
#define __PIC24FJ64GA102__

#define IOPORTA_CFG			0b01000
#define IOPORTB_CFG 		0b1111000111000000
#define ANALOGPINS_CFG 		0b0111110000000

#define MiWi_CfgCS			LATAbits.LATA3
#define MiWi_CfgCS_Tris		TRISAbits.TRISA3
#define MiWi_DataCS			LATAbits.LATA4
#define MiWi_DataCS_Tris	TRISAbits.TRISA4
#define MiWi_Reset			LATBbits.LATB4
#define MiWi_Reset_Tris		TRISBbits.TRIS4	

/*ADC Pins-Channel Name*/
/*...................................................................
AN1----> <Vgnd> Virtual Ground
AN2----> <Vout> Work Electrode Current Measurement Output Voltage
AN3----> <CNT> Counter Electrode
AN4----> <Vctrl> Input Reference Voltage for CNT-REF Voltage
AN5----> <REF> Reference Electrode
.....................................................................*/
#define ADC_VGND_CH		1
#define ADC_VOUT_CH		2
#define ADC_CNT_CH		3
#define ADC_VCRTL_CH	4
#define ADC_REF_CH		5
#define ADC_DEFAULT_CH	ADC_VGND_CH

/*-----------------------------------------------------------------------------------------*/
void CfgHardware_Init(void);
void CfgPPS(void);
void CfgCFGBits(void);
/*-----------------------------------------------------------------------------------------*/



#endif