/********************************************************************
* FileName:		NVM.c
* Dependencies: NVM.h
* Processor:	PIC18, PIC24, PIC32, dsPIC30, dsPIC33
*               tested with 18F4620, dsPIC33FJ256GP710	
* Complier:     Microchip C18 v3.04 or higher
*				Microchip C30 v2.03 or higher
*               Microchip C32 v1.02 or higher	
* Company:		Microchip Technology, Inc.
*
* Copyright © 2007-2010 Microchip Technology Inc.  All rights reserved.
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
*********************************************************************
* File Description:
*
*   This file access MAC EEPROM through SPI interface
*
* Change History:
*  Rev   Date         Author    Description
*  2.0   4/15/2009    yfy       MiMAC and MiApp revision
*  3.1   5/28/2010    yfy       MiWi DE 3.1
*  4.1   6/3/2011     yfy       MAL v2011-06
********************************************************************/
#include "MiWi_NVM.h"

/*-----------------------------------------------------------------------------------------*/
#if defined(ENABLE_NVM)
    
/*-----------------------------------------------------------------------------------------*/
    WORD    nvmMyPANID;
    WORD    nvmCurrentChannel;
    WORD    nvmConnMode;
    WORD    nvmConnectionTable;
    WORD	nvmOutFrameCounter;
  	WORD 	nextEEPosition;

/*-----------------------------------------------------------------------------------------*/
    extern void MacroNop(void);

/*.........................................................................................*/
    void NVMRead(BYTE *dest, WORD addr, WORD count)
    {
	    while( count )
        {
        	EEADRH = addr >> 8;
            EEADR = addr;
            EECON1bits.EEPGD = 0;
            EECON1bits.CFGS = 0;
            EECON1bits.RD = 1;   
            MacroNop();
            *dest++ = EEDATA;
            count--;
            addr++;
        }            
    }

/*.........................................................................................*/
    void NVMWrite(BYTE *source, WORD addr, WORD count)
    {
    	BYTE oldGIEH;
        while(count)
        {   
        	EEADRH = addr >> 8;
            EEADR = addr;
            EEDATA = *source++;   
            EECON1bits.EEPGD = 0;
            EECON1bits.CFGS = 0;
            EECON1bits.WREN = 1;
            oldGIEH = INTCONbits.GIEH;
            INTCONbits.GIEH = 0; 
            EECON2 = 0x55;
            EECON2 = 0xAA;
            EECON1bits.WR = 1;
            INTCONbits.GIEH = oldGIEH;
            while(EECON1bits.WR) ;
            EECON1bits.WREN = 0;
            count--;
            addr++;
        }
    }

/*.........................................................................................*/
    BOOL NVMalloc(WORD size, WORD *location)
    {
    	//WORD retval;
        if ((nextEEPosition + size) > TOTAL_NVM_BYTES)
        {
        	return FALSE;
        }
        *location = nextEEPosition;
        nextEEPosition += size;
        return TRUE;
    }
        
/*.........................................................................................*/
    BOOL NVMInit(void)
    {
    	BOOL result = TRUE;
        nextEEPosition = 0;
        result &= NVMalloc(2, &nvmMyPANID);
        result &= NVMalloc(1, &nvmCurrentChannel);
        result &= NVMalloc(1, &nvmConnMode);
        result &= NVMalloc(sizeof(CONNECTION_ENTRY) * CONNECTION_SIZE, &nvmConnectionTable);
        result &= NVMalloc(4, &nvmOutFrameCounter);
        return result;
    }

/*-----------------------------------------------------------------------------------------*/
#else
    extern char bogusVar;
    
/*-----------------------------------------------------------------------------------------*/
#endif   
