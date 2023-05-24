 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Lcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 1
 ******************************************************************************/
#include "../inc/Dio.h"



/* PB structure used with Dio_Init API */
Dio_Conf_Channel DIO_CFG_ARR[] = { 
{DioConf_LED1_PORT_NUM,DioConf_LED1_CHANNEL_NUM},
{DioConf_LED2_PORT_NUM,DioConf_LED2_CHANNEL_NUM},
{DioConf_LED3_PORT_NUM,DioConf_LED3_CHANNEL_NUM},
{DioConf_SW1_PORT_NUM,DioConf_SW1_CHANNEL_NUM},
{DioConf_SW2_PORT_NUM,DioConf_SW2_CHANNEL_NUM}
}; 


//Dio_ChannelGroupType ChannelGroupParam = {5,0x0E,0};   