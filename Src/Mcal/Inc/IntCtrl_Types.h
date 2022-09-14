/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
GPIOA=0 , GPIOB , GPIOC , GPIOD , GPIOE , UART0 , UART1 , SSI0 ,I2C0 , PWM0_FAULT , PWM0_GENERATOR0 , 
PWM0_GENERATOR1 , PWM0_GENERATOR2 , QEI0 , ADC0_SEQUENCE0 , ADC0_SEQUENCE1 ,ADC0_SEQUENCE2 , ADC0_SEQUENCE3 , 
WDT0_1 , _16_32_TIMER0A , _16_32_TIMER0B , _16_32_TIMER1A , _16_32_TIMER1B , _16_32_TIMER2A ,_16_32_TIMER2B , AC0 , 
AC1 , SYSTEM_CONTROL=28 , FLASH_AND_EEPROM_CONTROL , GPIOF , UART2=33 , SSI1 ,_16_32_TIMER3A , _16_32_TIMER3B , 
I2C1 , QEI1 , CAN0 , CAN1 , HIBERNATION_MODULE=43 , USB ,PWM_GENERATOR3 , DMA_SOFTWARE , DMA_ERROR , ADC1_SEQUENCE0 , 
ADC1_SEQUENCE1 , ADC1_SEQUENCE2 , ADC1_SEQUENCE3 , SSI2=57 ,SSI3 , UART3 , UART4 , UART5 , UART6 , UART7 , 
I2C2=68 , I2C3 ,_16_32_TIMER4A , _16_32_TIMER4B , _16_32_TIMER5A=92 , _16_32_TIMER5B , _32_64_TIMER0A , 
_32_64_TIMER0B , _32_64_TIMER1A , _32_64_TIMER1B ,_32_64_TIMER2A , _32_64_TIMER2B , _32_64_TIMER3A , 
_32_64_TIMER3B , _32_64_TIMER4A , _32_64_TIMER4B , _32_64_TIMER5A , _32_64_TIMER5B ,
SYSTEM_EXCEPTION , PWM1_GENERATOR0=134 , PWM1_GENERATOR1 , PWM1_GENERATOR2 , PWM1_GENERATOR3 , PWM1_FAULT
}IntCtrl_InterruptType;

typedef enum
{
Reset=1 , NMI , HARD_FAULT , MEMORY_MANAGEMENT , BUS_FAULT , USAGE_FAULT , SVCALL=11 , DEBUG_MONITOR ,
PENDSV=14 , SYSTICK
}ExcepCtrl_ExceptiontType;


 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/