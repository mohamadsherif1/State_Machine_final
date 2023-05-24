 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.h
 *
 * Description: Header file for Os Scheduler.
 *
 * Author: Team 1
 ******************************************************************************/

#ifndef OS_H_
#define OS_H_


/* Timer counting time in ms */
#define TIME_SLICE 10

/* OS Pre-Compile Configuration Header file */
#include "OS_Cfg.h"



#include "../../../services/Std_Types.h"
   
/*    add the SYSTICK driver AND CAN */
#include "../../../MCAL/SYSTICK_TIMER/inc/systick.h"
#include "../../../MCAL/CAN/inc/CAN_INIT.h"
   

#include "../../APP/inc/APP.h"

   
 
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
typedef struct {
  uint16 predecity ;
  void (* ptr_fun)(void);
  
  }task_struct;
 
typedef struct {
task_struct Tasks[NO_OF_TASKS]; 
}OS_TASKS_TYPE;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Description: 
 * Function responsible for:
 * 1.Assign the structure pointer
 * 2. Enable Interrupts
 * 3. Start the Os timer
 * 4. Execute the Init Task
 * 5. Start the Scheduler to run the tasks
 */

void Os_start(void);

/* Description: The Engine of the Os Scheduler used for switch between different tasks */
void Os_Scheduler(const OS_TASKS_TYPE *  Task_Confg_ptr);

/* Description: Function called by the Timer Driver in the MCAL layer using the call back pointer */
void Os_NewTimerTick(void);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const OS_TASKS_TYPE TASK_CONFIG;

#endif /* OS_H_ */
