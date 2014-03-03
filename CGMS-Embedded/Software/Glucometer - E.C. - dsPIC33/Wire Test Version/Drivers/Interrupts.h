/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H


/*-----------------------------------------------------------------------------------------*/
#include <p33fxxxx.h>
#include <GenericTypeDefs.h>
//#include "ADC_Handler.h"


/*-----------------------------------------------------------------------------------------*/
#define _LVL_15		15
#define _LVL_14		14
#define _LVL_13		13
#define _LVL_12		12
#define _LVL_11		11
#define _LVL_10		10
#define _LVL_9		9
#define _LVL_8		8
#define _LVL_7		7
#define _LVL_6		6
#define _LVL_5		5
#define _LVL_4		4
#define _LVL_3		3
#define _LVL_2		2
#define _LVL_1		1
#define _LVL_0		0

#define _POS_EDGE		0
#define _NEG_EDGE		1

#define _HIGHEST_PENDING_INT	1
#define _LAST_ACK_INT			0

/*............ General IR Configuration ...................................................*/
#define IR_NESTING_ENABLED			INTCON1bits.NSTDIS = CLEAR;
#define IR_NESTING_DISABLED			INTCON1bits.NSTDIS = SET;
#define IR_AOverflowTrap_Flag		INTCON1bits.OVAERR
#define IR_BOverflowTrap_Flag		INTCON1bits.OVBERR
#define IR_ACatasOvTrap_Flag		INTCON1bits.COVAERR
#define IR_BCatasOvTrap_Flag		INTCON1bits.COVBERR
#define IR_AOVTRAP_ENABLED			INTCON1bits.OVATE = SET;
#define IR_AOVTRAP_DISABLED			INTCON1bits.OVATE = CLEAR;
#define IR_BOVTRAP_ENABLED			INTCON1bits.OVBTE = SET;
#define IR_BOVTRAP_DISABLED			INTCON1bits.OVBTE = CLEAR;
#define IR_CATASOVTRAP_ENABLED		INTCON1bits.COVTE = SET;
#define IR_CATASOVTRAP_DISABLED		INTCON1bits.COVTE = CLEAR;
#define IR_ShiftAccError_Status		INTCON1bits.SFTACERR
#define IR_Div0ArithError_Status	INTCON1bits.DIV0ERR
#define IR_DMAContError_Status		INTCON1bits.DMACERR
#define IR_ArithError_Status		INTCON1bits.MATHERR
#define IR_AddErrorTrap_Status		INTCON1bits.ADDRERR
#define IR_StackErrorTrap_Status	INTCON1bits.STKERR
#define IR_OscFailTrap_Status		INTCON1btis.OSCFAIL

#define IR_USE_ALT_VECTORTABLE		INTCON2bits.ALTIVT=SET;
#define IR_USE_STD_VECTORTABLE		INTCON2bits.ALTIVT=CLEAR;
#define IR_DISIIns_Status			INTCON2bits.DISI

#define IR_NewCPU_Priority			INTTREGbits.IRL
#define IR_PendingIntID				INTTREGbits.VECNUM		/*Pending Interrupt Vector ID bits (pending vector number is VECNUM + 8)
														0111111 = Interrupt Vector pending is number 135
														•••
														0000001 = Interrupt Vector pending is number 9
														0000000 = Interrupt Vector pending is number 8	 */

#define IR_QEI1EventIRQ_Flag		IFS3bits.QEI1IF
#define IR_QEI1EVENTIRQ_ON			IEC3bits.QEI1IE = SET;
#define IR_QEI1EVENTIRQ_OFF			IEC3bits.QEI1IE = CLEAR;
#define IR_QEI1IRQ_Priority			IPC14bits.QEI1IP

#define IR_QEI2EventIRQ_Flag		IFS4bits.QEI2IF		
#define IR_QEI2EVENTIRQ_ON			IEC4bits.QEI2IE = SET;
#define IR_QEI2EVENTIRQ_OFF			IEC4bits.QEI2IE = CLEAR;
#define IR_QEI2IRQ_Priority			IPC18bits.QEI2IP


/*............. DMA Interrupts ............................................................*/
#define DMA_CH0IRQ_Flag				IFS0bits.DMA0IF
#define DMA_CH0IRQ_ON				IEC0bits.DMA0IE = SET;
#define DMA_CH0IRQ_OFF				IEC0bits.DMA0IE = CLEAR;
#define DMA_CH0IRQ_Priority			IPC1bits.DMA0IP

