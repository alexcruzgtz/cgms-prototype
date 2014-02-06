/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "Drivers/Oscillator.h"
#include <p24fxxxx.h>
#include "Drivers/GenericTypeDefs.h"

/*-----------------------------------------------------------------------------------------*/
void Oscillator_Init(void)
{
	OSC_CurrentOsc = _FRC;
	OSC_NewOsc = _FRC;
	OSC_CLKLOCK_OFF
	OSC_IOLOCK_ON
	OSC_CLEAR_CLKFAIL
	OSC_POSCSLEEP_OFF
	OSC_32KSOSC_DISABLE
	OSC_RECOVERONISR_OFF
	OSC_PeripheralClkRatio = _DOZE_1_1;
	OSC_PERIPHCLKRATIO_DISABLE
	OSC_FRCPostscaler = _RCDIV_8M;
	OSC_OscTune = 0b000000;
	OSC_REFOSC_DISABLE
	OSC_REFOSCSLEEP_DISABLE
	OSC_REFOSC_SOURCE_SYSCLK
	OSC_RefOsc_Divisor = _RODIV_1;
}
