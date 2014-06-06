/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef  _UART_HANDLER_H_
#define  _UART_HANDLER_H_


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include <uart.h>
//#include "Drivers/Compiler.h"
#include "Drivers/Oscillator.h"
//#include "Scheduler/HardwareConfig.h"


/*-----------------------------------------------------------------------------------------*/
#define BAUD_RATE 			9600
#define _9bit_NoParity		3
#define _8bit_OddParity		2
#define _8bit_EvenParity	1	
#define _8bit_NoParity		0

#define UART1_BaudRateGenerator			U1BRG	

#define UART1_TxRegister				U1TXREG
#define UART1_RxRegister				U1RXREG

/*............. U1MODE UART1 Mode Register ................................................*/
#define UART1_ON						U1MODEbits.UARTEN = SET;
#define UART1_OFF						U1MODEbits.UARTEN = CLEAR;
#define UART1_STOP_AT_IDLE				U1MODEbits.USIDL = SET;
#define UART1_CONT_AT_IDLE				U1MODEbits.USIDL = CLEAR;
#define UART1_IRDA_ON					U1MODEbits.IREN = SET;
#define UART1_IRDA_OFF					U1MODEbits.IREN = CLEAR;
#define UART1_RTS_SIMPLEX				U1MODEbits.RTSMD = SET;
#define UART1_RTS_FLOWCTRL				U1MODEbits.RTSMD = CLEAR;
#define UART1_EnableBits				U1MODEbits.UEN		/*UART1 Enable bits
										11 = UxTX, UxRX and BCLK pins are enabled and used; UxCTS pin controlled by port latches
										10 = UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
										01 = UxTX, UxRX and UxRTS pins are enabled and used; UxCTS pin controlled by port latches
										00 = UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLK pins controlled by port latches*/
#define UART1_WAKE_ON					U1MODEbits.WAKE = SET;
#define UART1_WAKE_OFF					U1MODEbits.WAKE = CLEAR;
#define UART1_LOOP_ON					U1MODEbits.LPBACK = SET;
#define UART1_LOOP_OFF					U1MODEbits.LPBACK = CLEAR;
#define UART1_AUTOBAUD_ON				U1MODEbits.ABAUD = SET;
#define UART1_AUTOBAUD_OFF				U1MODEbits.ABAUD = CLEAR;
#define UART1_RXPOL_IDLEZERO			U1MODEbits.URXINV = SET;
#define UART1_RXPOL_IDLEONE				U1MODEbits.URXINV = CLEAR;
#define UART1_HIGHSPEED_BAUD			U1MODEbits.BRGH = SET;
#define UART1_STDSPEED_BAUD				U1MODEbits.BRGH = CLEAR;
#define UART1_ParitySelect				U1MODEbits.PDSEL	/*Parity and Data Selection bits
										11 = 9-bit data, no parity
										10 = 8-bit data, odd parity
										01 = 8-bit data, even parity
										00 = 8-bit data, no parity*/		
#define UART1_ONE_STOP_BIT				U1MODEbits.STSEL = CLEAR;
#define UART1_TWO_STOP_BIT				U1MODEbits.STSEL = SET;	

/*............. U1STA UART1 Status and Control Register ................................*/
#define UART1_Tx_IRQModeb0				U1STAbits.UTXISEL0
#define UART1_Tx_IRQModeb1				U1STAbits.UTXISEL1		/*Transmission Interrupt Mode Selection bits
										11 = Reserved; do not use
										10 = Interrupt when a character is transferred to the Transmit Shift Register (TSR),
										     and as a result, the transmit buffer becomes empty
										01 = Interrupt when the last character is shifted out of the Transmit Shift Register;
										     all transmit operations are completed
										00 = Interrupt when a character is transferred to the Transmit Shift Register
										     (this implies there is at least one character open in the transmit buffer)*/
#define UART1_TXPOL_IDLEZERO			U1STAbits.UTXINV = SET;
#define UART1_TXPOL_IDLEONE				U1STAbits.UTXINV = CLEAR; /*IrDA® Encoder Transmit Polarity Inversion bit
										IREN = 0:
											1 = UxTX Idle ‘0’
											0 = UxTX Idle ‘1’
										IREN = 1:
											1 = UxTX Idle ‘1’
											0 = UxTX Idle ‘0’*/
#define UART1_SYNCBREAK_ON				U1STAbits.UTXBRK = SET;
#define UART1_SYNCBREAK_OFF				U1STAbits.UTXBRK = CLEAR;
#define UART1_TX_ON						U1STAbits.UTXEN = SET;
#define UART1_TX_OFF					U1STAbits.UTXEN = CLEAR;
#define UART1_TxBuffer_Status			U1STAbits.UTXBF
#define UART1_TxShiftRegEmpty_Status	U1STAbits.TRMT
#define UART1_Rx_IRQMode				U1STAbits.URXISEL	/*Receive Interrupt Mode Selection bits
										11 = Interrupt is set on RSR transfer, making the receive buffer full 
											 (i.e., has 4 data characters)
										10 = Interrupt is set on RSR transfer, making the receive buffer 3/4 full
											 (i.e., has 3 data characters)
										0x = Interrupt is set when any character is received and transferred from 
											 the RSR to the receive buffer; receive buffer has one or more characters*/
#define UART1_ADDRDETECT_ON				U1STAbits.ADDEN = SET;
#define UART1_ADDRDETECT_OFF			U1STAbits.ADDEN = CLEAR;
#define UART1_RxIdle_Status				U1STAbits.RIDLE
#define UART1_ParityError_Status		U1STAbits.PERR
#define UART1_FramingError_Status		U1STAbits.FERR
#define UART1_RxBufOverrun_Status		U1STAbits.OERR
#define UART1_RXBUFOVERRUN_CLEAR		U1STAbits.OERR = CLEAR;
#define UART1_RxBufData_Status			U1STAbits.URXDA


/*-----------------------------------------------------------------------------------------*/
void vUART_Init( void );
void vUART_Put( BYTE c );
void vUART_PutROMString( const char* str);
BYTE bUART_Get( void );
void vPrintChar( BYTE );
void vPrintDec( BYTE );

#define vPrintf(x) vUART_PutROMString( (const char*)x )

void vUART_Test( void );

/*-----------------------------------------------------------------------------------------*/
#endif