#define DMA_CH1IRQ_Flag				IFS0bits.DMA1IF
#define DMA_CH1IRQ_ON				IEC0bits.DMA1IE = SET;
#define DMA_CH1IRQ_OFF				IEC0bits.DMA1IE = CLEAR;
#define DMA_CH1IRQ_Priority			IPC3bits.DMA1IP

#define DMA_CH2IRQ_Flag				IFS1bits.DMA2IF
#define DMA_CH2IRQ_ON				IEC1bits.DMA2IE = SET;
#define DMA_CH2IRQ_OFF				IEC1bits.DMA2IE = CLEAR;
#define DMA_CH2IRQ_Priority			IPC6bits.DMA2IP

#define DMA_CH3IRQ_Flag				IFS2bits.DMA3IF
#define DMA_CH3IRQ_ON				IEC2bits.DMA3IE = SET;
#define DMA_CH3IRQ_OFF				IEC2bits.DMA3IE = CLEAR;
#define DMA_CH3IRQ_Priority			IPC9bits.DMA3IP

#define DMA_CH4IRQ_Flag				IFS2bits.DMA4IF
#define DMA_CH4IRQ_ON				IEC2bits.DMA4IE = SET;
#define DMA_CH4IRQ_OFF				IEC2bits.DMA4IE = CLEAR;
#define DMA_CH4IRQ_Priority			IPC11bits.DMA4IP

#define DMA_CH5IRQ_Flag				IFS3bits.DMA5IF
#define DMA_CH5IRQ_ON				IEC3bits.DMA5IE = SET;
#define DMA_CH5IRQ_OFF				IEC3bits.DMA5IE = CLEAR;
#define DMA_CH5IRQ_Priority			IPC15bits.DMA5IP

#define DMA_CH6IRQ_Flag				IFS4bits.DMA6IF
#define DMA_CH6IRQ_ON				IEC4bits.DMA6IE = SET;
#define DMA_CH6IRQ_OFF				IEC4bits.DMA6IE = CLEAR;
#define DMA_CH6IRQ_Priority			IPC17bits.DMA6IP

#define DMA_CH7IRQ_Flag				IFS4bits.DMA7IF
#define DMA_CH7IRQ_ON				IEC4bits.DMA7IE = SET;
#define DMA_CH7IRQ_OFF				IEC4bits.DMA7IE = CLEAR;
#define DMA_CH7IRQ_Priority			IPC17bits.DMA7IP

/*............. External Interrupts .......................................................*/
#define INT0_EdgeDetect				INTCON2bits.INT0EP
#define INT0_IRQ_Flag				IFS0bits.INT0IF
#define INT0_IRQ_En					IEC0bits.INT0IE
#define INT0_IRQ_ON					IEC0bits.INT0IE = SET;
#define INT0_IRQ_OFF				IEC0bits.INT0IE = CLEAR;
#define INT0_IRQ_Priority			IPC0bits.INT0IP

#define INT1_EdgeDetect				INTCON2bits.INT1EP
#define INT1_IRQ_Flag				IFS1bits.INT1IF
#define INT1_IRQ_En					IEC1bits.INT1IE
#define INT1_IRQ_ON					IEC1bits.INT1IE = SET;
#define INT1_IRQ_OFF				IEC1bits.INT1IE = CLEAR;
#define INT1_IRQ_Priority			IPC5bits.INT1IP

#define INT2_EdgeDetect				INTCON2bits.INT2EP
#define INT2_IRQ_Flag				IFS1bits.INT2IF
#define INT2_IRQ_En					IEC1bits.INT2IE
#define INT2_IRQ_ON					IEC1bits.INT2IE = SET;
#define INT2_IRQ_OFF				IEC1bits.INT2IE = CLEAR;
#define INT2_IRQ_Priority			IPC7bits.INT2IP


/*............. ADC .......................................................................*/
#define ADC_IRQ_Flag				IFS0bits.AD1IF
#define ADC_IRQ_ON					IEC0bits.AD1IE = SET;
#define ADC_IRQ_OFF					IEC0bits.AD1IE = CLEAR;
#define ADC_IRQ_Priority			IPC3bits.AD1IP


/*............. DAC .......................................................................*/
#define DAC_LeftIRQ_Flag			IFS4bits.DAC1LIF
#define DAC_LEFTIRQ_ON				IEC4bits.DAC1LIE = SET;
#define DAC_LEFTIRQ_OFF				IEC4bits.DAC1LIE = CLEAR;
#define DAC_LeftIRQ_Priority		IPC19bits.DAC1LIP

