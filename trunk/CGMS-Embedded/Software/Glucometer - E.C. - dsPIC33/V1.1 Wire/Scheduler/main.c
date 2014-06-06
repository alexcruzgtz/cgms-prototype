/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#include "Scheduler/main.h"
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include <PPS.h>
#include <uart.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/Reset.h"
#include "Drivers/CPU.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"


/*-----------------------------------------------------------------------------------------*/
Config_CFGBits();


/*-----------------------------------------------------------------------------------------*/
int main( void )
{
	vHardwareCfg_Init();  
	//LCD_Pwr_Tris = 0;

	//LCD_Pwr_Lat = 1;
	LED_Lat = 0;
	//UART_Tx = 0;
	//vLCD_Test();
	char Txdata[] = {'M','i','c','r','o','c','h','i','p','\0'};
	putsUART1 ((UINT *)Txdata);
	while(1)
	{
		//DelayMs(100);
		WriteUART1(0xAA);
		while(BusyUART1());
	}
}


/*-----------------------------------------------------------------------------------------*/
