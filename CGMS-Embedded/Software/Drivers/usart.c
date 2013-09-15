#include <p18f4550.h>
#include "usart.h"
#include "stdio.h"
#include "Eusart.h"
#include "flex_lcd_c18.h"
#include "LcdHandler.h"
#include "E2PHandler.h"
#include "E2P.h"
#include "I2CHandler.h"

/*-----------------------------------------------------------------------------------------*/
void Initialize_USART( void );
void DataReception(void);

/*-----------------------------------------------------------------------------------------*/
unsigned char DataRx[50];
unsigned char DataRxIndex = 0;
unsigned char RequestTx = 0;
unsigned int  DataTx = 0;
unsigned char DataTxTemp=0;

unsigned int  ISIG_Tx_Addr;
unsigned int  GLU_Tx_Addr;
unsigned int  GLU_cal_Tx_Addr;
unsigned int  VSEN_Tx_Addr;
unsigned int  TIME_Tx_Addr;


/*-----------------------------------------------------------------------------------------*/
void Initialize_USART( void )
{
	unsigned char i;
	OpenUSART(USART_TX_INT_OFF & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT &
	USART_CONT_RX & USART_BRGH_HIGH,25);	//19200,8,n,1
	PIR1bits.RCIF=0; 
	DataRxIndex=0;
	for(i=0;i<=49;i++)
	{
		DataRx[i]=0;	
	}
	
	ISIG_Tx_Addr=((unsigned int) ISIG_ADDR_2);
	ISIG_Tx_Addr=(ISIG_Tx_Addr<<8);
	ISIG_Tx_Addr|=((unsigned int) ISIG_ADDR_1);
	
	GLU_Tx_Addr=((unsigned int) GLU_ADDR_2);
	GLU_Tx_Addr=(GLU_Tx_Addr<<8);
	GLU_Tx_Addr|=((unsigned int) GLU_ADDR_1);
	
	GLU_cal_Tx_Addr=((unsigned int) GLU_cal_ADDR_2);
	GLU_cal_Tx_Addr=(GLU_cal_Tx_Addr<<8);
	GLU_cal_Tx_Addr|=((unsigned int) GLU_cal_ADDR_1);
	
	VSEN_Tx_Addr=((unsigned int) VSEN_ADDR_2);
	VSEN_Tx_Addr=(VSEN_Tx_Addr<<8);
	VSEN_Tx_Addr|=((unsigned int) VSEN_ADDR_1);
	
	TIME_Tx_Addr=((unsigned int) TIME_ADDR_2);
	TIME_Tx_Addr=(TIME_Tx_Addr<<8);
	TIME_Tx_Addr|=((unsigned int) TIME_ADDR_1);
	
}

