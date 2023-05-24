 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: App.c
 *
 * Description: Source file for Application Tasks.
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/APP.h"


  static uint8_t counter ;


   
/************************************************************************************
* Service Name:Init_Tasks
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Task executes once to initialize all the Modules
************************************************************************************/
void Init_Tasks(void)
{
/*     start port */  
 can_init();

 Port_Init(&Port_Configuration);

/*     start dio */   
  DIO_CFG_INIT(DIO_CFG_ARR);
  
  
}
/************************************************************************************
* Service Name:Button_state
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to check button state and executes every 40 Mili-seconds
************************************************************************************/


void Button_state_TASK(void){
/* Description: read the two buttons happens every 40 ms*/

 BUTTON_ONE_Read();
 BUTTON_TWO_Read();

}


/************************************************************************************
* Service Name:App_TASK
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to switch between states based on btn state and sends to tiva2
************************************************************************************/

void App_TASK (void){
    
    static uint8_t flag = NULL;
    static uint8_t old_state = NULL;
    static uint8_t check = NULL;
    static uint16 state = 10;
    
    if(old_state == counter){
check ++;
state = counter;
if (check>4){
state = 6;
}
    }
    
    if(counter != old_state){
    state = counter;
    check = 0;
    }
    

    
   if (state==0 ){
      
    red_ON();
    green_OFF();
    blue_OFF();
    old_state = state;
    //check = 0;
     }
    
     else if (state==1 ){
    red_OFF();
    green_ON();
    blue_OFF();
    old_state = state;
   // check = 0;
     }
    
     else if (state==2 ){
     red_OFF();
    green_OFF();
    blue_ON();
    old_state = state;
   // check = 0;
     }
    else if (state==6 ){
     red_ON();
    green_ON();
    blue_ON();
     }
   
   /*if(old_state != 6){
   check = 0;
   flag = 0;
   }*/


}
/************************************************************************************
* Service Name:reception
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to check the reception and executes every 10 Mili-seconds
************************************************************************************/


void reception(void){

  
  counter = canRX();

}




