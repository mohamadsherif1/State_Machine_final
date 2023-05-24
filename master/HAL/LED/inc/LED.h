/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Team 1
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "../../../services/Std_Types.h"

#include "../../../MCAL/DIO/inc/Dio.h"


/*******************************************************************************
 *                      API Prototypes                                    *
 *******************************************************************************/
/* Description: Set the red LED state to ON */
void red_ON(void);

/* Description: Set the green LED state to ON */
void green_ON(void);

/* Description: Set the blue LED state to ON */
void blue_ON(void);

/* Description: Set the red LED state to OFF */
void red_OFF(void);

/* Description: Set the green LED state to OFF */
void green_OFF(void);

/* Description: Set the blue LED state to OFF */
void blue_OFF(void);


#endif /* LED_H */
