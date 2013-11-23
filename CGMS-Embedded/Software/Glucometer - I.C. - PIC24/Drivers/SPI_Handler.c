/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <p24fj64ga102.h>
#include "GenericTypeDefs.h"
#include "SPI_Handler.h"

/*-----------------------------------------------------------------------------------------*/
uint16_t SPI1_Tx(uint16_t *Data)
{     
    SPI1BUF = *Data;
    while (SPI1_TBF_Status);
    return SPI1BUF;
}

uint16_t SPI1_Rx(void)
{
    uint16_t Data=0;
    Data = SPI1BUF;
    while (SPI1_RBF_Status);
    return Data;
}