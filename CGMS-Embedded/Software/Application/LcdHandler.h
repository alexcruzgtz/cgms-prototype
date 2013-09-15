#include <p18f4550.h>

#ifndef __LCDHANDLER_H
#define __LCDHANDLER_H

/*----------------------------------------------------------------*/
/*                    Macro Definitions                           */
/*----------------------------------------------------------------*/
						   		/*0______________F*/
#define TEXT_GLUCOSE_VALUE	     " CONC. GLUCOSA  "
#define TEXT_ISIG_VALUE			 "     ISIG       "
#define	TEXT_SENSOR_VOL			 " REF  CNT  VSEN "
#define	TEXT_SOURCE_VOL		     "VCC   VGND  GND "
#define TEXT_CAL_POINT			 "PUNTO CAL. GLU. "
#define TEXT_TIME_CFG			 "  CONFIG TIME   "
#define TEXT_UART				 "     UART       "

#define TEXT_UART_MONITOR		 "   MONITOREO    "
#define TEXT_UART_TRANSFER		 "  TRANFERENCIA  "
#define TEXT_ISIG_MEAS			 "[nA]            "
#define TEXT_GLU_MEAS			 "[mg/dl]         "	
#define TEXT_MIN_CFG			 "    [  ]min     "
#define TEXT_HR_CFG			     "    [  ]hr      "
#define TEXT_DATE_CFG			 "    [  ]date    "
#define TEXT_MONTH_CFG			 "    [  ]month   "
#define TEXT_YEAR_CFG			 "    [    ]year  "

#define TEXT_BLANK				 "                "

#define UART		0
#define LCD			1
#define NO_ADDRESS 	0

/*----------------------------------------------------------------*/
/*                    Exported Functions                          */
/*----------------------------------------------------------------*/
extern void Update_LCD (void);
extern void ShowDataMeas(unsigned int, unsigned char, unsigned int);
extern void ShowDataCfg(unsigned int, unsigned char);
extern void ShowText(unsigned char Address,unsigned char Text[]);

/*----------------------------------------------------------------*/
/*                    Exported Variables                          */
/*----------------------------------------------------------------*/
extern unsigned char update_LCD;
extern unsigned char Actual_LCD_page;
extern unsigned char update_LCD_Values;

#endif
