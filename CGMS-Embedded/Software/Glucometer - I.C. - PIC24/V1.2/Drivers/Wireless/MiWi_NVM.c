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


#include "Drivers/Wireless/MiWi_NVM.h"
#include "Drivers/Wireless/MiWi_ConfigApp.h"
#include <GenericTypeDefs.h>
#include "Drivers/Compiler.h"
#include "Drivers/UART_Handler.h"
#include "Drivers/Wireless/MiWi_MCHP_API.h"
#include "Drivers/Wireless/MiWi_P2P.h"

/*-----------------------------------------------------------------------------------------*/
#if defined(ENABLE_NVM)

/*-----------------------------------------------------------------------------------------*/
    ROM BYTE filler[ERASE_BLOCK_SIZE] = {0x00};
    ROM WORD_VAL            nvmMyPANID;
    ROM BYTE                nvmCurrentChannel;
    ROM BYTE                nvmConnMode;
    ROM CONNECTION_ENTRY    nvmConnectionTable[CONNECTION_SIZE];
    ROM DWORD_VAL           nvmOutFrameCounter;               
    ROM BYTE filler2[ERASE_BLOCK_SIZE] = {0x00};

/*-----------------------------------------------------------------------------------------*/
	extern void MacroNop(void);
  	
	void NVMWrite(BYTE *src, ROM BYTE* dest, WORD count)
    {
	    ROM char *pEraseBlock;
        static BYTE memBlock[ERASE_BLOCK_SIZE];
        BYTE *pMemBlock;
        BYTE writeIndex;
        BYTE writeStart;
        BYTE writeCount;
        BYTE oldGIEH;
        DWORD oldTBLPTR;
        
        #if defined(VERIFY_WRITE)
      	  while( memcmppgm2ram( src, (MEM_MODEL ROM void *)dest, count))
        #elif defined(CHECK_BEFORE_WRITE)
          if (memcmppgm2ram( src, (MEM_MODEL ROM void *)dest, count ))
        #endif
        {
        	// First of all get nearest "left" erase block boundary
            pEraseBlock = (ROM char*)((long)dest & (long)(~(ERASE_BLOCK_SIZE-1)));
            writeStart = (BYTE)((BYTE)dest & (BYTE)(ERASE_BLOCK_SIZE-1));
            while( count )
            {
	            // Now read the entire erase block size into RAM.
                NVMRead(memBlock, (far ROM void*)pEraseBlock, ERASE_BLOCK_SIZE);
                // Erase the block.
                // Erase flash memory, enable write control.
                EECON1 = 0x94;
                oldGIEH = INTCONbits.GIEH;
                INTCONbits.GIEH = 0;
                EECON2 = 0x55;
                EECON2 = 0xaa;
                EECON1bits.WR = 1;
                MacroNop();
                EECON1bits.WREN = 0;
                oldTBLPTR = TBLPTR;
                INTCONbits.GIEH = oldGIEH;
        
                // Modify 64-byte block of RAM buffer as per what is required.
                pMemBlock = &memBlock[writeStart];
                while( writeStart < ERASE_BLOCK_SIZE && count )
                {
                	*pMemBlock++ = *src++;
                    count--;
                    writeStart++;
                }
                // After first block write, next start would start from 0.
                writeStart = 0;
                // Now write entire 64 byte block in one write block at a time.
                writeIndex = ERASE_BLOCK_SIZE / WRITE_BLOCK_SIZE;
                pMemBlock = memBlock;
                while( writeIndex )
                {
	                oldGIEH = INTCONbits.GIEH;
                    INTCONbits.GIEH = 0;
                    TBLPTR = oldTBLPTR;
                    // Load individual block
                    writeCount = WRITE_BLOCK_SIZE;
                    while( writeCount-- )
                    {
	                    TABLAT = *pMemBlock++;
                        //TBLWTPOSTINC();
                        _asm tblwtpostinc _endasm
                    }
                    // Start the write process: reposition tblptr back into memory block that we want to write to.
                    // Write flash memory, enable write control.
                    EECON1 = 0x84;
                    EECON2 = 0x55;
                    EECON2 = 0xaa;
                    EECON1bits.WR = 1;
                    MacroNop();
                    EECON1bits.WREN = 0;
                    // One less block to write
                    writeIndex--;
                    TBLPTR++;
                    oldTBLPTR = TBLPTR;
                    INTCONbits.GIEH = oldGIEH;
                }
                // Go back and do it all over again until we write all
                // data bytes - this time the next block.
                #if !defined(WIN32)
	                pEraseBlock += ERASE_BLOCK_SIZE;
                #endif
            }
        }
     }


/*-----------------------------------------------------------------------------------------*/
#else
    extern char bogusVar;


/*-----------------------------------------------------------------------------------------*/    
#endif   
