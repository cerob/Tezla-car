#include "PWM.h"

/*
Right Motor, ENA: PORT1_2 (PIN30) PWM0_1
Left Motor,  ENB: PORT1_3 (PIN29) PWM0_2
*/

void PWM_Init() {
	// Enable PWM0
	PCONP |= 1 << 5;
	
	// Set FUNC
	uint32_t func = 0x3;
	IOCON_MOTOR_RIGHT_SPEED |= func;
	IOCON_MOTOR_LEFT_SPEED |= func;
	
	// Enable PWM output for corresponding pins.
	PWM0->PCR |= ((1<<9) | (1<<10));
	
	// Reset The PWM Timer Counter and The PWM Prescale Counter on the Next Positive Edge of PCLK
	PWM0->TCR |= (1<<1);
	
	// Set frequency
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * 20 * 1000;
	
	// Reset TC, when corresponding MRs matches TC.
	// TODO: inspect
	PWM0->MCR |= ((1<<1) | (1<<4) | (1<<7));
	
	// Enable PWM Match 0/1/2 Latches.
	// TODO: inspect
	PWM0->LER |= ((1<<0) | (1<<1) | (1<<2));
	
	// Enable Counter
	PWM0->TCR |= (1<<0);
	
	// Enable PWM
	PWM0->TCR |= (1<<3);
	
	// Clear Reset on the PWM
	PWM0->TCR &= ~(1<<1);
	
	PWM_Write(0);
}

void PWM_Cycle_Rate(uint32_t period_In_Cycles) {
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * period_In_Cycles * 1000;
	
	// Enable PWM Match 0/1/2 Latches.
	// TODO: inspect
	PWM0->LER |= ((1<<0) | (1<<1) | (1<<2));
}

void PWM_Write(uint32_t T_ON) {	
	if(T_ON > 100) {
		T_ON = 100;
	}
	
	T_ON = (uint32_t)(((PWM0->MR0) * T_ON) / 100);
	
	if (T_ON == PWM0->MR0) {
		T_ON++;
	}
	PWM0->MR2 = T_ON;
	
	// Enable PWM Match 0/1/2 Latches.
	// TODO: inspect
	PWM0->LER |= ((1<<0) | (1<<1) | (1<<2));
}
