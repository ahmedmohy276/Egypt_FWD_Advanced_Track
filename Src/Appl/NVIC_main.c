
#include "Std_Types.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Types.h"

int main(void)
{
//	Int_Config.int_Num = GPIOA;
//	Int_Config.groub_priority = 1;
//	Int_Config.sub_Priority = 0;
//	Int_Config.int_State = ENABLE;
//	Int_Config.pending_Flag = ENABLE;
//	IntCrtl_Init();
	
//	Int_Config.int_Num = GPI OB;
//	Int_Config.groub_priority = 3;
//	Int_Config.sub_Priority = 1;
//	Int_Config.int_State = ENABLE; 
//	Int_Config.pending_Flag = ENABLE;
//	IntCrtl_Init();
	
	Int_Config.int_Num = UART5;
	Int_Config.groub_priority = 2;
	Int_Config.sub_Priority = 1;
	Int_Config.int_State = ENABLE;
	Int_Config.pending_Flag = DISABLE;
	IntCrtl_Init();
	
	while(1)
	{
		IntCrtl_Init();
	}
	
	return 0;
}