
/*void MeasureChannel(unsigned char Channel,unsigned int* SignalBuffer);
void MakeMeasures (void);
void ConvertToVolts(void);

#if(ALGORITHM == AVERAGE_VALUE)
	void CalculateAverages(void);

#elif(ALGORITHM == MOST_REPEAT_VALUE)
	void CalculateMostRepeat(unsigned int* SignalBuffer);

#elif(ALGORITHM == MAX_VALUE)
	void CalculateMax(unsigned int* SignalBuffer);

#elif(ALGORITHM == MIN_VALUE)
	void CalculateMin(unsigned int* SignalBuffer);

#endif
unsigned char SignalMeasure;

unsigned int ISIGvalue[AMOUNT_OF_MEASURES];
unsigned int REFvalue[AMOUNT_OF_MEASURES];
unsigned int CNTvalue[AMOUNT_OF_MEASURES];
unsigned int VCCvalue[AMOUNT_OF_MEASURES]; 
unsigned int VGNDvalue[AMOUNT_OF_MEASURES];
unsigned int GNDvalue[AMOUNT_OF_MEASURES];

unsigned char IndexForMeasures;
unsigned char PolISIG;

unsigned int VCC,VGND,GND;
unsigned int REF,CNT,ISIG;
unsigned int GLU,GLU_cal,VSEN;

unsigned char TIME_min;
unsigned char TIME_hr;
unsigned char TIME_date;
unsigned char TIME_month;
unsigned char TIME_year;

void Initialize_Measurements(void)
{
	SignalMeasure=MEAS_ISIG;
	IndexForMeasures=0;
	PolISIG=0;
	VCC=0;
	VGND=0;
	GND=0;
	REF=0;
	CNT=0;
	ISIG=0;
	GLU=0;
	GLU_cal=90;
	VSEN=0;
	TIME_min=0;
	TIME_hr=0;
	TIME_date=1;
	TIME_month=1;
	TIME_year=2013;
}
*/
/*-----------------------------------------------------------------------------------------*/
/*void MakeMeasures (void)
{
	switch (SignalMeasure)
	{
		case MEAS_ISIG:
			MeasureChannel(0x00,ISIGvalue);
			SignalMeasure=MEAS_REF;
		break;
	
		case MEAS_REF:
			MeasureChannel(0x04,REFvalue);
			SignalMeasure=MEAS_CNT;
		break;
		
		case MEAS_CNT:
			MeasureChannel(0x01,CNTvalue);
			SignalMeasure=MEAS_VCC;
		break;
		
		case MEAS_VCC:
			MeasureChannel(0x06,VCCvalue);
			SignalMeasure=MEAS_VGND;
		break;
		
		case MEAS_VGND:
			MeasureChannel(0x05,VGNDvalue);
			SignalMeasure=MEAS_GND;
		break;
		
		case MEAS_GND:
			MeasureChannel(0x07,GNDvalue);
			SignalMeasure=MEAS_ISIG;
						
			if(IndexForMeasures>=(AMOUNT_OF_MEASURES-2))
			{
				SignalMeasure=CALCULATE_AVERAGES;	
			}	
			else
			{
				IndexForMeasures++;
			}	
		break;
		
		case CALCULATE_AVERAGES:
		#if(ALGORITHM == AVERAGE_VALUE)	
			CalculateAverages();
		#elif(ALGORITHM == MOST_REPEAT_VALUE)
			CalculateMostRepeat(ISIGvalue);
			CalculateMostRepeat(REFvalue);
			CalculateMostRepeat(CNTvalue);
			CalculateMostRepeat(GNDvalue);
			CalculateMostRepeat(VGNDvalue);
			CalculateMostRepeat(VCCvalue);
		#endif
			
			ConvertToVolts();
			IndexForMeasures=0;
			SignalMeasure=MEAS_ISIG;
		break;
		
	}	
	update_LCD_Values=1;
}
*/
/*----------------------------------------------------------------------------------------*/
/*#if(ALGORITHM == AVERAGE_VALUE)
void CalculateAverages(void)
{
	unsigned char IterationIndex;
	unsigned long Temporal;
	
	ISIGvalue[AVERAGE_INDEX]=0;
	REFvalue[AVERAGE_INDEX]=0;
	CNTvalue[AVERAGE_INDEX]=0;
	VCCvalue[AVERAGE_INDEX]=0;
	VGNDvalue[AVERAGE_INDEX]=0;
	GNDvalue[AVERAGE_INDEX]=0;

	for(IterationIndex=0;IterationIndex<AMOUNT_OF_MEASURES-1;IterationIndex++)
	{
		ISIGvalue[AVERAGE_INDEX]+=ISIGvalue[IterationIndex];
		REFvalue[AVERAGE_INDEX]+=REFvalue[IterationIndex];
		CNTvalue[AVERAGE_INDEX]+=CNTvalue[IterationIndex];
		VCCvalue[AVERAGE_INDEX]+=VCCvalue[IterationIndex];
		VGNDvalue[AVERAGE_INDEX]+=VGNDvalue[IterationIndex];
		GNDvalue[AVERAGE_INDEX]+=GNDvalue[IterationIndex];
	}	

	ISIGvalue[AVERAGE_INDEX]=ISIGvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
	REFvalue[AVERAGE_INDEX]=REFvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
	CNTvalue[AVERAGE_INDEX]=CNTvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
	VCCvalue[AVERAGE_INDEX]=VCCvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
	VGNDvalue[AVERAGE_INDEX]=VGNDvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
	GNDvalue[AVERAGE_INDEX]=GNDvalue[AVERAGE_INDEX]/(AVERAGE_INDEX);
}
*/
/*----------------------------------------------------------------------------------------*/
/*#elif (ALGORITHM == MOST_REPEAT_VALUE)
void CalculateMostRepeat(unsigned int* SignalBuffer)
{
	unsigned char i,j,k,l;
	unsigned char pasa;
	unsigned int aux1,aux2;
	unsigned int Cuentas[AMOUNT_OF_MEASURES][2];
	unsigned char Omision[AMOUNT_OF_MEASURES]={100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
	pasa=0;
	k=0;
	for(i=0;i<=AMOUNT_OF_MEASURES-2;i++)
	{
		for(j=0;j<=1;j++)
		{
			Cuentas[i][j]=0;
		}
	}
	for(i=0;i<=AMOUNT_OF_MEASURES-2;i++)
	{
		Cuentas[i][0]=*(SignalBuffer+i);
	}
	for(i=0;i<=AMOUNT_OF_MEASURES-2;i++)
	{
		for(j=i;j<=AMOUNT_OF_MEASURES-2;j++)
		{
			for(l=0;l<=k;l++)
			{
				if(j==Omision[l])
				{
					pasa=1;
				}	
			}	
			
			if(pasa!=1)
			{
				if(*(SignalBuffer+i)==*(SignalBuffer+j))
				{
					Cuentas[i][1]++;
					Omision[k]=j;
					k++;
					
				}	
			}
			pasa=0;
		}	
	}	
	for(i=0; i < AMOUNT_OF_MEASURES-2; i++)
	{                            
    	for(j=0; j < AMOUNT_OF_MEASURES-2; j++)
		{                  
			if(Cuentas[j][1] > Cuentas[j+1][1])
			{              
				aux1=Cuentas[j][1];                 
				Cuentas[j][1]=Cuentas[j+1][1];            
				Cuentas[j+1][1]=aux1;
				aux2=Cuentas[j][0];                 
				Cuentas[j][0]=Cuentas[j+1][0];            
				Cuentas[j+1][0]=aux2;
			} 
		}
	}
	*(SignalBuffer+AMOUNT_OF_MEASURES-1)=Cuentas[AMOUNT_OF_MEASURES-2][0];
}	
#endif
*/
/*----------------------------------------------------------------------------------------*/
/*void ConvertToVolts(void)
{
	unsigned long Temporal;
	Temporal=((unsigned long)REFvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	REF=(Temporal/10000);
	
	Temporal=((unsigned long)CNTvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	CNT=(Temporal/10000);

	Temporal=((unsigned long)VCCvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	VCC=(Temporal/10000);

	Temporal=((unsigned long)VGNDvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	VGND=(Temporal/10000);

	Temporal=((unsigned long)GNDvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	GND=(Temporal/10000);

	if(ISIGvalue[AVERAGE_INDEX]>=VGNDvalue[AVERAGE_INDEX])	
	{	
		PolISIG=0;
		ISIGvalue[AVERAGE_INDEX]=ISIGvalue[AVERAGE_INDEX]-VGNDvalue[AVERAGE_INDEX];
	}
	else
	{
		PolISIG=1;
		ISIGvalue[AVERAGE_INDEX]=511-ISIGvalue[AVERAGE_INDEX];
	}
	if(ISIGvalue[AVERAGE_INDEX]>=20)
	{
		ISIGvalue[AVERAGE_INDEX]+=6;
	}	
	Temporal=((unsigned long)ISIGvalue[AVERAGE_INDEX]*FACTOR_VOLTAJE);
	ISIG=(Temporal/10000);
		
	#if (SHOW_ISIG == NANOAMPERE)
		ISIG=(ISIG/5);
	#endif

	VSEN=CNT-REF;

	GLU=ISIG;	
	
	ReadTime();
	
	if((MeasuresDone<AMOUNT_OF_MEASURES_TO_SAVE)&&(FlagMeasuresComplete==0))
	{
		MeasuresDone++;
		FlagMeasuresComplete=1;
	}
	
}		
*/
/*----------------------------------------------------------------------------------------*/
/*void MeasureChannel(unsigned char Channel,unsigned int* SignalBuffer)
{
	ADC_Select_Channel(Channel);
	ADC_StartConvertion();
	while(ADCON0bits.GO==1){}
	*(SignalBuffer+IndexForMeasures) = ReadADC();
}	
*/
