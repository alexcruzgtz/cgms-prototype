/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Drivers/Interrupts.h"
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
//#include "ADC_Handler.h"
#include "Scheduler/HardwareConfig.h"


/*-----------------------------------------------------------------------------------------*/
void vInterrupts_Init(void)
{

	//IR_NESTING_DISABLED
	//UART1_RxIRQ_Priority = _LVL_5;
	//UART1_TxIRQ_Priority = _LVL_4;
	//ADC_IRQ_OFF

	//I2C1_MASTERIRQ_OFF
	//I2C1_SLAVEIRQ_OFF
	
	//UART1_TXIRQ_OFF
	//UART1_RXIRQ_OFF
	//UART1_ERRIRQ_OFF
	
}

/*.........................................................................................*/
/*void __attribute__ ((__interrupt__)) _ADC1Interrupt(void)
{
ADC_IRQ_Flag = CLEAR;
}
*/
/*.........................................................................................*/
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void)
{  
   IFS0bits.U1TXIF = 0;
} 
/* This is UART1 receive ISR */
void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0;
/* Read the receive buffer till atleast one or more character can be read */ 
	LED_Lat ^= 1;
} 
/*.........................................................................................*/


/*-----------------------------------------------------------------------------------------*/
