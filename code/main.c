#include "LPC407x_8x_177x_8x.h"

#include "Library/GPIO.h"
#include "Library/LED.h"
#include "Library/PWM.h"
#include "Library/Timer.h"
#include "Library/Joystick.h"
#include "Library/MotorController.h"
#include "Parameters.h"

void init() {
	LED_Init();
	//Timer_Init();
	//Joystick_Init();
	//MotorController_Init();
	
//	PWM_Init();
	//PWM_Write(0);
}

/* 
Joystick up: Forward
Joystick down: Backward
Joystick right: 90 degree right (CW)
Joystick left: 90 degree left (CCW)
Joystick center: Stop
*/
void update() {
	if (Joystick_Up_Pressed()) {
		Set_Forward_Flag();
		LED_Forward();
		MC_Set_Direction_Forward();
		
	}
	else if (Joystick_Down_Pressed()) {
		Set_Backward_Flag();
		LED_Backward();
		MC_Set_Direction_Backward();
		
	}
	else if (Joystick_Right_Pressed()) {
		Set_Turn_Right_Flag();
		LED_Right(); // TODO: blink 2 times in a second
		MC_Set_Direction_Forward();
		
	}
	else if (Joystick_Left_Pressed()) {
		Set_Turn_Left_Flag();
		LED_Left(); // TODO: blink 2 times in a second
		MC_Set_Direction_Forward();
		
	}
	else if (Joystick_Center_Pressed()) {
		Reset_Flags();
		LED_OFF();
		MC_Stop_Brakes();
	}
}

int main() {
	init();
	
	while(1) {
		update();
	}
}
