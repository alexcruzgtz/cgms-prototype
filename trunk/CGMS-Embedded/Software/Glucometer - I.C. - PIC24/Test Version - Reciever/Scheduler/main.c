/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#include "Scheduler/main.h"
#include <p24fxxxx.h>
#include "Drivers/compiler.h"
#include <GenericTypeDefs.h>
#include <PPS.h>
#include "Drivers/Interrupts.h"
#include "Drivers/Oscillator.h"
#include "Drivers/ADC_Handler.h"
#include "Drivers/LCD_Handler.h"
#include "Drivers/SPI_Handler.h"
//#include "Drivers/I2C_Handler.h"
#include "Drivers/UART_Handler.h"
#include "Drivers/SymbolTime.h"
#include "Drivers/TimeDelay.h"
#include "Drivers/Wireless/MiWi_ConfigApp.h"
#include "Drivers/Wireless/MiWi_ConfigMRF89XA.h"
#include "Drivers/Wireless/MiWi_MCHP_API.h"
#include "Drivers/Wireless/MiWi_MCHP_MAC.h"
#include "Drivers/Wireless/MiWi_MRF89XA.h"
#include "Drivers/Wireless/MiWi_NVM.h"
#include "Drivers/Wireless/MiWi_P2P.h"
#include "Drivers/Wireless/MiWi_Security.h"

#include "Application/DemoOutput.h"

Config_CFGBits();


/*int main( void )
{
	HardwareCfg_Init();  
	LCD_Test();
	UART_Test();
	while(1){}
}*/



/*-----------------------------------------------------------------------------------------*/

#define LIGHT   0x01
#define SWITCH  0x02
#if ADDITIONAL_NODE_ID_SIZE > 0
    BYTE AdditionalNodeID[ADDITIONAL_NODE_ID_SIZE] = {LIGHT};
#endif
BYTE myChannel = 24;

BYTE tempAddr[8] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
extern DWORD_VAL OutgoingFrameCounter; int main(void)
{   
    BYTE i = 0;
	BYTE TxSynCount = 0;
    BYTE TxSynCount2 = 0;
    BYTE TxNum = 0;
    BYTE RxNum = 0;
    
    HardwareCfg_Init();      
    
	DemoOutput_Greeting();
	MiApp_ProtocolInit(FALSE);

    // Set default channel
    if( MiApp_SetChannel(myChannel) == FALSE )
    {
        DemoOutput_ChannelError(myChannel);
        return 0;
    }
    MiApp_ConnectionMode(ENABLE_ALL_CONN);
    DemoOutput_Channel(myChannel, 0);
    i = MiApp_EstablishConnection(0xFF, CONN_MODE_DIRECT);
    
    if( i != 0xFF )
    {
        DemoOutput_Channel(myChannel, 1);
    }
    else
    {
       MiApp_StartConnection(START_CONN_DIRECT, 10, 0);
    }
    // Turn on LED 1 to indicate connection established
    LED_Lat = 1;
    //DemoOutput_Instruction();

    while(1)
    {
        if( MiApp_MessageAvailable() )
        {
            DemoOutput_HandleMessage();
            DemoOutput_UpdateTxRx(TxNum, ++RxNum);
            
            // Toggle LED2 to indicate receiving a packet.
            LED_Lat ^= 1;
            MiApp_DiscardMessage();
        }
        else
        {
            BYTE PressedButton =0;// ButtonPressed();
            switch( PressedButton )
            {
                case 1:                 
                    
                    MiApp_FlushTx();
                    for(i = 0; i < 21; i++)
                    {
                        MiApp_WriteData(MiWi[(TxSynCount%6)][i]);
                    }
                    TxSynCount++;
                    MiApp_BroadcastPacket(FALSE);
                    DemoOutput_UpdateTxRx(++TxNum, RxNum);
                    break;
                    
                case 2:
                    MiApp_FlushTx();   
                    for(i = 0; i < 11; i++)
                    {
                        MiApp_WriteData(DE[(TxSynCount2%6)][i]);
                    }
                    TxSynCount2++;
                    if( MiApp_UnicastConnection(0, TRUE) == FALSE )
                    {
                        DemoOutput_UnicastFail();
                    }
                    else
                    {
                        TxNum++;
                    }                   
                    DemoOutput_UpdateTxRx(TxNum, RxNum);
                    break;
                    
                default:
                    break;
            } 
        }
    }
}

/*-----------------------------------------------------------------------------------------*/

/*BYTE ButtonPressed(void)
{
    MIWI_TICK tickDifference;
        
    if(PushB_Pin == 0)
    {
        //if the button was previously not pressed
        if(PUSH_BUTTON_pressed == FALSE)
        {
            PUSH_BUTTON_pressed = TRUE;
            PUSH_BUTTON_press_time = MiWi_TickGet();
            return 1;
        }
    }
    else if(PUSH_BUTTON_2 == 0)
    {
        //if the button was previously not pressed
        if(PUSH_BUTTON_pressed == FALSE)
        {
            PUSH_BUTTON_pressed = TRUE;
            PUSH_BUTTON_press_time = MiWi_TickGet();
            return 2;
        }
    } 
    else
    {
        //get the current time
        MIWI_TICK t = MiWi_TickGet();
        
        //if the button has been released long enough
        tickDifference.Val = MiWi_TickGetDiff(t,PUSH_BUTTON_press_time);
        
        //then we can mark it as not pressed
        if(tickDifference.Val > DEBOUNCE_TIME)
        {
            PUSH_BUTTON_pressed = FALSE;
        }
    }
    
    return 0;
}
*/

