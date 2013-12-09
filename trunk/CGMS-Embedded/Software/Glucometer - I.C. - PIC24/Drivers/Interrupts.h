/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"

#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H


/*-----------------------------------------------------------------------------------------*/
#define _IRQ_LVL_15		15
#define _IRQ_LVL_14		14
#define _IRQ_LVL_13		13
#define _IRQ_LVL_12		12
#define _IRQ_LVL_11		11
#define _IRQ_LVL_10		10
#define _IRQ_LVL_9		9
#define _IRQ_LVL_8		8
#define _IRQ_LVL_7		7
#define _IRQ_LVL_6		6
#define _IRQ_LVL_5		5
#define _IRQ_LVL_4		4
#define _IRQ_LVL_3		3
#define _IRQ_LVL_2		2
#define _IRQ_LVL_1		1
#define _IRQ_LVL_0		0

#define _POS_EDGE		1
#define _NEG_EDGE		0

#define _HIGHEST_PENDING_INT	1
#define _LAST_ACK_INT			0

/*............ General IR Configuration ...................................................*/
#define IR_NESTING_ENABLED		INTCON1bits.NSTDIS=CLEAR;
#define IR_NESTING_DISABLED		INTCON1bits.NSTDIS=SET;
#define IR_USE_ALT_VECTORTABLE	INTCON2bits.ALTIVT=SET;
#define IR_USE_STD_VECTORTABLE	INTCON2bits.ALTIVT=CLEAR;
#define IR_DISI_Ins_Status		INTCON2bits.DISI
#define IR_IRQFromCPU_Status	INTTREGbits.CPUIRQ		//Set when CPU priority is higher than IRQ, and a IRQ has ocurred
#define IR_CfgVectorHold		INTTREGbits.VHOLD
#define IR_NewCPU_Priority		INTTREGbits.IRL
#define IR_PendingIntID			INTTREGbits.VECNUM		/*Pending Interrupt Vector ID bits (pending vector number is VECNUM + 8)
														0111111 = Interrupt Vector pending is number 135
														•••
														0000001 = Interrupt Vector pending is number 9
														0000000 = Interrupt Vector pending is number 8	 */


/*............. CPU .......................................................................*/
#define CPU_IRQ_Priority		SRbits.IPL
#define CPU_IRQ_GREATER			CORCONbits.IPL3=SET;
#define CPU_IRQ_LESS			CORCONbits.IPL3=CLEAR;
#define CPU_OverflowTrap_Status	INTCON1bits.MATHERR
#define CPU_AddressTrap_Status	INTCON1bits.ADDRERR
#define CPU_StackTrap_Status	INTCON1bits.STKERR
#define CPU_OscTrap_STatus		INTCON1bits.OSCFAIL
		

/*............. External Interrupts .......................................................*/
#define INT0_EdgeDetect			INTCON2bits.INT0EP
#define INT1_EdgeDetect			INTCON2bits.INT1EP
#define INT2_EdgeDetect			INTCON2bits.INT2EP

#define INT0_IRQ_Flag			IFS0bits.INT0IF
#define INT1_IRQ_Flag			IFS1bits.INT1IF
#define INT2_IRQ_Flag			IFS1bits.INT2IF

#define INT0_IRQ_ON				IEC0bits.INT0IE=SET;
#define INT0_IRQ_OFF			IEC0bits.INT0IE=CLEAR;
#define INT1_IRQ_ON				IEC1bits.INT1IE=SET;
#define INT1_IRQ_OFF			IEC1bits.INT1IE=CLEAR;
#define INT2_IRQ_ON				IEC1bits.INT2IE=SET;
#define INT2_IRQ_OFF			IEC1bits.INT2IE=CLEAR;

#define INT0_IRQ_Priority		IPC0bits.INT0IP
#define INT1_IRQ_Priority		IPC5bits.INT1IP
#define INT2_IRQ_Priority		IPC7bits.INT2IP


/*............. ADC .......................................................................*/
#define ADC_IRQ_Flag			IFS0bits.AD1IF
	
#define ADC_IRQ_ON				IEC0bits.AD1IE=SET;
#define ADC_IRQ_OFF				IEC0bits.AD1IE=CLEAR;

