/**********************************************************************************************/
/** \file 		Buttons.c
*	\version 	1.0
*   \author 	Carlos D�az  
*   \mail 		cedg88@gmail.com
*   \date 		31/Enero/2012
* 	\brief 		Este archivo pertenece a la capa de aplicaci�n y se encarga de manejar 
* 				las tareas correspondientes a los botones.
*/
/**********************************************************************************************/

#include <p18f4550.h>
#include "Buttons.h"
#include "LcdHandler.h"
#include "measurements.h"

/*----------------------------------------------------------------*/
/*                    Prototipo de funciones                      */
/*----------------------------------------------------------------*/
void Btn_Debounce (void);
void CheckUpButton(void);
void CheckDownButton(void);
void CheckEnterButton(void);

/*----------------------------------------------------------------*/
/*                    Definicion de variables                     */
/*----------------------------------------------------------------*/
/**********************************************************************************************/
/** \var 	unsigned char ActualButtonState;
* 	\brief 	Indica el estado actual en el que se encuentran los botones.
* 
* 	Para obtener el valor actual de los botones debe de hacer referencia a los botones que se
*	encuentren presionados. Los botones se encuentran especificados en el diagrama esquematico 
*	del dispositivo.
*/
/**********************************************************************************************/
unsigned char ActualButtonState;		//Indica el estado actual en el qeu se encuentran los botones
unsigned char LastButtonState;			//Indica el valor de un estado previo de los botones.
unsigned char DebounceCntr;				//Esta variable lleva la cuenta de la cantidad de tiempo que ha estado presionado un boton
unsigned char ButtonState;				//Indica si el boton esta presionado(PRESSED) o si fue liberado(RELEASE)

unsigned char ActualTimeVar;
unsigned char GluCal_Flag;
unsigned char TimeCal_Flag;

/*----------------------------------------------------------------*/
/*                    Function Description                        */
/*----------------------------------------------------------------*/

void Initialize_Buttons(void)
{
	ButtonState=RELEASE;
	ActualTimeVar=1;
	GluCal_Flag=0;
	TimeCal_Flag=0;
}
/********************************************************************/
/** \fn 		void Btn_Debounce (void)
* 	\brief 		Esta funcion se encarga de manejar el debounce de los 
*				botones con el objetivo de evitar la mala presion de 
*				algun boton.
* 	\param 		Sin parametros
* 	\return 	No devuelve ningun valor							*/
/********************************************************************/
void Btn_Debounce (void)
{
	ActualButtonState=(PORTC&0x07);
	ActualButtonState=ActualButtonState|(PORTA&0x10);

	if((ActualButtonState==LastButtonState))
	{
		if(DebounceCntr<=20)
		{
			DebounceCntr++;	
		}	
		if(ActualButtonState!=0)
		{	
			if((DebounceCntr>=20)&&(ButtonState==RELEASE))
			{
				ButtonState=PRESS;

				/***** Up-Right Button *****/
				if(ActualButtonState==1)
				{
					CheckUpButton();
				}

				/***** Down-Left Button *****/
				else if(ActualButtonState==4)
				{
					CheckDownButton();
				}

				/***** "Enter" Button *****/
				else if(ActualButtonState==2)
				{
					CheckEnterButton();
				}	

				/***** BackLight Button *****/
				else if(ActualButtonState==8)
				{	
					if(PORTDbits.RD7==0)
					{
						PORTDbits.RD7=1;
					}
					else
					{
						PORTDbits.RD7=0;
					}
				}		
			}
		}
		else
		{
			if(DebounceCntr>=20)
			{
				ButtonState=RELEASE;
			}
		}			
	}
	else
	{
		DebounceCntr=0x00;
	}	
	LastButtonState=ActualButtonState;
}

/*-----------------------------------------------------------------------------------------*/
void CheckUpButton(void)
{
	if(GluCal_Flag==1)
	{
		if(GLU_cal<360)
		{
			GLU_cal++;
		}
		ShowDataCfg(GLU_cal,0xC7);
	}
	else if (TimeCal_Flag==1)
	{
		switch(ActualTimeVar)
		{
		case 1:
			if(TIME_min<59)
			{
				TIME_min++;
			}
			else if(TIME_min==59)
			{
				TIME_min=0;
			}
			ShowDataCfg(TIME_min,0xC5);	
		break;

		case 2:
			if(TIME_hr<23)
			{
				TIME_hr++;
			}
			else if(TIME_hr==23)
			{
				TIME_hr=0;
			}			
			ShowText(0xC0,TEXT_HR_CFG);					
			ShowDataCfg(TIME_hr,0xC5);
		break;
							
		case 3:
			if(TIME_year<2018)
			{
				TIME_year++;
			}
			else
			{
				TIME_year=2013;
			}
			ShowText(0xC0,TEXT_YEAR_CFG);
			ShowDataCfg(TIME_year,0xC5);
		break;
							
		case 4:
			if(TIME_month<12)
			{
				TIME_month++;
			}
			else if(TIME_month==12)
			{
				TIME_month=1;
			}
			ShowText(0xC0,TEXT_MONTH_CFG);
			ShowDataCfg(TIME_month,0xC5);	
		break;
							
		case 5:
			if((TIME_date==28)&&(TIME_month==2))
			{
				TIME_date=1;
			}
			else if(TIME_date<30)
			{
				TIME_date++;
			}
			else if(TIME_date==30)
			{
				if((TIME_month==1)&&
			   (TIME_month==3)&&
			   (TIME_month==5)&&
			   (TIME_month==7)&&
			   (TIME_month==8)&&
			   (TIME_month==10)&&
			   (TIME_month==12) )
				{
					TIME_date++;
				}
				else
				{
					TIME_date=1;
				}
			}
			else if(TIME_date==31)
			{
				TIME_date=1;
			}
			ShowText(0xC0,TEXT_DATE_CFG);
			ShowDataCfg(TIME_date,0xC5);
		break;
		}
	}
	else if (Actual_LCD_page>1)
	{
		Actual_LCD_page--;		//Page increment
		update_LCD=1;
		update_LCD_Values=1;
	}
}

