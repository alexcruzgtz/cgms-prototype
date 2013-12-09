/********************************************************************
* FileName:		NVM.h
* Dependencies: none
* Processor:	PIC18, PIC24F, PIC32, dsPIC30, dsPIC33
*               tested with 18F4620, dsPIC33FJ256GP710	
* Complier:     Microchip C18 v3.04 or higher
*				Microchip C30 v2.03 or higher
*               Microchip C32 v1.02 or higher	
* Company:		Microchip Technology, Inc.
*
* Copyright and Disclaimer Notice
*
* Copyright � 2007-2010 Microchip Technology Inc.  All rights reserved.
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
* SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY 
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
*  Defines interface to access EUI EEPROM
*
* Change History:
*  Rev   Date         Author    Description
*  2.0   4/15/2009    yfy       MiMAC and MiApp revision
*  3.1   5/28/2010    yfy       MiWi DE 3.1
********************************************************************/
#ifndef __EEPROM_H
#define __EEPROM_H

/*-----------------------------------------------------------------------------------------*/
#include "MiWi_ConfigApp.h"
#if defined(PROTOCOL_P2P)
    #include "WirelessProtocols/P2P/MiWi_P2P.h"
#elif defined(PROTOCOL_MIWI)
    #include "WirelessProtocols/MiWi/MiWi.h"
#elif defined(PROTOCOL_MIWI_PRO)
    #include "WirelessProtocols/MiWiPRO/MiWiPRO.h"
#endif
    
/*.........................................................................................*/
#if defined(ENABLE_NVM)
	#include "GenericTypeDefs.h"
    #include "Compiler.h"
    #include "WirelessProtocols/MiWi_MCHP_API.h"


