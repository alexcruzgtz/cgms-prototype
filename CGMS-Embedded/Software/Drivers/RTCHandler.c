#include <p18f4550.h>
#include "RTCHandler.h"
#include "I2CHandler.h"
#include "Measurements.h"

/*-----------------------------------------------------------------------------------------*/
void Initialize_RTC(void);
void SaveTime(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
void ReadTime(void);


/*-----------------------------------------------------------------------------------------*/
void Initialize_RTC(void)
{
	unsigned char i;
	unsigned char cfg[8]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	
	
	LDByteReadI2C(CONTROLBYTE_RTC, 0x00, &i);
	if ((i&0b10000000)!=0)	
	{
		LDPageWriteI2C(CONTROLBYTE_RTC, 0x00, &cfg, 8);
	}
	TIME_year=2013;
	TIME_date=1;
	TIME_month=1;
	TIME_min=0;
	TIME_hr=0;
	SaveTime(TIME_min,TIME_hr,TIME_date,TIME_month,TIME_year);
}


/*-----------------------------------------------------------------------------------------*/
void SaveTime(unsigned char min, unsigned char hr, unsigned char date, unsigned char month, unsigned char year)
{
	unsigned char temp1=0;
	unsigned char temp2=0;
	
	temp1=min/10;
	temp2=min%10;
	min=((temp1<<4)&0x70);
	min|=(temp2&0x0F);
	
	temp1=hr/10;
	temp2=hr%10;
	hr=((temp1<<4)&0x70);
	hr|=(temp2&0x0F);

	temp1=date/10;
	temp2=date%10;
	date=((temp1<<4)&0x30);
	date|=(temp2&0x0F);

	temp1=month/10;
	temp2=month%10;
	month=((temp1<<4)&0x10);
	month|=(temp2&0x0F);
	
	temp1=year/10;
	temp2=year%10;
	year=((temp1<<4)&0xF0);
	year|=(temp2&0x0F);

	LDByteWriteI2C(CONTROLBYTE_RTC,MIN_ADDR,min);
	LDByteWriteI2C(CONTROLBYTE_RTC,HR_ADDR,hr);
	LDByteWriteI2C(CONTROLBYTE_RTC,DATE_ADDR,date);
	LDByteWriteI2C(CONTROLBYTE_RTC,MONTH_ADDR,month);
	LDByteWriteI2C(CONTROLBYTE_RTC,YEAR_ADDR,year);	
}

/*-----------------------------------------------------------------------------------------*/
void ReadTime(void)
{
	unsigned char temp=0;

	LDByteReadI2C(CONTROLBYTE_RTC, MIN_ADDR, &TIME_min);
	LDByteReadI2C(CONTROLBYTE_RTC, HR_ADDR, &TIME_hr);
	LDByteReadI2C(CONTROLBYTE_RTC, DATE_ADDR, &TIME_date);
	LDByteReadI2C(CONTROLBYTE_RTC, MONTH_ADDR, &TIME_month);
	LDByteReadI2C(CONTROLBYTE_RTC, YEAR_ADDR, &TIME_year);
	
	temp=(TIME_min>>4)&0x07;
	temp=temp*10;
	TIME_min=temp+(TIME_min&0x0F);
	
	temp=(TIME_hr>>4)&0x03;
	temp=temp*10;
	TIME_hr=temp+(TIME_hr&0x0F);

	temp=(TIME_date>>4)&0x03;
	temp=temp*10;
	TIME_date=temp+(TIME_date&0x0F);

	temp=(TIME_month>>4)&0x01;
	if (temp==0)
	{
		TIME_month=TIME_month&0x0F;
	}
	else
	{
		temp=temp*10;
		TIME_month=temp+(TIME_month&0x0F);
	}
	
	temp=(TIME_year>>4)&0x0F;
	temp=temp*10;
	TIME_year=temp+(TIME_year&0x0F);
}

