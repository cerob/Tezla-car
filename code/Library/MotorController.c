
#include "MotorController.h"

void MotorController_Init() {
	
	
	uint32_t func =PORT0->DIR;
 func|= MC_IN1_MASK |MC_IN2_MASK | MC_IN3_MASK | MC_IN4_MASK; 
PORT0->DIR=func;
	
	
	
	
}

void MC_Set_Direction_Forward() {
	
	
uint32_t func =PORT0->PIN;
func|= MC_IN1_MASK |MC_IN3_MASK ;
func &= ~(MC_IN2_MASK);
func &= ~(MC_IN4_MASK);
PORT0->PIN=func;
	
	
}


		
//	if(TIMER3->CR0>a_currentTime){
//     a_previousTime=a_currentTime;
//    a_currentTime=TIMER3->CR0;
//    a_capturedTime= a_currentTime-a_previousTime;   
//	}
		
void MC_Set_Turning(){
	uint32_t counter =0;

	while(counter<ROTATION_NUMBER_FOR_90_DEGREE){
	
		if(TIMER3->CR0>a_currentTime){
     a_previousTime=a_currentTime;
    a_currentTime=TIMER3->CR0;
    a_capturedTime= a_currentTime-a_previousTime;   
		counter++;
		}
	}
	MC_Stop_Brakes();	
	counter=0;
	
}

void MC_Set_Direction_Right() {
	


	
		uint32_t func =PORT0->PIN;
func|= MC_IN1_MASK |MC_IN4_MASK ;
func &= ~(MC_IN2_MASK);
func &= ~(MC_IN3_MASK);
PORT0->PIN=func;
	
	
	MC_Set_Turning();
	
}


void MC_Set_Direction_Left() {
	
uint32_t func =PORT0->PIN;
func|= MC_IN2_MASK |MC_IN3_MASK ;
func &= ~(MC_IN1_MASK);
func &= ~(MC_IN4_MASK);
PORT0->PIN=func;
	
	MC_Set_Turning();

}



void MC_Set_Direction_Backward() {
	
uint32_t func =PORT0->PIN;
func|= MC_IN2_MASK |MC_IN4_MASK ;
func &= ~(MC_IN1_MASK);
func &= ~(MC_IN3_MASK);
PORT0->PIN=func;
	
}

void MC_Stop_Brakes() {
		
	uint32_t func =PORT0->PIN;
 func|= MC_IN1_MASK |MC_IN2_MASK | MC_IN3_MASK | MC_IN4_MASK; 
PORT0->PIN=func;
	
	
}
