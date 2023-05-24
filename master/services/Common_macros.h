#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H


#include <stdbool.h>
#include <stdint.h>

/* Set a certain bit in any register */
#define Set_Bit(Register,bit)   	Register|=(1<<bit)

/* Clear a certain bit in any register */
#define Clear_Bit(Register,bit) 	Register&=~(1<<bit)

/* Toggle a certain bit in any register */
#define Toggle_Bit(Register,Bit)	Register ^=(1<<Bit)

/* get a certain bit in any register */
#define Get_Bit(Reg,Bit)        	((Reg>>Bit)&1)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG = (REG>>num) | (REG << ((sizeof(REG) * 8)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG = (REG<<num) | (REG >> ((sizeof(REG) * 8)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )




#endif