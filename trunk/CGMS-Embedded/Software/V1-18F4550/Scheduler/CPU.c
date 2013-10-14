#include <p18f4550.h>

void Initialize_CPU (void);

/*-----------------------------------------------------------------------------------------*/
void Initialize_CPU (void)
{

/******************************************************************/
    OSCCONbits.SCS0 = 0;
    OSCCONbits.SCS1 = 1; 

/* bit 1-0 SCS1:SCS0: System Clock Select bits   */
/* 1x = Internal oscillator block                */
/* 01 = Timer1 oscillator                        */
/* 00 = Primary oscillator                       */

/******************************************************************/
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1;

/* bit 6-4 IRCF2:IRCF0: Internal Oscillator Frequency Select bits */
/* 111 = 8 MHz (INTOSC drives clock directly)                     */
/* 110 = 4 MHz                                                    */
/* 101 = 2 MHz                                                    */
/* 100 = 1 MHz(3)                                                 */
/* 011 = 500 kHz                                                  */
/* 010 = 250 kHz                                                  */
/* 001 = 125 kHz                                                  */
/* 000 = 31 kHz (from either INTOSC/256 or INTRC directly)(2)     */

/******************************************************************/
    OSCCONbits.IDLEN = 0;

/* bit 7 IDLEN: Idle Enable bit                          */
/* 1 = Device enters Idle mode on SLEEP instruction      */
/* 0 = Device enters Sleep mode on SLEEP instruction     */

/******************************************************************/
    RCONbits.IPEN = 1;
/*  IPEN: Interrupt Priority Enable bit
    1 = Enable priority levels on interrupts
    0 = Disable priority levels on interrupts (PIC16CXXX Compatibility mode)
*/
}