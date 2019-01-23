#include "LPC407x_8x_177x_8x.h"
#include "Library/GPIO.h"
#include "Library/PWM.h"
#include "Library/Timer.h"
#include "Library/LED.h"
#include "Library/Joystick.h"
#include "Library/MotorController.h"
#include "Library/Ultrasonic.h"
#include "Library/Controller.h"
#include "Library/Parameters.h"
#include "Library/Serial.h"
//#include "Library/Wait.h"
//#include "Library/DrivingMode.h"
#include "Library/ADC.h"
#include "Library/External.h"

// Stores half second
#define SECOND 500000

typedef enum
{
	false,
	true
} bool;

void init()
{
	LED_Init();
	PWM_Init();
	Joystick_Init();
	Timer_Init();
	ADC_Init();
	Serial_Init();

	MotorController_Init();
	Ultrasonic_Trigger_Timer_Init();
	Ultrasonic_Capture_Timer_Init();
	External_Init();
}

bool isApproachedTo15 = false;

// Stores last continued movement
uint32_t whichDirection = 0;
// Stores # of turn if car turns right or left
uint32_t counter = 0;
uint32_t TrimpotDataValue;
uint32_t LDRDataRight;
uint32_t LDRDataLeft;
uint32_t inflateLeft = 0;
uint32_t inflateRight = 0;
uint32_t inflatedSpeed = 0;

uint32_t inflateLeftMax = 0;
uint32_t inflateRightMax = 0;

uint32_t kamil;
uint32_t runLDR=0;

