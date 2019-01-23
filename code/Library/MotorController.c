#include "MotorController.h"

// Initilaze Motor Controller
void MotorController_Init()
{
	// Set direction of corresponding IN pins as out
	uint32_t func = PORT0->DIR;
	func |= MC_IN1_MASK;
	func |= MC_IN2_MASK;
	func |= MC_IN3_MASK;
	func |= MC_IN4_MASK;
	PORT0->DIR = func;
	// Stop motors
	uint32_t func2 = PORT0->PIN;
	func2 &= ~(MC_IN1_MASK);
	func2 &= ~(MC_IN2_MASK);
	func2 &= ~(MC_IN3_MASK);
	func2 &= ~(MC_IN4_MASK);
	PORT0->PIN = func2;
	// Set motor speed
	PWM_WriteLeft(ROBOT_SPEED);
	PWM_WriteRight(ROBOT_SPEED);
}
// Set direction of motorA and motorB as forward
void MC_Set_Direction_Forward()
{
	uint32_t func = PORT0->PIN;
	func |= MC_IN1_MASK;
	func |= MC_IN3_MASK;
	func &= ~(MC_IN2_MASK);
	func &= ~(MC_IN4_MASK);
	PORT0->PIN = func;
}
// Set direction of motorA as forward and motorB as backward
void MC_Set_Direction_Right()
{
	uint32_t func = PORT0->PIN;
	func |= MC_IN1_MASK;
	func |= MC_IN4_MASK;
	func &= ~(MC_IN2_MASK);
	func &= ~(MC_IN3_MASK);
	PORT0->PIN = func;
}
// Set direction of motorA as backward and motorB as forward
void MC_Set_Direction_Left()
{
	uint32_t func = PORT0->PIN;
	func |= MC_IN2_MASK;
	func |= MC_IN3_MASK;
	func &= ~(MC_IN1_MASK);
	func &= ~(MC_IN4_MASK);
	PORT0->PIN = func;
}
// Set direction of motorA and motorB as backward
void MC_Set_Direction_Backward()
{
	uint32_t func = PORT0->PIN;
	func |= MC_IN2_MASK;
	func |= MC_IN4_MASK;
	func &= ~(MC_IN1_MASK);
	func &= ~(MC_IN3_MASK);
	PORT0->PIN = func;
}
// Stops motors
void MC_Stop_Brakes()
{
	uint32_t func = PORT0->PIN;
	func &= ~(MC_IN1_MASK);
	func &= ~(MC_IN2_MASK);
	func &= ~(MC_IN3_MASK);
	func &= ~(MC_IN4_MASK);
	PORT0->PIN = func;
}
