 /******************************************************************************
 * Module: Port
 *
 * File Name: Port_PBcfg.h
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - OS Driver
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/OS.h"

/*               DECLARING THE TASKS PREDICTY AND FUNCTIONS                   */

   const OS_TASKS_TYPE TASK_CONFIG ={
TASK_1_PREDECTIY,reception,
TASK_2_PREDECTIY,App_TASK
   };

   