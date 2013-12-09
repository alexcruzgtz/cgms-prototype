/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"
#include "GenericTypeDefs.h"
#include "SPI_Handler.h"

/*-----------------------------------------------------------------------------------------*/
/*********************************************************************
* Function:         void SPIPut(BYTE v)
* PreCondition:     SPI has been configured 
* Input:		    v - is the byte that needs to be transfered
* Output:		    none
* Side Effects:	    SPI transmits the byte
* Overview:		    This function will send a byte over the SPI
* Note:			    None
********************************************************************/
void SPIPut(BYTE v)
{
	BYTE i;
    SPI1_EventIRQ_Flag = 0;
    i = SPI1BUF;
    SPI1BUF = v;
    while(SPI1_EventIRQ_Flag == 0){}
}

/*********************************************************************
* Function:         BYTE SPIGet(void)
* PreCondition:     SPI has been configured 
* Input:		    none
* Output:		    BYTE - the byte that was last received by the SPI
* Side Effects:	    none
* Overview:		    This function will read a byte over the SPI
* Note:			    None
********************************************************************/
BYTE SPIGet(void)
{
    SPIPut(0x00);
	return SPI1BUF;
}