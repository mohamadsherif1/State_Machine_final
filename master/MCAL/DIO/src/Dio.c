
 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/Dio.h"

static Dio_Conf_Channel* Dio_PortChannels = NULL_PTR;

//static Dio_ChannelGroupType* channelGroupIdptr = &ChannelGroupParam;
uint8 Dio_Status = DIO_NOT_INITIALIZED;


/************************************************************************************
* Service Name: DIO_CFG_INIT
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): CfgPtr pointer
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/
void DIO_CFG_INIT( Dio_Conf_Channel* CfgPtr){
  
Dio_Status  = DIO_INITIALIZED;
Dio_PortChannels =  CfgPtr;

}



/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): channel_id - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a Level of a channel.
************************************************************************************/

void Dio_WriteChannel(Dio_ChannelType channel_id, Dio_LevelType level)
{
    if (Dio_PortChannels[channel_id].port_number == PORTA) {
        
        if (level == STD_HIGH) {
        	Set_Bit(GPIO_PORTA_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
        	Clear_Bit(GPIO_PORTA_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }
    if (Dio_PortChannels[channel_id].port_number == PORTB) {
        if (level == STD_HIGH) {
            	Set_Bit(GPIO_PORTB_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
            	Clear_Bit(GPIO_PORTB_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }
    if (Dio_PortChannels[channel_id].port_number == PORTC) {
        if (level == STD_HIGH) {
            	Set_Bit(GPIO_PORTC_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
            	Clear_Bit(GPIO_PORTC_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }
    if (Dio_PortChannels[channel_id].port_number == PORTD) {
        if (level == STD_HIGH) {
            	Set_Bit(GPIO_PORTD_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
            	Clear_Bit(GPIO_PORTD_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }
    if (Dio_PortChannels[channel_id].port_number == PORTE) {
        if (level == STD_HIGH) {
            	Set_Bit(GPIO_PORTE_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
            Clear_Bit(GPIO_PORTE_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }
    if (Dio_PortChannels[channel_id].port_number == PORTF) {
        if (level == STD_HIGH) {
            	Set_Bit(GPIO_PORTF_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

        }
        else {
            	Clear_Bit(GPIO_PORTF_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
        }
    }


}






/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): channel_id - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/


Dio_LevelType Dio_ReadChannel(Dio_ChannelType channel_id) {
  
    Dio_ChannelType Level = 0;
    if (Dio_PortChannels[channel_id].port_number == PORTA) {
        /* Read the required channel */
        Level = Get_Bit(GPIO_PORTA_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

    }
    if (Dio_PortChannels[channel_id].port_number == PORTB) {
        /* Read the required channel */
        Level = Get_Bit(GPIO_PORTB_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

    }
    if (Dio_PortChannels[channel_id].port_number == PORTC) {
              /* Read the required channel */
       Level = Get_Bit(GPIO_PORTB_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

    }
    if (Dio_PortChannels[channel_id].port_number == PORTD) {
        /* Read the required channel */
        Level = Get_Bit(GPIO_PORTD_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
    
    }
    if (Dio_PortChannels[channel_id].port_number == PORTE) {
              /* Read the required channel */
        Level = Get_Bit(GPIO_PORTE_DATA_REG, (Dio_PortChannels[channel_id].channel_number));

    }
    if (Dio_PortChannels[channel_id].port_number == PORTF) {
        /* Read the required channel */
        Level = Get_Bit(GPIO_PORTF_DATA_REG, (Dio_PortChannels[channel_id].channel_number));
     
    }
    if(Level == STD_HIGH){
    return STD_HIGH;
    }else{
      return STD_LOW;
    }
    
}






/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO port.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a Level of a port.
************************************************************************************/

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level) {

    //DIO_PORTS port = PortId;
    switch (PortId)
    {
    case PORTA: GPIO_PORTA_DATA_REG = level; 	break;
    case PORTB: GPIO_PORTB_DATA_REG = level;	break;
    case PORTC: GPIO_PORTC_DATA_REG = level;	break;
    case PORTD: GPIO_PORTD_DATA_REG = level;	break;
    case PORTE: GPIO_PORTE_DATA_REG = level;	break;
    case PORTF: GPIO_PORTF_DATA_REG = level;	break;
    default: break; /*error*/
    }

}



/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO PORT.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO PORT.
************************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
   // DIO_PORTS port = PortId;
    Dio_PortLevelType Val =0;
    switch (PortId) {
    case PORTA:
        Val = GPIO_PORTA_DATA_REG;
        return Val;
        break;
    case PORTB:
        Val = GPIO_PORTB_DATA_REG;
        return Val;
        break;
    case PORTC:
        Val = GPIO_PORTC_DATA_REG
          ;
        return Val;
        break;
    case PORTD:
        Val = GPIO_PORTD_DATA_REG;
        return Val;
        break;
    case PORTE:
        Val = GPIO_PORTE_DATA_REG;
        return Val;
        break;
    case PORTF:
        Val = GPIO_PORTF_DATA_REG;
        return Val;
        break;
    default: break;
    }
return Val;
}




/************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr Pointer to ChannelGroup / Level Value to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set a subset of the adjoining bits of a port to a specified level
************************************************************************************/

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType level) {

    switch (ChannelGroupIdPtr->DioChannelGroupIdentification)
    {
    case PORTA:
        GPIO_PORTA_DATA_REG = (GPIO_PORTA_DATA_REG & (~(ChannelGroupIdPtr->DioPortMask))) | (level << ChannelGroupIdPtr->DioPortOffset);
       
        break;
    case PORTB:
        GPIO_PORTB_DATA_REG = (GPIO_PORTB_DATA_REG & (~(ChannelGroupIdPtr->DioPortMask))) | (level << ChannelGroupIdPtr->DioPortOffset);
        break;
    case PORTC:
        GPIO_PORTC_DATA_REG = (GPIO_PORTC_DATA_REG & (~(ChannelGroupIdPtr->DioPortMask))) | (level << ChannelGroupIdPtr->DioPortOffset);
        break;
    case PORTD:
        GPIO_PORTD_DATA_REG = (GPIO_PORTD_DATA_REG & (~(ChannelGroupIdPtr->DioPortMask))) | (level << ChannelGroupIdPtr->DioPortOffset);
        break;
    case PORTE:
        GPIO_PORTE_DATA_REG = (GPIO_PORTE_DATA_REG & (~(ChannelGroupIdPtr->DioPortMask))) | (level << ChannelGroupIdPtr->DioPortOffset);
        break;
    case PORTF:
        GPIO_PORTF_DATA_REG = (GPIO_PORTF_DATA_REG & ~(ChannelGroupIdPtr->DioPortMask)) | (level << ChannelGroupIdPtr->DioPortOffset);
        break;
    }
}

/************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr Pointer to ChannelGroup 
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType Level of a subset of the adjoining bits of a por
* Description:  This Service reads a subset of the adjoining bits of a port.
************************************************************************************/




Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){
    
    Dio_PortLevelType Val = 0;
    switch (ChannelGroupIdPtr->DioChannelGroupIdentification) {
    case PORTA:
        Val = (GPIO_PORTA_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;
    case PORTB:
        Val = (GPIO_PORTB_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;

    case PORTC:
        Val = (GPIO_PORTC_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;

    case PORTD:
        Val = (GPIO_PORTD_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;

    case PORTE:
        Val = (GPIO_PORTE_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;

    case PORTF:
        Val = (GPIO_PORTF_DATA_REG & (ChannelGroupIdPtr->DioPortMask)) >> ChannelGroupIdPtr->DioPortOffset;
        return Val;
        break;
    }
    
    return Val;

}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): channel_id - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the Level of a channel and return the Level of the channel after flip.
************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType channel_id){

  if (Dio_PortChannels[channel_id].port_number == PORTA) {
   
    if(Get_Bit(GPIO_PORTA_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTA_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTA_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else if (Dio_PortChannels[channel_id].port_number == PORTB) {
   
    if(Get_Bit(GPIO_PORTB_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTB_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTB_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else if (Dio_PortChannels[channel_id].port_number == PORTC) {
   
    if(Get_Bit(GPIO_PORTC_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTC_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTC_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else if (Dio_PortChannels[channel_id].port_number == PORTD) {
   
    if(Get_Bit(GPIO_PORTD_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTD_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTD_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else if (Dio_PortChannels[channel_id].port_number == PORTE) {
   
    if(Get_Bit(GPIO_PORTE_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTE_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTE_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else if (Dio_PortChannels[channel_id].port_number == PORTF) {
   
    if(Get_Bit(GPIO_PORTF_DATA_REG,Dio_PortChannels[channel_id].channel_number)== STD_HIGH){
    Clear_Bit(GPIO_PORTF_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_LOW;
    }else{
    Set_Bit(GPIO_PORTF_DATA_REG,Dio_PortChannels[channel_id].channel_number);
    return STD_HIGH;
    }
  }
  else{
 return STD_LOW;
  }
  
  

}
#endif