#define DAC_RightIRQ_Flag			IFS4bits.DAC1RIF
#define DAC_RIGHTIRQ_ON				IEC4bits.DAC1RIE = SET;
#define DAC_RIGHTIRQ_OFF			IEC4bits.DAC1RIE = CLEAR;
#define DAC_RightIRQ_Priority		IPC19bits.DAC1RIP

/*............. UART ......................................................................*/
#define UART1_TxIRQ_Flag		IFS0bits.U1TXIF
#define UART1_TXIRQ_ON			IEC0bits.U1TXIE = SET;
#define UART1_TXIRQ_OFF			IEC0bits.U1TXIE = CLEAR;
#define UART1_RxIRQ_Priority	IPC2bits.U1RXIP
#define UART1_RxIRQ_Flag		IFS0bits.U1RXIF
#define UART1_RXIRQ_ON			IEC0bits.U1RXIE = SET;
#define UART1_RXIRQ_OFF			IEC0bits.U1RXIE = CLEAR;
#define UART1_TxIRQ_Priority	IPC3bits.U1TXIP
#define UART1_ErrIRQ_Flag		IFS4bits.U1EIF
#define UART1_ERRIRQ_ON			IEC4bits.U1EIE = SET;
#define UART1_ERRIRQ_OFF		IEC4bits.U1EIE = CLEAR;
#define UART1_ErrIRQ_Priority	IPC16bits.U1EIP

#define UART2_TxIRQ_Flag		IFS1bits.U2TXIF
#define UART2_TXIRQ_ON			IEC1bits.U2TXIE = SET;
#define UART2_TXIRQ_OFF			IEC1bits.U2TXIE = CLEAR;
#define UART2_RxIRQ_Priority	IPC7bits.U2RXIP
#define UART2_RxIRQ_Flag		IFS1bits.U2RXIF
#define UART2_RXIRQ_ON			IEC1bits.U2RXIE = SET;
#define UART2_RXIRQ_OFF			IEC1bits.U2RXIE = CLEAR;
#define UART2_TxIRQ_Priority	IPC7bits.U2TXIP
#define UART2_ErrIRQ_Flag		IFS4bits.U2EIF
#define UART2_ERRIRQ_ON			IEC4bits.U2EIE = SET;
#define UART2_ERRIRQ_OFF		IEC4bits.U2EIE = CLEAR;
#define UART2_ErrIRQ_Priority	IPC16bits.U2EIP


/*............. SPI .......................................................................*/
#define SPI1_EventIRQ_Flag		IFS0bits.SPI1IF
#define SPI1_EVENTIRQ_ON		IEC0bits.SPI1IE = SET;
#define SPI1_EVENTIRQ_OFF		IEC0bits.SPI1IE = CLEAR;
#define SPI1_EventIRQ_Priority	IPC2bits.SPI1IP
#define SPI1_ErrIRQ_Flag		IFS0bits.SPF1IF
#define SPI1_ERRIRQ_ON			IEC0bits.SPI1EIE = SET;
#define SPI1_ERRIRQ_OFF			IEC0bits.SPI1EIE = CLEAR;
#define SPI1_ErrIRQ_Priority	IPC2bits.SPI1EIP

#define SPI2_EventIRQ_Flag		IFS2bits.SPI2IF
#define SPI2_EVENTIRQ_ON		IEC2bits.SPI2IE = SET;
#define SPI2_EVENTIRQ_OFF		IEC2bits.SPI2IE = CLEAR;
#define SPI2_EventIRQ_Priority	IPC8bits.SPI2IP
#define SPI2_ErrIRQ_Flag		IFS2bits.SPF2IF
#define SPI2_ERRIRQ_ON			IEC2bits.SPI2EIE = SET;
#define SPI2_ERRIRQ_OFF			IEC2bits.SPI2EIE = CLEAR;
#define SPI2_ErrIRQ_Priority	IPC8bits.SPI2EIP


/*............. I2C .......................................................................*/
#define I2C1_MasterIRQ_Flag		IFS1bits.MI2C1IF
#define I2C1_MASTERIRQ_ON		IEC1bits.MI2C1IE = SET;
#define I2C1_MASTERIRQ_OFF		IEC1bits.MI2C1IE = CLEAR;
#define I2C1_MasterIRQ_Priority	IPC4bits.MI2C1IP

