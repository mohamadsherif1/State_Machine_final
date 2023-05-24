 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver Registers
 *
 * Author: Team 1
 ******************************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H
/*******************************************************************************
                        GPIO Registers offset macro                                   
 *******************************************************************************/ 
   
   
#define GPOIO_OFFSET(x)  (x<4?((0x40004000) + ((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))
   
/*******************************************************************************
                        GPIO Registers offset addresses                                    
 *******************************************************************************/ 
/* GPIO Registers base addresses */
/*
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000
*/

#define GPIO_DATA(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0X3FC))
#define GPIO_DIR(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x400))
#define GPIO_ALT(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x420))
#define GPIO_PULL_UP(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x510))
 #define GPIO_PULL_DOWN(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x514))  
#define GPIO_DEN(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x51C))
#define GPIO_LOCK(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x520))
#define GPIO_CR(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x524))
#define GPIO_ANALOG(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x528))
#define GPIO_CTL(x)   *(volatile uint32 *)((volatile uint8 *)(GPOIO_OFFSET(x)+ 0x52C))
 



/*******************************************************************************
                        Clock Registers                                    
 *******************************************************************************/ 

#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))


#endif /* PORT_REGS_H */