/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERIPHERAL_BASE_ADDRESS             0XE000E000
/***********************************************SCB registers************************************************/
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0xD04))

/***********************************************NVIC registers***********************************************/
#define EN																			((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x100))
#define DIS																			((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x180))
#define PEND																		((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x200))
#define UNPEND																	((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x280))
#define ACTIVE																	((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x300))
#define PRI																			((volatile uint8*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x400))
#define SWTRIG																 *((volatile uint32*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0xF00))

/***********************************************RCC registers***********************************************/
#define SYSTEM_CONTROL_BASE_ADDRESS             0x400FE000






/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/