#define I2C1_SlaveIRQ_Flag		IFS1bits.SI2C1IF
#define I2C1_SLAVEIRQ_ON		IEC1bits.SI2C1IE = SET;
#define I2C1_SLAVEIRQ_OFF		IEC1bits.SI2C1IE = CLEAR;
#define I2C1_SlaveIRQ_Priority	IPC4bits.SI2C1IP


/*............. ECAN ......................................................................*/
#define ECAN_EventIRQ_Flag		IFS2bits.C1IF
#define ECAN_EVENTIRQ_ON		IEC2bits.C1IE = SET;
#define ECAN_EVENTIRQ_OFF		IEC2bits.C1IE = CLEAR;
#define ECAN_EventIRQ_Priority	IPC8bits.C1IP

#define ECAN_RxIRQ_Flag			IFS2bits.C1RXIF
#define ECAN_RXIRQ_ON			IEC2bits.C1RXIE = SET;
#define ECAN_RXIRQ_OFF			IEC2bits.C1RXIE = CLEAR;
#define ECAN_RxIRQ_Priority		IPC8bits.C1RXIP

#define ECAN_TxIRQ_Flag			IFS4bits.C1TXIF
#define ECAN_TXIRQ_ON			IEC4bits.C1TXIE = SET;
#define ECAN_TXIRQ_OFF			IEC4bits.C1TXIE = CLEAR;
#define ECAN_TxIRQ_Priority		IPC17bits.C1TXIP


/*............. TIMERS ....................................................................*/
#define TMR1_IRQ_Flag			IFS0bits.T1IF
#define TMR1_IRQ_ON				IEC0bits.T1IE = SET;
#define TMR1_IRQ_OFF			IEC0bits.T1IE = CLEAR;
#define TMR1_IRQ_Priority		IPC0bits.T1IP

#define TMR2_IRQ_Flag			IFS0bits.T2IF
#define TMR2_IRQ_ON				IEC0bits.T2IE = SET;
#define TMR2_IRQ_OFF			IEC0bits.T2IE = CLEAR;
#define TMR2_IRQ_Priority		IPC1bits.T2IP

#define TMR3_IRQ_Flag			IFS0bits.T3IF
#define TMR3_IRQ_ON				IEC0bits.T3IE = SET;
#define TMR3_IRQ_OFF			IEC0bits.T3IE = CLEAR;
#define TMR3_IRQ_Priority		IPC2bits.T3IP

#define TMR4_IRQ_Flag			IFS1bits.T4IF
#define TMR4_IRQ_ON				IEC1bits.T4IE = SET;
#define TMR4_IRQ_OFF			IEC1bits.T4IE = CLEAR;
#define TMR4_IRQ_Priority		IPC6bits.T4IP

#define TMR5_IRQ_Flag			IFS1bits.T5IF
#define TMR5_IRQ_ON				IEC1bits.T5IE = SET;
#define TMR5_IRQ_OFF			IEC1bits.T5IE = CLEAR;
#define TMR5_IRQ_Priority		IPC7bits.T5IP


/*............. Output Compare ............................................................*/
#define OC1_IRQ_Flag			IFS0bits.OC1IF
#define OC1_IRQ_ON				IEC0bits.OC1IE = SET;
#define OC1_IRQ_OFF				IEC0bits.OC1IE = CLEAR;
#define OC1_IRQ_Priority		IPC0bits.OC1IP

#define OC2_IRQ_Flag			IFS0bits.OC2IF
#define OC2_IRQ_ON				IEC0bits.OC2IE = SET;
#define OC2_IRQ_OFF				IEC0bits.OC2IE = CLEAR;
#define OC2_IRQ_Priority		IPC1bits.OC2IP

#define OC3_IRQ_Flag			IFS1bits.OC3IF
#define OC3_IRQ_ON				IEC1bits.OC3IE = SET;
#define OC3_IRQ_OFF				IEC1bits.OC3IE = CLEAR;
#define OC3_IRQ_Priority		IPC6bits.OC3IP

#define OC4_IRQ_Flag			IFS1bits.OC4IF
#define OC4_IRQ_ON				IEC1bits.OC4IE = SET;
#define OC4_IRQ_OFF				IEC1bits.OC4IE = CLEAR;
#define OC4_IRQ_Priority		IPC6bits.OC4IP


/*............. Input Compare .............................................................*/
#define IC1_IRQ_Flag			IFS0bits.IC1IF
#define IC1_IRQ_ON				IEC0bits.IC1IE = SET;
#define IC1_IRQ_OFF				IEC0bits.IC1IE = CLEAR;
#define IC1_IRQ_Priority		IPC0bits.IC1IP

