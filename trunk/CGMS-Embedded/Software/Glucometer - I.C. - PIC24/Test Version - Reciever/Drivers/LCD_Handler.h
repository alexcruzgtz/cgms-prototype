/******************************************************************************* 
   \file FLEX_LCD_C18.h
   \version: 1.0
   
   \author Suky. 
   \web www.infopic.comlu.com
   \mail inf.pic.suky@live.com.ar
   \date 03/04/10
*/

/*;--- Modos de Entrada
; Incrementa Direccion, Display fijo	0x06
; Decrementa Direccion, Display fijo	0x04
; Incrementa Direccion, Cursor fijo		0x07
; Decrementa Direccion, Cursor fijo		0x05
;--- Corriemiento Cursor
; Cursor a la Izquierda					0x10
; Cursor a la Derecha					0x14
; Display a la Izquierda				0x18
; Display a la Derecha					0x1C
;--- Fijar Sistema
; Bus 8 bits, 1 línea, 5x7				0x30
; Bus 8 bits, 1 linea, 5x10				0x34
; Bus 8 bits, 2 líneas, 5x7				0x38
; Bus 4 bits, 1 línea, 5x7				0x20	
; Bus 4 bits, 1 linea, 5x10				0x24
; Bus 4 bits, 2 líneas, 5x7 			0x28*/


/*-----------------------------------------------------------------------------------------*/
#ifndef __LCD_HANDLER_H
#define __LCD_HANDLER_H

/*-----------------------------------------------------------------------------------------*/
#include "Drivers/GenericTypeDefs.h"
#include "Drivers/Compiler.h"
#include "Drivers/TimeDelay.h"
#include "Scheduler/HardwareConfig.h"
#include <stdio.h>

/*-----------------------------------------------------------------------------------------*/
//extern unsigned char Text_Line1;
//extern unsigned char Text_Line2;

/*-----------------------------------------------------------------------------------------*/
/* ** Para no utilizar el PIN RW comentar la siguiente definición ** */
//#define USE_RW 

#define DATA_PIN_7 			LCD_Pin7_Lat
#define DATA_PIN_6 			LCD_Pin6_Lat
#define DATA_PIN_5 			LCD_Pin5_Lat
#define DATA_PIN_4 			LCD_Pin4_Lat
	
#define READ_PIN_7			LCD_Pin7
#define READ_PIN_6			LCD_Pin6
#define READ_PIN_5			LCD_Pin5
#define READ_PIN_4			LCD_Pin4
	
#define TRIS_DATA_PIN_7     LCD_Pin7_Tris
#define TRIS_DATA_PIN_6     LCD_Pin6_Tris
#define TRIS_DATA_PIN_5     LCD_Pin5_Tris
#define TRIS_DATA_PIN_4     LCD_Pin4_Tris
	
	
#define E_PIN				LCD_PinE_Lat
#define RS_PIN				LCD_PinRS_Lat
#ifdef USE_RW
	#define RW_PIN			LCD_PinRW_Lat 
#endif
	
#define TRIS_E				LCD_PinE_Tris
#define TRIS_RS				LCD_PinRS_Tris  
#ifdef USE_RW 
	#define TRIS_RW			LCD_PinRW_Tris 
#endif 

#define LCD_TYPE 2 // 0=5x7, 1=5x10, 2=2 lines
#define SECOND_LINE 0x40 // LCD RAM address for the 2nd line

/*-----------------------------------------------------------------------------------------*/
void LCD_Init( void );
void LCD_gotoxy( UINT8 x, UINT8 y );
//void LCD_putc( UINT8 c );
void LCD_send_nibble( UINT8 nibble );
void LCD_send_byte ( UINT8 address, UINT8 n );

/*-----------------------------------------------------------------------------------------*/
#endif
