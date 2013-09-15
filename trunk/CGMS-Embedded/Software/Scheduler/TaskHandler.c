#include <p18f4550.h>
#include "stdio.h"
#include "main.h"
#include "Ports.h"
#include "Timer0cfg.h"
#include "interrupciones.h"
#include "CPU.h"
#include "ADC.h"
#include "TaskHandler.h"
#include "flex_lcd_c18.h"
#include "Buttons.h"
#include "LcdHandler.h"
#include "Measurements.h"
#include "eusart.h"
#include "E2PHandler.h"
#include "I2CHandler.h"
#include "RTCHandler.h"

/*-----------------------------------------------------------------------------------------*/
void Task_Handler_Function(void);
void Initialize_TaskHandler(void);

void (*Task[AMOUNT_OF_TASK])(void);

/*-----------------------------------------------------------------------------------------*/
volatile unsigned int TaskTime[AMOUNT_OF_TASK];
volatile unsigned int TaskCounter;

/*-----------------------------------------------------------------------------------------*/
void Initialize_TaskHandler(void)
{
	Task[0]=Btn_Debounce; 	TaskTime[0]=3;
	Task[1]=MakeMeasures; 	TaskTime[1]=570;
	Task[2]=Update_E2P; 	TaskTime[2]=1800;
	Task[3]=Update_LCD; 	TaskTime[3]=50;
	
	TaskCounter=0;
}

/*-----------------------------------------------------------------------------------------*/
void Task_Handler_Function(void)
{
	if(TaskCounter%TaskTime[0]==0)
	{
		Task[0]();
	}
	if(TaskCounter%TaskTime[1]==0)
	{
		Task[1]();
	}
	if(TaskCounter%TaskTime[2]==0)
	{
		Task[2]();
	}
	if(TaskCounter%TaskTime[3]==0)
	{
		Task[3]();
	}
	FlagRunTask=0;
}


