#include "LPC407x_8x_177x_8x.h"
#include "Library/GPIO.h"
#include "Library/PWM.h"
#include "Library/Timer.h"
#include "Library/LED.h"
#include "Library/Joystick.h"
#include "Library/MotorController.h"
#include "Library/Controller.h"
#include "Library/Parameters.h"



	#define IN1	*((volatile uint32_t *) 0x4002C024)
#define IN2	*((volatile uint32_t *) 0x4002C020)
#define IN3	*((volatile uint32_t *) 0x4002C01C)
#define IN4	*((volatile uint32_t *) 0x4002C018)



void init() {
	
	//	LED_Init();	
	PWM_Init();
	Joystick_Init();
	Timer_Init();
	MotorController_Init();
	
	IN1  &= ~(7);
	IN2  &= ~(7);
	IN3  &= ~(7);
	IN4  &= ~(7);



	

	
LED_OFF();
uint32_t func =PORT0->PIN;
func|= MC_IN1_MASK |MC_IN2_MASK | MC_IN3_MASK | MC_IN4_MASK; 
PORT0->PIN=func;
	
	
	
}
/* 
Joystick up: Forward
Joystick down: Backward
Joystick right: 90 degree right (CW)
Joystick left: 90 degree left (CCW)
Joystick center: Stop
*/

uint32_t kamil=0;

void update() {	
	
	PWM_Write(100,1);
	PWM_Write(100,2);
	PWM_Cycle_Rate(500);
	//LED_OFF();
//MC_Set_Direction_Forward();
	
	
	if (Joystick_Up_Pressed()) {
		kamil=1;
		Led_Motor_Forward();
	}else if (Joystick_Right_Pressed()) {	
		kamil=2;
		Led_Motor_Right();
	}else if (Joystick_Center_Pressed()) {
		kamil=3;
		Led_Motor_Stop();
	}else if (Joystick_Left_Pressed()) {
		kamil=4;
		Led_Motor_Left();
	}else if (Joystick_Down_Pressed()) {
		kamil=5;
		Led_Motor_Backward();
	}
}

int main() {
	init();
	while(1) {
		update();
	}
}
