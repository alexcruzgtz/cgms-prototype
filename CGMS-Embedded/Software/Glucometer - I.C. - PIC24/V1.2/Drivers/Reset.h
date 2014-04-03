/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <p24fxxxx.h>

#ifndef __RESET_H
#define __RESET_H


/*-----------------------------------------------------------------------------------------*/

/*............. RCON Reset Control Register ...............................................*/
#define RST_TrapReset_Status		RCONbits.TRAPR		//1=Trap Conflict Reset Ocurred. 0= No Conflict Ocurred
#define RST_IllegalOpcode_Status	RCONbits.IOPUWR		
#define RST_DeepSleepMode_Status	RCONbits.DPSLP
#define RST_CfgWordMismatch_Status	RCONbits.CM
#define RST_PrgmMemoryPower_Status	RCONbits.PMSLP
#define RST_MCLR_Status				RCONbits.EXTR
#define RST_SoftwareReset_Status	RCONbits.SWR
#define RST_SoftwareWDT_Status		RCONbits.SWDTEN
#define RST_WDTTimeOut_Status		RCONbits.WDTO
#define RST_WakeSleepMode_Status	RCONbits.SLEEP
#define RST_WakeIdleMode_Status		RCONbits.IDLE
#define RST_BOROcurred_Status		RCONbits.BOR
#define RST_POROcurred_Status		RCONbits.POR


/*-----------------------------------------------------------------------------------------*/
#endif