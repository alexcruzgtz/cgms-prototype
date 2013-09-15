#include <p18f4550.h>
#include "Ports.h"

void Initialize_Ports(void);

void Initialize_Ports(void)
{
	INITIALIZE_PORT_A	
	INITIALIZE_PORT_B
	INITIALIZE_PORT_C
	INITIALIZE_PORT_D
	INITIALIZE_PORT_E
}
