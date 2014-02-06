/** \file 		flex_lcd_c18.c
*   \version 	1.0
*   \brief 		Este archivo pertenece a la capa de drivers. Incluye las funciones básicas para manejar el display LCD.
*   \author 	Carlos Díaz  
*   \mail 		cedg88@gmail.com
*   \date 		30/Enero/2012
*/

/**/


/*-----------------------------------------------------------------------------------------*/
#include "Drivers/LCD_Handler.h"
#include <GenericTypeDefs.h>
#include <stdio.h>
#include "Drivers/TimeDelay.h"

/*-----------------------------------------------------------------------------------------*/
//unsigned char Text_Line1;
//unsigned char Text_Line2;

/*-----------------------------------------------------------------------------------------*/
void LCD_Init( void );

/*.........................................................................................*/
rom const INT8 LCD_INIT_STRING[4] =
{
  0x20 | (LCD_TYPE << 2), // Func set: 4-bit, 2 lines, 5x8 dots
  0x0C, // Display on
  1, // Clear display
  6 // Increment cursor
};

/*.........................................................................................*/
void LCD_send_nibble( UINT8 nibble )
{
	DATA_PIN_4 =!! (nibble & 0x01);
	DATA_PIN_5 =!! (nibble & 0x02);
	DATA_PIN_6 =!! (nibble & 0x04);
	DATA_PIN_7 =!! (nibble & 0x08);
	
	Nop();
	E_PIN = 1;
	Nop();
	Nop();
	E_PIN = 0;
}

/*.........................................................................................*/
void LCD_send_byte ( UINT8 address, UINT8 n )
{
	RS_PIN = 0;
	Delay10us(10);
	TRIS_DATA_PIN_4 = 0;
	TRIS_DATA_PIN_5 = 0;
	TRIS_DATA_PIN_6 = 0;
	TRIS_DATA_PIN_7 = 0;
	if( address )
		RS_PIN = 1;
	else
		RS_PIN = 0;
	Nop();
	LCD_send_nibble( n >> 4 );
	LCD_send_nibble( n & 0xf );
}

/*.........................................................................................*/
void LCD_Init( void )
{
	UINT8 i;

	TRIS_RS = 0;
	TRIS_E = 0;
	RS_PIN = 0;
	E_PIN = 0;
	TRIS_DATA_PIN_4 = 0;
	TRIS_DATA_PIN_5 = 0;
	TRIS_DATA_PIN_6 = 0;
	TRIS_DATA_PIN_7 = 0;
	
	DelayMs(15);
	for(i = 0 ; i < 3 ; i++)
	{
		LCD_send_nibble( 0x03 );
		DelayMs(5);
  	}
	LCD_send_nibble(0x02);
	for(i = 0 ; i < sizeof(LCD_INIT_STRING); i++)
	{
		LCD_send_byte(0, LCD_INIT_STRING[i]);
	}
}

/*.........................................................................................*/
void LCD_gotoxy( UINT8 x, UINT8 y )
{
	UINT8 address;

	if(y != 1)
		address = SECOND_LINE;
	else
		address=0;

	address += x-1;
	LCD_send_byte(0, 0x80 | address);
}

/*.........................................................................................*/
void LCD_putc( UINT8 c )
{
	switch( c )
	{
		case '\f':
			LCD_send_byte( 0 , 1 );
		break;

		case '\n':
			LCD_gotoxy( 1 , 2 );
		break;

		case '\b':
      		LCD_send_byte( 0 , 0x10 );
		break;

		default:
			LCD_send_byte( 1 , c );
		break;
  }
}

