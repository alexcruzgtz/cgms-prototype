#include <p18f4550.h>

#ifndef __MEASUREMENTS_H
#define __MEASUREMENTS_H
/*----------------------------------------------------------------*/
/*                    Macro Definitions                           */
/*----------------------------------------------------------------*/
#define FACTOR_VOLTAJE		48828	
#define MEAS_ISIG			0
#define MEAS_REF			1
#define MEAS_CNT			2
#define MEAS_VCC			3
#define MEAS_VGND			4
#define MEAS_GND			5
#define CALCULATE_AVERAGES 	6

#define AMOUNT_OF_MEASURES 	15
#define AVERAGE_INDEX		AMOUNT_OF_MEASURES-1

#define MAX_VALUE			0
#define MIN_VALUE			1
#define AVERAGE_VALUE		2
#define MOST_REPEAT_VALUE	3

#define ALGORITHM			AVERAGE_VALUE

#define VOLTS				0
#define NANOAMPERE			1

#define SHOW_ISIG			NANOAMPERE

/*----------------------------------------------------------------*/
/*                    Exported Functions                          */
/*----------------------------------------------------------------*/
extern void MakeMeasures (void);
extern void	Initialize_Measurements(void);

/*----------------------------------------------------------------*/
/*                    Exported Variables                          */
/*----------------------------------------------------------------*/
extern unsigned char PolVCTR;
extern unsigned char PolISIG;
extern unsigned char SignalMeasure;
extern unsigned char IndexForMeasures;

extern unsigned int VCC,VGND,GND;
extern unsigned int REF,CNT,ISIG;
extern unsigned int GLU,GLU_cal,VSEN;

extern unsigned char TIME_min;
extern unsigned char TIME_hr;
extern unsigned char TIME_date;
extern unsigned char TIME_month;
extern unsigned char TIME_year;
#endif