#include <p18f4550.h>

#ifndef __EUSART_H
#define __EUSART_H

/*-----------------------------------------------------------------------------------------*/
#define SYNCHRONOUS		1
#define ASYNCHRONOUS	0

#define SYNCH_MODE		ASYNCHRONOUS

/*******************ASYNCHRONOUS***************************************/
#if (SYNCH_MODE==ASYNCHRONOUS)

#define SYNCH_MODE_CONFIG	TXSTAbits.SYNC=ASYNCHRONOUS;

#define SEND_BREAK_CHARACTER_ON_NEXT_TX	TXSTAbits.SENDB=1;
#define SEND_BREAK_TX_COMPLETE			TXSTAbits.SENDB=0;

#define HIGH_SPEED_BAUD_RATE	TXSTAbits.BRGH=1;
#define LOW_SPEED_BAUD_RATE		TXSTAbits.BRGH=0;

#endif
/**********************************************************************/


/********************SYNCHRONOUS***************************************/
#if (SYNCH_MODE==SYNCHRONOUS)

#define SYNCH_MODE_CONFIG	TXSTAbits.SYNC=SYNCHRONOUS;

#define CLOCK_SOURCE_MASTER	TXSTAbits.CSRC=1;
#define	CLOCK_SOURCE_SLAVE	TXSTAbits.CSRC=0;

#endif
/**********************************************************************/

#define TRANSMIT_9_BITS		TXSTAbits.TX9=1;
#define TRANSMIT_8_BITS		TXSTAbits.TX9=0;

#define TRANSMIT_ENABLE		TXSTAbits.TXEN=1;
#define TRANSMIT_DISABLE	TXSTAbits.TXEN=0;

#define TRANSMIT_SHIFT_REGISTER_EMPTY	TXSTAbits.TRMT=1;
#define TRANSMIT_SHIFT_REGISTER_FULL	TXSTAbits.TRMT=0;

#define DATA_TX_9_BIT		TXSTAbits.TX9D;

/*-----------------------------------------------------------------------------------------*/
extern void DataReception(void);
extern unsigned char RequestTx;

#endif