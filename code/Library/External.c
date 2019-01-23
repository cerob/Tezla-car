#include "External.h"
#include "Parameters.h"
#include "Controller.h"
#include "Serial.h"

uint8_t DriveMode = 0;

void External_Init() {
	//Change the functionality of the push button as EINT0
	uint32_t value = IOCON_PUSH_BUTTON;
	value &= ~((1<<1) | (1<<2));
	value |= (1<<0);
	IOCON_PUSH_BUTTON = value;
	
	//Change the External interrupt mode as Edge Sensitive
	EXT->EXTMODE |= (1<<0);
	
	//Enable interrupt for EINT0_IRQn.
	NVIC_EnableIRQ(EINT0_IRQn);
	NVIC_SetPriority(EINT0_IRQn, 3);
	
	if (START_MODE == MANUEL) {
		DriveMode = 0;
		LED3_On();
	} else {
		DriveMode = 1;
		LED3_Off();
	}
}

void EINT0_IRQHandler() {
	//Clear interrupt for EINT0
	EXT->EXTINT |= 1;
	if(DriveMode==1){
		DriveMode=0;
		LED3_On();
		DRIVING_MODE = MANUEL;
		Led_Motor_Stop();

	}
	else {
		autoDirection = 0;
		DriveMode=1;
		LED3_Off();
		DRIVING_MODE = AUTO;
		Led_Motor_Stop();

	}

	NVIC_ClearPendingIRQ(EINT0_IRQn);
}
