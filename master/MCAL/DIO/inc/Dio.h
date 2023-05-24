 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 1
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H


/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"


/* Standard AUTOSAR types */
#include "../../../services/Std_Types.h"

#include "Dio_Regs.h"

#include "../../../services/Platform_Types.h"

#include "../../../services/Common_macros.h"


#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Non AUTOSAR files */


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType; // dio.h


/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;  // dio.h

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Type definition enumorate for Dio_LevelType used by the DIO APIs */
typedef enum{ STD_LOW=0,STD_HIGH
}Dio_LevelType;



typedef struct
{
    /* Member contains the ID of the Port that this channel belongs to */
    Dio_PortType port_number;
    /* Member contains the ID of the Channel*/
    Dio_ChannelType channel_number;
}Dio_Conf_Channel; 

typedef struct {

    Dio_ChannelType DioChannelGroupIdentification;
    Dio_ChannelType DioPortMask;
    Dio_ChannelType DioPortOffset;

}Dio_ChannelGroupType;  // in the dio.h 3momn

typedef enum ports {
    PORTA = 0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
} DIO_PORTS;

/*******************************************************************************
 *                      API Prototypes                                    *
 *******************************************************************************/


/* Function for DIO write Port API */
void DIO_CFG_INIT( Dio_Conf_Channel* CfgPtr);

/* Function for DIO Initialization API */
void Dio_WriteChannel(Dio_ChannelType channel_id, Dio_LevelType level);  

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channel_id);

/*Dio Write Port Definition*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level); // dio.h

/*Dio Read Port Definition*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/*DIO_WRITE CHANNEL*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType level);

/*DIO READ CHANNEL*/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);


#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType channel_id);
#endif
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/


extern Dio_Conf_Channel DIO_CFG_ARR[];   // extern array of DIO_CONF_CHANNELS

extern Dio_ChannelGroupType ChannelGroupParam;



#endif /* DIO_H */