/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "Drivers/ADC_Handler.h"
#include <p24fxxxx.h>
#include "Drivers/GenericTypeDefs.h"
#include "Scheduler/HardwareConfig.h"
#include "Drivers/Interrupts.h"

/*-----------------------------------------------------------------------------------------*/
void ADC_Init(void)
{
	ADC_OFF
	ADC_IDLE_MODE_ON
	ADC_OUTPUT_INT
	ADC_CONV_TRIG_INTERNAL
	ADC_HOLD_SAMPLING
	ADC_VREFS_INTERNALS
	ADC_Samp_Conv_Per_Interrupt = ADC_NUM_INPUTS;
	ADC_TWO_8_BUFFER
	ADC_DONT_ALTERNATE_SAMPLING
	ADC_CLOCK_SOURCE_INTERNAL
	ADC_Auto_Sample_Time = _2_TAD;
	ADC_Conv_Clock = _1_TCY;
	ADC_MB_NEG_INPUT_VRNEG
	ADC_MB_Pos_Input = 0; //ADC_DEFAULT_CH;
	ADC_MA_NEG_INPUT_VRNEG
	ADC_MA_Pos_Input = 0; //ADC_DEFAULT_CH;
	ADC_BAND_GAP_REF_DISABLED
	//ADC_HALFBAND_REF_DISABLED
	ADC_INT_VREG_CH_DISABLED
	ADC_Analog_Pins_Cfg = ANALOGPINS_CFG;
	ADC_BAND_GAP_DISABLED
	ADC_HALF_BAND_GAP_DISABLED
	ADC_INT_VREG_DISABLED
	ADC_Scan_Pins_Enabled = ANALOG_SCANCHANNELS;
	//ptr_ADCBuffer = &ADC1BUF0;
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
