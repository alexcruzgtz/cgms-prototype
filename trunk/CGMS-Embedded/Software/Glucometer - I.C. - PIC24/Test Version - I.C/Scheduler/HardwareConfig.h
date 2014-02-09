/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef __HARDWARE_CONFIG_H
#define __HARDWARE_CONFIG_H

/*-----------------------------------------------------------------------------------------*/
#include <p24fxxxx.h>
#include <PPS.h>
#include "Drivers/GenericTypeDefs.h"
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/SPI_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"

/*-----------------------------------------------------------------------------------------*/
//#define __PIC24FJ64GA102__

#define Config_CFGBits(); _CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx2 & FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS1)\
						  _CONFIG2(IESO_OFF & FNOSC_FRC & FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_ON & I2C1SEL_PRI & POSCMOD_NONE)\
						  _CONFIG3(WPDIS_WPDIS & WUTSEL_LEG & SOSCSEL_IO)\
						  _CONFIG4(DSWDTEN_OFF & DSBOREN_ON & RTCOSC_LPRC & DSWDTOSC_LPRC & DSWDTPS_DSWDTPS9)\

/*#define IOPORTA_CFG		0b00000
#define IOPORTB_CFG 		0b1010000010100000
#define ANALOGPINS_CFG 		0b0000000000000*/

#define IOPORTA_CFG			0b00010
#define IOPORTB_CFG 		0b0010001110101111
#define ANALOGPINS_CFG 		0b0000000111110

#define LED_Lat				LATBbits.LATB14
#define LED_Tris			TRISBbits.TRISB14
#define LED_Pin				PORTBbits.RB14

#define PushB_Lat			LATBbits.LATB15							
#define PushB_Tris			TRISBbits.TRISB15
#define PushB_Pin			PORTBbits.RB15

#define TMRL 				TMR2

/*Wireless Transceiver Control Pins*/
/*...................................................................
Configuration Chip Select -> Port A Pin 2
Data Chip Select		  -> Port A Pin 4
Reset Pin				  -> Port A Pin 3
Interrupt Request 1 Pin	  -> Port B Pin 5
.....................................................................*/
#define Config_nCS			LATAbits.LATA2
#define Config_nCS_TRIS		TRISAbits.TRISA2
#define Data_nCS			LATAbits.LATA4
#define Data_nCS_TRIS		TRISAbits.TRISA4
#define PHY_RESETn			LATAbits.LATA3
#define PHY_RESETn_TRIS		TRISAbits.TRISA3	
#define IRQ1_INT_PIN		PORTBbits.RB5
#define IRQ1_INT_TRIS		TRISBbits.TRISB5
#define PHY_IRQ1			INT1_IRQ_Flag
#define PHY_IRQ1_En			INT1_IRQ_En
#define PHY_IRQ1_TRIS   	TRISBbits.TRISB5

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
