/**
   \version: 1.1

   
   \author Suky
   \web www.micros-designs.com.ar
   \date 16/08/10


///////////////////////////////////////////////////////////////////////////
////                                                                   ////
////                                                                   ////
////        (C) Copyright 2010 www.micros-designs.com.ar               ////
//// Este código puede ser usado, modificado y distribuido libremente  ////
//// sin eliminar esta cabecera y  sin garantía de ningún tipo.        ////
////                                                                   ////
////                                                                   ////
/////////////////////////////////////////////////////////////////////////// 
   
 *- Version Log --------------------------------------------------------------*
 *   Fecha       Autor                Comentarios                             *
 *----------------------------------------------------------------------------*
 * 16/08/10      Suky               Original (Rev 1.0)                        *
 * 20/08/10      Suky               Se incluye CodeVisionAVR                  *
 *----------------------------------------------------------------------------* 
 Se puede seleccionar entre 3 modos de trabajo siempre configurando al LCD
 en modo 4-bits:
 Modo normal con control sobre RW  -> RS | RW | E ... LCD4 | LCD5 | LCD6 | LCD7
 Modo sin control sobre RW -> RS | E ... LCD4 | LCD5 | LCD6 | LCD7
 Modo 3 pines, sin control sobre RW -> E ... SERIAL_DATA | SERIAL_CLK
                                 LCD4-> REGISTRO_DESPLAZAMIENTO_D0
                                 LCD5-> REGISTRO_DESPLAZAMIENTO_D1
                                 LCD6-> REGISTRO_DESPLAZAMIENTO_D2
                                 LCD7-> REGISTRO_DESPLAZAMIENTO_D3
                                 RS-> REGISTRO_DESPLAZAMIENTO_D4

 Además permite la configuración entre: 1 linea 5x7, 1 linea 5x10 o varias lineas 5x7.
 Y entre LCD de 2 lineas o 4 lineas, configurando las direcciones de las lineas.-  
 */

/*-----------------------------------------------------------------------------------------*/
#ifndef __LCD_HANDLER_H_
#define __LCD_HANDLER_H_


/*-----------------------------------------------------------------------------------------*/
#include <p33Fxxxx.h
#include <GenericTypeDefs.h>
#include <libpic30.h>
#include "Drivers/Oscillator.h"
#include "Scheduler/HardwareConfig.h"


/*-----------------------------------------------------------------------------------------*/

/* **  DEFINICION PARA INICIALIZACIÖN DEL LCD ** */
#define __LCD_Type 				2 			// 0=5x7, 1=5x10, 2=varias lineas

/* ** DEFINICION PARA TRABAJAR CON LCD DE 2 LINEAS o 4 LINEAS** */
//#define LCD_4LINES

/* ** DEFINICIONES DE DIRECCIONAMIENTO DE LINEAS EN LCD ** */
#define LCD_LINE_1_ADDRESS 		0x80
#define LCD_LINE_2_ADDRESS 		0xC0
#if defined(LCD_4LINES)
	#define LCD_LINE_3_ADDRESS 	0x14
	#define LCD_LINE_4_ADDRESS 	0x54
#endif

/* ** Para no utilizar el PIN RW comentar la siguiente definición ** */
//#define LCD_USE_RW 
/* ** El siguiente modo no utiliza el PIN RW** */
//#define LCD_USE_3PINES		// Se utiliza registro de desplazamiento para DATA[0..3] y RS.
#if defined(LCD_USE_3PINES) && defined(LCD_USE_RW)
	#undef LCD_USE_RW
#endif


/*-----------------------------------------------------------------------------------------*/
#define	__delay_1Cycle()	Nop()
#define __delay_1us()		__delay_us(1)
#define __delay_100us()		__delay_us(100)
#define __delay_2ms() 		__delay_ms(2)
  
#define __INPUT    	1
#define __OUTPUT   	0

#define __COMMAND			0
#define __DATA			1

#ifndef LCD_USE_3PINES
	/* ** Pines tolerables a 5V para usar RW ** */
	#define LCD_DATA_PIN_7 			LCD_DB7_Lat
	#define LCD_DATA_PIN_6 			LCD_DB6_Lat
	#define LCD_DATA_PIN_5 			LCD_DB5_Lat
	#define LCD_DATA_PIN_4 			LCD_DB4_Lat
		
	#define LCD_READ_PIN_7			LCD_DB7
	#define LCD_READ_PIN_6			LCD_DB6
	#define LCD_READ_PIN_5			LCD_DB5
	#define LCD_READ_PIN_4			LCD_DB4
				
	#define LCD_TRIS_DATA_PIN_7     LCD_DB7_Tris
	#define LCD_TRIS_DATA_PIN_6     LCD_DB6_Tris
	#define LCD_TRIS_DATA_PIN_5     LCD_DB5_Tris
	#define LCD_TRIS_DATA_PIN_4     LCD_DB4_Tris
		
	#define LCD_E_PIN	LCD_E_Lat 
	#define LCD_RS_PIN	LCD_RS_Lat 
	#ifdef LCD_USE_RW
		#define LCD_RW_PIN	LCD_RW_Lat 
	#endif
		
	#define LCD_TRIS_E	LCD_E_Tris
	#define LCD_TRIS_RS	LCD_RS_Tris  
	#ifdef LCD_USE_RW 
		#define LCD_TRIS_RW	LCD_RW_Tris 
	#endif 
#else
	/*#define LCD_DATA_PIN  	LATCbits.LATC6
	#define LCD_CLOCK_PIN 	LATCbits.LATC7
	#define LCD_E_PIN	  		LATBbits.LATB0

	#define LCD_TRIS_DATA	TRISCbits.TRISC6
	#define LCD_TRIS_CLOCK	TRISCbits.TRISC7
	#define LCD_TRIS_E		TRISBbits.TRISB0*/
#endif


/*-----------------------------------------------------------------------------------------*/    
void vLCD_Init( void );
UINT8 ui8BusyLCD( void );
void vLCD_Write( UINT8 Data, UINT8 Type );
void vLCD_Putc( UINT8 Data );
void vLCD_Gotoxy( UINT8 x, UINT8 y );
void vLCD_Puts( UINT8 *buffer );



/*-----------------------------------------------------------------------------------------*/    
#endif
