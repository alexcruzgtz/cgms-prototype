/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#include "p24fxxxx.h"
#include "GenericTypeDefs.h"
#include "PPS.h"
#include "HardwareConfig.h"
#include "Oscillator.h"


/*-----------------------------------------------------------------------------------------*/
void HardwareCfg_Init(void)
{
Cfg_CFGBits();
Cfg_PPS();
Cfg_Ports();
}


/*.........................................................................................*/
void Cfg_CFGBits(void);
{
	_CONFIG1(JTAGEN_OFF & GPC_OFF & GWRP_OFF & ICS_PGx2 & FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS1)
	_CONFIG2 (IESO_OFF & FNOSC_FRC & FCKSM_CSECMD & OSCIOFCN_ON & IOL1WAY_ON & I2C1SEL_PRI & POSCMOD_NONE)
	_CONFIG3 (WPDIS_WPDIS & WUTSEL_LEG & SOSCSEL_IO)
	_CONFIG4 (DSWDTEN_OFF & DSBOREN_ON & RTCOSC_LPRC & DSWDTOSC_LPRC & DSWDTPS_DSWDTPS9)
}


/*.........................................................................................*/
void Cfg_PPS(void)
{
	PPSUnLock
	iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_NULL);		//PPS RP0 function Null
	iPPSOutput(OUT_PIN_PPS_RP1, OUT_FN_PPS_NULL);		//PPS RP1 function Null
	iPPSOutput(OUT_PIN_PPS_RP2, OUT_FN_PPS_NULL);		//PPS RP2 function Null
	iPPSOutput(OUT_PIN_PPS_RP3, OUT_FN_PPS_NULL);		//PPS RP3function Null
	iPPSOutput(OUT_PIN_PPS_RP4, OUT_FN_PPS_NULL);		//PPS RP4 function Null
	iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_SDO1);		//PPS RP5 function SPI -> SDO1
	iPPSOutput(OUT_PIN_PPS_RP6, OUT_FN_PPS_SCK1OUT);	//PPS RP6 function SPI -> SCK1
	iPPSInput(IN_FN_PPS_SDI1, IN_PIN_PPS_RP7);			//PPS RP7 function SPI <- SDI
	iPPSOutput(OUT_PIN_PPS_RP8, OUT_FN_PPS_NULL);		//PPS RP8 function Null
	iPPSOutput(OUT_PIN_PPS_RP9, OUT_FN_PPS_NULL);		//PPS RP9 function Null
	iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_NULL);		//PPS RP10 function Null
	iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);		//PPS RP11 function Null
	iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_U1TX);		//PPS RP12 function UART1 -> Tx
	iPPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP13);			//PPS RP13 function UART1 <- Rx
	iPPSOutput(OUT_PIN_PPS_RP14, OUT_FN_PPS_NULL);		//PPS RP14 function Null
	iPPSOutput(OUT_PIN_PPS_RP15, OUT_FN_PPS_NULL);		//PPS RP15 function Null
	PPSLock
}


/*.........................................................................................*/
void Cfg_Ports(void)
{
	PORTA=0;
	LATA=0;
	TRISA=IOPORTA_CFG;
	
	PORTB=0;
	LATB=0;
	TRISA=IOPORTB_CFG
}


/*-----------------------------------------------------------------------------------------*/
#endif