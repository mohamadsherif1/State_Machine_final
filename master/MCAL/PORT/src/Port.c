 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Team 1
 ******************************************************************************/

#include "../inc/Port.h"

volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

 const Port_Pin_Type * Port_Confg = NULL_PTR;

 uint8 Port_Status = PORT_NOT_INITIALIZED;

 
 
/************************************************************************************
* Service Name: Port_Init
*Service ID[hex]:0x01
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    volatile uint32 delay = STD_OFF;
   // SYSCTL_REGCGC2_REG |= clock_mask;
    
   
    Port_Status =PORT_INITIALIZED;  // DONE
    uint8 PIN_Index =0;
              
    Port_Confg =  ConfigPtr->Pins;
    for(PIN_Index=0 ;PIN_Index <= PORT_CONFIGURED_CHANNLES ;PIN_Index++)
    {
      Port_PortType port_NO = Port_Confg[PIN_Index].port_num; 
      Port_PinType pin_NO = Port_Confg[PIN_Index].pin_num;
      Port_PinModeType pin_Mode = Port_Confg[PIN_Index].PinMode;
      
      
      SYSCTL_REGCGC2_REG |= (1<<port_NO); // ENABLE THE CLOCK
       delay = SYSCTL_REGCGC2_REG; 
       
       
        if(((port_NO == 3) && ( pin_NO== 7)) || ((port_NO == 5) && ( pin_NO == 0))) /* PD7 or PF0 */
     {
        GPIO_LOCK(port_NO)= 0x4C4F434B;                         /* Unlock the GPIOCR register */ 
        Set_Bit(GPIO_CR(port_NO),pin_NO);/* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        
     }
     
     
     
     /*********************** DIO MODE  ***************************/
     if(pin_Mode == PORT_PIN_MODE_DIO){
     // clearing the bit to disable alternative function by clearing the GPIOAFSEL Register 
       Clear_Bit(GPIO_ALT(port_NO),pin_NO);
       Clear_Bit(GPIO_CTL(port_NO),pin_NO);
       
        Set_Bit(GPIO_CR(port_NO),pin_NO);
        
       /**********************OUT PUT MODE   ***************************/

        if(Port_Confg[PIN_Index].direction == PORT_PIN_OUT){
          
     Set_Bit(GPIO_DIR(port_NO),pin_NO);
     Clear_Bit(GPIO_ANALOG(port_NO),pin_NO);
     
     if(Port_Confg[PIN_Index].Digital_Value == DIGITAL_MODE){    
       
     Set_Bit(GPIO_DEN(port_NO),pin_NO);
     
     }if(Port_Confg[PIN_Index].initial_value == STD_HIGH){
     Set_Bit(GPIO_DATA(port_NO),pin_NO);
     }if(Port_Confg[PIN_Index].initial_value == STD_LOW){
     Clear_Bit(GPIO_DATA(port_NO),pin_NO);
     }
        }
        /**********************IN PUT MODE   ***************************/
       
        if(Port_Confg[PIN_Index].direction == PORT_PIN_IN){
         Clear_Bit(GPIO_DIR(port_NO),pin_NO);

         Clear_Bit(GPIO_ANALOG(port_NO),pin_NO);
          if(Port_Confg[PIN_Index].Digital_Value == DIGITAL_MODE){    
       
         Set_Bit(GPIO_DEN(port_NO),pin_NO);
          }
          if(Port_Confg[PIN_Index].initial_value == STD_LOW){
     Clear_Bit(GPIO_DATA(port_NO),pin_NO);
     }
          if(Port_Confg[PIN_Index].resistor == PULL_DOWN){
            
            Set_Bit(GPIO_PULL_DOWN(port_NO),pin_NO);
          
          }else if(Port_Confg[PIN_Index].resistor == PULL_UP){
          Set_Bit(GPIO_PULL_UP(port_NO),pin_NO);
          }else{
          Clear_Bit(GPIO_PULL_DOWN(port_NO),pin_NO);
          Clear_Bit(GPIO_PULL_UP(port_NO),pin_NO);
          }
          
          
        }
     }
     
     /*********************** DIO MODE END  ***************************/
    
    
    }
}



#if (PORT_SET_PIN_DIRECTION_API)
/************************************************************************************
* Service Name: Port_SetPinDirection
*Service ID[hex]:0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin : Port pin ID number
                   Direction : Port pin direction 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set the port pin direction 
************************************************************************************/

void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
 {
       
     volatile uint32 *Port_Address =NULL_PTR ;
     volatile uint32 delay = 0;
    
	boolean error = FALSE;
       switch(Port_Confg[Pin].port_num)
    {
    case PORTA: 
      Port_Address = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS;         // PORT A Base Address
      break; 
      
      case PORTB: 
      Port_Address = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS;        // PORT B Base Address
      break; 
      
      case PORTC: 
      Port_Address = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS;        // PORT C Base Address
      break; 
      
      case PORTD: 
      Port_Address = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS;        // PORT D Base Address
      break; 
      
      case PORTE: 
      Port_Address = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS;        // PORT E Base Address
      break; 
      
      case PORTF: 
      Port_Address = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS;        // PORT F Base Address
      break; 
    }
  
      if(Direction == PORT_PIN_IN)
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address+PORT_DIR_REG_OFFSET),Pin);    // clear bit to be Input
      
      }
      
        if(Direction == PORT_PIN_OUT)
      {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address+PORT_DIR_REG_OFFSET),Pin);    // Set bit to be Output
      
      }
         
  } 
 
#endif






#if(Port_RefreshPortDirection_API)
/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]:0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): Versioninfo , Pointer to where to store the version information of this module.
* Return value: None
* Description: Set the port pin direction 
************************************************************************************/


