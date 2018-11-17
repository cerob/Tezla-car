#include "MotorController.h"

void MotorController_Init() {
	GPIO_DIR_Write(PORT0, MC_IN1_MASK, 1);
	GPIO_DIR_Write(PORT0, MC_IN2_MASK, 1);
	GPIO_DIR_Write(PORT0, MC_IN3_MASK, 1);
	GPIO_DIR_Write(PORT0, MC_IN4_MASK, 1);	
}

void MC_Set_Direction_Forward() {
	GPIO_PIN_Write(PORT0, MC_IN1_MASK, 1);
	GPIO_PIN_Write(PORT0, MC_IN2_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN3_MASK, 1);
	GPIO_PIN_Write(PORT0, MC_IN4_MASK, 0);
}

void MC_Set_Direction_Backward() {
	GPIO_PIN_Write(PORT0, MC_IN1_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN2_MASK, 1);
	GPIO_PIN_Write(PORT0, MC_IN3_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN4_MASK, 1);
}

void MC_Stop_Brakes() {
	GPIO_PIN_Write(PORT0, MC_IN1_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN2_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN3_MASK, 0);
	GPIO_PIN_Write(PORT0, MC_IN4_MASK, 0);	
}