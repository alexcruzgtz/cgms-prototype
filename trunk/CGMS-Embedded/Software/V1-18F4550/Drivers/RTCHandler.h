

#ifndef __RTCHANDLER_H
#define __RTCHANDLER_H

/*-----------------------------------------------------------------------------------------*/
#define MIN_ADDR	0x01
#define HR_ADDR		0x02
#define DATE_ADDR	0x04
#define MONTH_ADDR	0x05
#define YEAR_ADDR	0x06

#define CONTROLBYTE_RTC	0b11010000

/*-----------------------------------------------------------------------------------------*/
extern void Initialize_RTC(void);
extern void SaveTime(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void ReadTime(void);

#endif