/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "Scheduler/HardwareConfig.h"
#include <p24fxxxx.h>
#include <p24fj64ga102.h>
#include <PPS.h>
#include "Drivers/GenericTypeDefs.h"
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/SPI_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"

/*-----------------------------------------------------------------------------------------*/
void HardwareCfg_Init(void)
{
//Cfg_CFGBits();
Cfg_PPS();
Cfg_Ports();

Oscillator_Init();
Interrupts_Init();
ADC_Init();
SPI_Init();
//I2C_Init();
//ConsoleInit();
}


/*.........................................................................................*/
/*void Cfg_CFGBits(void)
{
	#define USE_AND_OR
	
}*/


/*.........................................................................................*/
void Cfg_PPS(void)
{
	PPSUnLock;
	iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_NULL);		//PPS RP0 function Null
	iPPSOutput(OUT_PIN_PPS_RP1, OUT_FN_PPS_NULL);		//PPS RP1 function Null
	iPPSOutput(OUT_PIN_PPS_RP2, OUT_FN_PPS_NULL);		//PPS RP2 function Null
	iPPSOutput(OUT_PIN_PPS_RP3, OUT_FN_PPS_NULL);		//PPS RP3 function Null
	iPPSOutput(OUT_PIN_PPS_RP4, OUT_FN_PPS_SDO1);		//PPS RP4 function SPI -> SDO1
	iPPSInput (IN_FN_PPS_INT1, IN_PIN_PPS_RP5 );		//PPS RP5 function INT1 <- MiWi IRQ1
	iPPSOutput(OUT_PIN_PPS_RP6, OUT_FN_PPS_SCK1OUT);	//PPS RP6 function SPI -> SCK1
	iPPSInput (IN_FN_PPS_SDI1, IN_PIN_PPS_RP7);			//PPS RP7 function SPI <- SDI
	iPPSOutput(OUT_PIN_PPS_RP8, OUT_FN_PPS_NULL);		//PPS RP8 function Null
	iPPSOutput(OUT_PIN_PPS_RP9, OUT_FN_PPS_NULL);		//PPS RP9 function Null
	iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_NULL);		//PPS RP10 function Null
	iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);		//PPS RP11 function Null
	iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_U1TX);		//PPS RP12 function UART1 -> Tx
	iPPSInput (IN_FN_PPS_U1RX, IN_PIN_PPS_RP13);		//PPS RP13 function UART1 <- Rx
	iPPSOutput(OUT_PIN_PPS_RP14, OUT_FN_PPS_NULL);		//PPS RP14 function Null
	iPPSOutput(OUT_PIN_PPS_RP15, OUT_FN_PPS_NULL);		//PPS RP15 function Null
	PPSLock;
}


/*.........................................................................................*/
void Cfg_Ports(void)
{
	/* General Ports Configuration */
	PORTA=0;
	LATA=0;
	TRISA=IOPORTA_CFG;
	
	PORTB=0;
	LATB=0;
	TRISB=IOPORTB_CFG;
    
	LED_Tris = 0;
	LED_Lat = 0;
	PushB_Tris = 1;
	PushB_Lat = 0;

	/* MiWi Pins Configuration */
	Data_nCS_TRIS = 0;
    Config_nCS_TRIS = 0;
    Data_nCS = 1;   
    Config_nCS = 1;
    IRQ1_INT_TRIS = 1;
	PHY_IRQ1 = 0;
    //IRQ0_INT_TRIS = 1;
    //PHY_IRQ0 = 0;
    PHY_RESETn_TRIS = 1;
}


/*-----------------------------------------------------------------------------------------*/
