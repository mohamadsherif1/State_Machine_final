#include "../inc/CAN_INIT.h"


tCANMsgObject sCANMessage_tx;


uint8_t pui8MsgData[4];


uint8_t  fault_state_flag = 0;

//*****************************************************************************
//
// A flag for the interrupt handler to indicate that a message was received.
//
//*****************************************************************************

volatile bool g_bRXFlag = 0;


//*****************************************************************************
//
// A flag to indicate that some reception error occurred.
//
//*****************************************************************************

volatile bool g_bErrFlag = 0;
//*****************************************************************************
/************************************************************************************
* Service Name: can_init
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function Initalizes CAN GPIO Peripherals ,Systick Peripherals, Interrupt
Peripherals.
*Also initializes transmit and receive
Objects
************************************************************************************/
void can_init(){
SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);

    //
    // For this example CAN0 is used with RX and TX pins on port B4 and B5.
    // The actual port and pins used may be different on your part, consult
    // the data sheet for more information.
    // GPIO port B needs to be enabled so these pins can be used.
    // TODO: change this to whichever GPIO port you are using
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    




    //
    // Configure the GPIO pin muxing to select CAN0 functions for these pins.
    // This step selects which alternate function is available for these pins.
    // This is necessary if your part supports GPIO pin function muxing.
    // Consult the data sheet to see which functions are allocated per pin.
    // TODO: change this to select the port/pin you are using
    //
    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    //
    // Enable the alternate function on the GPIO pins.  The above step selects
    // which alternate function is available.  This step actually enables the
    // alternate function instead of GPIO for these pins.
    // TODO: change this to match the port/pin you are using
    //
    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    //
    // The GPIO port and pins have been set up for CAN.  The CAN peripheral
    // must be enabled.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    //
    // Initialize the CAN controller
    //
    CANInit(CAN0_BASE);

    //
    // Set up the bit rate for the CAN bus.  This function sets up the CAN
    // bus timing for a nominal configuration.  You can achieve more control
    // over the CAN bus timing by using the function CANBitTimingSet() instead
    // of this one, if needed.
    // In this example, the CAN bus is set to 500 kHz.  In the function below,
    // the call to SysCtlClockGet() or ui32SysClock is used to determine the 
    // clock rate that is used for clocking the CAN peripheral.  This can be 
    // replaced with a  fixed value if you know the value of the system clock, 
    // saving the extra function call.  For some parts, the CAN peripheral is 
    // clocked by a fixed 8 MHz regardless of the system clock in which case 
    // the call to SysCtlClockGet() or ui32SysClock should be replaced with 
    // 8000000.  Consult the data sheet for more information about CAN 
    // peripheral clocking.
    //
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);

    //
    // Enable interrupts on the CAN peripheral.  This example uses static
    // allocation of interrupt handlers which means the name of the handler
    // is in the vector table of startup code.  If you want to use dynamic
    // allocation of the vector table, then you must also call CANIntRegister()
    // here.
    //
    // CANIntRegister(CAN0_BASE, CANIntHandler); // if using dynamic vectors
    //
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    //
    // Enable the CAN interrupt on the processor (NVIC).
    //
    IntEnable(INT_CAN0);

    //
    // Enable the CAN for operation.
    //
    CANEnable(CAN0_BASE);
    
     //
    // Initialize a message object to be used for receiving CAN messages with
    // any CAN ID.  In order to receive any CAN ID, the ID and mask must both
    // be set to 0, and the ID filter enabled.
    //
     sCANMessage_tx.ui32MsgID=1;
     sCANMessage_tx.ui32MsgIDMask = 1; 
     
    sCANMessage_tx.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sCANMessage_tx.ui32MsgLen =  8;
    sCANMessage_tx.pui8MsgData = pui8MsgData;

    // Now load the message object into the CAN peripheral.  Once loaded the
    // CAN will receive any message on the bus, and an interrupt will occur.
    // Use message object 1 for receiving messages (this is not the same as
    // the CAN ID which can be any value in this example).
    //
    //CANMessageSet(CAN0_BASE, 1, &sCANMessage_rx, MSG_OBJ_TYPE_RX);
    //
    // Enter loop to process received messages.  This loop just checks a flag
    // that is set by the interrupt handler, and if set it reads out the
    // message and displays the contents.  This is not a robust method for
    // processing incoming CAN data and can only handle one messages at a time.
    // If many messages are being received close together, then some messages
    // may be dropped.  In a real application, some other method should be used
    // for queuing received messages in a way to ensure they are not lost.  You
    // can also make use of CAN FIFO mode which will allow messages to be
    // buffered before they are processed.
    //

}

/************************************************************************************
* Service Name: CANIntHandler
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function is the interrupt handler for the CAN peripheral,
*It checks for the cause of the interrupt, and maintains a count of all messages that have been transmitted.
************************************************************************************/

void
CANIntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);
    
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
       
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

     
        g_bErrFlag = 1;
        
  
        
    }
    else if(ui32Status == 1)
    { 
       CANIntClear(CAN0_BASE, 1);

       g_bRXFlag = 1;
        
       
       g_bErrFlag = 0;
    }
    
   
    else
    {
    }
}

/************************************************************************************
* Service Name: cantx
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): index,id
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function to transmit object message 
************************************************************************************/

void cantx(uint8 index)
{
  pui8MsgData[0] = index;
  CANMessageSet(CAN0_BASE, 1, &sCANMessage_tx, MSG_OBJ_TYPE_TX);
}