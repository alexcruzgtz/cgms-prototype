/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"
#include "GenericTypeDefs.h"
#include "PPS.h"
#include "Interrupts.h"
#include "Oscillator.h"

#ifndef __CONFIG_MCU
#define __CONFIG_MCU


/*-----------------------------------------------------------------------------------------*/
#define __PIC24FJ64GA102__

#define IOPORTA_CFG			0b00010
#define IOPORTB_CFG 		0b0010001110101111
#define ANALOGPINS_CFG 		0b0000000111110

/*Wireless Transceiver Control bits*/
/*...................................................................
Configuration Chip Select -> Port A Pin 2
Data Chip Select		  -> Port A Pin 4
Reset Pin				  -> Port A Pin 3
Interrupt Request 1 Pin	  -> Port B Pin 5
.....................................................................*/
#define Config_nCs			LATAbits.LATA2
#define Config_nCs_TRIS		TRISAbits.TRISA2
#define Data_nCS			LATAbits.LATA4
#define Data_nCS_TRIS		TRISAbits.TRISA4
#define PHY_RESETn			LATAbits.LATA3
#define PHY_RESETn_TRIS		TRISAbits.TRISA3	
#define IRQ1_INT_PIN		LATBbits.LATB5
#define IRQ1_INT_TRIS		TRISBbits.TRISB5
#define PHY_IRQ1			INT1_IRQ_Flag
#define PHY_IRQ1_En			INT1_IRQ_En


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
void HardwareCfg_Init(void);
void Cfg_PPS(void);
void Cfg_CFGBits(void);
void Cfg_Ports(void);
/*-----------------------------------------------------------------------------------------*/



#endif