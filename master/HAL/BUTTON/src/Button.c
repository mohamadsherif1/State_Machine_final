/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Button Module.
 *
 * Author: Team 1
 ******************************************************************************/



#include "../inc/Button.h"

/* Global variable to hold the button state */
 uint8 B_button_state = BUTTON_RELEASED;

 uint8 B_button_state_2 = BUTTON_RELEASED;

/************************************************************************************
* Service Name: BUTTON_RET_State
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void).
* Parameters (inout): None
* Parameters (out): uint8
* Return value: None
* Description: Function to get the button s.
************************************************************************************/

uint8 BUTTON_ONE_RET_State(void)
{
  uint8 dummy;
  dummy= B_button_state;
  B_button_state = BUTTON_RELEASED;
    return dummy;
}


uint8 BUTTON_TWO_RET_State(void)
{
  uint8 dummy;
  dummy= B_button_state_2;
  B_button_state_2 = BUTTON_RELEASED;
  
  return dummy;

}
/************************************************************************************
* Service Name: BUTTON_ONE_Read
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void).
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to read the button state.
************************************************************************************/

void BUTTON_ONE_Read(void){
  static uint8 B_Pressed_Count=STD_OFF;
   
    uint8 state = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX); 
    
    if(state == STD_LOW){
    B_Pressed_Count ++;
    }
    if(B_Pressed_Count > BUTTON_CHECK_NO){
    
    B_button_state = BUTTON_PRESSED;
    B_Pressed_Count =STD_OFF;
    }
    
  
  
    
}

/************************************************************************************
* Service Name: BUTTON_TWO_Read
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void).
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to read the button state.
************************************************************************************/
void BUTTON_TWO_Read(void){
  static uint8 B_Pressed_Count=STD_OFF;
   
    uint8 state = Dio_ReadChannel(DioConf_SW2_CHANNEL_ID_INDEX); 
    
    if(state == STD_LOW){
    B_Pressed_Count ++;
    }
    if(B_Pressed_Count > BUTTON_CHECK_NO){
    
    B_button_state_2 = BUTTON_PRESSED;
     B_Pressed_Count =STD_OFF;

    }
    
}

