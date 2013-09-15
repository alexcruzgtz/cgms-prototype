
#include <p18f4550.h>
#include "stdio.h"
#include "E2PHandler.h"
#include "main.h"
#include "Ports.h"
#include "Timer0cfg.h"
#include "interrupciones.h"
#include "CPU.h"
#include "ADC.h"
#include "TaskHandler.h"
#include "flex_lcd_c18.h"
#include "TaskHandler.h"
#include "Eusart.h"
#include "LcdHandler.h"
#include "Measurements.h"
#include "Buttons.h"
#include "I2CHandler.h"
#include "RTCHandler.h"

/*-----------------------------------------------------------------------------------------*/
/*++++++++++++++++   config words   +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#pragma romdata CONFIG

rom const unsigned char CONFIG1L = 0x00;
/*
bit 7-6	Unimplemented: Read as ‘0’
bit 5	USBDIV: USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1)
			1 = USB clock source comes from the 96 MHz PLL divided by 2
			0 = USB clock source comes directly from the primary oscillator block with no postscale
bit 4-3 CPUDIV1:CPUDIV0: System Clock Postscaler Selection bits
			For XT, HS, EC and ECIO Oscillator modes:
				11 = Primary oscillator divided by 4 to derive system clock
				10 = Primary oscillator divided by 3 to derive system clock
				01 = Primary oscillator divided by 2 to derive system clock
				00 = Primary oscillator used directly for system clock (no postscaler)
			For XTPLL, HSPLL, ECPLL and ECPIO Oscillator modes:
				11 = 96 MHz PLL divided by 6 to derive system clock
				10 = 96 MHz PLL divided by 4 to derive system clock
				01 = 96 MHz PLL divided by 3 to derive system clock
				00 = 96 MHz PLL divided by 2 to derive system clock
bit 2-0 PLLDIV2:PLLDIV0: PLL Prescaler Selection bits
	 		111 = Divide by 12 (48 MHz oscillator input)
			110 = Divide by 10 (40 MHz oscillator input)
			101 = Divide by 6 (24 MHz oscillator input)
			100 = Divide by 5 (20 MHz oscillator input)
			011 = Divide by 4 (16 MHz oscillator input)
			010 = Divide by 3 (12 MHz oscillator input)
			001 = Divide by 2 (8 MHz oscillator input)
			000 = No prescale (4 MHz oscillator input drives PLL directly)
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG1H = 0x8A;
/*
bit 7	IESO: Internal/External Oscillator Switchover bit
			1 = Oscillator Switchover mode enabled
			0 = Oscillator Switchover mode disabled
bit 6 	FCMEN: Fail-Safe Clock Monitor Enable bit
			1 = Fail-Safe Clock Monitor enabled
			0 = Fail-Safe Clock Monitor disabled
bit 5-4 Unimplemented: Read as ‘0’
bit 3-0 FOSC3:FOSC0: Oscillator Selection bits(1)
			111x = HS oscillator, PLL enabled (HSPLL)
			110x = HS oscillator (HS)
			1011 = Internal oscillator, HS oscillator used by USB (INTHS)
			1010 = Internal oscillator, XT used by USB (INTXT)
			1001 = Internal oscillator, CLKO function on RA6, EC used by USB (INTCKO)
			1000 = Internal oscillator, port function on RA6, EC used by USB (INTIO)
			0111 = EC oscillator, PLL enabled, CLKO function on RA6 (ECPLL)
			0110 = EC oscillator, PLL enabled, port function on RA6 (ECPIO)
			0101 = EC oscillator, CLKO function on RA6 (EC)
			0100 = EC oscillator, port function on RA6 (ECIO)
			001x = XT oscillator, PLL enabled (XTPLL)
			000x = XT oscillator (XT)
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG2L = 0x11;
/*
bit 7-6 Unimplemented: Read as ‘0’
bit 5 	VREGEN: USB Internal Voltage Regulator Enable bit
			1 = USB voltage regulator enabled
			0 = USB voltage regulator disabled
bit 4-3 BORV1:BORV0: Brown-out Reset Voltage bits(1)
			11 = Minimum setting
			..
			.
			00 = Maximum setting
bit 2-1 BOREN1:BOREN0: Brown-out Reset Enable bits(2)
			11 = Brown-out Reset enabled in hardware only (SBOREN is disabled)
			10 = Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
			01 = Brown-out Reset enabled and controlled by software (SBOREN is enabled)
			00 = Brown-out Reset disabled in hardware and software
bit 0 	PWRTEN: Power-up Timer Enable bit(2)
			1 = PWRT disabled
			0 = PWRT enabled
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG2H = 0x00;
/*
bit 7-5 Unimplemented: Read as ‘0’
bit 4-1 WDTPS3:WDTPS0: Watchdog Timer Postscale Select bits
			1111 = 1:32,768
			1110 = 1:16,384
			1101 = 1:8,192
			1100 = 1:4,096
			1011 = 1:2,048
			1010 = 1:1,024
			1001 = 1:512
			1000 = 1:256
			0111 = 1:128
			0110 = 1:64
			0101 = 1:32
			0100 = 1:16
			0011 = 1:8
			0010 = 1:4
			0001 = 1:2
			0000 = 1:1
bit 0 	WDTEN: Watchdog Timer Enable bit
			1 = WDT enabled
			0 = WDT disabled (control is placed on the SWDTEN bit)
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG3L = 0xFF;
/*
Dummy
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG3H = 0xF4;
/*
bit 7	MCLRE: MCLR Pin Enable bit
			1 = MCLR pin enabled, RE3 input pin disabled
			0 = RE3 input pin enabled, MCLR pin disabled
bit 6-3 Unimplemented: Read as ‘0’
bit 2 	LPT1OSC: Low-Power Timer1 Oscillator Enable bit
			1 = Timer1 configured for low-power operation
			0 = Timer1 configured for higher power operation
bit 1 	PBADEN: PORTB A/D Enable bit
		(Affects ADCON1 Reset state. ADCON1 controls PORTB<4:0> pin configuration.)
			1 = PORTB<4:0> pins are configured as analog input channels on Reset
			0 = PORTB<4:0> pins are configured as digital I/O on Reset
bit 0 	CCP2MX: CCP2 MUX bit
			1 = CCP2 input/output is multiplexed with RC1
			0 = CCP2 input/output is multiplexed with RB3
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG4L = 0x81;
/*
bit 7 	DEBUG: Background Debugger Enable bit
			1 = Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
			0 = Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
bit 6 	XINST: Extended Instruction Set Enable bit
			1 = Instruction set extension and Indexed Addressing mode enabled
			0 = Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
bit 5 	ICPRT: Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit(1)
			1 = ICPORT enabled
			0 = ICPORT disabled
bit 4-3 Unimplemented: Read as ‘0’
bit 2 	LVP: Single-Supply ICSP™ Enable bit
			1 = Single-Supply ICSP enabled
			0 = Single-Supply ICSP disabled
bit 1 	Unimplemented: Read as ‘0’
bit 0 	STVREN: Stack Full/Underflow Reset Enable bit
			1 = Stack full/underflow will cause Reset
			0 = Stack full/underflow will not cause Reset
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG4H = 0xFF;
/*
Dummy
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG5L = 0xFF;
/*
bit 7-4 Unimplemented: Read as ‘0’
bit 3 	CP3: Code Protection bit(1)
			1 = Block 3 (006000-007FFFh) is not code-protected
			0 = Block 3 (006000-007FFFh) is code-protected
bit 2 	CP2: Code Protection bit
			1 = Block 2 (004000-005FFFh) is not code-protected
			0 = Block 2 (004000-005FFFh) is code-protected
bit 1 	CP1: Code Protection bit
			1 = Block 1 (002000-003FFFh) is not code-protected
			0 = Block 1 (002000-003FFFh) is code-protected
bit 0 	CP0: Code Protection bit
			1 = Block 0 (000800-001FFFh) is not code-protected
			0 = Block 0 (000800-001FFFh) is code-protected
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG5H = 0xFF;
/*
bit 7 	CPD: Data EEPROM Code Protection bit
			1 = Data EEPROM is not code-protected
			0 = Data EEPROM is code-protected
bit 6	CPB: Boot Block Code Protection bit
			1 = Boot block (000000-0007FFh) is not code-protected
			0 = Boot block (000000-0007FFh) is code-protected
bit 5-0 Unimplemented: Read as ‘0’
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG6L = 0xFF;
/*
bit 7-4 Unimplemented: Read as ‘0’
bit 3 	WRT3: Write Protection bit(1)
			1 = Block 3 (006000-007FFFh) is not write-protected
			0 = Block 3 (006000-007FFFh) is write-protected
bit 2 	WRT2: Write Protection bit
			1 = Block 2 (004000-005FFFh) is not write-protected
			0 = Block 2 (004000-005FFFh) is write-protected
bit 1 	WRT1: Write Protection bit
			1 = Block 1 (002000-003FFFh) is not write-protected
			0 = Block 1 (002000-003FFFh) is write-protected
bit 0 	WRT0: Write Protection bit
			1 = Block 0 (000800-001FFFh) or (001000-001FFFh) is not write-protected
			0 = Block 0 (000800-001FFFh) or (001000-001FFFh) is write-protected
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG6H = 0xFF;
/*
bit 7 	WRTD: Data EEPROM Write Protection bit
			1 = Data EEPROM is not write-protected
			0 = Data EEPROM is write-protected
bit 6 	WRTB: Boot Block Write Protection bit
			1 = Boot block (000000-0007FFh) is not write-protected
			0 = Boot block (000000-0007FFh) is write-protected
bit 5 	WRTC: Configuration Register Write Protection bit(1)
			1 = Configuration registers (300000-3000FFh) are not write-protected
			0 = Configuration registers (300000-3000FFh) are write-protected
bit 4-0 Unimplemented: Read as ‘0’
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG7L = 0xFF;
/*
bit 7-4 Unimplemented: Read as ‘0’
bit 3 	EBTR3: Table Read Protection bit(1)
			1 = Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
			0 = Block 3 (006000-007FFFh) protected from table reads executed in other blocks
bit 2 	EBTR2: Table Read Protection bit
			1 = Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
			0 = Block 2 (004000-005FFFh) protected from table reads executed in other blocks
bit 1 	EBTR1: Table Read Protection bit
			1 = Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks
			0 = Block 1 (002000-003FFFh) is protected from table reads executed in other blocks
bit 0 	EBTR0: Table Read Protection bit
			1 = Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks
			0 = Block 0 (000800-001FFFh) is protected from table reads executed in other blocks
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
rom const unsigned char CONFIG7H = 0xFF;
/*
bit 7 	Unimplemented: Read as ‘0’
bit 6 	EBTRB: Boot Block Table Read Protection bit
			1 = Boot block (000000-0007FFh) is not protected from table reads executed in other blocks
			0 = Boot block (000000-0007FFh) is protected from table reads executed in other blocks
bit 5-0 Unimplemented: Read as ‘0’
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#pragma romdata

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


  /*-----------------------------------------------------------------------------------------*/
unsigned char FlagRunTask;

/*-----------------------------------------------------------------------------------------*/
void main (void)
{
	
	//MACRO_START_DEVICE
	Initialize_CPU(); 		  /*Configures the clock, sleep instrunction and interrupt priority*/ 
	Initialize_Ports();		  /*Configures the portas as Output and digital*/ 
	Initialize_TaskHandler(); /*Initialize the list of task*/ 									
	Initialize_Interrupts();  /*Configures all the interrupts*/ 									
	Initialize_Timer0();	  /*Initial configuration of Timer0*/ 								
	//Initialize_I2C();		  /*Initial configuration for I2C interface*/ 
	Initialize_ADC();		  /*Initial configuration for aADC*/ 								
	Initialize_USART();		  /*Initialize the LCD Hardware*/								
	Initialize_LCD(); 
	Initialize_Measurements();
	Initialize_Buttons();
	Initialize_RTC();

	EEPROM_Status = E_READ_ISIG_ADDR;
	update_LCD_Values=1;
	update_LCD=1;
	Actual_LCD_page=1;

	while(1)
	{
		if(FlagRunTask==1)
		{
			Task_Handler_Function();
		}
	}
}