/********************************************************************
* FileName:		Console.h
* Dependencies: none
* Processor:	PIC18, PIC24F, PIC24H, dsPIC30, dsPIC33
*               tested with 18F4620, dsPIC33FJ256GP710	
* Hardware:		PICDEM Z, Explorer 16
* Complier:     Microchip C18 v3.04 or higher
*				Microchip C30 v2.03 or higher
*               Microchip C32 v1.02 or higher
* Company:		Microchip Technology, Inc.
*
* Copyright Â© 2007-2010 Microchip Technology Inc.  All rights reserved.
*
* Microchip licenses to you the right to use, modify, copy and distribute 
* Software only when embedded on a Microchip microcontroller or digital 
* signal controller and used with a Microchip radio frequency transceiver, 
* which are integrated into your product or third party product (pursuant 
* to the terms in the accompanying license agreement). 
*
* You should refer to the license agreement accompanying this Software for 
* additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED Â“AS ISÂ” WITHOUT WARRANTY OF ANY 
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY 
* WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A 
* PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE 
* LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, 
* CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY 
* DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO 
* ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, 
* LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, 
* TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT 
* NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*
*********************************************************************
* File Description:
*
*  This header file allows usage of the console functions located
*   in Console.c
*
* Change History:
*  Rev   Date         Author    Description
*  0.1   11/09/2006   yfy       Initial revision
*  1.0   01/09/2007   yfy       Initial release
*  2.0   4/15/2009    yfy       MiMAC and MiApp revision
*  3.1   5/28/2010    yfy       MiWi DE 3.1
*  4.1   6/3/2011     yfy       MAL v2011-06
********************************************************************/

/*-----------------------------------------------------------------------------------------*/
#ifndef  _UART_HANDLER_H_
#define  _UART_HANDLER_H_


/*-----------------------------------------------------------------------------------------*/
#include <p24fxxxx.h>
#include <GenericTypeDefs.h>
#include "Drivers/Compiler.h"
#include "Drivers/Oscillator.h"
//#include "Scheduler/HardwareConfig.h"
#include "Drivers/Wireless/MiWi_ConfigApp.h"
//#include "Drivers/Wireless/MiWi_P2P.h"


/*-----------------------------------------------------------------------------------------*/
#define BAUD_RATE 9600
#define _9bit_NoParity		3
#define _8bit_OddParity		2
#define _8bit_EvenParity	1	
#define _8bit_NoParity		0

/*............. UxMODE -> UARTx Mode Register .............................................*/
#define UART1_ON					U1MODEbits.UARTEN = SET;
#define UART1_OFF					U1MODEbits.UARTEN = CLEAR;
#define UART1_STOP_AT_IDLE			U1MODEbits.USIDL = SET;
#define UART1_CONT_AT_IDLE			U1MODEbits.USIDL = CLEAR;
#define UART1_IRDA_ON				U1MODEbits.IREN = SET;
#define UART1_IRDA_OFF				U1MODEbits.IREN = CLEAR;
#define UART1_RTS_SIMPLEX			U1MODEbits.RTSMD = SET;
#define UART1_RTS_FLOW				U1MODEbits.RTSMD = CLEAR;
#define UART1_WAKESLEEP_ON			U1MODEbits.WAKE = SET;
#define UART1_WAKESLEEP_OFF			U1MODEbits.WAKE = CLEAR;
#define UART1_LOOP_ON				U1MODEbits.LPBACK = SET;
#define UART1_LOOP_OFF				U1MODEbits.LPBACK = CLEAR;
#define UART1_AUTOBAUD_ON			U1MODEbits.ABAUD = SET;
#define UART1_AUTOBAUD_OFF			U1MODEbits.ABAUD = CLEAR;
#define UART1_RXPOL_IDLEZERO		U1MODEbits.RXINV = SET;
#define UART1_RXPOL_IDLEONE			U1MODEbits.RXINV = CLEAR;
#define UART1_HIGHSPEED_BAUD		U1MODEbits.BRGH = SET;
#define UART1_STDSPEED_BAUD			U1MODEbits.BRGH = CLEAR;
#define UART1_ParitySelect			U1MODEbits.PDSEL		/*Parity and Data Selection bits
									11 = 9-bit data, no parity
									10 = 8-bit data, odd parity
									01 = 8-bit data, even parity
									00 = 8-bit data, no parity*/		
