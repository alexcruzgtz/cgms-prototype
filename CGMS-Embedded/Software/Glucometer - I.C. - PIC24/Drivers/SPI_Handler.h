/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"
#include "GenericTypeDefs.h"

#ifndef __SPI_HANDLER_H
#define __SPI_HANDLER_H

/*-----------------------------------------------------------------------------------------*/
/*SPI clock speed obey the following equation:
FSCK= Fcy / Primary Prescaler * Secundary Prescaler */
/*... Secundary Prescaler*/
#define _2P_1_1        7 /* 1:1 */
#define _2P_2_1        6 /* 2:1 */
#define _2P_3_1        5 /* 3:1 */
#define _2P_4_1        4 /* 4:1 */
#define _2P_5_1        3 /* 5:1 */
#define _2P_6_1        2 /* 6:1 */
#define _2P_7_1        1 /* 7:1 */
#define _2P_8_1        0 /* 8:1 */
/*... Primary Prescaler*/
#define _1P_1_1        3 /* 1:1 */
#define _1P_4_1        2 /* 4:1 */
#define _1P_16_1       1 /* 16:1 */
#define _1P_64_1       0 /* 64:1 */

#define _IRQ_TXBUF_FULL			7 	/*Interrupt when SPIx transmit buffer is full (SPITBF bit is set)*/
#define _IRQ_TXFIFO_EMPTY		6	/*Interrupt when last bit is shifted into SPIxSR; as a result, the TX FIFO is empty*/
#define _IRQ_TX_COMPLETE		5	/*Interrupt when the last bit is shifted out of SPIxSR; now the transmit is complete*/
#define _IRQ_ONEDATA_SHIFTED	4	/*Interrupt when one data is shifted into the SPIxSR; as a result, the TX FIFO has one open spot*/
#define _IRQ_RXBUF_FULL			3	/*Interrupt when SPIx receive buffer is full (SPIRBF bit is set)*/
#define _IRQ_RX_3_4_FULL		2	/*Interrupt when SPIx receive buffer is 3/4 or more full*/
#define _IRQ_RXDATA_AVAILABLE	1	/*Interrupt when data is available in the receive buffer (SRMPT bit is set)*/
#define _IRQ_RXBUF_EMPTY		0	/*Interrupt when the last data in the receive buffer is read; as a result, the buffer is empty(SRXMPT bit set)*/

/*............. SPI1STAT Status and Control Register Macros ...............................*/
#define SPI1_ON             		SPI1STATbits.SPIEN=SET;		/* Enable module */
#define SPI1_OFF            		SPI1STATbits.SPIEN=CLEAR; 	/* Disable module */
#define SPI1_IDLE_DISCONTINUE 	    SPI1STATbits.SPISIDL=SET; 	/* Discontinue module operation in idle mode */
#define SPI1_IDLE_CONTINUE       	SPI1STATbits.SPISIDL=CLEAR 	/* Continue module operation in idle mode */
#define SPI1_BufCounter_Status		SPI1STATbits.SPIBEC			/*2:0. Num transfers pending (Master). Num transfers unread (Slave)*/
#define SPI1_ShiftReg_Status		SPI1STATbits.SRMPT			/*1=Empty, 0=Not empty*/
#define SPI1_Rx_Overflow_Flag		SPI1STATbits.SPIROV 		/*If set: Rx buffer overflow. User software has not read previus data in SPI1BUF*/
#define SPI1_CLEAR_RX_OVERFLOW   	SPI1STATbits.SPIROV=CLEAR;	/* Clear receive overflow bit */
#define SPI1_Rx_FIFOEmpty_Status	SPI1STATbits.SRXMPT			/*1=Empty. 0=Not empty*/
#define SPI1_BufIRQ_Mode			SPI1STATbits.SISEL			/*Buffer interrupt mode selection*/
#define SPI1_TBF_Status				SPI1STATbits.SPITBF
#define SPI1_RBF_Status				SPI1STATbits.SPIRBF

