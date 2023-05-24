/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 * Author: Team 1
 ******************************************************************************/


#ifndef BUTTON_H
#define BUTTON_H


#include "../../../MCAL/DIO/inc/Dio.h"
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
   
   
#define BUTTON_PRESSED  STD_LOW

#define BUTTON_RELEASED STD_HIGH

#define BUTTON_CHECK_NO  (2)

/*******************************************************************************
 *                      API Prototypes                                    *
 *******************************************************************************/
uint8 BUTTON_ONE_RET_State(void);


uint8 BUTTON_TWO_RET_State(void);


void BUTTON_ONE_Read(void);


void BUTTON_TWO_Read(void);


#endif /* BUTTON_H */
