 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author:Team 1
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "../../DIO/inc/Dio.h"

#include "Port_REG.h"

#include "../../../services/Std_Types.h"
#include "../../../services/Platform_Types.h"
#include "../../../services/Common_macros.h"


/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/*******************************************************************************
 *                      DIO Macro's status                                        *
 *******************************************************************************/
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#define DIGITAL_MODE                    (1U)
 

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;
/* Type definition for Port_PinDirectionType used by the Port APIs */
   /* Description: Enum to hold PIN direction */

typedef enum
{
  PORT_PIN_IN = STD_LOW,
  PORT_PIN_OUT = STD_HIGH
}Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the Port APIs */
typedef uint8 Port_PinModeType;
typedef uint8 Port_PortType;
/* 
Type definition for Port_PinType used by the Port APIs */
typedef uint32 Port_PinType ; 

/* Description: Enum to hold is dierction changable for PIN or not */

typedef enum
{
  PORT_PIN_DIR_UNCHANGEABLE,PORT_PIN_DIR_CHANGEABLE
  
}Port_PinDirChangeable;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the Mode of pin 
 *      4. the direction of pin --> INPUT or OUTPUT
 *      5. the internal resistor --> Disable, Pull up or Pull down
 *      6. The Intial value STD_HIGH , STD_LOW
 */
typedef struct 
{
    Port_PortType port_num; 
    uint8 pin_num; 
    Port_PinModeType PinMode; 
    uint8 Digital_Value;
    uint8 direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinDirChangeable ChangableDierction;
    
}Port_Pin_Type;


typedef struct {
Port_Pin_Type Pins[PORT_CONFIGURED_CHANNLES]; 
}Port_ConfigType;



/*******************************************************************************
 *                      NON-AUTOSAR DATA TYPES                                    *
 *******************************************************************************/

#define clock_mask 0x3f
#define PORT_PIN_LEVEL_HIGH                  STD_HIGH
#define PORT_PIN_LEVEL_LOW                   STD_LOW

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*  Function to initialze the port */ 

void Port_Init(  const Port_ConfigType* ConfigPtr  );


/*  Function to set the pin Mode */ 

#if(PORT_SET_PIN_DIRECTION_API)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif

#if(Port_RefreshPortDirection_API)
void Port_RefreshPortDirection(void);
#endif

#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( 
                          const Std_VersionInfoType* versioninfo 
                         );
#endif

#if(Port_SetPinMode_API)
 void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);

#endif
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;


#endif /* PORT_H */
