#include "LED.h"
#include "PWM.h"

void LED_ON() {
	LED_Front_Right_On();
	LED_Front_Left_On();
	LED_Back_Right_On();
	LED_Back_Left_On();
}

	

void LED_Front_Right_On() {
	PWM_Write(100,3);

	
}

void LED_Front_Left_On() {
	PWM_Write(100,4);	
}

void LED_Back_Right_On() {
	PWM_Write(100,5);
}

void LED_Back_Left_On() {
	PWM_Write(100,6);
}

void LED_OFF() {
	LED_Front_Right_Off();
	LED_Front_Left_Off();
	LED_Back_Right_Off();
	LED_Back_Left_Off();
}

void LED_Front_Right_Off() {
	PWM_Write(0,3);

}

void LED_Front_Left_Off() {
	PWM_Write(0,4);	
}

void LED_Back_Right_Off() {
	PWM_Write(0,5);
}

void LED_Back_Left_Off() {
	PWM_Write(0,6);
}

void LED_Forward(void) {
	LED_Front_Right_On();
	LED_Front_Left_On();
	LED_Back_Right_Off();
	LED_Back_Left_Off();
}

void LED_Backward(void) {
	LED_Front_Right_Off();
	LED_Front_Left_Off();
	LED_Back_Right_On();
	LED_Back_Left_On();
}

void LED_Right(void) {
	
	
	LED_Front_Right_On();
	LED_Front_Left_Off();
	LED_Back_Right_On();
	LED_Back_Left_Off();
}

void LED_Left(void) {
	LED_Front_Right_Off();
	LED_Front_Left_On();
	LED_Back_Right_Off();
	LED_Back_Left_On();
}


