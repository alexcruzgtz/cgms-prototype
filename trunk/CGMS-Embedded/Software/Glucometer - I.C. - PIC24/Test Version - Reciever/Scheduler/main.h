/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef __MAIN_H
#define __MAIN_H


#include "Scheduler/HardwareConfig.h"

#include <p24fxxxx.h>
#include "Drivers/Compiler.h"
#include <GenericTypeDefs.h>

#include <PPS.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
#include "Drivers/SPI_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"
#include "Drivers/SymbolTime.h"
#include "Drivers/TimeDelay.h"

#include "Drivers/Wireless/MiWi_ConfigApp.h"
#include "Drivers/Wireless/MiWi_ConfigMRF89XA.h"
#include "Drivers/Wireless/MiWi_MCHP_API.h"
#include "Drivers/Wireless/MiWi_MCHP_MAC.h"
#include "Drivers/Wireless/MiWi_MRF89XA.h"
#include "Drivers/Wireless/MiWi_NVM.h"
#include "Drivers/Wireless/MiWi_P2P.h"
#include "Drivers/Wireless/MiWi_Security.h"



/*-----------------------------------------------------------------------------------------*/
#define TEST_PROGRAM
//#define FULL_PROGRAM


/*-----------------------------------------------------------------------------------------*/
#endif
