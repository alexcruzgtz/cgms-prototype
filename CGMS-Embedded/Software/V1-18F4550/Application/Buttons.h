#include <p18f4550.h>

#ifndef __BUTTONS_H
#define __BUTTONS_H

/*----------------------------------------------------------------*/
/*                    Macro Definitions                           */
/*----------------------------------------------------------------*/
#define PRESS		0
#define RELEASE		1

/*----------------------------------------------------------------*/
/*                    Exported Functions                          */
/*----------------------------------------------------------------*/
extern void Btn_Debounce (void);
void CheckUpButton(void);
void CheckDownButton(void);
void CheckEnterButton(void);
/*----------------------------------------------------------------*/
/*                    Exported Variables                          */
/*----------------------------------------------------------------*/
/*
unsigned char ActualButtonState;		//Indica el estado actual en el qeu se encuentran los botones
unsigned char LastButtonState;			//Indica el valor de un estado previo de los botones.
unsigned char DebounceCntr;				//Esta variable lleva la cuenta de la cantidad de tiempo que ha estado presionado un boton
unsigned char ButtonState;				//Indica si el boton esta presionado(PRESSED) o si fue liberado(RELEASE)

unsigned char ActualTimeVar;
unsigned char GluCal_Flag;
unsigned char TimeCal_Flag;
*/
#endif
