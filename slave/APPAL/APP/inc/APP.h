 /******************************************************************************
 *
 * Module: application
 *
 * File Name: App.h
 *
 * Description: Header file for Application Tasks.
 *
 * Author: Team 1
 ******************************************************************************/

#ifndef APP_H_
#define APP_H_
   
   
   /*    add the PORT driver */
#include "../../../MCAL/PORT/inc/Port.h"

   
/*    add the led driver */
#include "../../../HAL/LED/inc/LED.h"

#include "../../../HAL/BUTTON/inc/Button.h"

#include "../../OS/inc/OS.h"
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
   
#define  RED_State       (0U)
#define  GREEN_State       (1U)
#define  BLUE_State       (2U)
#define  both_Pressed     (0U)

#define   NO_State        (3U)
/*******************************************************************************
 *                      API Prototypes                                    *
 *******************************************************************************/
/* Description: task to init the ports and run for once */
void Init_Tasks(void);


/* Description: task to check buttons */
void Button_state_TASK(void);


/* Description: task for state machine */
void App_TASK (void);


/* Description: task for reception  */

void reception(void);

#endif /* APP_H_ */