#include "Controller.h"

void Led_Motor_Forward(){
	Set_Forward_Flag();
	LED_Forward();
	MC_Set_Direction_Forward();
}
void Led_Motor_Backward(){
	Set_Backward_Flag();
	LED_Backward();
	MC_Set_Direction_Backward();		
}
void Led_Motor_Stop(){
	Reset_Flags();
	LED_OFF();
//	MC_Stop_Brakes();
}
void Led_Motor_Right(){
	Set_Turn_Right_Flag();
	LED_Right();
	//MC_Set_Direction_Right();
}
void Led_Motor_Left(){
	Set_Turn_Left_Flag();
	LED_Left();
	//MC_Set_Direction_Left();
}
