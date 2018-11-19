#include "LED.h"

void LED_Init() {
	LED_Front_Right_Init();
	LED_Front_Left_Init();
	LED_Back_Right_Init();
	LED_Back_Left_Init();
}

void LED_Front_Right_Init() {
	GPIO_DIR_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, OUTPUT);
}

void LED_Front_Left_Init() {
	GPIO_DIR_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, OUTPUT);
}

void LED_Back_Right_Init() {
	GPIO_DIR_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, OUTPUT);
}

void LED_Back_Left_Init() {
	GPIO_DIR_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, OUTPUT);
}

void LED_ON() {
	LED_Front_Right_On();
	LED_Front_Left_On();
	LED_Back_Right_On();
	LED_Back_Left_On();
}

void LED_Front_Right_On() {
	GPIO_PIN_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, HIGH);
}

void LED_Front_Left_On() {
	GPIO_PIN_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, HIGH);
}

void LED_Back_Right_On() {
	GPIO_PIN_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, HIGH);
}

void LED_Back_Left_On() {
	GPIO_PIN_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, HIGH);
}

void LED_OFF() {
	LED_Front_Right_Off();
	LED_Front_Left_Off();
	LED_Back_Right_Off();
	LED_Back_Left_Off();
}

void LED_Front_Right_Off() {
	GPIO_PIN_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, LOW);
}

void LED_Front_Left_Off() {
	GPIO_PIN_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, LOW);
}

void LED_Back_Right_Off() {
	GPIO_PIN_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, LOW);
}

void LED_Back_Left_Off() {
	GPIO_PIN_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, LOW);
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







void LED_Front_Right_On_Blink() {
		

}


void LED_Front_Left_On_Blink() {

}

void LED_Back_Right_On_Blink() {
}

void LED_Back_Left_On_Blink() {
}


