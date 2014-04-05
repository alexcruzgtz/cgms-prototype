/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef __HARDWARE_CONFIG_H
#define __HARDWARE_CONFIG_H

/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <PPS.h>
#include <GenericTypeDefs.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/Reset.h"
#include "Drivers/CPU.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"

/*-----------------------------------------------------------------------------------------*/

#define Config_CFGBits(); 		_FBS(BWRP_WRPROTECT_OFF & RBS_NO_BOOT_RAM)\
								_FSS(SWRP_WRPROTECT_OFF & SSS_NO_SEC_CODE & RSS_NO_SEC_RAM)\
								_FGS(GWRP_OFF & GCP_OFF)\
								_FOSCSEL(FNOSC_FRC & IESO_ON)\
								_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_ON & FCKSM_CSECME)\
								_FWDT(WDTPOST_PS128 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF)\
								_FPOR(FPWRT_PWR1 & ALTI2C_OFF & LPOL_OFF & HPOL_OFF & PWMPIN_ON)\
								_FICD(JTAGEN_OFF)//ICS_PGD3 & 

#define IOPORT_A_CFG			0b00100011111
#define IOPORT_B_CFG 			0b0000001000011111
#define IOPORT_C_CFG			0b0000100000


/*Analog Pins*/
/*...................................................................
Vout	-> AN0 Port A.0
Vgnd	-> AN1 Port A.1
CNT		-> AN2 Port B.0
Vctrl	-> AN3 Port B.1
REF		-> AN4 Port B.2
3.3V	-> AN5 Port B.3
.....................................................................*/
#define ANALOGPINS_CFG 			0b111000000

#define _VOUT_CH				0
#define _VGND_CH				1
#define _CNT_CH					2
#define _VCRTL_CH				3
#define _REF_CH					4
#define _VCC_CH					5
#define _DEFAULT_CH				_VGND_CH

#define AN0_Lat					LATAbits.LATA0
#define AN0_Tris				TRISAbits.TRISA0
#define AN1_Lat					LATAbits.LATA1
#define AN1_Tris				TRISAbits.TRISA1
#define AN2_Lat					LATBbits.LATB0
#define AN2_Tris				TRISBbits.TRISB0
#define AN3_Lat					LATBbits.LATB1
#define AN3_Tris				TRISBbits.TRISB1
#define AN4_Lat					LATBbits.LATB2
#define AN4_Tris				TRISBbits.TRISB2
#define AN5_Lat					LATBbits.LATB3
#define AN5_Tris				TRISBbits.TRISB3



/*Push Buttons Input/Control Pins*/
/*...................................................................
UP  	-> Port A.2
Enter  	-> Port A.3
Down  	-> Port A.8
.....................................................................*/
#define PushB_Up_Lat			LATAbits.LATA2							
#define PushB_Up_Tris			TRISAbits.TRISA2
#define PushB_Up				PORTAbits.RA2

#define PushB_Enter_Lat			LATAbits.LATA3						
#define PushB_Enter_Tris		TRISAbits.TRISA3
#define PushB_Enter				PORTAbits.RA3

#define PushB_Down_Lat			LATAbits.LATA8						
#define PushB_Down_Tris			TRISAbits.TRISA8
#define PushB_Down				PORTAbits.RA8


/*LCD Display Control Pins*/
/*...................................................................
DB07  	 -> Port B.11
DB06  	 -> Port B.12
DB05  	 -> Port B.13
DB04  	 -> Port A.10
E	  	 -> Port A.7
RS	  	 -> Port B.14
LCDPower -> Port B.15
.....................................................................*/
#define LCD_DB7_Lat				LATBbits.LATB11
#define LCD_DB7_Tris			TRISBbits.TRISB11
#define LCD_DB7					PORTBbits.RB11

#define LCD_DB6_Lat				LATBbits.LATB12
#define LCD_DB6_Tris			TRISBbits.TRISB12
#define LCD_DB6					PORTBbits.RB12

#define LCD_DB5_Lat				LATBbits.LATB13
#define LCD_DB5_Tris			TRISBbits.TRISB13
#define LCD_DB5					PORTBbits.RB13

#define LCD_DB4_Lat				LATAbits.LATA10
#define LCD_DB4_Tris			TRISAbits.TRISA10
#define LCD_DB4					PORTAbits.RA10

#define LCD_E_Lat				LATAbits.LATA7
#define LCD_E_Tris				TRISAbits.TRISA7

//#define LCD_RW_Lat	
//#define LCD_RW_Tris

#define LCD_RS_Lat				LATBbits.LATB14
#define LCD_RS_Tris				TRISBbits.TRISB14

#define LCD_Pwr_Lat				LATBbits.LATB15
#define LCD_Pwr_Tris			TRISBbits.TRISB15
#define LCD_Pwr					PORTBbits.RB15


/*Communication Protocols Pins*/
/*...................................................................
I2C-SDA	 -> Port B.9
I2C-SCL	 -> Port B.8
UART-Tx	 -> Port C.4
UART_Rx	 -> Port C.5
LED		 -> Port A.9
.....................................................................*/
#define I2C_SDA_Lat				LATBbits.LATB9
#define I2C_SDA_Tris			TRISBbits.TRISB9
#define I2C_SDA					PORTBbits.RB9

#define I2C_SCL_Lat				LATBbits.LATB8
#define I2C_SCL_Tris			TRISBbits.TRISB8
#define I2C_SCL					PORTBbits.RB8

#define UART_Tx_Lat				LATCbits.LATC4
#define UART_Tx_Tris			TRISCbits.TRISC4
#define UART_Tx					PORTCbits.RC4

#define UART_Rx_Lat				LATCbits.LATC5
#define UART_Rx_Tris			TRISCbits.TRISC5
#define UART_Rx					PORTCbits.RC5


#define LED_Lat					LATAbits.LATA9
#define LED_Tris				TRISAbits.TRISA9
#define LED_Pin					PORTAbits.RA9


/*-----------------------------------------------------------------------------------------*/
void vHardwareCfg_Init( void );
void vCPU_Init( void );
void vPorts_Init( void );
void vOscillator_Init( void );

/*-----------------------------------------------------------------------------------------*/
#endif