#define UART1_ONE_STOP_BIT			U1MODEbits.STSEL = CLEAR;
#define UART1_TWO_STOP_BIT			U1MODEbits.STSEL = SET;

/*............. UxSTA -> UARTx Status and Control Register ................................*/
#define UART1_Tx_IRQModeb0			U1STAbits.UTXISEL0
#define UART1_Tx_IRQModeb1			U1STAbits.UTXISEL1		/*Transmission Interrupt Mode Selection bits
									11 = Reserved; do not use
									10 = Interrupt when a character is transferred to the Transmit Shift Register (TSR),
									     and as a result, the transmit buffer becomes empty
									01 = Interrupt when the last character is shifted out of the Transmit Shift Register;
									     all transmit operations are completed
									00 = Interrupt when a character is transferred to the Transmit Shift Register
									     (this implies there is at least one character open in the transmit buffer)*/
#define UART1_TXPOL_IDLEZERO		U1STAbits.UTXINV = SET;
#define UART1_TXPOL_IDLEONE			U1STAbits.UTXINV = CLEAR; /*IrDA® Encoder Transmit Polarity Inversion bit
									IREN = 0:
										1 = UxTX Idle ‘0’
										0 = UxTX Idle ‘1’
									IREN = 1:
										1 = UxTX Idle ‘1’
										0 = UxTX Idle ‘0’*/
#define UART1_SYNCBREAK_ON			U1STAbits.UTXBRK = SET;
#define UART1_SYNCBREAK_OFF			U1STAbits.UTXBRK = CLEAR;
#define UART1_TX_ON					U1STAbits.UTXEN = SET;
#define UART1_TX_OFF				U1STAbits.UTXEN = CLEAR;
#define UART1_TxBuffer_Status		U1STAbits.UTXBF
#define UART1_TxShiftRegEmpty		U1STAbits.TRMT
#define UART1_Rx_IRQMode			U1STAbits.URXISEL	/*Receive Interrupt Mode Selection bits
									11 = Interrupt is set on RSR transfer, making the receive buffer full 
										 (i.e., has 4 data characters)
									10 = Interrupt is set on RSR transfer, making the receive buffer 3/4 full
										 (i.e., has 3 data characters)
									0x = Interrupt is set when any character is received and transferred from 
										 the RSR to the receive buffer; receive buffer has one or more characters*/
#define UART1_ADDRDETECT_ON			U1STAbits.ADDEN = SET;
#define UART1_ADDRDETECT_OFF		U1STAbits.ADDEN = CLEAR;
#define UART1_RxIdle_Status			U1STAbits.RIDLE
#define UART1_ParityError_Status	U1STAbits.PERR
#define UART1_FramingError_Status	U1STAbits.FERR
#define UART1_RxBufOverrun_Status	U1STAbits.OERR
#define UART1_RXBUFOVERRUN_CLEAR	U1STAbits.OERR = CLEAR;
#define UART1_RxBufData_Status		U1STAbits.URXDA


#define UART1_BaudRateGenerator		U1BRG

#define UART1_TxRegister			U1TXREG
#define UART1_RxRegister			U1RXREG


/*-----------------------------------------------------------------------------------------*/
#if defined( ENABLE_UART )
	void ConsoleInit( void );
    //#define ConsoleIsPutReady()     ( U1STAbits.TRMT )
    void ConsolePut( BYTE c );
    //void ConsolePutString(BYTE *s);
    void ConsolePutROMString( ROM char* str );
    //#define ConsoleIsGetReady()     ( UART1_RxIRQ_Flag )
    BYTE ConsoleGet( void );
    //BYTE ConsoleGetString(char *buffer, BYTE bufferLen);
    void PrintChar( BYTE );
    void PrintDec( BYTE );
	//#ifdef __ENABLE_TESTS__
		void UART_Test( void );	
	//#endif
#else
    #define ConsoleInit()
    #define ConsoleIsPutReady() 1
    #define ConsolePut(c)
	#define ConsolePutString(s)
    #define ConsolePutROMString(str)
    #define ConsoleIsGetReady() 1
    #define ConsoleGet()        'a'
    #define ConsoleGetString(buffer, bufferLen) 0
    #define PrintChar(a)
    #define PrintDec(a)
#endif

#define Printf(x) ConsolePutROMString( (ROM char*)x )
//#define printf(x) ConsolePutROMString((ROM char*)x)


/*-----------------------------------------------------------------------------------------*/
#endif
