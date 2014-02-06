/****************************************************************************
* FileName:		DemoOutput.c
* Dependencies: none   
* Processor:	PIC18, PIC24F, PIC32, dsPIC30, dsPIC33
*               tested with 18F4620, dsPIC33FJ256GP710	
* Complier:     Microchip C18 v3.04 or higher
*				Microchip C30 v2.03 or higher	
*               Microchip C32 v1.02 or higher
* Company:		Microchip Technology, Inc.
*
* Copyright and Disclaimer Notice for MiWi DE Software:
*
* Copyright © 2007-2012 Microchip Technology Inc.  All rights reserved.
*
* Microchip licenses to you the right to use, modify, copy and distribute 
* Software only when embedded on a Microchip microcontroller or digital 
* signal controller and used with a Microchip radio frequency transceiver, 
* which are integrated into your product or third party product (pursuant 
* to the terms in the accompanying license agreement).   
*
* You should refer to the license agreement accompanying this Software for 
* additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY 
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY 
* WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A 
* PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE 
* LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, 
* CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY 
* DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO 
* ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, 
* LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, 
* TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT 
* NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*
****************************************************************************
* File Description:
*
*  This is the output for the demo. The output information is displayed on
*  hyper terminal and LCD screen if demo board has one.
*
* Change History:
*  Rev   Date         Author    Description
*  4.1   1/31/2012    yfy       MiWi DE 4.2, simplified demo interface
**************************************************************************/

#include "Application/DemoOutput.h"

/*************************************************************************/
// the following two variable arrays are the data to be transmitted
// in this demo. They are bit map of English word "MiWi" and "DE"
// respectively.
/*************************************************************************/
ROM const BYTE MiWi[6][21] = 
{
    {0x20,0xB2,0x20,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0x20,0x20,0xB2,0x20,0xB2,0x0D,0x0A},
    {0xB2,0x20,0xB2,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0x20,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0xB2,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0xB2,0x20,0x20,0xB2,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0xB2,0x0D,0x0A},
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x0D,0x0A}
    
};   

ROM const BYTE DE[6][11] = 
{
    {0xB2,0xB2,0xB2,0x20,0x20,0xB2,0xB2,0xB2,0xB2,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0xB2,0xB2,0xB2,0xB2,0x0D,0x0A},
    {0xB2,0x20,0x20,0xB2,0x20,0xB2,0x20,0x20,0x20,0x0D,0x0A},
    {0xB2,0xB2,0xB2,0x20,0x20,0xB2,0xB2,0xB2,0xB2,0x0D,0x0A},
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x0D,0x0A}
}; 
void DemoOutput_Greeting(void)
{
	BYTE i=0;
	stdout =_H_USER;
	LCD_send_byte(0x80,0);
	printf("Simple P2P Demo");
	for (i=0 ; i<4 ; i++ )
	{
		DelayMs(250);
	}
    Printf("\r\nStarting Node 1 of Simple Demo for MiWi(TM) P2P Stack ...");  
    Printf("\r\nInput Configuration:");
    Printf("\r\n           Button: RB15");
    Printf("\r\nOutput Configuration:");
    Printf("\r\n              RS232 port");
    Printf("\r\n              LED: RB14");
    Printf("\r\n     RF Transceiver: MRF89XA");
}        

void DemoOutput_Channel(BYTE channel, BYTE Step)
{
	BYTE i=0;
    if( Step == 0 )
    {
		stdout =_H_USER;
		LCD_send_byte(0x80,0);
		printf("Conn Peer Chann");
		LCD_send_byte(0xC0,0);
		printf("%d",channel);
		for (i=0 ; i<4 ; i++ )
		{
			DelayMs(250);
		}
        Printf("\r\nConnecting Peer on Channel ");
        PrintDec(channel);
        Printf("\r\n");
    }
    else
    {    
        stdout =_H_USER;
		LCD_send_byte(0x80,0);
		printf("Conn Peer Chann");
		LCD_send_byte(0xC0,0);
		printf("%d",channel);
		for (i=0 ; i<4 ; i++ )
		{
			DelayMs(250);
		}
        Printf("\r\nConnected Peer on Channel ");
        PrintDec(channel);
        Printf("\r\n");
    }
}    


void DemoOutput_HandleMessage(void)
{
    BYTE i;
    
    if( rxMessage.flags.bits.secEn )
    {
        ConsolePutROMString((ROM char *)"Secured ");
    }

    if( rxMessage.flags.bits.broadcast )
    {
        ConsolePutROMString((ROM char *)"Broadcast Packet with RSSI ");
    }
    else
    {
        ConsolePutROMString((ROM char *)"Unicast Packet with RSSI ");
    }
    PrintChar(rxMessage.PacketRSSI);
    if( rxMessage.flags.bits.srcPrsnt )
    {
        ConsolePutROMString((ROM char *)" from ");
        if( rxMessage.flags.bits.altSrcAddr )
        {
            PrintChar( rxMessage.SourceAddress[1]);
            PrintChar( rxMessage.SourceAddress[0]);
        }
        else
        {    
            for(i = 0; i < MY_ADDRESS_LENGTH; i++)
            {
                PrintChar(rxMessage.SourceAddress[MY_ADDRESS_LENGTH-1-i]);
            }    
        }
    }
    ConsolePutROMString((ROM char *)": ");
    
    for(i = 0; i < rxMessage.PayloadSize; i++)
    {
        ConsolePut(rxMessage.Payload[i]);
    }       
}    

void DemoOutput_UpdateTxRx(BYTE TxNum, BYTE RxNum)
{
	BYTE i=0;
	stdout =_H_USER;
	LCD_send_byte(0x80,0);
	printf("TX:%d",TxNum);
	LCD_send_byte(0xC0,0);
	printf("RX:%d",RxNum);
	for (i=0 ; i<4 ; i++ )
	{
		DelayMs(250);
	}
}    

void DemoOutput_ChannelError(BYTE channel)
{
    Printf("\r\nSelection of channel ");
    PrintDec(channel);
    Printf(" is not supported in current configuration.\r\n");
}    

void DemoOutput_UnicastFail(void)
{
	BYTE i=0;
    Printf("\r\nUnicast Failed\r\n");                  
    stdout =_H_USER;
	LCD_send_byte(0x80,0);
	printf("Unicast Failed");
	for (i=0 ; i<4 ; i++ )
	{
		DelayMs(250);
	} 
}    