/*-----------------------------------------------------------------------------------------*/
  	#define TOTAL_NVM_BYTES     1024

    extern WORD        nvmMyPANID;
    extern WORD        nvmCurrentChannel;
    extern WORD        nvmConnMode;
    extern WORD        nvmConnectionTable;
    extern WORD        nvmOutFrameCounter;
                            
    #if defined(PROTOCOL_MIWI)
		extern WORD        nvmMyShortAddress;
        extern WORD        nvmMyParent;
        #ifdef NWK_ROLE_COORDINATOR
        	extern WORD    nvmRoutingTable;
            extern WORD    nvmKnownCoordinators;
            extern WORD    nvmRole;
        #endif
    #endif
       
    #if defined(PROTOCOL_MIWI_PRO)
    	extern WORD        nvmMyShortAddress;
        extern WORD        nvmMyParent;
        #ifdef NWK_ROLE_COORDINATOR
	    	extern WORD    nvmRoutingTable;
            extern WORD    nvmFamilyTree;
            extern WORD    nvmNeighborRoutingTable;
            extern WORD    nvmRole;
        #endif
    #endif
        
    void NVMRead(BYTE *dest, WORD addr, WORD count);
    void NVMWrite(BYTE *source, WORD addr, WORD count);
    BOOL NVMInit(void);

    #define nvmGetMyPANID( x )                  NVMRead( (BYTE *)x, nvmMyPANID, 2)
    #define nvmPutMyPANID( x )                  NVMWrite((BYTE *)x, nvmMyPANID, 2)
    #define nvmGetCurrentChannel( x )           NVMRead( (BYTE *)x, nvmCurrentChannel, 1)
    #define nvmPutCurrentChannel( x )           NVMWrite((BYTE *)x, nvmCurrentChannel, 1)
    #define nvmGetConnMode( x )                 NVMRead( (BYTE *)x, nvmConnMode, 1)
    #define nvmPutConnMode( x )                 NVMWrite((BYTE *)x, nvmConnMode, 1)
    #define nvmGetConnectionTable( x )          NVMRead( (BYTE *)x, nvmConnectionTable, (WORD)CONNECTION_SIZE * sizeof(CONNECTION_ENTRY))
    #define nvmPutConnectionTable( x )          NVMWrite((BYTE *)x, nvmConnectionTable, (WORD)CONNECTION_SIZE * sizeof(CONNECTION_ENTRY))
    #define nvmPutConnectionTableIndex(x, y)    NVMWrite((BYTE *)x, nvmConnectionTable+((WORD)y * sizeof(CONNECTION_ENTRY)), sizeof(CONNECTION_ENTRY))
    #define nvmGetOutFrameCounter( x )          NVMRead( (BYTE *)x, nvmOutFrameCounter, 4)
    #define nvmPutOutFrameCounter( x )          NVMWrite((BYTE *)x, nvmOutFrameCounter, 4)
            
    #if defined(PROTOCOL_MIWI)
		#define nvmGetMyShortAddress( x )       NVMRead( (BYTE *)x, nvmMyShortAddress, 2)
        #define nvmPutMyShortAddress( x )       NVMWrite((BYTE *)x, nvmMyShortAddress, 2)
        #define nvmGetMyParent( x )             NVMRead( (BYTE *)x, nvmMyParent, 1)
        #define nvmPutMyParent( x )             NVMWrite((BYTE *)x, nvmMyParent, 1)
	    #if defined(NWK_ROLE_COORDINATOR)
	    	#define nvmGetRoutingTable( x )         NVMRead( (BYTE *)x, nvmRoutingTable, 8)
            #define nvmPutRoutingTable( x )         NVMWrite((BYTE *)x, nvmRoutingTable, 8)
            #define nvmGetKnownCoordinators( x )    NVMRead( (BYTE *)x, nvmKnownCoordinators, 1)
            #define nvmPutKnownCoordinators( x )    NVMWrite((BYTE *)x, nvmKnownCoordinators, 1)
            #define nvmGetRole( x )                 NVMRead( (BYTE *)x, nvmRole, 1)
            #define nvmPutRole( x )                 NVMWrite((BYTE *)x, nvmRole, 1)
        #endif
    #endif
            
    #if defined(PROTOCOL_MIWI_PRO)
		#define nvmGetMyShortAddress( x )       NVMRead( (BYTE *)x, nvmMyShortAddress, 2)
        #define nvmPutMyShortAddress( x )       NVMWrite((BYTE *)x, nvmMyShortAddress, 2)
        #define nvmGetMyParent( x )             NVMRead( (BYTE *)x, nvmMyParent, 1)
        #define nvmPutMyParent( x )             NVMWrite((BYTE *)x, nvmMyParent, 1)
    	#if defined(NWK_ROLE_COORDINATOR)
        	#define nvmGetRoutingTable( x )         NVMRead( (BYTE *)x, nvmRoutingTable, NUM_COORDINATOR/8)
            #define nvmPutRoutingTable( x )         NVMWrite((BYTE *)x, nvmRoutingTable, NUM_COORDINATOR/8)
            #define nvmGetNeighborRoutingTable( x ) NVMRead( (BYTE *)x, nvmNeighborRoutingTable, ((WORD)NUM_COORDINATOR/8) * ((WORD)NUM_COORDINATOR))
            #define nvmPutNeighborRoutingTable( x ) NVMWrite((BYTE *)x, nvmNeighborRoutingTable, ((WORD)NUM_COORDINATOR/8) * ((WORD)NUM_COORDINATOR))
            #define nvmGetFamilyTree( x )           NVMRead( (BYTE *)x, nvmFamilyTree, NUM_COORDINATOR)
            #define nvmPutFamilyTree( x )           NVMWrite((BYTE *)x, nvmFamilyTree, NUM_COORDINATOR)
            #define nvmGetRole( x )                 NVMRead( (BYTE *)x, nvmRole, 1)
            #define nvmPutRole( x )                 NVMWrite((BYTE *)x, nvmRole, 1)
        #endif
    #endif    
    


/*-----------------------------------------------------------------------------------------*/
#endif
