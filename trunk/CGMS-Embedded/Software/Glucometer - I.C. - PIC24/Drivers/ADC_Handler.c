/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <p24fj64ga102.h>
#include "GenericTypeDefs.h"
#include "ADC_Handler.h"

/*-----------------------------------------------------------------------------------------*/
extern void ADC_Init(void);
extern void ADC_ReadMeasurements(uint16_t *ADCBufAddress);


/*-----------------------------------------------------------------------------------------*/
void ADC_ReadAllMeasurements(uint16_t *ADCBufAddress)
{
	uint16_t i=0;
	if(!ADC_Buf_Status)
	{
		ptr_ADCBuffer=&(ADC1BUF0+ADC_BUF_OFFSET);
	}
	else
	{
		ptr_ADCBuffer=&ADC1BUF0;
	}
	for(i;i<ADC_NUM_INPUTS+1;i++)
	{
		*(ADCBufAddress+i)=*(ptr_ADCBuffer+i);
	}
}

/*.........................................................................................*/
uint16_t ADC_MakeOneMeasurement(uint16_t ADCAnalogInput)
{
	_ADC_OFF
	_ADC_INTERRUPT_OFF
	_ADC_MANUAL_START
	_ADC_DONT_SCAN_INPUTS
	_ADC_HOLD_SAMPLING
	_ADC_CLEAR_CONV_DONE
	ADC_MA_Pos_Input=ADCAnalogInput;
	_ADC_ON
	_ADC_START_SAMPLING
	while(!ADC_Conv_Done){}
	return ADC1BUF0;
}

/*.........................................................................................*/
void ADC_StartMeasurements(void)
{	
	_ADC_OFF
	_ADC_INTERRUPT_ON
	ADC_Interrupt_Flag=CLEAR;
	_ADC_AUTO_START
	_ADC_SCAN_INPUTS
	_ADC_CLEAR_CONV_DONE
	_ADC_ON
	_ADC_START_SAMPLING
}

void ADC_StopMeasurements(void)
{
	_ADC_HOLD_SAMPLING
	_ADC_INTERRUPT_OFF
	_ADC_OFF
}
/*.........................................................................................*/
void ADC_Init(void)
{
	_ADC_OFF
	_ADC_IDLEMODE_ON
	_ADC_OUTPUT_INT
	_ADC_CONV_TRIGG_INTERNAL
	_ADC_HOLD_SAMPLING
	_ADC_VREFS_INTERNALS
	ADC_Samp_Conv_Per_Interrupt=ADC_NUM_INPUTS;
	_ADC_TWO_8_BUFFER
	_ADC_DONT_ALTERNATE_SAMPLING
	_ADC_CLOCK_SOURCE_INTERNAL
	ADC_Auto_Sample_Time=_2_TAD;
	ADC_Conv_Clock=_1_TCY;
	_ADC_MB_NEG_INPUT_VRNEG
	ADC_MB_Pos_Input=0x00;
	_ADC_MA_NEG_INPUT_VRNEG
	ADC_MA_Pos_Input=0x00;
	_ADC_BAND_GAP_REF_DISABLED
	_ADC_HALF_BAND_REF_DISABLED
	_ADC_INT_VREG_CH_DISABLED
	ADC_Analog_Pins_Cfg=0b1111111000001;
	_ADC_BAND_GAP_DISABLED
	_ADC_HALF_BAND_GAP_DISABLED
	_ADC_INT_VREG_DISABLED
	ADC_Scan_Pins_Enabled=0b1111111000001;
	ptr_ADCBuffer=&ADC1BUF0;
	ADC_Interrupt_Priority=5;
}