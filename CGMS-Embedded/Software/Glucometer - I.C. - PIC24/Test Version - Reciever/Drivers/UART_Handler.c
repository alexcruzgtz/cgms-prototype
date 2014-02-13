/********************************************************************
* FileName:		Console.c (File name changed to UART_Handler)
* Dependencies: Console.h
* Processor:	PIC18, PIC24F, PIC32, dsPIC30, dsPIC33
*               tested with 18F4620, dsPIC33FJ256GP710	
* Hardware:		PICDEM Z, Explorer 16, PIC18 Explorer
* Complier:     Microchip C18 v3.04 or higher
*				Microchip C30 v2.03 or higher
*               Microchip C32 v1.02 or higher	
* Company:		Microchip Technology, Inc.
*
* Copyright © 2007-2010 Microchip Technology Inc.  All rights reserved.
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
* SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY 
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
*   This file configures and provides the function for using the
*   UART to transmit data over RS232 to the computer.
*
* Change History:
*  Rev   Date         Author    Description
*  0.1   11/09/2006   yfy       Initial revision
*  1.0   01/09/2007   yfy       Initial release
*  2.0   4/24/2009    yfy       Modified for MiApp interface
*  2.1   6/20/2009    yfy       Add LCD support
*  3.1   5/28/2010    yfy       MiWi DE 3.1
*  4.1   6/3/2011     yfy       MAL v2011-06
********************************************************************/

#include "Drivers/UART_Handler.h"
#include <p24fxxxx.h>
#include "Drivers/Compiler.h"
#include <GenericTypeDefs.h>
#include "Drivers/Oscillator.h"
#include "Drivers/Interrupts.h"
//#include "Scheduler/HardwareConfig.h"
#include "Drivers/Wireless/MiWi_ConfigApp.h"
//#include "Drivers/Wireless/MiWi_P2P.h"

/*-----------------------------------------------------------------------------------------*/
#if defined( ENABLE_UART )
	ROM unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

/*-----------------------------------------------------------------------------------------*/
/*********************************************************************
* Function:         void ConsoleInit(void)
* PreCondition:     none
* Input:		    none
* Output:		    none
* Side Effects:	    UART1 is configured
* Overview:		    This function will configure the UART for use at 
*                   in 8 bits, 1 stop, no flowcontrol mode
* Note:			    None
********************************************************************/
void ConsoleInit( void )
{
	UART1_BaudRateGenerator = 25;//((FCY/BAUD_RATE)/16 ) - 1;
    UART1_RxIRQ_Flag = 0;
	UART1_TxIRQ_Flag = 0;

	//... Configuring UxSTA Register
    UART1_Tx_IRQModeb0 = 0;
    UART1_Tx_IRQModeb1 = 0;
	UART1_TXPOL_IDLEONE
	UART1_SYNCBREAK_OFF
	UART1_TX_OFF
	UART1_Rx_IRQMode = 0;
	UART1_ADDRDETECT_OFF
	UART1_RXBUFOVERRUN_CLEAR
	
	//... Configuring UxMODE Segister
	UART1_OFF
	UART1_CONT_AT_IDLE    
	UART1_IRDA_OFF
	UART1_RTS_FLOW
	UART1_WAKESLEEP_ON
	UART1_LOOP_OFF
	UART1_AUTOBAUD_OFF
	UART1_RXPOL_IDLEONE
	UART1_STDSPEED_BAUD
	UART1_ParitySelect = _8bit_NoParity;
	UART1_ONE_STOP_BIT
	
	//... Starting UART
	UART1_ON
    UART1_TX_ON
}

/*.........................................................................................*/
/*********************************************************************
* Function:         void ConsolePutROMString(ROM char* str)
* PreCondition:     none
* Input:		    str - ROM string that needs to be printed
* Output:		    none
* Side Effects:	    str is printed to the console
* Overview:		    This function will print the inputed ROM string
* Note:			    Do not power down the microcontroller until 
*                   the transmission is complete or the last 
*                   transmission of the string can be corrupted.  
********************************************************************/
void ConsolePutROMString( ROM char* str )
{
    BYTE c;
    while( (c = *str++) )
        ConsolePut(c);
}

/*.........................................................................................*/
/*********************************************************************
* Function:         void ConsolePut(BYTE c)
* PreCondition:     none
* Input:		    c - character to be printed
* Output:		    none
* Side Effects:	    c is printed to the console
* Overview:		    This function will print the inputed character
* Note:			    Do not power down the microcontroller until 
*                   the transmission is complete or the last 
*                   transmission of the string can be corrupted.  
********************************************************************/
void ConsolePut( BYTE c )
{
    while(UART1_TxShiftRegEmpty == 0);
    UART1_TxRegister = c;
}

/*.........................................................................................*/
/*********************************************************************
* Function:         BYTE ConsoleGet(void)
* PreCondition:     none
* Input:		    none
* Output:		    one byte received by UART
* Side Effects:	    none
* Overview:		    This function will receive one byte from UART
* Note:			    Do not power down the microcontroller until 
*                   the transmission is complete or the last 
*                   transmission of the string can be corrupted.  
********************************************************************/
BYTE ConsoleGet( void )
{
	char Temp;
    while(UART1_RxIRQ_Flag == 0);
	Temp = UART1_RxRegister;
    UART1_RxIRQ_Flag = 0;
	return Temp;
}

/*.........................................................................................*/
/*********************************************************************
* Function:         void PrintChar(BYTE toPrint)
* PreCondition:     none
* Input:		    toPrint - character to be printed
* Output:		    none
* Side Effects:	    toPrint is printed to the console
* Overview:		    This function will print the inputed BYTE to 
*                   the console in hexidecimal form
* Note:			    Do not power down the microcontroller until 
*                   the transmission is complete or the last 
*                   transmission of the string can be corrupted.  
********************************************************************/
void PrintChar( BYTE toPrint )
{
    BYTE PRINT_VAR;
    PRINT_VAR = toPrint;
    toPrint = (toPrint>>4) & 0x0F;
    ConsolePut( CharacterArray[toPrint] );
    toPrint = (PRINT_VAR) & 0x0F;
    ConsolePut( CharacterArray[toPrint] );
    return;
}

/*.........................................................................................*/
/*********************************************************************
* Function:         void PrintDec(BYTE toPrint)
* PreCondition:     none
* Input:		    toPrint - character to be printed. Range is 0-99
* Output:		    none
* Side Effects:	    toPrint is printed to the console in decimal
* Overview:		    This function will print the inputed BYTE to 
*                   the console in decimal form
* Note:			    Do not power down the microcontroller until 
*                   the transmission is complete or the last 
*                   transmission of the string can be corrupted.  
********************************************************************/
void PrintDec( BYTE toPrint )
{
    ConsolePut( CharacterArray[toPrint/10] );
    ConsolePut( CharacterArray[toPrint%10] );
}

/*.........................................................................................*/
//#if defined ( __ENABLE_TESTS__ )
	void UART_Test( void )
	{
		ConsoleInit();
		BYTE i;
		for( i=0 ; i<10 ; i++ )
		{
			ConsolePut('A');
		}
		ConsolePutROMString("\r\n Hola! \n");
		PrintChar("A");
		PrintDec(50);
		Printf("\r ... UART Test OK ... \n");
		Printf("\r Presiona una tecla \n");
		i=ConsoleGet();
		Printf("\r Tecla Presionada: ");
		ConsolePut(i);
		Printf("\r\n Adios! ");
	}
//#endif


/*-----------------------------------------------------------------------------------------*/
#endif
