#include <p18f4550.h>

#ifndef __PORTS_H
#define __PORTS_H


#define INITIALIZE_PORT_A		PORTA=0x00;\
								LATA=0x00;\
								ADCON1=ADCON1|0x07;\
								CMCON=0x07;\
								TRISA=0xFF;	
	
#define INITIALIZE_PORT_B		PORTB=0x00;\
								LATB=0x00;\
								ADCON1=ADCON1|0x07;\
								TRISB=0x00;

#define INITIALIZE_PORT_C		PORTC=0x00;\
								LATC=0x00;\
								TRISC=0x07;

#define INITIALIZE_PORT_D		PORTD=0x00;\
								LATD=0x00;\
								TRISD=0x00;
		
#define INITIALIZE_PORT_E		PORTE=0x00;\
								LATE=0x00;\
								ADCON1=ADCON1|0x07;\
								CMCON=0x07;\
								TRISE=0x0F;			

extern void Initialize_Ports(void);
							
							


#endif