#define ADC_IRQ_Priority		IPC3bits.AD1IP


/*............. UART ......................................................................*/
#define UART1_TxIRQ_Flag		IFS0bits.U1TXIF
#define UART1_RxIRQ_Flag		IFS0bits.U1RXIF
#define UART1_ErrorIRQ_Flag		IFS4bits.U1ERIF
#define UART2_TxIRQ_Flag		IFS1bits.U2TXIF
#define UART2_RxIRQ_Flag		IFS1bits.U2RXIF
#define UART2_ErrorIRQ_Flag		IFS4bits.U2ERIF

#define UART1_TXIRQ_ON			IEC0bits.U1TXIE=SET;
#define UART1_TXIRQ_OFF			IEC0bits.U1TXIE=CLEAR;
#define UART1_RXIRQ_ON			IEC0bits.U1RXIE=SET;
#define UART1_RXIRQ_OFF			IEC0bits.U1RXIE=CLEAR;
#define UART2_TXIRQ_ON			IEC1bits.U2TXIE=SET;
#define UART2_TXIRQ_OFF			IEC1bits.U2TXIE=CLEAR;
#define UART2_RXIRQ_ON			IEC1bits.U2RXIE=SET;
#define UART2_RXIRQ_OFF			IEC1bits.U2RXIE=CLEAR;
#define UART1_ERRORIRQ_ON		IEC4bits.U1ERIE=SET;
#define UART1_ERRORIRQ_OFF		IEC4bits.U1ERIE=CLEAR;
#define UART2_ERRORIRQ_ON		IEC4bits.U2ERIE=SET;
#define UART2_ERRORIRQ_OFF		IEC4bits.U2ERIE=CLEAR;

#define UART1_RxIRQ_Priority	IPC2bits.U1RXIP
#define UART1_TxIRQ_Priority	IPC3bits.U1TXIP
#define UART2_RxIRQ_Priority	IPC7bits.U2RXIP
#define UART2_TxIRQ_Priority	IPC7bits.U2TXIP
#define UART1_ErrorIRQ_Priority	IPC16bits.U1ERIP
#define UART2_ErrorIRQ_Priority	IPC16bits.U2ERIP


/*............. SPI .......................................................................*/
#define SPI1_EventIRQ_Flag		IFS0bits.SPI1IF
#define SPI1_FaultIRQ_Flag		IFS0bits.SPF1IF
#define SPI2_EventIRQ_Flag		IFS2bits.SPI2IF
#define SPI2_FaultIRQ_Flag		IFS2bits.SPF2IF

#define SPI1_EVENTIRQ_ON		IEC0bits.SPI1IE=SET;
#define SPI1_EVENTIRQ_OFF		IEC0bits.SPI1IE=CLEAR;
#define SPI1_FAULTIRQ_ON		IEC0bits.SPF1IE=SET;
#define SPI1_FAULTIRQ_OFF		IEC0bits.SPF1IE=CLEAR;
#define SPI2_EVENTIRQ_ON		IEC2bits.SPI2IE=SET;
#define SPI2_EVENTIRQ_OFF		IEC2bits.SPI2IE=CLEAR;
#define SPI2_FAULTIRQ_ON		IEC2bits.SPF2IE=SET;
#define SPI2_FAULTIRQ_OFF		IEC2bits.SPF2IE=CLEAR;

#define SPI1_EventIRQ_Priority	IPC2bits.SPI1IP
#define SPI1_FaultIRQ_Priority	IPC2bits.SPF1IP
#define SPI2_EventIRQ_Priority	IPC8bits.SPI2IP
#define SPI2_FaultIRQ_Priority	IPC8bits.SPF2IP


/*............. I2C .......................................................................*/
#define I2C1_MasterIRQ_Flag		IFS1bits.MI2C1IF
#define I2C1_SlaveIRQ_Flag		IFS1bits.SI2C1IF
#define I2C2_MasterIRQ_Flag		IFS3bits.MI2C2IF
#define I2C2_SlaveIRQ_Flag		IFS3bits.SI2C2IF

