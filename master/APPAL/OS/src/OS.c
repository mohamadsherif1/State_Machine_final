 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/OS.h"
  
#define Enable_Interrupts()    __asm("CPSIE I")

 const task_struct * Task_Confg = NULL_PTR;

/* Global variable store the Os Time */
static uint32 Tick_Count = NULL;

/* Global variable to indicate the the timer has a new tick */
static uint16 Tick_Flag = STD_ON;

/*********************************************************************************************/

/************************************************************************************
* Service Name:Os_start
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Task executes once to initialize all the Modules
***********************************************************************************/

void Os_start(void){

/*   start global interrupt */  // lama n48l el can
Enable_Interrupts();

/*         set callbacks       */
//SysTick_SetCallBack(Os_NewTimerTick);

/*         strart systick       */
  SysTick_Start(TIME_SLICE,Os_NewTimerTick);
  
/*        init the ports and dio */
  Init_Tasks();

}



void Os_Scheduler(const OS_TASKS_TYPE *  Task_Confg_ptr){
  Task_Confg = Task_Confg_ptr -> Tasks;
  
 
  Os_start();
  
  while(1){
    
    /*        going through all tasks */
    for(uint8 index = NULL ; index<NO_OF_TASKS;index++){
      
      /*        check if the tick flag == 1 */
      if(Tick_Flag ==STD_ON){
        /*        check the predicty for each fun   */
        if(Tick_Count %Task_Confg[index].predecity==NULL){
          /*        call the function by the pointer function method  */
      Task_Confg[index].ptr_fun();
      
      Tick_Flag =NULL;
        }
      }
    
    }
  
  }
  
}




void Os_NewTimerTick(void){

   /* Increment the Os time by TIME_SLICE */
     Tick_Count   += TIME_SLICE;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    Tick_Flag = STD_ON;
    
    /*        resetting the time frame         */
    if(Tick_Count>MAX_TIME){
    Tick_Count = TIME_SLICE;
    }
    
}

