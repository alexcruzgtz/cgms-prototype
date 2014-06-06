/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __ADC_HANDLER_H
#define __ADC_HANDLER_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include "Scheduler/HardwareConfig.h"
#include "Drivers/Interrupts.h"


/*-----------------------------------------------------------------------------------------*/
#define _31_TAD		31
#define _16_TAD		16
#define _8_TAD		8
#define _4_TAD		4
#define _2_TAD		2
#define _1_TAD		1
#define _0_TAD		0

#define _1_TCY		0
#define _2_TCY		1
#define _3_TCY		2
#define _4_TCY		3
#define _8_TCY		7
#define _16_TCY		15
#define _32_TCY		31
#define _64_TCY		63

#define ADC_NUM_INPUTS			1
#define ANALOG_SCANCHANNELS		ANALOGPINS_CFG
#define ADC_BUF2_OFFSET			0x0008




/*............. AD1CON1 A/D Control Register 1 ............................................*/
#define ADC_ON							AD1CON1bits.ADON = SET;
#define ADC_OFF							AD1CON1bits.ADON = CLEAR;
#define ADC_IDLE_ON						AD1CON1bits.ADSIDL = CLEAR;
#define ADC_IDLE_OFF					AD1CON1bits.ADSIDL = SET;
#define ADC_DMABUF_INORDER				AD1CON1bits.ADDMABM = SET;
#define ADC_DMABUF_SCATTER				AD1CON1bits.ADDMABM = CLEAR;
#define ADC_1CH_12b						AD1CON1bits.AD12B = SET;
#define ADC_4CH_10b						AD1CON1bits.AD12B = CLEAR;
#define ADC_DataOutFormat				AD1CON1bits.FORM		/*Data Output Format bits
										For 10-bit operation:
											11 = Signed fractional (DOUT = sddd dddd dd00 0000, where s =.NOT.d<9>)
											10 = Fractional (DOUT = dddd dddd dd00 0000)
											01 = Signed integer (DOUT = ssss sssd dddd dddd, where s = .NOT.d<9>)
											00 = Integer (DOUT = 0000 00dd dddd dddd)
										For 12-bit operation:
											11 = Signed fractional (DOUT = sddd dddd dddd 0000, where s = .NOT.d<11>)
											10 = Fractional (DOUT = dddd dddd dddd 0000)
											01 = Signed Integer (DOUT = ssss sddd dddd dddd
											00 = Integer (DOUT = 0000 dddd dddd dddd)*/
#define ADC_SampleClkSource				AD1CON1bits.SSRC		/*Sample Clock Source Select bits
										111 = Internal counter ends sampling and starts conversion (auto-convert)
										110 = Reserved
										101 = Motor Control PWM2 interval ends sampling and starts conversion
										100 = GP timer (Timer5 for ADC1) compare ends sampling and starts conversion
										011 = Motor Control PWM1 interval ends sampling and starts conversion
										010 = GP timer (Timer3 for ADC1) compare ends sampling and starts conversion
										001 = Active transition on INT0 pin ends sampling and starts conversion
										000 = Clearing sample bit ends sampling and starts conversion*/
#define ADC_SIMULTANEOUSSAMPLE_ON		AD1CON1bits.SIMSAM = SET;
#define ADC_SIMULTANEOUSSAMPLE_OFF		AD1CON1bits.SIMSAM = CLEAR;
#define ADC_AUTO_START					AD1CON1bits.ASAM = SET;
#define ADC_MANUAL_START				AD1CON1bits.ASAM = CLEAR;
#define ADC_START_SAMPLING				AD1CON1bits.SAMP = SET;
#define ADC_HOLD_SAMPLING				AD1CON1bits.SAMP = CLEAR;
#define ADC_ConvDone_Status				AD1CON1bits.DONE
#define ADC_CLEAR_CONV_DONE				AD1CON1bits.DONE = CLEAR;


/*............. AD1CON2 A/D Control Register 2 ............................................*/
#define ADC_VREFS_INTERNALS				AD1CON2bits.VCFG = 0;
#define ADC_VREFS_VPOSEXT_VNEGINT		AD1CON2bits.VCFG = 1;
#define ADC_VREFS_VPOSINT_VNEGEXT		AD1CON2bits.VCFG = 2;
#define ADC_VREFS_EXTERNALS				AD1CON2bits.VCFG = 3;
#define ADC_SCAN						AD1CON2bits.CSCNA = SET;
#define ADC_DONTSCAN					AD1CON2bits.CSCNA = CLEAR;
#define ADC_SelectChannels				AD1CON2bits.CHPS	/*Selects Channels Utilized bits
										When AD12B = 1, CHPS<1:0> is: U-0, Unimplemented, Read as ‘0’
											1x = Converts CH0, CH1, CH2 and CH3
											01 = Converts CH0 and CH1
											00 = Converts CH0*/
#define ADC_BufFill_Status				AD1CON2bits.BUFS /*If 1: AD filling upper buffer. If 0: AD filling lower buffer*/
#define ADC_NumSamp_PerIRQ				AD1CON2bits.SMPI	//[3:0]
#define ADC_TWO_8_BUFFER				AD1CON2bits.BUFM = SET;
#define ADC_ONE_16_BUFFER				AD1CON2bits.BUFM = CLEAR;
#define ADC_ALTERNATE_SAMPLING			AD1CON2bits.ALTS = SET;
#define ADC_DONT_ALTERNATE_SAMPLING		AD1CON2bits.ALTS = CLEAR;


/*............. AD1CON3 A/D Control Register 3 ............................................*/
#define ADC_CLOCK_SOURCE_INTERNAL		AD1CON3bits.ADRC = SET;
#define ADC_CLOCK_SOURCE_SYSTEM			AD1CON3bits.ADRC = CLEAR;
#define ADC_Auto_Sample_Time			AD1CON3bits.SAMC	/*Auto Sample Time bits(1)
										11111 = 31 TAD
										•
										00001 = 1 TAD
										00000 = 0 TAD*/
#define ADC_Conv_Clock					AD1CON3bits.ADCS	/* ADC Conversion Clock Select bits
										11111111 = Reserved
										•
										01000000 = Reserved
										00111111 = TCY · (ADCS<7:0> + 1) = 64 · TCY = TAD
										•
										00000010 = TCY · (ADCS<7:0> + 1) = 3 · TCY = TAD
										00000001 = TCY · (ADCS<7:0> + 1) = 2 · TCY = TAD
										00000000 = TCY · (ADCS<7:0> + 1) = 1 · TCY = TAD*/


/*............. AD1CON4 A/D Control Register 4 ............................................*/
#define ADC_DMABufLoc_PerAnIn			AD1CON4bits.DMABL	/*Selects Number of DMA Buffer Locations per Analog Input bits
										111 = Allocates 128 words of buffer to each analog input
										110 = Allocates 64 words of buffer to each analog input
										101 = Allocates 32 words of buffer to each analog input
										100 = Allocates 16 words of buffer to each analog input
										011 = Allocates 8 words of buffer to each analog input
										010 = Allocates 4 words of buffer to each analog input
										001 = Allocates 2 words of buffer to each analog input
										000 = Allocates 1 word of buffer to each analog input*/


/*............. AD1CHS123 ADC1 Input Channel 1,2,3 Select Register ........................*/
#define ADC_CH123_BNegInput				AD1CHS123bits.CH123NB	/*Channel 1, 2, 3 Negative Input Select for Sample B bits
										If AD12B = 1:
											11 = Reserved
											10 = Reserved
											01 = Reserved
											00 = Reserved
										If AD12B = 0:
											11 = Reserved
											10 = CH1 negative input is AN6, CH2 negative input is AN7, CH3 negative input is AN8
											01 = CH1, CH2, CH3 negative input is VREF-
											00 = CH1, CH2, CH3 negative input is VREF*/
#define ADC_CH123_BPosInput				AD1CHS123bits.CH123SB	/*Channel 1, 2, 3 Positive Input Select for Sample B bit
										If AD12B = 1:
											1 = Reserved
											0 = Reserved
										If AD12B = 0:
											1 = CH1 positive input is AN3, CH2 positive input is AN4, CH3 positive input is AN5
											0 = CH1 positive input is AN0, CH2 positive input is AN1, CH3 positive input is AN2*/
#define ADC_CH123_ANegInput				AD1CHS123bits.CH123NA	/*Channel 1, 2, 3 Negative Input Select for Sample A bits
										If AD12B = 1:
											11 = Reserved
											10 = Reserved
											01 = Reserved
											00 = Reserved
										If AD12B = 0:
											11 = Reserved
											10 = CH1 negative input is AN6, CH2 negative input is AN7, CH3 negative input is AN8
											01 = CH1, CH2, CH3 negative input is VREF-
											00 = CH1, CH2, CH3 negative input is VREF*/
#define ADC_CH123_APosInput				AD1CHS123bits.CH123SA	/*Channel 1, 2, 3 Positive Input Select for Sample A bit
										If AD12B = 1:
											1 = Reserved
											0 = Reserved
										If AD12B = 0:
											1 = CH1 positive input is AN3, CH2 positive input is AN4, CH3 positive input is AN5
											0 = CH1 positive input is AN0, CH2 positive input is AN1, CH3 positive input is AN2*/


/*............. AD1CHS0 ADC1 Input Channel 0 Select Register ..............................*/
#define ADC_CH0_BNegInput				AD1CHS0bits.CH0NB	/*Channel 0 Negative Input Select for Sample B bit
										1 = Channel 0 negative input is AN1
										0 = Channel 0 negative input is VREF*/
#define ADC_CH0_BPosInput				AD1CHS0bits.CH0SB	/*Channel 0 Positive Input Select for Sample B bits
										01000 = Channel 0 positive input is AN8
										•
										00010 = Channel 0 positive input is AN2
										00001 = Channel 0 positive input is AN1
										00000 = Channel 0 positive input is AN0*/
#define ADC_CH0_ANegInput				AD1CHS0bits.CH0NA	/*Channel 0 Negative Input Select for Sample A bit
										1 = Channel 0 negative input is AN1
										0 = Channel 0 negative input is VREF*/
#define ADC_CH0_APosInput				AD1CHS0bits.CH0SA	/*Channel 0 Positive Input Select for Sample A bits
										01000 = Channel 0 positive input is AN8
										•
										00010 = Channel 0 positive input is AN2
										00001 = Channel 0 positive input is AN1*/


/*............. AD1CSSL A/D Input Scan Select Register Low ................................*/
#define ADC_ScanPins					AD1CSSL	/*
										1 = Select ANx for input scan
										0 = Skip ANx for input scan*/


/*............. AD1PCFGL A/D Port Confirutation Register Low ..............................*/
#define ADC_PortCfg						AD1PCFGL	/*
1 = Port pin in Digital mode, port read input enabled, ADC input multiplexer connected to AVSS
0 = Port pin in Analog mode, port read input disabled, ADC samples pin voltage*/


/*-----------------------------------------------------------------------------------------*/
void vADC_Init( void );
//void 	ADC_ReadAll(UINT16 *ADCBufAddress);
//UINT16 	ADC_ReadOne(UINT16 ADCAnalogInpit);
//void	ADC_StartAll(void);
//void	ADC_StopAll(void);

//UINT16 	*ptr_ADC8Buffer;


/*-----------------------------------------------------------------------------------------*/
#endif