#define I2C1_MASTERIRQ_ON		IEC1bits.MI2C1IE=SET;
#define I2C1_MASTERIRQ_OFF		IEC1bits.MI2C1IE=CLEAR;
#define I2C1_SLAVEIRQ_ON		IEC1bits.SI2C1IE=SET;
#define I2C1_SLAVEIRQ_OFF		IEC1bits.SI2C1IE=CLEAR;
#define I2C2_MASTERIRQ_ON		IEC3bits.MI2C2IE=SET;
#define I2C2_MASTERIRQ_OFF		IEC3bits.MI2C2IE=CLEAR;
#define I2C2_SLAVEIRQ_ON		IEC3bits.SI2C2IE=SET;
#define I2C2_SLAVEIRQ_OFF		IEC3bits.SI2C2IE=CLEAR;

#define I2C1_MasterIRQ_Priority	IPC4bits.MI2C1IP
#define I2C1_SlaveIRQ_Priority	IPC4bits.SI2C1IP
#define I2C2_MasterIRQ_Priority	IPC12bits.MI2C2IP
#define I2C2_SlaveIRQ_Priority	IPC12bits.SI2C2IP


/*............. TIMERS ....................................................................*/
#define TMR1_IRQ_Flag			IFS0bits.T1IF
#define TMR2_IRQ_Flag			IFS0bits.T2IF
#define TMR3_IRQ_Flag			IFS0bits.T3IF
#define TMR4_IRQ_Flag			IFS1bits.T4IF
#define TMR5_IRQ_Flag			IFS1bits.T5IF

#define TMR1_IRQ_ON				IEC0bits.T1IE=SET;
#define TMR1_IRQ_OFF			IEC0bits.T1IE=CLEAR;
#define TMR2_IRQ_ON				IEC0bits.T2IE=SET;
#define TMR2_IRQ_OFF			IEC0bits.T2IE=CLEAR;
#define TMR3_IRQ_ON				IEC0bits.T3IE=SET;
#define TMR3_IRQ_OFF			IEC0bits.T3IE=CLEAR;
#define TMR4_IRQ_ON				IEC1bits.T4IE=SET;
#define TMR4_IRQ_OFF			IEC1bits.T4IE=CLEAR;
#define TMR5_IRQ_ON				IEC1bits.T5IE=SET;
#define TMR5_IRQ_OFF			IEC1bits.T5IE=CLEAR;

#define TMR1_IRQ_Priority		IPC0bits.T1IP
#define TMR2_IRQ_Priority		IPC1bits.T2IP
#define TMR3_IRQ_Priority		IPC2bits.T3IP
#define TMR4_IRQ_Priority		IPC6bits.T4IP
#define TMR5_IRQ_Priority		IPC7bits.T5IP


/*............. Output Compare ............................................................*/
#define OC1_IRQ_Flag			IFS0bits.OC1IF
#define OC2_IRQ_Flag			IFS0bits.OC2IF
#define OC3_IRQ_Flag			IFS1bits.OC3IF
#define OC4_IRQ_Flag			IFS1bits.OC4IF
#define OC5_IRQ_Flag			IFS2bits.OC5IF

#define OC1_IRQ_ON				IEC0bits.OC1IE=SET;
#define OC1_IRQ_OFF				IEC0bits.OC1IE=CLEAR;
#define OC2_IRQ_ON				IEC0bits.OC2IE=SET;
#define OC2_IRQ_OFF				IEC0bits.OC2IE=CLEAR;
#define OC3_IRQ_ON				IEC1bits.OC3IE=SET;
#define OC3_IRQ_OFF				IEC1bits.OC3IE=CLEAR;
#define OC4_IRQ_ON				IEC1bits.OC4IE=SET;
#define OC4_IRQ_OFF				IEC1bits.OC4IE=CLEAR;
#define OC5_IRQ_ON				IEC2bits.OC5IE=SET;
#define OC5_IRQ_OFF				IEC2bits.OC5IE=CLEAR;

#define OC1_IRQ_Priority		IPC0bits.OC1IP
#define OC2_IRQ_Priority		IPC1bits.OC2IP
#define OC3_IRQ_Priority		IPC6bits.OC3IP
#define OC4_IRQ_Priority		IPC6bits.OC4IP
#define OC5_IRQ_Priority		IPC10bits.OC5IP


