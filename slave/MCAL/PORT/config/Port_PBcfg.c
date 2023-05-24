 /******************************************************************************
 * Module: Port
 *
 * File Name: Port_PBcfg.h
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/Port.h"

#ifndef PORT_PBCFG_H_
#define PORT_PBCFG_H_


      
const Port_ConfigType Port_Configuration ={

                /* Port F Configuartion  */
     PORTF,PORT_PIN0,PORT_PIN_MODE_DIO,DIGITAL_MODE,PORT_PIN_IN,PULL_UP,PORT_PIN_LEVEL_LOW,PORT_PIN_DIR_UNCHANGEABLE,// Button1
     PORTF,PORT_PIN1,PORT_PIN_MODE_DIO,DIGITAL_MODE,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_DIR_UNCHANGEABLE , // LED1
     PORTF,PORT_PIN2,PORT_PIN_MODE_DIO,DIGITAL_MODE,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_DIR_UNCHANGEABLE,  // LED2
     PORTF,PORT_PIN3,PORT_PIN_MODE_DIO,DIGITAL_MODE,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_DIR_UNCHANGEABLE,  // LED3
     PORTF,PORT_PIN4,PORT_PIN_MODE_DIO,DIGITAL_MODE,PORT_PIN_IN,PULL_UP,PORT_PIN_LEVEL_LOW,PORT_PIN_DIR_UNCHANGEABLE , // Button2
};

#endif   /* PORT_PBcfg_H */