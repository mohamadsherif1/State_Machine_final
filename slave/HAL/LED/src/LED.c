/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Team 1
 ******************************************************************************/
#include "../inc/LED.h"


/************************************************************************************
* Service Name: LED_ON
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to led on.
************************************************************************************/
void red_ON(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);  /* LED ON */
}
void blue_ON(void)
{
    Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_HIGH);  /* LED ON */
    
}void green_ON(void)
{
    Dio_WriteChannel(DioConf_LED3_CHANNEL_ID_INDEX,STD_HIGH);  /* LED ON */
}

/************************************************************************************
* Service Name: LED_OFF
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None(void)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to led off.
************************************************************************************/
void red_OFF(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);  /* LED OFF */
}
void blue_OFF(void)
{
    Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_LOW);  /* LED OFF */
    
}
void green_OFF(void)
{
    Dio_WriteChannel(DioConf_LED3_CHANNEL_ID_INDEX,STD_LOW);  /* LED OFF */
}