#define IC2_IRQ_Flag			IFS0bits.IC2IF
#define IC2_IRQ_ON				IEC0bits.IC2IE = SET;
#define IC2_IRQ_OFF				IEC0bits.IC2IE = CLEAR;
#define IC2_IRQ_Priority		IPC1bits.IC2IP

#define IC7_IRQ_Flag			IFS1bits.IC7IF
#define IC7_IRQ_ON				IEC2bits.IC7IE = SET;
#define IC7_IRQ_OFF				IEC2bits.IC7IE = CLEAR;
#define IC7_IRQ_Priority		IPC5bits.IC7IP

#define IC8_IRQ_Flag			IFS1bits.IC8IF
#define IC8_IRQ_ON				IEC2bits.IC8IE = SET;
#define IC8_IRQ_OFF				IEC2bits.IC8IE = CLEAR;
#define IC8_IRQ_Priority		IPC5bits.IC8IP


/*............. PWM .......................................................................*/
#define PWM1_EventIRQ_Flag		IFS3bits.PWM1IF
#define PWM1_FaultIRQ_Flag		IFS3bits.FLTA1IF
#define PWM1_FAULTIRQ_ON		IEC3bits.FLTA1IE = SET;
#define PWM1_FAULTIRQ_OFF		IEC3bits.FLTA1IE = CLEAR;
#define PWM1_EVENTIRQ_ON		IEC3bits.PWM1IE = SET;
#define PWM1_EVENTIRQ_OFF		IEC3bits.PWM1IE = CLEAR;
#define PWM1_EventIRQ_Priority	IPC14bits.PWM1IP
#define PWM1_FaultIRQ_Priority	IPC15bits.FLTA1IP

#define PWM2_EventIRQ_Flag		IFS4bits.PWM2IF
#define PWM2_FaultIRQ_Flag		IFS4bits.FLTA2IF
#define PWM2_FAULTIRQ_ON		IEC4bits.FLTA2IE = SET;
#define PWM2_FAULTIRQ_OFF		IEC4bits.FLTA2IE = CLEAR;
#define PWM2_EVENTIRQ_ON		IEC4bits.PWM2IE = SET;
#define PWM2_EVENTIRQ_OFF		IEC4bits.PWM2IE = CLEAR;
#define PWM2_EventIRQ_Priority	IPC18bits.PWM2IP
#define PWM2_FaultIRQ_Priority	IPC18bits.FLTA2IP


/*............. Input Change Notification .................................................*/
#define ICN_IRQ_Flag			IFS1bits.CNIF
#define ICN_IRQ_ON				IEC1bits.CNIE = SET;
#define ICN_IRQ_OFF				IEC1bits.CNIE = CLEAR;
#define ICN_IRQ_Priority		IPC4bits.CNIP


/*............. Comparator ................................................................*/
#define COMP_IRQ_Flag			IFS1bits.CMIF
#define COMP_IRQ_ON				IEC1bits.CMIE = SET;
#define COMP_IRQ_OFF			IEC1bits.CMIE = CLEAR;
#define COMP_IRQ_Priority		IPC4bits.CMIP


/*............. Parallel Master Port ......................................................*/
#define PMP_IRQ_Flag			IFS2bits.PMPIF
#define PMP_IRQ_ON				IEC2bits.PMPIE = SET;
#define PMP_IRQ_OFF				IEC2bits.PMPIE = CLEAR;
#define PMP_IRQ_Priority		IPC11bits.PMPIP


/*............. Real Time Clock/Calendar ..................................................*/
#define RTCC_IRQ_Flag			IFS3bits.RTCIF
#define RTCC_IRQ_ON				IEC3bits.RTCIE = SET;
#define RTCC_IRQ_OFF			IEC3bits.RTCIE = CLEAR;
#define RTCC_IRQ_Priority		IPC15bits.RTCIP


/*............. CRC Generator .............................................................*/
#define CRC_IRQ_Flag			IFS4bits.CRCIF
#define CRC_IRQ_ON				IEC4bits.CRCIE = SET;
#define CRC_IRQ_OFF				IEC4bits.CRCIE = CLEAR;
#define CRC_IRQ_Priority		IPC16bits.CRCIP


/*-----------------------------------------------------------------------------------------*/
void Interrupts_Init(void);


/*-----------------------------------------------------------------------------------------*/
#endif