/*............. Input Compare .............................................................*/
#define IC1_IRQ_Flag			IFS0bits.IC1IF
#define IC2_IRQ_Flag			IFS0bits.IC2IF
#define IC3_IRQ_Flag			IFS2bits.IC3IF
#define IC4_IRQ_Flag			IFS2bits.IC4IF
#define IC5_IRQ_Flag			IFS2bits.IC5IF

#define IC1_IRQ_ON				IEC0bits.IC1IE=SET;
#define IC1_IRQ_OFF				IEC0bits.IC1IE=CLEAR;
#define IC2_IRQ_ON				IEC0bits.IC2IE=SET;
#define IC2_IRQ_OFF				IEC0bits.IC2IE=CLEAR;
#define IC3_IRQ_ON				IEC2bits.IC3IE=SET;
#define IC3_IRQ_OFF				IEC2bits.IC3IE=CLEAR;
#define IC4_IRQ_ON				IEC2bits.IC4IE=SET;
#define IC4_IRQ_OFF				IEC2bits.IC4IE=CLEAR;
#define IC5_IRQ_ON				IEC2bits.IC5IE=SET;
#define IC5_IRQ_OFF				IEC2bits.IC5IE=CLEAR;

#define IC1_IRQ_Priority		IPC0bits.IC1IP
#define IC2_IRQ_Priority		IPC1bits.IC2IP
#define IC3_IRQ_Priority		IPC9bits.IC3IP
#define IC4_IRQ_Priority		IPC9bits.IC4IP
#define IC5_IRQ_Priority		IPC9bits.IC5IP


/*............. Input Change Notification .................................................*/
#define ICN_IRQ_Flag			IFS1bits.CNIF

#define ICN_IRQ_ON				IEC1bits.CNIE=SET;
#define ICN_IRQ_OFF				IEC1bits.CNIE=CLEAR;

#define ICN_IRQ_Priority		IPC4bits.CNIP


/*............. Comparator ................................................................*/
#define COMP_IRQ_Flag			IFS1bits.CMIF

#define COMP_IRQ_ON				IEC1bits.CMIE=SET;
#define COMP_IRQ_OFF			IEC1bits.CMIE=CLEAR;

#define COMP_IRQ_Priority		IPC4bits.CMIP


/*............. Parallel Master Port ......................................................*/
#define PMP_IRQ_Flag			IFS2bits.PMPIF

#define PMP_IRQ_ON				IEC2bits.PMPIE=SET;
#define PMP_IRQ_OFF				IEC2bits.PMPIE=CLEAR;

#define PMP_IRQ_Priority		IPC11bits.PMPIP


/*............. Real Time Clock/Calendar ..................................................*/
#define RTCC_IRQ_Flag			IFS3bits.RTCIF

#define RTCC_IRQ_ON				IEC3bits.RTCIE=SET;
#define RTCC_IRQ_OFF			IEC3bits.RTCIE=CLEAR;

#define RTCC_IRQ_Priority		IPC15bits.RTCIP


/*............. Charge Time Measurement Unit ..............................................*/
#define CTMU_IRQ_Flag			IFS4bits.CTMUIF

#define CTMU_IRQ_ON				IEC4bits.CTMUIE=SET;
#define CTMU_IRQ_OFF			IEC4bits.CTMUIE=CLEAR;

#define CTMU_IRQ_Priority		IPC19bits.CTMUIP


/*............. Low Voltage Detector ......................................................*/
#define LVD_IRQ_Flag			IFS4bits.LVDIF

#define LVD_IRQ_ON				IEC4bits.LVDIE=SET;
#define LVD_IRQ_OFF				IEC4bits.LVDIE=CLEAR;

#define LVD_IRQ_Priority		IPC18bits.LVDIP


/*............. CRC Generator .............................................................*/
#define CRC_IRQ_Flag			IFS4bits.CRCIF

#define CRC_IRQ_ON				IEC4bits.CRCIE=SET;
#define CRC_IRQ_OFF				IEC4bits.CRCIE=CLEAR;

#define CRC_IRQ_Priority		IPC16bits.CRCIP



/*-----------------------------------------------------------------------------------------*/
#endif