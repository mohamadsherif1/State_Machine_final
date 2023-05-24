#ifndef CAN_INIT_H
#define CAN_INIT_H

#include <stdint.h>
#include <stdio.h>

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#include "../../../services/Platform_Types.h"

#include "../../../can.h"



extern uint8_t pui8MsgData[];




extern tCANMsgObject sCANMessage_rx;

extern volatile bool g_bRXFlag ;


void can_init();

void
CANIntHandler(void);


__uint8_t canRX();

#endif