/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Drivers/UART_Handler.h"
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include <uart.h>
#include "Drivers/Oscillator.h"
#include "Drivers/Interrupts.h"
//#include "Scheduler/HardwareConfig.h"


/*-----------------------------------------------------------------------------------------*/
const unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

/*-----------------------------------------------------------------------------------------*/

void vUART_Init( void )
{
	/*UART1_BaudRateGenerator = 25;//((FCY/BAUD_RATE)/16 ) - 1;
    UART1_RxIRQ_Flag = 0;
	UART1_TxIRQ_Flag = 0;

	//... Configuring U1STA Register
    UART1_Tx_IRQModeb0 = 0b00;
    UART1_Tx_IRQModeb1 = 0b00;
	UART1_TXPOL_IDLEONE
	UART1_SYNCBREAK_OFF
	UART1_TX_OFF
	UART1_Rx_IRQMode = 0b00;
	UART1_ADDRDETECT_OFF
	UART1_RXBUFOVERRUN_CLEAR
	
	//... Configuring U1MODE Segister
	UART1_OFF
	UART1_CONT_AT_IDLE    
	UART1_IRDA_OFF
	UART1_RTS_FLOWCTRL
	UART1_EnableBits = 0b00;
	UART1_WAKE_ON
	UART1_LOOP_OFF
	UART1_AUTOBAUD_OFF
	UART1_RXPOL_IDLEONE
	UART1_STDSPEED_BAUD
	UART1_ParitySelect = _8bit_NoParity;
	UART1_ONE_STOP_BIT
	
	//... Starting UART
	UART1_ON
    UART1_TX_ON
	*/
	UINT U1MODEvalue, U1STAvalue;
	
	CloseUART1();
/* Configure uart1 receive and transmit interrupt */
    ConfigIntUART1(UART_RX_INT_EN & UART_RX_INT_PR6 & 
                   UART_TX_INT_DIS & UART_TX_INT_PR2);
/* Configure UART1 module to transmit 8 bit data with one stopbit. Also Enable loopback mode  */
	U1MODEvalue = UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE & UART_MODE_SIMPLEX &
			UART_UEN_00 & UART_DIS_WAKE &
			UART_EN_LOOPBACK & UART_DIS_ABAUD &
			UART_BRGH_SIXTEEN & UART_NO_PAR_8BIT & UART_1STOPBIT;
 
	U1STAvalue = UART_INT_TX_BUF_EMPTY & UART_TX_ENABLE &
			 UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR &
			 UART_IrDA_POL_INV_ZERO & UART_SYNC_BREAK_DISABLED;
 
	OpenUART1 (U1MODEvalue, U1STAvalue, 2);

}

/*.........................................................................................*/
void vUART_PutROMString( const char *str )
{
    BYTE c;
    while( (c = *str++) )
    	vUART_Put(c);
}

/*.........................................................................................*/
void vUART_Put( BYTE c )
{
    while(UART1_TxShiftRegEmpty_Status == 0);
    UART1_TxRegister = c;

}

/*.........................................................................................*/
BYTE bUART_Get( void )
{
	char Temp;
    while(UART1_RxIRQ_Flag == 0);
	Temp = UART1_RxRegister;
    UART1_RxIRQ_Flag = 0;
	return Temp;
}

/*.........................................................................................*/
void vPrintChar( BYTE toPrint )
{
    BYTE PRINT_VAR;
    PRINT_VAR = toPrint;
    toPrint = (toPrint>>4) & 0x0F;
    vUART_Put( CharacterArray[toPrint] );
    toPrint = (PRINT_VAR) & 0x0F;
    vUART_Put( CharacterArray[toPrint] );
    return;
}

/*.........................................................................................*/
void vPrintDec( BYTE toPrint )
{
    vUART_Put( CharacterArray[toPrint/10] );
    vUART_Put( CharacterArray[toPrint%10] );
}

/*.........................................................................................*/
void vUART_Test( void )
{
	//vUART_Init();
	//while(UART1_TxShiftRegEmpty_Status == 0);
    //UART1_TxRegister = 0x55;
	//BYTE i;
	//for( i=0 ; i<10 ; i++ )
	//{
		//vUART_Put('A');
	//}
	/*vUART_PutROMString((const char *)"A");
	
	vPrintChar('A');
	vPrintDec(50);
	vPrintf("\r ... UART Test OK ... \n");
	vPrintf("\r Presiona una tecla \n");
	i = bUART_Get();
	vPrintf("\r Tecla Presionada: ");
	vUART_Put(i);
	vPrintf("\r\n Adios! ");*/
}



/*-----------------------------------------------------------------------------------------*/

