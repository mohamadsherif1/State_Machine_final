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
    
  /* Declare the btn1 and btn2 states  */
  static uint8 btn1_state  = BUTTON_RELEASED;
  static uint8 btn2_state  = BUTTON_RELEASED;
  static uint8 btn1_state_old  = BUTTON_RELEASED;
  static uint8 btn2_state_old  = BUTTON_RELEASED;
  
  static uint32 counter =  NULL;
  
  
   /* reading button states */

  btn1_state = BUTTON_ONE_RET_State();
  btn2_state  =BUTTON_TWO_RET_State();
  
  
     /* if both buttons pressed switch to red state */

   if(((btn1_state == BUTTON_PRESSED) && (btn1_state_old  == BUTTON_RELEASED))&&((btn2_state == BUTTON_PRESSED) && (btn2_state_old  == BUTTON_RELEASED))){
counter = both_Pressed;
   }
     /* if  sw1 is pressed increment the counter */

  if((btn1_state == BUTTON_PRESSED) && (btn1_state_old  == BUTTON_RELEASED)){
counter++;
  }
       /* if sw2 is pressed decrement the counter unless its equal to zero */

  if((btn2_state == BUTTON_PRESSED)&&(btn2_state_old  == BUTTON_RELEASED)){
    if(counter == NULL){
    counter = 2;
    }else{
    counter --;
    }
  }
  
  
  
     /* state machine */

    if ((counter%NO_State)==(RED_State)){   
      
    red_ON();
    green_OFF();
    blue_OFF();
    Data_Transmite(RED_State);

     }
     else if ((counter%NO_State)==GREEN_State){
    red_OFF();
    green_ON();
    blue_OFF();
    Data_Transmite(GREEN_State);

     }
     else if ((counter%NO_State)==BLUE_State){
     red_OFF();
    green_OFF();
    blue_ON();
     Data_Transmite(BLUE_State);

     }


 

   
   
       /* resetting the variables */
  
  btn1_state_old = btn1_state;
  btn2_state_old =btn2_state;
  
  
  btn1_state  = BUTTON_RELEASED;
  btn2_state  = BUTTON_RELEASED;

}

void Data_Transmite(uint8 data){

cantx(data);
}