/*-----------------------------------------------------------------------------------------*/
void CheckDownButton(void)
{
	if(GluCal_Flag==1)
	{
		if(GLU_cal>10)
		{
			GLU_cal--;
		}
		ShowDataCfg(GLU_cal,0xC7);
	}
	else if (TimeCal_Flag==1)
	{
		switch(ActualTimeVar)
		{
		case 1:
			if(TIME_min>0)
			{
				TIME_min--;
			}
			else if(TIME_min==0)
			{
				TIME_min=59;
			}
			ShowText(0xC0,TEXT_MIN_CFG);
			ShowDataCfg(TIME_min,0xC5);	
		break;

		case 2:
			if(TIME_hr>0)
			{
				TIME_hr--;
			}
			else if(TIME_hr==0)
			{
				TIME_hr=23;
			}			
			ShowText(0xC0,TEXT_HR_CFG);					
			ShowDataCfg(TIME_hr,0xC5);
		break;
							
		case 3:
			if(TIME_year>2013)
			{
				TIME_year--;
			}
			else
			{
				TIME_year=2018;
			}
			ShowText(0xC0,TEXT_YEAR_CFG);
			ShowDataCfg(TIME_year,0xC5);
		break;
							
		case 4:
			if(TIME_month>1)
			{
				TIME_month--;
			}
			else if(TIME_month==1)
			{
				TIME_month=12;
			}
			ShowText(0xC0,TEXT_MONTH_CFG);
			ShowDataCfg(TIME_month,0xC5);	
		break;
							
		case 5:
			if((TIME_date==1)&&(TIME_month==2))
			{
				TIME_date=28;
			}
			else if(TIME_date>1)
			{
				TIME_date--;
			}
			else if(TIME_date==1)
			{
				if((TIME_month==1)&&
			   (TIME_month==3)&&
			   (TIME_month==5)&&
			   (TIME_month==7)&&
			   (TIME_month==8)&&
			   (TIME_month==10)&&
			   (TIME_month==12) )
				{
					TIME_date=31;
				}
				else
				{
					TIME_date=30;
				}
			}
			ShowText(0xC0,TEXT_DATE_CFG);
			ShowDataCfg(TIME_date,0xC5);
		break;
		}
	}
	else if (Actual_LCD_page<8)
	{
		Actual_LCD_page++;		//Page increment
		update_LCD=1;
		update_LCD_Values=1;
	}
}

/*-----------------------------------------------------------------------------------------*/
void CheckEnterButton(void)
{
	if ((Actual_LCD_page==5)&&(GluCal_Flag==0))
	{
		GluCal_Flag=1;
		ShowText(0xC0,TEXT_GLU_MEAS);
		ShowDataCfg(GLU_cal,0xC7);
	}
	else if((Actual_LCD_page==6)&&(TimeCal_Flag==0))
	{
		TimeCal_Flag=1;
		ShowText(0xC0,TEXT_MIN_CFG);
		ShowDataCfg(TIME_min,0xC5);
	}
	else if((Actual_LCD_page==5)&&(GluCal_Flag==1))
	{
		GluCal_Flag=0;
		Actual_LCD_page=1;		//Page increment
		update_LCD=1;
		update_LCD_Values=1;
	}
	else if((Actual_LCD_page==6)&&(TimeCal_Flag==1))
	{
		if(ActualTimeVar<5)
		{
			ActualTimeVar++;
			switch(ActualTimeVar)
			{
				case 1:
					ShowText(0xC0,TEXT_MIN_CFG);
					ShowDataCfg(TIME_min,0xC5);	
				break;

				case 2:
					ShowText(0xC0,TEXT_HR_CFG);					
					ShowDataCfg(TIME_hr,0xC5);
				break;
							
				case 3:
					ShowText(0xC0,TEXT_YEAR_CFG);
					ShowDataCfg(TIME_year,0xC5);
				break;
							
				case 4:
					ShowText(0xC0,TEXT_MONTH_CFG);
					ShowDataCfg(TIME_month,0xC5);	
				break;
							
				case 5:
					ShowText(0xC0,TEXT_DATE_CFG);
					ShowDataCfg(TIME_date,0xC5);
				break;
			}
		}
		else if(ActualTimeVar==5)
		{
			ActualTimeVar=0;
			TimeCal_Flag=0;
			Actual_LCD_page=1;		//Page increment
			update_LCD=1;
			update_LCD_Values=1;
		}
	}
	else
	{				
		update_LCD=0;
	}
}