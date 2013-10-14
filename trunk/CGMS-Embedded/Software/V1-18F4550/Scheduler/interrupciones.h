#include <p18f4550.h>

#ifndef __INTERRUPCIONES_H
#define __INTERRUPCIONES_H

/*//////////////////////////////////////////////////*/
/*			TABLE FOR INTERRUPTS ENABLED			*/
/*//////////////////////////////////////////////////*/
#define TMR0_INTERRUPT_ENABLE
//#define TMR1_INTERRUPT_ENABLE
//#define INT0_INTERRUPT_ENABLE
//#define INT1_INTERRUPT_ENABLE
//#define INT2_INTERRUPT_ENABLE
//#define USB_INTERRUPT_ENABLE
//#define PORTB_INTERRUPT_ENABLE

/*//////////////////////////////////////////////////*/
/*					GENERAL DEFINES					*/
/*//////////////////////////////////////////////////*/
#define ACTIVE		0x01
#define INACTIVE	0x00
#define TRUE		0x01
#define FALSE		0x02

/*//////////////////////////////////////////////////*/
/*				DECLARE EXTERNAL FUNCTIONS			*/
/*//////////////////////////////////////////////////*/

extern void Tmr0_interrupt(void);
extern void Disable_Interrupts(void);
extern void Enable_Interrupts(void);
extern void Initialize_Interrupts(void);

/*//////////////////////////////////////////////////*/
/*				DEFINES FOR TIMER 0 INTERRUPT		*/
/*//////////////////////////////////////////////////*/						
#define	ENABLE_TMR0_INT			INTCONbits.TMR0IE=ACTIVE;
#define DISABLE_TMR0_INT		INTCONbits.TMR0IE=INACTIVE;

#define	TMR0_INTERRUPT_HIGH		INTCON2bits.TMR0IP=ACTIVE;
#define	TMR0_INTERRUPT_LOW		INTCON2bits.TMR0IP=INACTIVE;

#define INTERRUPT_TMR0_REQUEST	INTCONbits.TMR0IF
#define	CLEAR_INT_TMR0_REQ		INTCONbits.TMR0IF=INACTIVE;


/*//////////////////////////////////////////////////*/
/*				DEFINES FOR TIMER 1 INTERRUPT		*/
/*//////////////////////////////////////////////////*/


						
/*//////////////////////////////////////////////////*/
/*			DEFINES FOR EXTERNAL INTERRUPT 0		*/
/*//////////////////////////////////////////////////*/
#define ENABLE_INT0_INT			INTCONbits.INT0IE=ACTIVE;
#define DISABLE_INT0_INT		INTCONbits.INT0IE=INACTIVE;

#define INT0_EDG_RISING			INTCON2bits.INTEDG0=ACTIVE;
#define INT0_EDG_FALLING		INTCON2bits.INTEDG0=INACTIVE;

#define INTERRUPT_INT0_REQUEST	INTCONbits.INT0IF
#define CLEAR_INT0_REQ			INTCONbits.INT0IF=INACTIVE;

/*//////////////////////////////////////////////////*/
/*			DEFINES FOR EXTERNAL INTERRUPT 1		*/
/*//////////////////////////////////////////////////*/
#define	ENABLE_INT1_INT			INTCON3bits.INT1IE=ACTIVE;
#define	DISABLE_INT1_INT		INTCON3bits.INT1IE=INACTIVE;

#define INT1_EDG_RISING			INTCON2bits.INTEDG1=ACTIVE;
#define INT1_EDG_FALLING		INTCON2bits.INTEDG1=INACTIVE;

#define INT1_INTERRUPT_HIGH		INTCON3bits.INT1IP=ACTIVE;
#define INT1_INTERRUPT_LOW		INTCON3bits.INT1IP=INACTIVE;

#define INTERRUPT_INT1_REQUEST	INTCON3bits.INT1IF
#define CLEAR_INT1_REQ			INTCON3bits.INT1IF=INACTIVE;

/*//////////////////////////////////////////////////*/
/*			DEFINES FOR EXTERNAL INTERRUPT 2		*/
/*//////////////////////////////////////////////////*/
#define	ENABLE_INT2_INT			INTCON3bits.INT2IE=ACTIVE;
#define	DISABLE_INT2_INT		INTCON3bits.INT2IE=INACTIVE;

#define INT2_EDG_RISING			INTCON2bits.INTEDG2=ACTIVE;
#define INT2_EDG_FALLING		INTCON2bits.INTEDG2=INACTIVE;

#define INT2_INTERRUPT_HIGH		INTCON3bits.INT2IP=ACTIVE;
#define INT2_INTERRUPT_LOW		INTCON3bits.INT2IP=INACTIVE;

#define INTERRUPT_INT2_REQUEST	INTCON3bits.INT2IF
#define CLEAR_INT2_REQ			INTCON3bits.INT2IF=INACTIVE;


/*//////////////////////////////////////////////////*/
/*				DEFINES FOR USB INTERRUPT 			*/
/*//////////////////////////////////////////////////*/



/*//////////////////////////////////////////////////*/
/*				DEFINES FOR PORTB  INTERRUPT 		*/
/*//////////////////////////////////////////////////*/
#define ENABLE_PORTB_INT		INTCONbits.RBIE=ACTIVE;
#define DISABLE_PORTB_INT		INTCONbits.RBIE=INACTIVE;

#define DISABLE_PULLUP_PORTB	INTCON2bits.RBPU=ACTIVE;
#define ENABLE_PULLUP_PORTB		INTCON2bits.RBPU=INACTIVE;

#define	PORTB_INTERRUPT_HIGH	INTCON2bits.RBIP=ACTIVE;
#define	PORTB_INTERRUPT_LOW		INTCON2bits.RBIP=INACTIVE;

#define INTERRUPT_PORTB_REQUEST	INTCONbits.RBIF
#define CLEAR_INT_PORTB_REQ		INTCONbits.RBIF=INACTIVE;


#endif	