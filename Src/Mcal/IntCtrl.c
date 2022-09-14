/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : static void IntCtrl_Set_Priority(void)                                      
* \Description     : set the group and sub priority for an interrupt                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//uint8 localu8Priority;
//uint8 localByteAccess;
static void IntCtrl_Set_Priority(void)
{
	APINT = PRIORITY_GROUP_SUB;

	uint8 localu8Priority = (Int_Config.sub_Priority) | (Int_Config.groub_priority<<((PRIORITY_GROUP_SUB - PRIORITY_GROUP3_SUB0)/256));  //256 = 0x100
	uint8 localByteAccess = (Int_Config.int_Num/8) + 1 ;
	if(Int_Config.int_Num>=0)
	{
		PRI[localByteAccess] = localu8Priority << 5 ;
	}
}


/******************************************************************************
* \Syntax          : static void IntCtrl_Pending_State(void)                                      
* \Description     : clear or set the pending flag                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void IntCtrl_Pending_State(void)
{
	uint8 localByteAccess = (Int_Config.int_Num/32) + 1 ;
	uint8 localBitAccess = (Int_Config.int_Num % 32);
	switch(Int_Config.pending_Flag)
	{
		case ENABLE :
			PEND[localByteAccess] |= (1 << localBitAccess);
			break;
		
		case DISABLE :
			UNPEND[localByteAccess] |= (1 << localBitAccess);
			break;
	}
}


/******************************************************************************
* \Syntax          : static void IntCtrl_Int_State(void)                                      
* \Description     : enable or disable an interrupt                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void IntCtrl_Int_State(void)
{
	uint8 localByteAccess = (Int_Config.int_Num / 32) + 1 ;
	uint8 localBitAccess = (Int_Config.int_Num % 32) ;
	switch(Int_Config.int_State)
	{
		case ENABLE :
			EN[localByteAccess] |= (1 << localBitAccess);
			break;
		
		case DISABLE :
			DIS[localByteAccess] |= (1 << localBitAccess);
			break;
	}
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    IntCtrl_Set_Priority();
    
	/*TODO : Enable/Disable pending flag */
	IntCtrl_Pending_State();
	
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	IntCtrl_Int_State();

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/