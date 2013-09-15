#include <p18f4550.h>
#include "LcdHandler.h"
#include "Measurements.h"
#include "stdio.h"
#include "TaskHandler.h"
#include "Eusart.h"
#include "E2PHandler.h"

/*----------------------------------------------------------------*/
/*                    Prototype Functions                         */
/*----------------------------------------------------------------*/
near void Update_LCD(void);
void ShowDataMeas(unsigned int Data, unsigned char Address,unsigned int Destiny);
void ShowDataCfg(unsigned int Data, unsigned char Address);
void ShowText(unsigned char Address,unsigned char Text[]);

/*----------------------------------------------------------------*/
/*                    Variable Definitions                        */
/*----------------------------------------------------------------*/
unsigned char update_LCD;
unsigned char Actual_LCD_page;
unsigned char update_LCD_Values;

/*----------------------------------------------------------------*/
/*                    Funciton Description                        */
/*----------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*/
void Update_LCD(void)
{
	unsigned long Temporal;

	if(update_LCD==1)
	{
		switch (Actual_LCD_page)
		{
		case 1:
			ShowText(0x80,TEXT_GLUCOSE_VALUE);
			ShowText(0xC0,TEXT_GLU_MEAS);
		break;
		
		case 2:
			ShowText(0x80,TEXT_ISIG_VALUE);
			ShowText(0xC0,TEXT_ISIG_MEAS);
		break;

		case 3:
			ShowText(0x80,TEXT_SENSOR_VOL);
			ShowText(0xC0,TEXT_BLANK);
		break;	
		
		case 4:
			ShowText(0x80,TEXT_SOURCE_VOL);
			ShowText(0xC0,TEXT_BLANK);
		break;

		case 5:
			ShowText(0x80,TEXT_CAL_POINT);
			ShowText(0xC0,TEXT_BLANK);
		break;
		
		case 6:
			ShowText(0x80,TEXT_TIME_CFG);
			ShowText(0xC0,TEXT_BLANK);
		break;
	
		case 7:
			ShowText(0x80,TEXT_UART);
			ShowText(0xC0,TEXT_UART_MONITOR);
			update_LCD_Values=0;
		break;
		
		case 8:
			ShowText(0x80,TEXT_UART);
			ShowText(0xC0,TEXT_UART_TRANSFER);
			update_LCD_Values=0;
		break;

		}
	}

	/* Shows measures values */
	if(update_LCD_Values==1)
	{
		switch (Actual_LCD_page)
		{
		case 1:
			ShowDataMeas(GLU, 0xC9, LCD);
		break;
		
		case 2:
			/**	Shows ISIG **/
			ShowDataMeas(ISIG, 0xC4, LCD);

		break;
		
		case 3:
			/** Shows REF, CNT and VSEN **/
			ShowDataMeas(REF, 0xC0, LCD);
			ShowDataMeas(CNT, 0xC6, LCD);
			ShowDataMeas(VSEN, 0xCB, LCD);
		break;

		case 4:
			/** Shows VCC, VGND and GND **/
			ShowDataMeas(VCC,  0xC0, LCD);
			ShowDataMeas(VGND, 0xC6, LCD);
			ShowDataMeas(GND,  0xCC, LCD);
		break;
		
		case 5:
			/** Calibration point algorithm **/
		break;

		case 6: 	
		/* Send Data to UART */
		/*if(RequestTx == 1)
		{
			stdout = _H_USART;
			printf("GO:");
			ShowData(GO, NO_ADDRESS, UART);
			printf("isig:");
			ShowData(PolISIG, NO_ADDRESS, UART);
			printf("ISIG:");
			ShowData(ISIG, NO_ADDRESS, UART);
			printf("VSEN:");
			ShowData(VSEN, NO_ADDRESS, UART);
			printf("CNT:");
			ShowData(CNT, NO_ADDRESS, UART);
			printf("REF:");
			ShowData(REF, NO_ADDRESS, UART);
			RequestTx = 0;
		}*/
		break;

		case 7:
			
		break; 
		}
	}
	update_LCD_Values=0;
	update_LCD=0;	
}

/*-----------------------------------------------------------------------------------------*/
void ShowDataCfg(unsigned int Data, unsigned char Address)
{
	stdout = _H_USER;
	lcd_send_byte((unsigned char*)Address,0);
	printf("%u",Data);
}

/*-----------------------------------------------------------------------------------------*/
void ShowDataMeas(unsigned int Data, unsigned char Address, unsigned int Destiny)
{
	if(Destiny==UART)
	{
		stdout = _H_USART;
	}
	if(Destiny==LCD)
	{
		stdout = _H_USER;
		lcd_send_byte((unsigned char*)Address,0);
	}
	#if (SHOW_ISIG == NANOAMPERE)
	if(Data!=ISIG)
	{		
		printf("%u.",(unsigned int)(Data/1000));
		if((Data%1000)>=100)
		{
			printf("%u  ",(Data%1000));
		}
		else if((Data%1000)>=10)
		{
			printf("0%u ",(Data%1000));
		}
		else
		{
			printf("00%u",(Data%1000));
		}
	}
	else
	{
		if(PolISIG==0)
		{		
			printf("(+)%u",Data);
		}
		else if (PolISIG==1)
		{
			printf("(-)%u",Data);
		}
	}
	#elif (SHOW_ISIG == VOLTS)
	printf("%u.",(unsigned int)(Data/1000));
	if((Data%1000)>=100)
	{
		printf("%u  ",(Data%1000));
	}
	else if((Data%1000)>=10)
	{
		printf("0%u ",(Data%1000));
	}
	else
	{
		printf("00%u",(Data%1000));
	}
	#endif
}	

/*-----------------------------------------------------------------------------------------*/
void ShowText(unsigned char Address,unsigned char Text[])
{
	stdout =_H_USER;
	lcd_send_byte((unsigned char*)Address,0);
	printf(Text);
}	