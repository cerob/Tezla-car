#include "Controller.h"


void Led_Motor_Forward(){
	// Sets Flags
	Set_Forward_Flag();
	// Front-Left and Front-Right LEDs turned on and the other LEDs turned off
	LED_Forward();
	// Car starts to travel in forward direction
	MC_Set_Direction_Forward();
}
void Led_Motor_Backward(){
	// Sets Flags
	Set_Backward_Flag();
	// Back-Left and Back-Right LEDs turned on and the other LEDs turned off
	LED_Backward();
	// Car starts to travel in backward direction
	MC_Set_Direction_Backward();		
}
void Led_Motor_Stop(){
	// Sets Flags
	Reset_Flags();
	// All LEDs turned off
	LED_OFF();
	// Car stops
	MC_Stop_Brakes();
}
void Led_Motor_Right(){
	// Sets Flags
	Set_Turn_Right_Flag();
	// Front-Right and Back-Right LEDs turned on and the other LEDs turned off.
	LED_Right();
	// Car starts to rotate 90 degree in clockwise direction 
	MC_Set_Direction_Right();
}
void Led_Motor_Left(){
	// Sets Flags
	Set_Turn_Left_Flag();
	// Front-Left and Back-Left LEDs turned on and the other LEDs turned off.
	LED_Left();
	// Car starts to rotate 90 degree in counter-clockwise direction 
	MC_Set_Direction_Left();
}
