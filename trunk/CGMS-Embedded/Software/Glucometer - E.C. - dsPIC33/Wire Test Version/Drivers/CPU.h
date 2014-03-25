/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __CPU_H
#define __CPU_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>


/*-----------------------------------------------------------------------------------------*/

/*.............SR CPU Status Register .....................................................*/
#define CPU_AOverflow_Status		SRbits.OA
#define CPU_BOverflow_Status		SRbits.OB
#define CPU_ASaturation_Status		SRbits.SA
#define CPU_BSaturation_Status		SRbits.SB
#define CPU_ABOverflow_Status		SRbits.OAB
#define CPU_ABSaturation_Status		SRbits.SAB
#define CPU_DoLoopActive_Status		SRbits.DA
#define CPU_ALU_HalfCarry_Status	SRbits.DC
#define CPU_ISRPriority				SRbits.IPL		/*111 = CPU Interrupt Priority Level is 7 (15), user interrupts disabled
													  110 = CPU Interrupt Priority Level is 6 (14)
													  101 = CPU Interrupt Priority Level is 5 (13)
													  100 = CPU Interrupt Priority Level is 4 (12)
													  011 = CPU Interrupt Priority Level is 3 (11)
													  010 = CPU Interrupt Priority Level is 2 (10)
													  001 = CPU Interrupt Priority Level is 1 (9)
													  000 = CPU Interrupt Priority Level is 0 (8)*/
#define CPU_RepeatLoop_Status		SRbits.RA
#define CPU_ALU_Negative_Status		SRbits.N
#define CPU_ALU_Overflow_Status		SRbits.OV
#define CPU_ALU_Zero_Status			SRbits.Z
#define CPU_ALU_Carry_Status		SRbits.C


/*.............CORCON Core Control Register ...............................................*/
#define CPU_DSP_MULT_UNSIGNED		CORCONbits.US = SET;
#define CPU_DSP_MULT_SIGNED			CORCONbits.US = CLEAR;
#define CPU_DOLOOP_TERMINATION		CORCONbits.EDT = SET;
#define CPU_DoLoopNesting_Status	CORCONbits.DL
#define CPU_ASAT_ENABLED			CORCONbits.SATA = SET;
#define CPU_ASAT_DISABLED			CORCONbits.SATA = CLEAR;
#define CPU_BSAT_ENABLED			CORCONbits.SATB = SET;
#define CPU_BSAT_DISABLED			CORCONbits.SATB = CLEAR;
#define CPU_DATASPACESAT_ENABLED	CORCONbits.SATDW = SET;
#define CPU_DATASPACESAT_DISABLED	CORCONbits.SATDW = CLEAR;
#define CPU_ACCSATMODE_SUPER		CORCONbits.ACCSAT = SET;
#define CPU_ACCSATMODE_NORMAL		CORCONbits.ACCSAT = CLEAR;
#define CPU_ISRPRIORITY_GREATER		CORCONbits.IPL3 = SET;
#define CPU_ISRPRIORITY_LESS		CORCONbits.IPL3 = CLEAR;
#define CPU_PROGSPACE_VISIBLE		CORCONbits.PSV = SET;
#define CPU_PROGSPACE_NOTVISIBLE	CORCONbits.PSV = CLEAR;
#define CPU_ROUNDMODE_BIASED		CORCONbits.RND = SET;		//conventional
#define CPU_ROUNDMODE_UNBIASED		CORCONbits.RND = CLEAR;		//convergent
#define CPU_DSPMUL_INTEGER			CORCONbits.IF = SET;
#define CPU_DSPMUL_FRACTIONAL		CORCONbits.IF = CLEAR;


/*-----------------------------------------------------------------------------------------*/
#endif
