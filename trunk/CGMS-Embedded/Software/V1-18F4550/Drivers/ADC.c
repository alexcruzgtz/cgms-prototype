
#include <p18f4550.h>
#include "ADC.h"

/*-----------------------------------------------------------------------------------------*/
void ADC_PowerOn(void);
void ADC_StartConvertion(void);
void ADC_Select_Channel(unsigned char Channel);
void Initialize_ADC(void);
void ADC_Select_Reference_Positive(unsigned char Reference);
void ADC_Select_Reference_Negative(unsigned char Reference);
void ADC_SetAcquisitionTime(unsigned char AcquisitionTime);
void ADC_ConversionClocks(unsigned char ConversionClock);
unsigned int ReadADC(void);

/*-----------------------------------------------------------------------------------------*/
void ADC_PowerOn(void)
{
	ADCON0bits.ADON=0x01;	
}

/*-----------------------------------------------------------------------------------------*/
void ADC_StartConvertion(void)
{
	ADCON0bits.GO=0x01;
}

/*-----------------------------------------------------------------------------------------*/
void ADC_Select_Channel(unsigned char Channel)
{
	if(Channel<12)
	{
		ADCON0=((ADCON0 & 0xC3)|(Channel<<2));
		//ADCON1=(ADCON1|(0x0f-(Channel-1)));
	}
	else
	{
		
	}
}

/*-----------------------------------------------------------------------------------------*/
void ADC_Select_Reference_Positive(unsigned char Reference)
{
	if(Reference==EXTERNAL)
	{
		ADCON1bits.VCFG0=0x01;
		TRISAbits.TRISA3=0x01;
		ADCON1bits.PCFG3=0x00;
		ADCON1bits.PCFG2=0x01;
		ADCON1bits.PCFG1=0x01;
		ADCON1bits.PCFG0=0x01;
	}
	else if (Reference==INTERNAL)
	{
		ADCON1bits.VCFG0=0x00;
		TRISAbits.TRISA2=0x01;
		ADCON1bits.PCFG3=0x00;
		ADCON1bits.PCFG2=0x01;
		ADCON1bits.PCFG1=0x01;
		ADCON1bits.PCFG0=0x01;
	}
	else
	{
	}
}

/*-----------------------------------------------------------------------------------------*/
void ADC_Select_Reference_Negative(unsigned char Reference)
{
	if(Reference==EXTERNAL)
	{
		ADCON1bits.VCFG1=0x01;
	}
	else if (Reference==INTERNAL)
	{
		ADCON1bits.VCFG1=0x00;
	}
	else
	{
	}
}

/*-----------------------------------------------------------------------------------------*/
void ADC_Justified(unsigned char Shift)
{
	if(Shift==RIGHT)
	{
		ADCON2bits.ADFM=0x01;
	}
	else if (Shift==LEFT)
	{
		ADCON2bits.ADFM=0x00;
	}
	else
	{
	}
}

/*-----------------------------------------------------------------------------------------*/
void ADC_SetAcquisitionTime(unsigned char AcquisitionTime)
{
	if((AcquisitionTime==_20_TAD)||(AcquisitionTime==_16_TAD)||(AcquisitionTime==_12_TAD)||(AcquisitionTime==_8_TAD)||	
	(AcquisitionTime==_6_TAD)||(AcquisitionTime==_4_TAD)||(AcquisitionTime==_2_TAD)||(AcquisitionTime==_0_TAD))
	{
		ADCON2=((ADCON2&0xC7)|(AcquisitionTime<<3));
	}
	else
	{
	}
}

/*-----------------------------------------------------------------------------------------*/
void ADC_ConversionClocks(unsigned char ConversionClock)
{
	if((ConversionClock==_FRC)||(ConversionClock==_FOSC_64)||(ConversionClock==_FOSC_16)||(ConversionClock==_FOSC_4)||(ConversionClock==_FOSC_32)||
	(ConversionClock==_FOSC_8)||(ConversionClock==_FOSC_2))
	{
	ADCON2=((ADCON2 & 0xF8)|ConversionClock);
	}
	else
	{
	}
}

/*-----------------------------------------------------------------------------------------*/
void Initialize_ADC(void)
{
	ADC_PowerOn();
	ADC_Select_Channel(0x00);
	ADC_Select_Reference_Positive(EXTERNAL);
	ADC_Select_Reference_Negative(EXTERNAL);
	ADC_Justified(RIGHT);
	ADC_SetAcquisitionTime(_8_TAD);
	ADC_ConversionClocks(_FRC);
}

/*-----------------------------------------------------------------------------------------*/
unsigned int ReadADC(void)
{
  return (((unsigned int)ADRESH)<<8)|(ADRESL);
}