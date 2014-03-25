/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __RESET_H
#define __RESET_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>


/*-----------------------------------------------------------------------------------------*/

/*............. RCON Reset Control Register ...............................................*/
#define RST_TrapReset_Status		RCONbits.TRAPR		//1=Trap Conflict Reset Ocurred. 0= No Conflict Ocurred
#define RST_IllegalOpcode_Status	RCONbits.IOPUWR		
#define RST_CfgWordMismatch_Status	RCONbits.CM
#define RST_VREGINSLEEP_ON			RCONbits.VREGS = SET;
#define RST_VREGINSLEEP_OFF			RCONbits.VREGS = CLEAR;
#define RST_MCLR_Status				RCONbits.EXTR
#define RST_SoftwareReset_Status	RCONbits.SWR
#define RST_WDT_ENABLED				RCONbits.SWDTEN = SET;
#define RST_WDT_DISABLED			RCONbits.SWDTEN = CLEAR;
#define RST_WDTTimeOut_Status		RCONbits.WDTO
#define RST_WakeSleepMode_Status	RCONbits.SLEEP
#define RST_WakeIdleMode_Status		RCONbits.IDLE
#define RST_BOROcurred_Status		RCONbits.BOR
#define RST_POROcurred_Status		RCONbits.POR


/*-----------------------------------------------------------------------------------------*/
#endif
