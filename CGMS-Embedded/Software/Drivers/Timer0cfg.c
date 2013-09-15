#include <p18f4550.h>
#include "main.h"
#include "Ports.h"
#include "interrupciones.h"
#include "Timer0cfg.h"

void Initialize_Timer0(void);

void Initialize_Timer0(void)
{
	MACRO_DISABLE_TMR0
	MACRO_SET_16BITS_TMR0
	MACRO_SELECT_INTERNAL_CLK_SOURCE_TMR0
	MACRO_SELECT_RISING_EDGE_TMR0
	MACRO_PRESCALER_NOT_ASSIGNED_TMR0
	MACRO_PRESCALER_1_2_TMR0
	TMR0H = CONSTANT_1ms_LOW_NIBBLE;
	TMR0L = CONSTANT_1ms_HIGH_NIBBLE;

	CLEAR_INT_TMR0_REQ
	MACRO_ENABLE_TMR0
}