/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <p24fj64ga102.h>
#include "GenericTypeDefs.h"

#ifndef __ADC_HANDLER_H
#define __ADC_HANDLER_H

/*-----------------------------------------------------------------------------------------*/
extern void ADC_Init(void);
extern uint16_t ADC_Read(void);

extern uint16_t *ptr_ADC8Buffer

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

#define ADC_NUM_INPUTS			4;
#define ADC_BUF2_OFFSET			0x0008
#define ADC_Buf_Status 			AD1CON2bits.BUFS /*If 1: AD filling upper buffer. If 0: AD filling lower buffer*/
#define ADC_Conv_Done			AD1CON1bits.DONE

#define ADC_Interrupt_Flag		IFS0bits.AD1IF		
#define ADC_Interrupt_Priority	IPC3bits.AD1IP
#define _ADC_INTERRUPT_ON		IEC0bits.AD1IE=SET;
#define _ADC_INTERRUPT_OFF		IEC0bits.AD1IE=CLEAR;

/*............. AD1CON1 A/D Control Register 1 Macros .....................................*/
#define _ADC_ON							AD1CON1bits.ADON=SET;
#define _ADC_OFF						AD1CON1bits.ADON=CLEAR;
#define _ADC_IDLE_MODE_ON				AD1CON1bits.ADSIDL=CLEAR;
#define _ADC_IDLE_MODE_OFF				AD1CON1bits.ADSIDL=SET;
#define _ADC_OUTPUT_SFRAC				AD1CON1bits.FORM=3;
#define _ADC_OUTPUT_FRAC				AD1CON1bits.FORM=2;
#define _ADC_OUTPUT_SINT				AD1CON1bits.FORM=1;
#define _ADC_OUTPUT_INT					AD1CON1bits.FORM=0;
#define _ADC_CONV_TRIG_INTERNAL			AD1CON1bits.SSRC=7;
#define _ADC_CONV_TRIG_CTMU				AD1CON1bits.SSRC=6;
#define _ADC_CONV_TRIG_TM5				AD1CON1bits.SSRC=4;
#define _ADC_CONV_TRIG_TM3				AD1CON1bits.SSRC=2;
#define _ADC_CONV_TRIG_INT0				AD1CON1bits.SSRC=1;
#define _ADC_CONV_TRIG_SAMP				AD1CON1bits.SSRC=0;
#define _ADC_AUTO_START					AD1CON1bits.ASAM=SET;
#define _ADC_MANUAL_START				AD1CON1bits.ASAM=CLEAR;
#define _ADC_START_SAMPLING				AD1CON1bits.SAMP=SET;
#define _ADC_HOLD_SAMPLING				AD1CON1bits.SAMP=CLEAR;
#define _ADC_CLEAR_CONV_DONE			AD1CON1bits.DONE=CLEAR;

/*............. AD1CON2 A/D Control Register 2 Macros .....................................*/
#define _ADC_VREFS_INTERNALS			AD1CON2bits.VCFG=0;
#define _ADC_VREFS_VPOSEXT_VNEGINT		AD1CON2bits.VCFG=1;
#define _ADC_VREFS_VPOSINT_VNEGEXT		AD1CON2bits.VCFG=2;
#define _ADC_VREFS_EXTERNALs			AD1CON2bits.VCFG=3;
#define _ADC_SCAN_INPUTS				AD1CON2bits.CSCNA=SET;
#define _ADC_DONT_SCAN_INPUTS			AD1CON2bits.CSCNA=CLEAR;
#define ADC_Samp_Conv_Per_Interrupt		AD1CON2bits.SMPI
#define _ADC_TWO_8_BUFFER				AD1CON2bits.BUFM=SET;
#define _ADC_ONE_16_BUFFER				AD1CON2bits.BUFM=CLEAR;
#define _ADC_ALTERNATE_SAMPLING			AD1CON2bits.ALTS=SET;
#define _ADC_DONT_ALTERNATE_SAMPLING	AD1CON2bits.ALTS=CLEAR;

/*............. AD1CON3 A/D Control Register 3 Macros .....................................*/
#define _ADC_CLOCK_SOURCE_INTERNAL		AD1CON3bits.ADRC=SET;
#define _ADC_CLOCK_SOURCE_SYSTEM		AD1CON3bits.ADRC=CLEAR;
#define ADC_Auto_Sample_Time			AD1CON3bits.SAMC
#define ADC_Conv_Clock					AD1CON3bits.ADCS

/*............. AD1CHS A/D Input Select Register Macros ...................................*/
#define _ADC_MB_NEG_INPUT_AN1			AD1CHSbits.CH0NB=SET;
#define _ADC_MB_NEG_INPUT_VRNEG			AD1CHSbits.CH0NB=CLEAR;
#define ADC_MB_Pos_Input				AD1CHSbits.CH0SB
#define _ADC_MA_NEG_INPUT_AN1			AD1CHSbits.CH0NA=SET;
#define _ADC_MA_NEG_INPUT_VRNEG			AD1CHSbits.CH0NA=CLEAR;
#define ADC_MA_Pos_Input				AD1CHSbits.CH0SA

/*............. AD1PCFG A/D Port Configuration Register Macros ............................*/
#define	_ADC_BAND_GAP_REF_ENABLED		AD1PCFGbits.PCFG15=CLEAR;
#define	_ADC_BAND_GAP_REF_DISABLED		AD1PCFGbits.PCFG15=SET;
#define _ADC_HAlF_BAND_REF_ENABLED		AD1PCFGbits.PCFG14=CLEAR;
#define _ADC_HAlF_BAND_REF_DISABLED		AD1PCFGbits.PCFG14=SET;
#define _ADC_INT_VREG_CH_ENABLED		AD1PCFGbits.PCFG13=CLEAR;
#define _ADC_INT_VREG_CH_DISABLED		AD1PCFGbits.PCFG13=SET;
#define ADC_Analog_Pins_Cfg				AD1PCFGbits.PCFG

/*............. AD1CSSL A/D Input Scan Select Register Macros .............................*/
#define _ADC_BAND_GAP_ENABLED			AD1CSSLbits.CSSL15=SET;
#define _ADC_BAND_GAP_DISABLED			AD1CSSLbits.CSSL15=CLEAR;
#define _ADC_HALF_BAND_GAP_ENABLED		AD1CSSLbits.CSSL14=SET;
#define _ADC_HALF_BAND_GAP_DISABLED		AD1CSSLbits.CSSL14=CLEAR;
#define _ADC_INT_VREG_ENABLED			AD1CSSLbits.CSSL13=CLEAR;
#define _ADC_INT_VREG_DISABLED			AD1CSSLbits.CSSL13=SET;
#define ADC_Scan_Pins_Enabled			AD1CSSLbits.CSSL


#endif