/*............. SPI1CON1 Control Register 1 Macros ........................................*/
#define SPI1_DISABLE_SCK        	SPI1CON1bits.DISSCK=SET; 	/* SCK pin is not used by module */
#define SPI1_ENABLE_SCK         	SPI1CON1bits.DISSCK=CLEAR; 	/* SCK pin is  used by module */
#define SPI1_DISABLE_SDO        	SPI1CON1bits.DISSDO=SET; 	/* SDO pin is not used by module */
#define SPI1_ENABLE_SDO       		SPI1CON1bits.DISSDO=CLEAR; 	/* SDO pin is  used by module */
#define SPI1_WORD_COMM          	SPI1CON1bits.MODE16=SET;	/* Communication is word wide */
#define SPI1_BYTE_COMM         		SPI1CON1bits.MODE16=CLEAR;	/* Communication is byte wide */
#define SPI1_SMPDATA_END           	SPI1CON1bits.SMP=SET;	 	/* Input data sampled at end of data output time */
#define SPI1_SMPDATA_MIDDLE        	SPI1CON1bits.SMP=CLEAR;		/* Input data sampled at middle of data output time */
#define SPI1_CLK_ACTIVETOIDDLE     	SPI1CON1bits.CKE=SET;		/* Transmit happens from active clock state to idle clock state*/
#define SPI1_CLK_IDLETOACTIVE      	SPI1CON1bits.CKE=CLEAR;		/* Transmit happens on transition from idle clock state to active clock state */
#define SPI1_SLAVESELECT_ENABLE    	SPI1CON1bits.SSEN=SET;		/* Slave Select enbale */
#define SPI1_SLAVESELECT_DISABLE   	SPI1CON1bits.SSEN=CLEAR;	/* Slave Select not used by module */
#define SPI1_CLKPOL_ACTIVE_LOW     	SPI1CON1bits.CKP=SET; 		/* Idle state for clock is high, active is low */
#define SPI1_CLKPOL_ACTIVE_HIGH    	SPI1CON1bits.CKP=CLEAR;		/* Idle state for clock is low, active is high */
#define SPI1_MASTER_MODE       		SPI1CON1bits.MSTEN=SET;		/* Master Mode */
#define SPI1_SLAVE_MODE      		SPI1CON1bits.MSTEN=CLEAR;	/* Slave Mode */
#define SPI1_SecPrescaler_Mode		SPI1CON1bits.SPRE			/*1=Transmit not started, SPI1TXB full. 0=Transmit started, SPI1TXB empty*/
#define SPI1_PriPRescaler_Mode		SPI1CON1bits.PPRE			/*1=Receive is complete, SPI1RXB full. 0=Receive not complete, SPI1RXB empty*/

/*............. SPI1CON2 Control Register 2 Macros ........................................*/
#define SPI1_FRAME_ENABLE        	SPI1CON2bits.FRMEN=SET;	 	/* Frame SPI support enable */
#define SPI1_FRAME_DISABLE       	SPI1CON2bits.FRMEN=CLEAR;	/* Frame SPI support Disable */
#define SPI1_SYNC_SLAVE       		SPI1CON2bits.SPIFSD=SET; 	/* Frame sync pulse Input (slave)  */
#define SPI1_SYNC_MASTER      		SPI1CON2bits.SPIFSD=CLEAR; 	/* Frame sync pulse Output (master)*/
#define SPI1_SYNCPOL_ACTIVE_HIGH 	SPI1CON2bits.SPIFPOL=SET; 	/* Frame sync pulse Input (slave)  */
#define SPI1_SYNCPOL_ACTIVE_LOW  	SPI1CON2bits.SPIFPOL=CLEAR; /* Frame sync pulse Output (master)*/
#define SPI1_SYNCEDGE_COINCIDES 	SPI1CON2bits.SPIFE=SET; 	/* frame pulse coincides with the first bit clock */
#define SPI1_SYNCEDGE_PRECEDES  	SPI1CON2bits.SPIFE=CLEAR; 	/* frame pulse precedes the first bit clock */
#define SPI1_ENH_BUFF_ENABLE    	SPI1CON2bits.SPIBEN=SET; 	/* enable enhanced buffer */
#define SPI1_ENH_BUFF_DISABLE   	SPI1CON2bits.SPIBEN=CLEAR; 	/* disable enhanced buffer */


/*-----------------------------------------------------------------------------------------*/
#endif