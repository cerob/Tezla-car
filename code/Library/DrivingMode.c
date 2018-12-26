#include "DrivingMode.h"
#include "Parameters.h"

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
}

void EINT0_IRQHandler() {
	//Clear interrupt for EINT0
	EXT->EXTINT &= ~(1<<0);
	
	Switch_Driving_Mode();
}

void Switch_Driving_Mode() {
	if (DRIVING_MODE == AUTO) {
		DRIVING_MODE = MANUEL;
	}
	else if (DRIVING_MODE == MANUEL){
		DRIVING_MODE = AUTO;
	}
}
