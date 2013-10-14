/** \file 		flex_lcd_c18.c
*   \version 	1.0
*   \brief 		Este archivo pertenece a la capa de drivers. Incluye las funciones básicas para manejar el display LCD.
*   \author 	Carlos Díaz  
*   \mail 		cedg88@gmail.com
*   \date 		30/Enero/2012
*/
#include "flex_lcd_c18.h"

unsigned char Text_Line1;
unsigned char Text_Line2;

void Initialize_LCD(void);

rom const int8 LCD_INIT_STRING[4] =
{
  0x20 | (lcd_type << 2), // Func set: 4-bit, 2 lines, 5x8 dots
  0x0C, // Display on
  1, // Clear display
  6 // Increment cursor
};
//-------------------------------------

void lcd_send_nibble(int8 nibble){

	DATA_PIN_4=!!(nibble & 0x01);
	DATA_PIN_5=!!(nibble & 0x02);
	DATA_PIN_6=!!(nibble & 0x04);
	DATA_PIN_7=!!(nibble & 0x08);

	Nop();
	E_PIN=1;
	Nop();
	Nop();
	E_PIN=0;
}


void lcd_send_byte(int8 address, int8 n){

	RS_PIN=0;

	_delay_100us();


	TRIS_DATA_PIN_4=0;
	TRIS_DATA_PIN_5=0;
	TRIS_DATA_PIN_6=0;
	TRIS_DATA_PIN_7=0;

	if(address)
		RS_PIN=1;
	else
		RS_PIN=0;

	Nop();


	lcd_send_nibble(n >> 4);
	lcd_send_nibble(n & 0xf);
}

//----------------------------

void Initialize_LCD(void){
	int8 i;

	TRIS_RS=0;
	TRIS_E=0;


	RS_PIN=0;
	E_PIN=0;


	TRIS_DATA_PIN_4=0;
	TRIS_DATA_PIN_5=0;
	TRIS_DATA_PIN_6=0;
	TRIS_DATA_PIN_7=0;

	_delay_5ms();//15ms
	_delay_5ms();
	_delay_5ms();

	for(i=0 ;i < 3; i++){
		lcd_send_nibble(0x03);
		_delay_5ms();//5ms
  	}

	lcd_send_nibble(0x02);

	for(i=0; i < sizeof(LCD_INIT_STRING); i++){
		lcd_send_byte(0, LCD_INIT_STRING[i]);

	}
}
//----------------------------
void lcd_gotoxy(int8 x, int8 y){
	int8 address;

	if(y != 1)
		address = lcd_line_two;
	else
		address=0;

	address += x-1;
	lcd_send_byte(0, 0x80 | address);
}

//-----------------------------

void lcd_putc(int8 c){
	switch(c){
		case '\f':
			lcd_send_byte(0,1);
		break;
		case '\n':
			lcd_gotoxy(1,2);
		break;
		case '\b':
      		lcd_send_byte(0,0x10);
		break;
		default:
			lcd_send_byte(1,c);
		break;
  }
}

