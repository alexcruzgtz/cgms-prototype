#include <p18f4550.h>

#ifndef __ADC_H
#define __ADC_H

/*-----------------------------------------------------------------------------------------*/
extern void ADC_PowerOn(void);
extern void ADC_StartConvertion(void);
extern void ADC_Select_Channel(unsigned char Channel);
extern void Initialize_ADC(void);
extern void ADC_Select_Reference_Positive(unsigned char Reference);
extern void ADC_Select_Reference_Negative(unsigned char Reference);
extern void ADC_SetAcquisitionTime(unsigned char AcquisitionTime);
extern void ADC_ConversionClocks(unsigned char ConversionClock);
extern unsigned int ReadADC(void);

/*-----------------------------------------------------------------------------------------*/
#define EXTERNAL	0x00
#define INTERNAL	0x01

#define LEFT		0x00
#define RIGHT		0x01

#define _20_TAD		0x07
#define _16_TAD		0x06
#define _12_TAD		0x05
#define _8_TAD		0x04
#define _6_TAD		0x03
#define _4_TAD		0x02
#define _2_TAD		0x01
#define _0_TAD		0x00

#define _FRC		0b111 //FRC (clock derived from A/D RC oscillator)(1)
#define	_FOSC_64	0b110 //FOSC/64
#define	_FOSC_16	0b101 //FOSC/16
#define	_FOSC_4		0b100 //FOSC/4
#define	_FOSC_32	0b010 //FOSC/32
#define	_FOSC_8		0b001 //FOSC/8
#define	_FOSC_2		0b000 //FOSC/2


#endif