/*-----------------------------------------------------------------------------------------*/
void DataReception(void)
{
	//unsigned int tempadd;
	//tempadd=0x0000;
	DataRx[DataRxIndex]=RCREG;
	DataRxIndex=DataRxIndex+1;
	
	if(DataRxIndex==49)
	{
		DataRxIndex=0;
	}

	if((DataRx[DataRxIndex-1]==':'))
	{
		if( (DataRx[DataRxIndex-8]=='M')&&
			(DataRx[DataRxIndex-7]=='o')&&
			(DataRx[DataRxIndex-6]=='n')&&
			(DataRx[DataRxIndex-5]=='i')&&
			(DataRx[DataRxIndex-4]=='t')&&
			(DataRx[DataRxIndex-3]=='o')&&
			(DataRx[DataRxIndex-2]=='r') )
		{
			update_LCD=1;
			Actual_LCD_page=6;
			
		}

		else if( (DataRx[DataRxIndex-8]=='L')&&
			 	 (DataRx[DataRxIndex-7]=='e')&&
			 	 (DataRx[DataRxIndex-6]=='c')&&
				 (DataRx[DataRxIndex-5]=='t')&&
				 (DataRx[DataRxIndex-4]=='u')&&
				 (DataRx[DataRxIndex-3]=='r')&&
				 (DataRx[DataRxIndex-2]=='a') )
		{
			update_LCD=1;
			Actual_LCD_page=7;
		}

		else if( (DataRx[DataRxIndex-8]=='R')&&
			 	 (DataRx[DataRxIndex-7]=='e')&&
			 	 (DataRx[DataRxIndex-6]=='q')&&
				 (DataRx[DataRxIndex-5]=='u')&&
				 (DataRx[DataRxIndex-4]=='e')&&
				 (DataRx[DataRxIndex-3]=='s')&&
				 (DataRx[DataRxIndex-2]=='t') )
		{
			update_LCD=1;
			Actual_LCD_page=6;
			RequestTx = 1;
		}

		else if( (DataRx[DataRxIndex-8]=='L')&&
			 	 (DataRx[DataRxIndex-7]=='e')&&
			 	 (DataRx[DataRxIndex-6]=='e')&&
				 (DataRx[DataRxIndex-5]=='r')&&
				 (DataRx[DataRxIndex-4]=='C')&&
				 (DataRx[DataRxIndex-3]=='n')&&
				 (DataRx[DataRxIndex-2]=='t') )
		{
			update_LCD=1;
			Actual_LCD_page=7;
			stdout = _H_USART;
			printf("Cnt:");
			printf("%u      \r",(Actual_ISIG_Addr/2));
		}

		else if( (DataRx[DataRxIndex-8]=='L')&&
			 	 (DataRx[DataRxIndex-7]=='e')&&
			 	 (DataRx[DataRxIndex-6]=='e')&&
				 (DataRx[DataRxIndex-5]=='r')&&
				 (DataRx[DataRxIndex-4]=='D')&&
				 (DataRx[DataRxIndex-3]=='a')&&
				 (DataRx[DataRxIndex-2]=='t') )
		{
			update_LCD=1;
			Actual_LCD_page=7;
			if(ISIG_Tx_Addr<=Actual_ISIG_Addr)
			{
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(ISIG_Tx_Addr>>8)),((unsigned char)ISIG_Tx_Addr),&DataTxTemp,1);
				DataTx=(((unsigned int)DataTxTemp)<<8);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(ISIG_Tx_Addr>>8)),((unsigned char)ISIG_Tx_Addr)+1,&DataTxTemp,1);
				DataTx|=((unsigned int)DataTxTemp);
				stdout = _H_USART;
				printf("Isig:");
				printf("%x      \r",DataTx);
				
				DataTx=0;
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(GLU_Tx_Addr>>8)),((unsigned char)GLU_Tx_Addr),&DataTxTemp,1);
				DataTx=(((unsigned int)DataTxTemp)<<8);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(GLU_Tx_Addr>>8)),((unsigned char)GLU_Tx_Addr),&DataTxTemp,1);
				DataTx|=((unsigned int)DataTxTemp);
				printf("Glu:");
				printf("%x      \r",DataTx);

				DataTx=0;	
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(GLU_cal_Tx_Addr>>8)),((unsigned char)GLU_cal_Tx_Addr),&DataTxTemp,1);
				DataTx=(((unsigned int)DataTxTemp)<<8);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(GLU_cal_Tx_Addr>>8)),((unsigned char)GLU_cal_Tx_Addr)+1,&DataTxTemp,1);
				DataTx|=((unsigned int)DataTxTemp);
				printf("GluC:");
				printf("%x      \r",DataTx);

				DataTx=0;
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(VSEN_Tx_Addr>>8)),((unsigned char)VSEN_Tx_Addr),&DataTxTemp,1);
				DataTx=(unsigned int)(DataTxTemp)<<8;
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(VSEN_Tx_Addr>>8)),((unsigned char)VSEN_Tx_Addr)+1,&DataTxTemp,1);
				DataTx|=((unsigned int)DataTxTemp);				
				printf("Vsen:");
				printf("%x      \r",DataTx);

				DataTx=0;
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(TIME_Tx_Addr>>8)),((unsigned char)TIME_Tx_Addr),&DataTxTemp,1);
				printf("Min:");
				printf("%x      \r",DataTxTemp);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(TIME_Tx_Addr>>8)),((unsigned char)TIME_Tx_Addr)+1,&DataTxTemp,1);
				printf("Hr:");
				printf("%x      \r",DataTxTemp);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(TIME_Tx_Addr>>8)),((unsigned char)TIME_Tx_Addr)+2,&DataTxTemp,1);
				printf("Date:");
				printf("%x      \r",DataTxTemp);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(TIME_Tx_Addr>>8)),((unsigned char)TIME_Tx_Addr)+3,&DataTxTemp,1);
				printf("Month:");
				printf("%x      \r",DataTxTemp);
				HDByteReadI2C(CONTROLBYTE_E2P,((unsigned char)(TIME_Tx_Addr>>8)),((unsigned char)TIME_Tx_Addr)+4,&DataTxTemp,1);
				printf("Year:");
				printf("%x      \r",DataTxTemp);
				DataTxTemp=0;
				ISIG_Tx_Addr+=2;	
				GLU_Tx_Addr+=2;
				GLU_cal_Tx_Addr+=2;
				VSEN_Tx_Addr+=2;
				TIME_Tx_Addr+=5;
			}
		}

		else
		{
		}

		DataRxIndex=0;
	}
}
	