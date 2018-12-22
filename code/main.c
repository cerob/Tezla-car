#include "LPC407x_8x_177x_8x.h"
#include "Library/GPIO.h"
#include "Library/PWM.h"
#include "Library/Timer.h"
#include "Library/LED.h"
#include "Library/Joystick.h"
#include "Library/MotorController.h"
#include "Library/Controller.h"
#include "Library/Parameters.h"

// Stores half second
#define SECOND 500000
 
void init() {
	//initilaze led
	LED_Init();	
	PWM_Init();
	Joystick_Init();
	Timer_Init();
	MotorController_Init();	
}

// Stores last continued movement
uint32_t whichLed=0;
// Stores # of turn if car turns right or left
uint32_t counter=0;

void update() {
	// Control car is turning or not
	if(whichLed==4 || whichLed==2){
		// If car does not turn 90 degree, continue turning
		if(counter<ROTATION_NUMBER_FOR_90_DEGREE){
			// If timer3 capture faling or rising edge we inrease counter
			if((TIMER3->CR0)>a_currentTime){			 
				a_currentTime=TIMER3->CR0;
				counter++;
			}
		}
		// If car turn 90 degree, stop 
		else{
			// We stop motor and led
			Led_Motor_Stop();
			// We reset counter and which movement 
			counter=0;
			whichLed=0;
		}
	}	
	
	// Check joystick up button is pressed or not
	if (Joystick_Up_Pressed()) {
		// Set which movement
		whichLed=1;
		// Car start to travel in forward direction, sets flags and 
		// Front-Left and Front-Right LEDs turned on and the other LEDs turned off.
		Led_Motor_Forward();
		// We reset counter
		counter=0;
	}
	// Check joystick right button is pressed or not
	else if (Joystick_Right_Pressed()) {	
		// Set which movement		
		whichLed=2;
		// Sets Flags, Front-Right and Back-Right LEDs turned on and the other LEDs turned off,
		// Car starts to rotate 90 degree in clockwise direction 		
		Led_Motor_Right();
		// We reset counter
		counter=0;
	}
	// Check joystick center button is pressed or not
	else if (Joystick_Center_Pressed()) {
		// Set which movement
		whichLed=3;
		// Sets Flags, All LEDs turned off, Car stops
		Led_Motor_Stop();
		// We reset counter
		counter=0;
	}
	// Check joystick left button is pressed or not
	else if (Joystick_Left_Pressed()) {
		// Set which movement
		whichLed=4;
		// Sets Flags, Front-Left and Back-Left LEDs turned on and the other LEDs turned off.
		// Car starts to rotate 90 degree in counter-clockwise direction 
		Led_Motor_Left();
		// We reset counter
		counter=0;
	}
	// Check joystick down button is pressed or not
	else if (Joystick_Down_Pressed()) {
		// Set which movement
		whichLed=5;
		// Sets Flags, Back-Left and Back-Right LEDs turned on and the other LEDs turned off
		// Car starts to travel in backward direction
		Led_Motor_Backward();
		// We reset counter
		counter=0;
	}
	// If car continiues turning right, blink
	if(whichLed==2){
		// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
		// It satisfied blink
		if(TIMER3->TC%SECOND<SECOND/2){
			LED_Right();
		}
		else{
			LED_OFF();
		}
	}
	// If car continiues turning left, blink
	if(whichLed==4){
		// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
		// It satisfied blink
		if(TIMER3->TC%SECOND<SECOND/2){
			LED_Left();
		}
		else{
			LED_OFF();
		}
	}
}
 
int main() {
    init();
    while(1) {
      update();
    }
}
