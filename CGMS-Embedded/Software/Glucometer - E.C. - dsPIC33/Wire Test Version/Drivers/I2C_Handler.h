/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __I2C_HANDLER_H
#define __I2C_HANDLER_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
#include "Scheduler/HardwareConfig.h"
#include "Drivers/Interrupts.h"


/*-----------------------------------------------------------------------------------------*/

#define I2C_RxBuff					I2C1RCV
#define I2C_TxBuff					I2C1TRN
#define I2C_SlaveAddr				I2C1ADD
#define I2C_BaudRateGen				I2C1BRG


/*............. I2C1CON I2C1 Control Register .............................................*/
#define I2C_ON						I2C1CONbits.I2CEN = SET;
#define I2C_OFF						I2C1CONbits.I2CEN = CLEAR;
#define I2C_STOP_INIDLE				I2C1CONbits.I2CSIDL = SET;
#define I2C_CONTINUE_INIDLE			I2C1CONbits.I2CSIDL = CLEAR;
#define I2C_RELEACE_SCL				I2C1CONbits.SCLREL = SET;
#define I2C_HOLD_SCL				I2C1CONbits.SCLREL = CLEAR;
#define I2C_ENABLE_IPMI				I2C1COnbits.IPMIEN = SET;
#define I2C_DISABLE_IPMI			I2C1COnbits.IPMIEN = CLEAR;
#define I2C_10bit_SLAVEMODE			I2C1CONbits.A10M = SET;				//I2CxADD is a 10-bit slave address
#define I2C_7bit_SLAVEMODE			I2C1CONbits.A10M = CLEAR;			//I2CxADD is a 7-bit slave address
#define I2C_DISABLE_SLEWRATE		I2C1CONbits.DISSLW = SET;			//Slew rate control disabled
#define I2C_ENABLE_SLEWRATE			I2C1CONbits.DISSLW = CLEAR;			//Slew rate control enabled
#define I2C_ENABLE_SMbusLEVELS		I2C1CONbits.SMEN = SET;				//Enable I/O pin thresholds compliant with SMbus specification
#define I2C_DISABLE_SMbusLEVELS		I2C1CONbits.SMEN = CLEAR;			//Disable SMbus input thresholds
#define I2C_ENABLE_GENCALL			I2C1CONbits.GCEN = SET;				/*Enable interrupt when a general call address is 
																		  received in the I2CxRSR (module is enabled for reception)*/
#define I2C_DISABLE_GENCALL			I2C1CONbits.GCEN = CLEAR;			//General call address disabled
#define I2C_ENABLE_CLKSTRETCH		I2C1CONbits.STREN = SET;
#define I2C_DISABLE_CLKSTRETCH		I2C1CONbits.STREN = CLEAR;
#define I2C_Ack_DataBit_Status		I2C1CONbits.ACKDT
#define I2C_SEND_NACK				I2C1CONbits.ACKDT = SET;			//Send NACK during Acknowledge
#define I2C_SEND_ACK				I2C1CONbits.ACKDT	CLEAR;			//Send ACK during Acknowledge
#define I2C_Ack_SequenceEn_Status	I2C1CONbits.ACKEN
#define I2C_INIT_ACKSEQUENCE		I2C1CONbits.ACKEN = SET;   			/*Initiate Acknowledge sequence on SDAx and SCLx pins
																		  and transmit ACKDT data bit. Hardware clear at end
																		  of master Acknowledge sequence*/
//#define I2C_NO_ACKSEQUENCE			I2C1CONbits.ACKEN = CLEAR;			//Acknowledge sequence not in progress
#define I2C_Rx_Status				I2C1CONbits.RCEN
#define I2C_INIT_RX					I2C1CONbits.RCEN = SET;
#define I2C_StopCndtion_Status		I2C1CONbits.PEN
#define I2C_INIT_STOP				I2C1CONbits.PEN = SET;
#define I2C_RepStartCndtion_Status	I2C1CONbits.PSEN
#define I2C_INIT_REPSTART			I2C1CONbits.PSEN = SET;
#define I2C_StartCndtion_Status		I2C1CONbits.SEN
#define I2C_INIT_START				I2C1CONbits.SEN = SET;


/*............. I2C1STAT I2C1 Status Register .............................................*/
#define I2C_ACK_Status				I2C1STATbits.ACKSTAT   //1=NACK received from slave; 0=ACK received from slave
#define I2C_TX_Status				I2C1STATbits.TRSTAT   //1=Mstr tx in progress (8 bits + ACK);0=Mstr tx not in progress
#define I2C_BusCollision_Status		I2C1STATbits.BCL   //1=Bus collision detected during a master operation;0=No collision
#define I2C_CLEAR_BUSCOLL			I2C1STATbits.BCL = CLEAR;
#define I2C_GeneralCall_Status		I2C1STATbits.GCSTAT   //1=Gral call address received;0=not received
#define I2C_10bitAddr_Status		I2C1STATbits.ADD10   //1=10-bit address was matched;0=not matched
#define I2C_WriteCollision_Status	I2C1STATbits.IWCOL   //1=Attempt to write the I2CxTRN reg failed,I2C module is busy;0=No collision
#define I2C_CLEAR_WRITECOLL			I2C1STATbits.IWCOL = CLEAR;
#define I2C_RxOverflow_Status		I2C1STATbits.I2COV   //1=A byte received while I2CxRCV reg still holding previous byte;0=No overflow
#define I2C_CLEAR_RXOVERFLOW		I2C1STATbits.I2COV = CLEAR;
#define I2C_DataAddr_Status			I2C1STATbits.D_A  //1=last byte received->data;0=last byte received->address
#define I2C_Stopbit_Status			I2C1STATbits.P   //1=Stop bit has been detected last;0=Stop bit was not detected last
#define I2C_CLEAR_STOPBIT			I2C1STATbits.P = CLEAR;
#define I2C_Startbit_Status			I2C1STATbits.S   //1=a Start (or Repeated Start) bit has been detected last;0=Start bit not detected last
#define I2C_CLEAR_STARTBIT			I2C1STATbits.S = CLEAR;
#define I2C_ReadWrite_Status		I2C1STATbits.R_W   //1=Read – indicates data transfer is output from slave;0=Write – indicates data transfer is input to slave
#define I2C_RxBufferFull_Status		I2C1STATbits.RBF   //1=Receive complete, I2CxRCV is full;0=Receive not complete, I2CxRCV is empty
#define I2C_TxBufferFull_Status		I2C1STATbits.TBF   //1=Transmit in progress, I2CxTRN is full;0=Transmit complete, I2CxTRN is empty


/*............. I2C1MSK I2C1 Slave Mode Address Mask Register .............................*/
#define I2C_AddrMask				I2C1MSK


/*-----------------------------------------------------------------------------------------*/
#endif