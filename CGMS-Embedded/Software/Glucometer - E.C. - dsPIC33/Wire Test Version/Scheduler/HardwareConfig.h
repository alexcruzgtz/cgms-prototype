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
#include "Dirvers/CPU.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"

/*-----------------------------------------------------------------------------------------*/

#define Config_CFGBits(); 		_FBS(BWRP_WRPROTECT_OFF & RBS_NO_BOOT_RAM)\
								_FSS(SWRP_WRPROTECT_OFF & SSS_NO_SEC_CODE & RSS_NO_SEC_RAM)\
								_FGS(GWRP_OFF & GCP_OFF)\
								_FOSCSEL(FNOSC_FRC & IESO_ON)\
								_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_ON & FCKSM_CSECME)\
								_FWDT(WDTPOST_PS128 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF)\
								_FPOR(FPWRT_PWR1 & ALTI2C_OFF & LPOL_OFF & HPOL_OFF & PWMPIN_ON)\
								_FICD(JTAGEN_OFF)

#define IOPORT_A_CFG			0b00000000010
#define IOPORT_B_CFG 			0b0000001000001111
#define IOPORT_C_CFG			0b0000100111


/*Analog Pins*/
/*...................................................................
Vgnd	-> AN1 Port A.1
Vout	-> AN2 Port B.0
CNT		-> AN3 Port B.1
Vctrl	-> AN4 Port B.2
REF		-> AN5 Port B.3
.....................................................................*/
#define ANALOGPINS_CFG 			0b111000001

#define _VGND_CH				1
#define _VOUT_CH				2
#define _CNT_CH					3
#define _VCRTL_CH				4
#define _REF_CH					5
#define _DEFAULT_CH				_VGND_CH

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
UP  	-> Port C.0
Enter  	-> Port C.1
Down  	-> Port C.2
.....................................................................*/
#define PushB_Up_Lat			LATCbits.LATC0							
#define PushB_Up_Tris			TRISCbits.TRISC0
#define PushB_Up				PORTCbits.RC0

#define PushB_Enter_Lat			LATCbits.LATC1						
#define PushB_Enter_Tris		TRISCbits.TRISC1
#define PushB_Enter				PORTCbits.RC1

#define PushB_Down_Lat			LATCbits.LATC2							
#define PushB_Down_Tris			TRISCbits.TRISC2
#define PushB_Down				PORTCbits.RC2


/*LCD Display Control Pins*/
/*...................................................................
DB07  	 -> Port C.6
DB06  	 -> Port C.7
DB05  	 -> Port C.8
DB04  	 -> Port C.9
E	  	 -> Port B.10
RS	  	 -> Port B.11
LCDPower -> Port B.12
.....................................................................*/
#define LCD_DB7_Lat				LATCbits.LATC6
#define LCD_DB7_Tris			TRISCbits.TRISC6
#define LCD_DB7					PORTCbits.RC6

#define LCD_DB6_Lat				LATCbits.LATC7
#define LCD_DB6_Tris			TRISCbits.TRISC7
#define LCD_DB6					PORTCbits.RC7

#define LCD_DB5_Lat				LATCbits.LATC8
#define LCD_DB5_Tris			TRISCbits.TRISC8
#define LCD_DB5					PORTCbits.RC8

#define LCD_DB4_Lat				LATCbits.LATC9
#define LCD_DB4_Tris			TRISCbits.TRISC9
#define LCD_DB4					PORTCbits.RC9

#define LCD_E_Lat				LATBbits.LATB10
#define LCD_E_Tris				TRISBbits.TRISB10

//#define LCD_RW_Lat	
//#define LCD_RW_Tris

#define LCD_RS_Lat				LATBbits.LATB11
#define LCD_RS_Tris				TRISBbits.TRISB11

#define LCD_Pwr_Lat				LATBbits.LATB12
#define LCD_Pwr_Tris			TRISBbits.TRISB12
#define LCD_Pwr					PORTBbits.RB12


/*Communication Protocols Pins*/
/*...................................................................
I2C-SDA	 -> Port B.9
I2C-SCL	 -> Port B.8
UART-Tx	 -> Port C.4
UART_Rx	 -> Port C.5
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


//#define LED_Lat				LATBbits.LATB14
//#define LED_Tris				TRISBbits.TRISB14
//#define LED_Pin				PORTBbits.RB14


/*-----------------------------------------------------------------------------------------*/
void HardwareCfg_Init( void );
void CPU_Init( void );
void Ports_Init( void );
void Oscillator_Init( void );

/*-----------------------------------------------------------------------------------------*/
#endif
