/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Scheduler/HardwareConfig.h"
#include <p33fxxxx.h>
#include <PPS.h>
#include <GenericTypeDefs.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/Reset.h"
#include "Drivers/CPU.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"


/*-----------------------------------------------------------------------------------------*/
void vHardwareCfg_Init(void)
{
 	vCPU_Init();
 	vPorts_Init();
 	vOscillator_Init();
	vInterrupts_Init(); 

	vADC_Init();
	//vI2C_Init();
	//vLCD_Init();
	vUART_Init();
}

/*.........................................................................................*/
void vCPU_Init( void )
{
	//RST_VREGINSLEEP_OFF
	RST_WDT_DISABLED
	//CPU_DSP_MULT_SIGNED
	//CPU_ASAT_DISABLED
	//CPU_BSAT_DISABLED
	//CPU_DATASPACESAT_DISABLED
	//CPU_ACCSATMODE_NORMAL
	//CPU_ISRPRIORITY_LESS
	//CPU_PROGSPACE_NOTVISIBLE
	//CPU_ROUNDMODE_BIASED
	//CPU_DSPMUL_INTEGER
}
/*.........................................................................................*/
void vPorts_Init(void)
{
	/* Peripherical Pin Select Configuration*/
	//PPSUnLock;
	iPPSOutput(OUT_PIN_PPS_RP20, OUT_FN_PPS_U1TX);		//PPS RP20 function UART1 -> Tx
	iPPSInput (IN_FN_PPS_U1RX, IN_PIN_PPS_RP21);		//PPS RP21 function UART1 <- Rx	
	//PPSLock;

	/* General Ports Configuration */
	TRISA = IOPORT_A_CFG;
	TRISB = IOPORT_B_CFG;
    TRISC = IOPORT_C_CFG;

	//LATA = 0b01000000000;
	//LATB = 0b0000000000000000;
	//LATC = 0b0000000000;

	//Push Buttons Configuration
	PushB_Up_Tris = 1;
	PushB_Enter_Tris = 1;
	PushB_Down_Tris = 1;
	

	//LCD Pins Configuration
	LCD_DB7_Lat = 0;
	LCD_DB6_Lat = 0;
	LCD_DB5_Lat = 0;
	LCD_DB4_Lat = 0;
	LCD_E_Lat = 0;
	LCD_RS_Lat = 0;
	LCD_Pwr_Lat = 0;
	
	//Analog Pins Configuration*/
	AN1_Tris = 1;
	AN2_Tris = 1;
	AN3_Tris = 1;
	AN4_Tris = 1;
	AN5_Tris = 1;

	UART_Rx_Tris = 1;
	UART_Tx_Tris = 0;

	I2C_SDA_Tris = 1;
	I2C_SCL_Tris = 0;

	LED_Tris = 0;
}

/*.........................................................................................*/
void vOscillator_Init(void)
{

	
	//OSC_NewOsc = _FRCPLL;
	OSC_CLKLOCK_OFF
	OSC_IOLOCK_ON
	OSC_SOSC_DISABLED
	
	OSC_RECOVERONISR_OFF
	OSC_ProscClkReduction = _DOZE_1;
	OSC_DOZE_DISABLED
	OSC_FRCPostscaler = _RCDIV_64;

/*PLL configuration. Fosc = Fin( M / (N1 * N2) )
	For a 20Mhz configuration: N1=8; M=160; and N2=8*/
	//OSC_PLLInputDiv = 0b00110; //N1		
	//OSC_PLLFeedbackDiv = 0b10011110; //M
	//OSC_PLLOutputDiv = 0b11; //N2

	//OSC_FRCOscTune = 0b000000;

	//OSC_ACLKSOURCE_PLL
	//OSC_AClk_Mode = 0b00;		//Auxiliary Oscillator Disabled
	//OSC_AClkDiv = 0b111;		//Divided by 1
	//OSC_ACLK_SOURCE_PRIMARY
}


/*-----------------------------------------------------------------------------------------*/