void Port_RefreshPortDirection(void)
{
  for(int i=0;i<PORT_CONFIGURED_CHANNLES;i++)
        {
          if((Port_Confg[i].port_num == 2) && (Port_Confg[i].pin_num <= 3))
           {
             /* Do nothing JTAG pins*/
                continue;
           }
      else if (Port_Confg[i].ChangableDierction==PORT_PIN_DIR_UNCHANGEABLE)
           {
    switch(Port_Confg->port_num)
    {
    case 0: 
      Port_Address = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS;         // PORT A Base Address
      break; 
      
      case 1: 
      Port_Address = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS;        // PORT B Base Address
      break; 
      
      case 2: 
      Port_Address = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS;        // PORT C Base Address
      break; 
      
      case 3: 
      Port_Address = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS;        // PORT D Base Address
      break; 
      
      case 4: 
      Port_Address = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS;        // PORT E Base Address
      break; 
      
      case 5: 
      Port_Address = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS;        // PORT F Base Address
      break; 
    }
    if(Port_Confg[i].direction==PORT_PIN_OUT)        
      {
                /* Set bit to be Output*/
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address+PORT_DIR_REG_OFFSET),Port_Confg[i].pin_num);   
      }
    
     else if(Port_Confg[i].direction==PORT_PIN_IN)        
      {
                 /* Set bit to be Input*/
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address+PORT_DIR_REG_OFFSET),Port_Confg[i].pin_num);    
      }
           }
     
    
    else 
    {
    
    }
}
}

#endif






#if (PORT_VERSION_INFO_API==STD_ON)
/************************************************************************************
* Service Name: Port_GetVersionInfo
*Service ID[hex]:0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): Versioninfo , Pointer to where to store the version information of this module.
* Return value: None
* Description: Set the port pin direction 
************************************************************************************/

void Port_GetVersionInfo(const Std_VersionInfoType* versioninfo)
{
#if(PORT_DEV_ERROR_DETECT == STD_ON)
  
    if(NULL_PTR == versioninfo)
    {
     Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				Port_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    
    }
    else
    {
#endif
      (*(uint16*)versioninfo->vendorID) = (uint16)PORT_VENDOR_ID;
      (*(uint16*)versioninfo->moduleID) = (uint16)PORT_MODULE_ID; 
      (*(uint8*)versioninfo->sw_major_version) = PORT_SW_MAJOR_VERSION;
      (*(uint8*)versioninfo->sw_minor_version) = PORT_SW_MINOR_VERSION;
      (*(uint8*)versioninfo ->sw_patch_version) = PORT_SW_PATCH_VERSION;
    }
}
#endif




#if(Port_SetPinMode_API)
/************************************************************************************
* Service Name: Port_SetPinMode
*Service ID[hex]:0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant 
* Parameters (in): Pin : Port pin ID number
* Mode : New Port pin Mode om port pin 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set the port pin Mode 
************************************************************************************/

 void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
    {
             
     volatile uint32 *Port_Address =NULL_PTR ;
     volatile uint32 delay = 0;
    
     boolean error = FALSE;


    switch(Port_Confg[Pin].port_num)
    {
      case PORTA: 
      Port_Address = (volatile uint32*) GPIO_PORTA_BASE_ADDRESS;         // PORT A Base Address
      break; 
      
      case PORTB: 
      Port_Address = (volatile uint32*) GPIO_PORTB_BASE_ADDRESS;        // PORT B Base Address
      break; 
      
      case PORTC: 
      Port_Address = (volatile uint32*) GPIO_PORTC_BASE_ADDRESS;        // PORT C Base Address
      break; 
      
      case PORTD: 
      Port_Address = (volatile uint32*) GPIO_PORTD_BASE_ADDRESS;        // PORT D Base Address
      break; 
      
      case PORTE: 
      Port_Address = (volatile uint32*) GPIO_PORTE_BASE_ADDRESS;        // PORT E Base Address
      break; 
      
      case PORTF: 
      Port_Address = (volatile uint32*) GPIO_PORTF_BASE_ADDRESS;        // PORT F Base Address
      break; 
    }
    
    if(Mode == Mode0)
       {
           // clearing the bit to disable alternative function by clearing the GPIOAFSEL Register 
     
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address + (PORT_ALT_FUNC_REG_OFFSET)) , Pin);  
          // clear the PMCx bits for this pins 
         *(volatile uint32 *)((volatile uint8 *)Port_Address + PORT_CTL_REG_OFFSET) &= ~(0X0000000F << (Pin * 4));
       }
    
    else 
    {
      // Setting the bit to enable alternative function by clearing the GPIOAFSEL Register 
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Address + (PORT_ALT_FUNC_REG_OFFSET)) ,Pin);  
        // clear the PMCx bits for this pins 
         *(volatile uint32 *)((volatile uint8 *)Port_Address + PORT_CTL_REG_OFFSET) &= ~(0X0000000F << (Pin * 4)); 
         // Set the PMCx bit for this pin
        *(volatile uint32 *)((volatile uint8 *)Port_Address + PORT_CTL_REG_OFFSET) |= (Mode&One_Byte_Mask << (Pin * 4));      
    
    }
    
        if(Port_Confg[Pin].Digital_Value == Digital_Pin)  
    {
        /* Clear bit to disable Analog Function */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),Pin);    
       
       /* Set bit to enable Digital function  */
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),Pin);       
    }
    else  if(Port_Confg[Pin].Digital_Value == Analog_Pin) 
    {
      /* Clear bit to disable digital Function */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),Pin);      
      
       /* Set bit to enable Analog function  */
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),Pin);    
      
    }
    
    else 
    {
     /* Do Nothing */ 
    }

  }     
#endif