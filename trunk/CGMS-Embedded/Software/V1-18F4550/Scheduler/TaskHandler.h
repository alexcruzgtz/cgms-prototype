#include <p18f4550.h>

#ifndef __TASKHANDLER_H
#define __TASKHANDLER_H

#define AMOUNT_OF_TASK	5

extern volatile unsigned int TaskCounter;
extern volatile unsigned int TaskTime[AMOUNT_OF_TASK];
extern void Initialize_TaskHandler(void);
extern void Task_Handler_Function(void);
extern void task1 (void);
extern void task2 (void);

#endif