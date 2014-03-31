/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Drivers/ADC_Handler.h"
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include "Scheduler/HardwareConfig.h"
#include "Drivers/Interrupts.h"


/*-----------------------------------------------------------------------------------------*/
void ADC_Init( void )
{
	ADC_OFF
	ADC_IDLE_ON
	ADC_DMABUF_INORDER
	ADC_1CH_12b	
	ADC_DataOutFormat = 0b01;		//signed Integer
	ADC_SampleClkSource = 0b000; 	//Clearing sample bit ends sampling and starts conversion
	ADC_SIMULTANEOUSSAMPLE_OFF
	ADC_MANUAL_START
	ADC_HOLD_SAMPLING
	
	ADC_VREFS_INTERNALS
	ADC_DONTSCAN
	ADC_NumSamp_PerIRQ = 0b001;
	ADC_ONE_16_BUFFER
	ADC_DONT_ALTERNATE_SAMPLING
		
	ADC_CLOCK_SOURCE_INTERNAL
	ADC_Auto_Sample_Time = _1_TAD;

	ADC_CH0_BNegInput = 0b1;
	ADC_CH0_BPosInput = 0b00001;
	ADC_CH0_ANegInput = 0b1;
	ADC_CH0_APosInput = 0b00001;
	
	ADC_ScanPins = ANALOG_SCANCHANNELS;

	ADC_PortCfg = ANALOG_SCANCHANNELS;

}

/*.........................................................................................*/
/*void ADC_GetAll(UINT16 *ADCBufAddress)
{
	UINT16 i = 0;
	if(!ADC_Buf_Status)
	{
		ptr_ADCBuffer = &(ADC1BUF0+ADC_BUF_OFFSET);
	}
	else
	{
		ptr_ADCBuffer = &ADC1BUF0;
	}
	for(i; i <= ADC_NUM_INPUTS+1 ; i++)
	{
		*(ADCBufAddress+i) = *(ptr_ADCBuffer+i);
	}
}
*/
/*.........................................................................................*/
/*UINT16 ADC_MakeOne(UINT16 ADCAnalogInput)
{
	ADC_OFF
	ADC_IRQ_OFF
	ADC_MANUAL_START
	ADC_DONT_SCAN_INPUTS
	ADC_HOLD_SAMPLING
	ADC_CLEAR_CONV_DONE
	ADC_MA_Pos_Input = ADCAnalogInput;
	ADC_ON
	ADC_START_SAMPLING
	while(!ADC_Conv_Done){}
	return ADC1BUF0;
}
*/
/*.........................................................................................*/
/*void ADC_StartAll(void)
{	
	ADC_OFF
	ADC_IRQ_Flag = CLEAR;
	ADC_IRQ_ON
	ADC_AUTO_START
	ADC_SCAN_INPUTS
	ADC_CLEAR_CONV_DONE
	ADC_ON
	ADC_START_SAMPLING
}
*/
/*.........................................................................................*/
/*void ADC_StopAll(void)
{
	ADC_HOLD_SAMPLING
	ADC_IRQ_OFF
	ADC_OFF
}
*/
