#include <p18f4550.h>
#include "main.h"
#include "Ports.h"
#include "Timer0cfg.h"
#include "interrupciones.h"
#include "TaskHandler.h"
#include "Eusart.h"

/*-----------------------------------------------------------------------------------------*/
#pragma interrupt High_Priority_Int

#pragma code high_vector=0x08

void interrupt_at_high_vector(void)
{
_asm GOTO  High_Priority_Int _endasm
}
#pragma code /* return to the default code section */

/*-----------------------------------------------------------------------------------------*/
unsigned char control;

/*-----------------------------------------------------------------------------------------*/
void Tmr0_interrupt(void);
void Disable_Interrupts(void);
void Enable_Interrupts(void);
void Initialize_Interrupts(void);
void High_Priority_Int (void);

/*-----------------------------------------------------------------------------------------*/
void Tmr0_interrupt(void)
{
		TaskCounter++;
		if(TaskCounter>60000)
		{
			TaskCounter=1;
		}	
		FlagRunTask=1;
}

/*-----------------------------------------------------------------------------------------*/
void Initialize_Interrupts()
{
    INTCON3bits.INT1IF = 0;
/*  INT1IF: INT1 External Interrupt Flag bit
    1 = The INT1 external interrupt occurred (must be cleared in software)
    0 = The INT1 external interrupt did not occur
*/

    INTCON3bits.INT2IF = 0;
/*  INT2IF: INT2 External Interrupt Flag bit
    1 = The INT2 external interrupt occurred (must be cleared in software)
    0 = The INT2 external interrupt did not occur
*/

    INTCON3bits.INT1IE = 0;
/*  INT1IE: INT1 External Interrupt Enable bit
    1 = Enables the INT1 external interrupt
    0 = Disables the INT1 external interrupt
*/

    INTCON3bits.INT2IE = 0;
/*  INT2IE: INT2 External Interrupt Enable bit
    1 = Enables the INT2 external interrupt
    0 = Disables the INT2 external interrupt
*/

    INTCON3bits.INT1IP = 0;
/*  INT1IP: INT1 External Interrupt Priority bit
    1 = High priority
    0 = Low priority
*/
    INTCON3bits.INT2IP = 0;
/*  INT2IP: INT2 External Interrupt Priority bit
    1 = High priority
    0 = Low priority
*/

    INTCON2bits.RBIP = 0;
/*  RBIP: RB Port Change Interrupt Priority bit
    1 = High priority
    0 = Low priority
*/

    INTCON2bits.TMR0IP = 1;
/*  TMR0IP: TMR0 Overflow Interrupt Priority bit
    1 = High priority
    0 = Low priority
*/

    INTCON2bits.INTEDG2 = 0;
/*  INTEDG2: External Interrupt 2 Edge Select bit
    1 = Interrupt on rising edge
    0 = Interrupt on falling edge
*/

    INTCON2bits.INTEDG1 = 0;
/*  INTEDG1: External Interrupt 1 Edge Select bit
    1 = Interrupt on rising edge
    0 = Interrupt on falling edge
*/

    INTCON2bits.INTEDG0 = 0;
/*  INTEDG0: External Interrupt 0 Edge Select bit
    1 = Interrupt on rising edge
    0 = Interrupt on falling edge
*/

    INTCON2bits.NOT_RBPU = 0;
/*  RBPU: PORTB Pull-up Enable bit
    1 = All PORTB pull-ups are disabled
    0 = PORTB pull-ups are enabled by individual port latch values
*/

    INTCONbits.RBIF = 0;
/*  RBIF: RB Port Change Interrupt Flag bit
    1 = At least one of the RB7:RB4 pins changed state (must be cleared in software)
    0 = None of the RB7:RB4 pins have changed state
*/

    INTCONbits.INT0IF = 0;
/*  INT0IF: INT0 External Interrupt Flag bit
    1 = The INT0 external interrupt occurred (must be cleared in software)
    0 = The INT0 external interrupt did not occur
*/

    INTCONbits.TMR0IF = 0;
/*  TMR0IF: TMR0 Overflow Interrupt Flag bit
    1 = TMR0 register has overflowed (must be cleared in software)
    0 = TMR0 register did not overflow
*/

    INTCONbits.RBIE = 0;
/*  RBIE: RB Port Change Interrupt Enable bit
    1 = Enables the RB port change interrupt
    0 = Disables the RB port change interrupt
*/

    INTCONbits.INT0IE = 0;
/*  INT0IE: INT0 External Interrupt Enable bit
    1 = Enables the INT0 external interrupt
    0 = Disables the INT0 external interrupt
*/

    INTCONbits.TMR0IE = 1;
/*  TMR0IE: TMR0 Overflow Interrupt Enable bit
    1 = Enables the TMR0 overflow interrupt
    0 = Disables the TMR0 overflow interrupt
*/

    INTCONbits.PEIE = 0;
/*  PEIE/GIEL: Peripheral Interrupt Enable bit
    When IPEN = 0:
    1 = Enables all unmasked peripheral interrupts
    0 = Disables all peripheral interrupts
    When IPEN = 1:
    1 = Enables all low priority peripheral interrupts
    0 = Disables all low priority peripheral interrupts
*/
    Enable_Interrupts();
}

/*-----------------------------------------------------------------------------------------*/
void Enable_Interrupts(void)
{
    INTCONbits.GIE = 1;
/*	GIE/GIEH: Global Interrupt Enable bit
    When IPEN = 0:
    1 = Enables all unmasked interrupts
    0 = Disables all interrupts
    When IPEN = 1:
    1 = Enables all high priority interrupts
    0 = Disables all high priority interrupts
*/
}

/*-----------------------------------------------------------------------------------------*/
void Disable_Interrupts(void)
{
    INTCONbits.GIE = 0;
/*	GIE/GIEH: Global Interrupt Enable bit
    When IPEN = 0:
    1 = Enables all unmasked interrupts
    0 = Disables all interrupts
    When IPEN = 1:
    1 = Enables all high priority interrupts
    0 = Disables all high priority interrupts
*/
}

/*-----------------------------------------------------------------------------------------*/
void High_Priority_Int (void)
{
	#ifdef	TMR0_INTERRUPT_ENABLE
	if(INTCONbits.TMR0IF)
	{
		Tmr0_interrupt();
		Initialize_Timer0();
	}
	#endif

	#ifdef	TMR1_INTERRUPT_ENABLE
	if(INTCONbits.TMR1IF)
	{
		Tmr1_interrupt();
		Initialize_Timer1();
	}
	#endif
	if(PIR1bits.RCIF==1)
	{
		DataReception();
		PIR1bits.RCIF=0;
	}

	
}