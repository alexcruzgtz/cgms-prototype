

/*-----------------------------------------------------------------------------------------*/
/*unsigned int Actual_ISIG_Addr;
unsigned int Actual_GLU_Addr;
unsigned int Actual_GLU_cal_Addr;
unsigned int Actual_VSEN_Addr;
unsigned int Actual_TIME_Addr;

unsigned char MeasuresDone=0;
unsigned char FlagMeasuresComplete=0;

unsigned int ISIG_E2P;

EEPROM_STATUS EEPROM_Status;
*/
/*-----------------------------------------------------------------------------------------*/
/* Funciones de la máquina de estados */
/*void SM_EEPROM_STORAGE ( void );
void Update_E2P ( void );*/
//unsigned char ValidateE2PAddr ( void );

/*-----------------------------------------------------------------------------------------*/
/*
void Initialize_EEPROM(void)
{
		HDByteWriteI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1,ISIG_ADDR_2);
		HDByteWriteI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1+1,ISIG_ADDR_1);

		HDByteWriteI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1,GLU_ADDR_2);
		HDByteWriteI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1+1,GLU_ADDR_1);

		HDByteWriteI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1,GLU_cal_ADDR_2);
		HDByteWriteI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1+1,GLU_cal_ADDR_1);

		HDByteWriteI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1,VSEN_ADDR_2);
		HDByteWriteI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1+1,VSEN_ADDR_1);

		HDByteWriteI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1,TIME_ADDR_2);
		HDByteWriteI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1+1,TIME_ADDR_1);
		
		
}
*/
/*-----------------------------------------------------------------------------------------*/
/*void Update_E2P(void)
{
	if(FlagMeasuresComplete==1)
	{
		SM_EEPROM_STORAGE();
	}
}		
*/
/*-----------------------------------------------------------------------------------------*/
/*void SM_EEPROM_STORAGE ( void )
{
	unsigned char temp;
	switch (EEPROM_Status) 
	{
		case	E_READ_ISIG_ADDR:
					ISIG_E2P = (((( unsigned int ) PolISIG )<< 12)  | ISIG);
					HDByteReadI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1,&temp,1);
					Actual_ISIG_Addr=(((unsigned int)temp)<<8);
					HDByteReadI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1+1,&temp,1);
					Actual_ISIG_Addr|=((unsigned int)temp);
					if(Actual_ISIG_Addr==0xFFFF)
					{
						Initialize_EEPROM();
						return EEPROM_VALID;
					}
					EEPROM_Status = E_READ_GLU_ADDR;
				break;
		
		case 	E_READ_GLU_ADDR:
					HDByteReadI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1,&temp,1);
					Actual_GLU_Addr=(((unsigned int)temp)<<8);				
					HDByteReadI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1+1,&temp,1);
					Actual_GLU_Addr|=((unsigned int)temp);
					EEPROM_Status = E_READ_GLU_cal_ADDR;
				break;

		case 	E_READ_GLU_cal_ADDR:
					HDByteReadI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1,&temp,1);
					Actual_GLU_cal_Addr=(((unsigned int)temp)<<8);
					HDByteReadI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1+1,&temp,1);					
					Actual_GLU_cal_Addr|=((unsigned int)temp);
					EEPROM_Status = E_READ_VSEN_ADDR;
				break;

		case 	E_READ_VSEN_ADDR:
					HDByteReadI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1,&temp,1);
					Actual_VSEN_Addr=(((unsigned int)temp)<<8);
					HDByteReadI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1+1,&temp,1);
					Actual_VSEN_Addr=((unsigned int)temp);
					EEPROM_Status = E_READ_TIME_ADDR;
				break;

		case 	E_READ_TIME_ADDR:
					HDByteReadI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1,&temp,1);
					Actual_TIME_Addr=(((unsigned int)temp)<<8);
					HDByteReadI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1+1,&temp,1);
					Actual_TIME_Addr=((unsigned int)temp);
					EEPROM_Status = E_VALIDATE_ADDR;
				break;
	
		case	E_VALIDATE_ADDR:
					//if( ValidateE2PAddr() == EEPROM_VALID )
					//{
						if(Actual_ISIG_Addr < ADDR_OFFSET-1)
						{
							EEPROM_Status = E_UPDATE_ISIG;
						}
						else
						{
							EEPROM_Status = E_EEPROM_FULL;
						}	
					//}
					//else
					//{
					//	EEPROM_Status = E_EEPROM_CORRUPTED;
					//}	
				break;

		case	E_UPDATE_ISIG:
					Actual_ISIG_Addr +=2;
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_ISIG_Addr>>8)),((unsigned char)Actual_ISIG_Addr),((unsigned char)(ISIG>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_ISIG_Addr>>8)),((unsigned char)Actual_ISIG_Addr)+1,((unsigned char)ISIG));
					EEPROM_Status = E_UPDATE_GLU;
				break;

		case	E_UPDATE_GLU:
					Actual_GLU_Addr +=2;
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_GLU_Addr>>8)),((unsigned char)Actual_GLU_Addr),((unsigned char)(GLU>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_GLU_Addr>>8)),((unsigned char)Actual_GLU_Addr)+1,((unsigned char)GLU));
					EEPROM_Status = E_UPDATE_GLU_cal;
				break;

		case	E_UPDATE_GLU_cal:
					Actual_GLU_cal_Addr +=2;
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_GLU_cal_Addr>>8)),((unsigned char)Actual_GLU_cal_Addr),((unsigned char)(GLU_cal>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_GLU_cal_Addr>>8)),((unsigned char)Actual_GLU_cal_Addr)+1,((unsigned char)GLU_cal));
					EEPROM_Status = E_UPDATE_VSEN;
				break;

		case	E_UPDATE_VSEN:
					Actual_VSEN_Addr +=2;
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_VSEN_Addr>>8)),((unsigned char)Actual_VSEN_Addr),((unsigned char)(VSEN>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_VSEN_Addr>>8)),((unsigned char)Actual_VSEN_Addr)+1,((unsigned char)VSEN));
					EEPROM_Status = E_UPDATE_TIME;
				break;

		case	E_UPDATE_TIME:
					Actual_TIME_Addr +=5;
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_TIME_Addr>>8)),((unsigned char)Actual_TIME_Addr),TIME_min);
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_TIME_Addr>>8)),((unsigned char)Actual_TIME_Addr)+1,TIME_hr);
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_TIME_Addr>>8)),((unsigned char)Actual_TIME_Addr)+2,TIME_date);
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_TIME_Addr>>8)),((unsigned char)Actual_TIME_Addr)+3,TIME_month);
					HDByteWriteI2C(CONTROLBYTE_E2P,((unsigned char)(Actual_TIME_Addr>>8)),((unsigned char)Actual_TIME_Addr)+4,TIME_year);
					EEPROM_Status = E_UPDATE_ISIG_ADDR;
				break;

		case	E_UPDATE_ISIG_ADDR:
					HDByteWriteI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1,((unsigned char)(Actual_ISIG_Addr>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,ISIG_ADDR_2,ISIG_ADDR_1+1,((unsigned char)Actual_ISIG_Addr));
					EEPROM_Status = E_UPDATE_GLU_ADDR;
				break;

		case	E_UPDATE_GLU_ADDR:
					HDByteWriteI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1,((unsigned char)(Actual_GLU_Addr>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,GLU_ADDR_2,GLU_ADDR_1+1,((unsigned char)Actual_GLU_Addr));
					EEPROM_Status = E_UPDATE_GLU_cal_ADDR;
				break;

		case	E_UPDATE_GLU_cal_ADDR:
					HDByteWriteI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1,((unsigned char)(Actual_GLU_cal_Addr>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,GLU_cal_ADDR_2,GLU_cal_ADDR_1+1,((unsigned char)Actual_GLU_cal_Addr)); 
					EEPROM_Status = E_UPDATE_VSEN_ADDR;
				break;

		case	E_UPDATE_VSEN_ADDR:
					HDByteWriteI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1,((unsigned char)(Actual_VSEN_Addr>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,VSEN_ADDR_2,VSEN_ADDR_1+1,((unsigned char)Actual_VSEN_Addr));
					EEPROM_Status = E_UPDATE_TIME_ADDR;
				break;

		case	E_UPDATE_TIME_ADDR:
					HDByteWriteI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1,((unsigned char)(Actual_TIME_Addr>>8)));
					HDByteWriteI2C(CONTROLBYTE_E2P,TIME_ADDR_2,TIME_ADDR_1+1,((unsigned char)Actual_TIME_Addr));
					EEPROM_Status = E_EEPROM_OK;
				break;

		case	E_EEPROM_OK:
					//MeasuresDone=0;
					FlagMeasuresComplete=0;
					EEPROM_Status = E_READ_ISIG_ADDR;
				break;
		
		case	E_EEPROM_CORRUPTED:
				
				break;
		case	E_EEPROM_FULL:
				
				break;
		case	E_EEPROM_RESTORE:
				
				break;
	}
}	
*/
/*-----------------------------------------------------------------------------------------*/
/*
unsigned char ValidateE2PAddress ( void )
{
	if( Actual_ISIG_Addr == ( ~Actual_GO_Addr ) )
	{
		return EEPROM_VALID;
	}	
	else
	{
		return EEPROM_INVALID;
	}
}
*/
