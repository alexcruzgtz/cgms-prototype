/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "p24fxxxx.h"
#include "GenericTypeDefs.h"
#include "SPI_Handler.h"

/*-----------------------------------------------------------------------------------------*/
UINT16 SPI1_Tx(UINT16 *Data)
{     
    SPI1BUF = *Data;
    while (SPI1_TBF_Status);
    return SPI1BUF;
}

UINT16 SPI1_Rx(void)
{
    UINT16 Data=0;
    Data = SPI1BUF;
    while (SPI1_RBF_Status);
    return Data;
}