void update()
{
	Ultrasonic_Start_Trigger();
	
	TrimpotDataValue = ADC_Read0();
	LDRDataRight = ADC_Read();
	LDRDataLeft = ADC_Read2();
	//kamil = ultrasonicSensorDistance;
	if(comebackManuel==1){
		whichDirection=0;
		comebackManuel=0;
	}	
	if(DriveMode==0){
		//Serial_WriteData('+');
		PWM_WriteLeft(TrimpotDataValue);
		PWM_WriteRight(TrimpotDataValue);
		//WHILE IN FORWARD DIRECTION
		if (whichDirection == 1){
			if (LDRDataLeft < 450){
				runLDR=1;
				Led_Motor_Right();
			}else if (LDRDataRight < 450){
				runLDR=2;
				Led_Motor_Left();
			}else{
				runLDR=0;
				Led_Motor_Forward();
			}

			if (ultrasonicSensorDistance < OBSTACLE_DISTANCE){
				isApproachedTo15 = true;
	
				// Set which movement
				whichDirection = 5;
				// Sets Flags, Back-Left and Back-Right LEDs turned on and the other LEDs turned off
				// Car starts to travel in backward direction
				Led_Motor_Backward();
				// We reset counter
				counter = 0;
			}
		}

		if (isApproachedTo15 && ultrasonicSensorDistance > OBSTACLE_ESCAPE_DISTANCE 
			&& ultrasonicSensorDistance < 2*OBSTACLE_ESCAPE_DISTANCE){
			// Set which movement
			whichDirection = 1;
			// Car start to travel in forward direction, sets flags and
			// Front-Left and Front-Right LEDs turned on and the other LEDs turned off.
			Led_Motor_Forward();

			counter = 0;
			isApproachedTo15 = false;
		}

		// Check joystick up button is pressed or not
		if (Joystick_Up_Pressed()){

			// Set which movement
			whichDirection = 1;
			// Car start to travel in forward direction, sets flags and
			// Front-Left and Front-Right LEDs turned on and the other LEDs turned off.
			Led_Motor_Forward();
			// We reset counter
			counter = 0;
		}
		// Check joystick right button is pressed or not
		else if (Joystick_Right_Pressed()){
			// Set which movement
			whichDirection = 2;
			// Sets Flags, Front-Right and Back-Right LEDs turned on and the other LEDs turned off,
			// Car starts to rotate 90 degree in clockwise direction
			Led_Motor_Right();
			// We reset counter
			counter = 0;
		}
		// Check joystick center button is pressed or not
		else if (Joystick_Center_Pressed()){
			// Set which movement
			whichDirection = 3;
			// Sets Flags, All LEDs turned off, Car stops
			Led_Motor_Stop();
			// We reset counter
			counter = 0;
		}
		// Check joystick left button is pressed or not
		else if (Joystick_Left_Pressed()){
			// Set which movement
			whichDirection = 4;
			// Sets Flags, Front-Left and Back-Left LEDs turned on and the other LEDs turned off.
			// Car starts to rotate 90 degree in counter-clockwise direction
			Led_Motor_Left();
			// We reset counter
			counter = 0;
		}
		// Check joystick down button is pressed or not
		else if (Joystick_Down_Pressed()){
			// Set which movement
			whichDirection = 5;
			// Sets Flags, Back-Left and Back-Right LEDs turned on and the other LEDs turned off
			// Car starts to travel in backward direction
			Led_Motor_Backward();
			// We reset counter
			counter = 0;
		}

		// If car continiues turning right, blink
		if (whichDirection == 2||runLDR==1){
			// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
			// It satisfied blink
			if (TIMER3->TC % SECOND < SECOND / 2){
				LED_Right();
			}
			else{
				LED_OFF();
			}
		}
		// If car continiues turning left, blink
		if (whichDirection == 4||runLDR==2){
			// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
			// It satisfied blink
			if (TIMER3->TC % SECOND < SECOND / 2){
				LED_Left();
			}
			else{
				LED_OFF();
			}
		}
	}
	else{
		/* Autonomous Mode */
		//Serial_WriteData('-');
		if (Joystick_Up_Pressed() || autoDirection > 0){
			//Autonomius Mode FORWARD
			
			autoDirection = 1;
			if ( (LDRDataLeft > LDR_ACT && LDRDataRight > LDR_ACT) 
					 || LDRDataLeft-LDRDataRight < LDR_TOLERANCE
					 || LDRDataRight-LDRDataLeft < LDR_TOLERANCE ) {
				Led_Motor_Forward();
				inflateLeft = 0;
				inflateRight = 0;
			}
			else if (LDRDataLeft < LDR_ACT && LDRDataRight > LDR_ACT) {
				Led_Motor_Right();
				autoDirection=3;
				inflateRight++;
				if (inflateRightMax < inflateRight) {
					inflateRightMax = inflateRight;
				}
			}
			else if (LDRDataLeft > LDR_ACT && LDRDataRight < LDR_ACT) {
				Led_Motor_Left();
				autoDirection=4;
				inflateLeft++;
				if (inflateLeftMax < inflateLeft) {
					inflateLeftMax = inflateLeft;
				}
			}
			
			if (inflateRight > 500 || inflateLeft > 500) {
				inflatedSpeed = TrimpotDataValue * 5 / 10;
			}
			else {
				inflatedSpeed = TrimpotDataValue;
			}
			
			PWM_WriteLeft(inflatedSpeed);
			PWM_WriteRight(inflatedSpeed);
			
			if (autoDirection == 4){
			// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
			// It satisfied blink
				if (TIMER3->TC % SECOND < SECOND / 2){
					LED_Left();
				}
				else{
					LED_OFF();
				}
			}
			if (autoDirection == 3){
			// If Time(mod 500ms)< 250 ms, right leds turned on, other wise all led turned off
			// It satisfied blink
				if (TIMER3->TC % SECOND < SECOND / 2){
					LED_Right();
				}
				else{
					LED_OFF();
				}
			}
			

			if (ultrasonicSensorDistance < OBSTACLE_DISTANCE){
				autoDirection = 2;
				isApproachedTo15 = true;
				Led_Motor_Backward();
			}
			
			if (isApproachedTo15 && ultrasonicSensorDistance > OBSTACLE_ESCAPE_DISTANCE && 
				ultrasonicSensorDistance < 2*OBSTACLE_ESCAPE_DISTANCE){
				autoDirection = 1;
				Led_Motor_Forward();
				isApproachedTo15 = false;
			}
		}
	}
	
	

}

int main()
{
	init();
	while (1)
	{
		update();
	}
}
