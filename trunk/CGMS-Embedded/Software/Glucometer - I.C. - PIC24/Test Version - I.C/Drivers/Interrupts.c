/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "Interrupts.h"

/*-----------------------------------------------------------------------------------------*/
void Interupts_Init(void)
{
	IR_NESTING_DISABLED
	IR_USE_STD_VECTORTABLE
	INT1_EdgeDetect=_NEG_EDGE;
	INT1_IRQ_Priority = _IRQ_LVL_4;
	
	ADC_IRQ_OFF
	ADC_IRQ_Priority = _IRQ_LVL_5;

	SPI_EVENTIRQ_OFF
	SPI_FAULTIRQ_OFF

	I2C1_MASTERIRQ_OFF
	I2C1_SLAVEIRQ_OFF
}

/*.........................................................................................*/
void __attribute__ ((__interrupt__)) _ADC1Interrupt(void)
{
ADC_IRQ_Flag = CLEAR;
}

/*.........................................................................................*/
void _ISRFAST __attribute__((interrupt, auto_psv)) _INT1Interrupt(void)
{
IRQ1_Handler();
}

/*void _ISRFAST __attribute__((interrupt, auto_psv)) _INT2Interrupt(void)
{
IRQ0_Handler();
}*/

/*.........................................................................................*/