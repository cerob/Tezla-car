#include "Timer.h"

uint32_t a_currentTime = 0;
uint32_t a_previousTime = 0;
uint32_t a_capturedTime = 0;

uint32_t b_currentTime = 0;
uint32_t b_previousTime = 0;
uint32_t b_capturedTime = 0;

void Timer_Init() {
	// Function Values
	uint32_t func = 0x3;
	TIMERA_IOCON_OUT |= func;
	TIMERB_IOCON_OUT |= func;	
	
	// Enable Timer2 and Timer3
	PCONP |= ((1<<22) | (1<<23));
	
	// Change the mode of Timer2 and Timer3 to Timer Mode.
	TIMER2->CTCR &= ~((1<<0) | (1<<1));
	TIMER3->CTCR &= ~((1<<0) | (1<<1));
	
	// Disable Timer Counter and Prescale Counter for Timer2 and Timer3.
	TIMER2->TCR &= ~(1<<0);
	TIMER3->TCR &= ~(1<<0);
	
	// Reset Timer Counter and Prescale Counter for Timer2 and Timer3.
	TIMER2->TCR |= (1<<1);
	TIMER3->TCR |= (1<<1);
	
	// Change PR Register values for 1 microsecond incrementing
	TIMER2->TCR = PERIPHERAL_CLOCK_FREQUENCY / 1000000 - 1;
	TIMER3->TCR = PERIPHERAL_CLOCK_FREQUENCY / 1000000 - 1;
	
	// Capture Rising and Falling Edges on CAP0s
	TIMER2->CCR |= ((1<<0) | (1<<1));
	TIMER3->CCR |= ((1<<0) | (1<<1));
	
	// Remove the reset on counters of Timer2 and Timer3.
	TIMER2->TCR &= ~(1<<1);
	TIMER3->TCR &= ~(1<<1);
	
	// Enable Timer2 and Timer3 Counter and Prescale Counter for counting.	
	TIMER2->TCR |= (1<<0);
	TIMER3->TCR |= (1<<0);
}
