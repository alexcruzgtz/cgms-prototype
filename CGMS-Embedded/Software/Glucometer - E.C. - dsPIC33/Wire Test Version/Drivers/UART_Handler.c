/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Drivers/UART_Handler.h"
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include "Drivers/Oscillator.h"
#include "Drivers/Interrupts.h"
//#include "Scheduler/HardwareConfig.h"


/*-----------------------------------------------------------------------------------------*/
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
//#if defined ( ENABLE_TESTS )
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
