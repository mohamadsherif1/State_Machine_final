 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Team 1
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H


#define PORT_CONFIGURED_CHANNLES              (5U)

   /*******************************************************************************
 *                                   ENABLE/DISABLE                                     *
 *******************************************************************************/

#define PORT_SET_PIN_DIRECTION_API            STD_LOW

   
#define Port_RefreshPortDirection_API            STD_LOW

   
#define PORT_VERSION_INFO_API    STD_LOW
#define Port_SetPinMode_API STD_LOW
/*******************************************************************************
 *                                   MODES                                    *
 *******************************************************************************/



#define PORT_PIN_MODE_DIO		(0U)
#define PORT_PIN_MODE_ADC		(1U)
#define PORT_PIN_MODE_CAN		(2U)
#define PORT_PIN_MODE_GPT		(3U)
#define PORT_PIN_MODE_WDG		(4U)
#define PORT_PIN_MODE_FLEXRAY	(5U)
#define PORT_PIN_MODE_ICU		(6U)
#define PORT_PIN_MODE_LIN		(7U)
#define PORT_PIN_MODE_MEM		(8U)
#define PORT_PIN_MODE_PWM		(9U)
#define PORT_PIN_MODE_SPI		(10U)

   
/*******************************************************************************
 *                                   PIN                                     *
 *******************************************************************************/
   
#define PORT_PIN0 				(Port_PinType)0
#define PORT_PIN1 				(Port_PinType)1
#define PORT_PIN2 				(Port_PinType)2
#define PORT_PIN3 				(Port_PinType)3
#define PORT_PIN4 				(Port_PinType)4
#define PORT_PIN5 				(Port_PinType)5
#define PORT_PIN6 				(Port_PinType)6
#define PORT_PIN7 				(Port_PinType)7

/*******************************************************************************
 *                                   Ports                                     *
 *******************************************************************************/
    
#define PORTA 			   	(uint8)0
#define PORTB 				(uint8)1
#define PORTC 				(uint8)2
#define PORTD 				(uint8)3   
#define PORTE 				(uint8)4
#define PORTF 				(uint8)5   

#endif /* PORT_CFG_H */