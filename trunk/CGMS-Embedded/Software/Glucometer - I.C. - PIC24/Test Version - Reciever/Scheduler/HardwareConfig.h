/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef __HARDWARE_CONFIG_H
#define __HARDWARE_CONFIG_H

/*-----------------------------------------------------------------------------------------*/
#include <p24fxxxx.h>
#include <PPS.h>
#include <GenericTypeDefs.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
#include "Drivers/SPI_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"

/*-----------------------------------------------------------------------------------------*/
#define __PIC24FJ64GA102__

#define IOPORTA_CFG			0b00000
#define IOPORTB_CFG 		0b1010000010100000
#define ANALOGPINS_CFG 		0b0000000000000

#define LED_Lat				LATBbits.LATB14
#define LED_Tris			LATBbits.TRISB14
#define LED_Pin				PORTBbits.RB14

#define PushB_Lat			LATBbits.LATB15							
#define PushB_Tris			LATBbits.TRISB15
#define PushB_Pin			PORTBbits.RB15


/*Wireless Transceiver Control Pins*/
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


/*LCD Display Control Pins*/
/*...................................................................
DB07  -> Port B Pin 3
DB06  -> Port B Pin 2
DB05  -> Port B Pin 1
DB04  -> Port B Pin 0
RS	  -> Port A Pin 0
E	  -> Port A Pin 1
.....................................................................*/
#define LCD_Pin7_Lat		LATBbits.LATB3
#define LCD_Pin6_Lat		LATBbits.LATB2
#define LCD_Pin5_Lat		LATBbits.LATB1
#define LCD_Pin4_Lat		LATBbits.LATB0
#define LCD_Pin7			PORTBbits.RB3
#define LCD_Pin6			PORTBbits.RB2
#define LCD_Pin5			PORTBbits.RB1
#define LCD_Pin4			PORTBbits.RB0
#define LCD_Pin7_Tris		TRISBbits.TRISB3
#define LCD_Pin6_Tris		TRISBbits.TRISB2
#define LCD_Pin5_Tris		TRISBbits.TRISB1
#define LCD_Pin4_Tris		TRISBbits.TRISB0
#define LCD_PinE_Lat		LATAbits.LATA1
#define LCD_PinRS_Lat		LATAbits.LATA0
//#define LCD_PinRW_Lat		
#define LCD_PinE_Tris		TRISAbits.TRISA1
#define LCD_PinRS_Tris		TRISAbits.TRISA0
//#define LCD_PinRW_Tris



/*-----------------------------------------------------------------------------------------*/
void HardwareCfg_Init(void);
void Cfg_PPS(void);
void Cfg_CFGBits(void);
void Cfg_Ports(void);
/*-----------------------------------------------------------------------------------------*/



#endif
