#include "Timer.h"

// Timer3
uint32_t a_currentTime = 0;
uint32_t a_previousTime = 0;
uint32_t a_capturedTime = 0;


uint32_t LeftButtonTime = 0;
uint32_t RightButtonTime = 0;

//Timer2
uint32_t b_currentTime = 0;
uint32_t b_previousTime = 0;
uint32_t b_capturedTime = 0;

// Initilaze timer
void Timer_Init() {
	// Set IOCON
	uint32_t func = 0x3;
	TIMERA_IOCON_OUT |= func;
	TIMERB_IOCON_OUT |= func;	
	
	// Enable Timer2 and Timer3
	PCONP |= ((1<<22)  | (1<<23));
	
	// Change the mode of Timer2 and Timer3 to Timer Mode.
	TIMER2->CTCR &= ~(func);
	TIMER3->CTCR &= ~(func);
	
	// Disable Timer Counter and Prescale Counter for Timer2 and Timer3.
	TIMER2->TCR &= ~(1<<0);
	TIMER3->TCR &= ~(1<<0);
	
	// Reset Timer Counter and Prescale Counter for Timer2 and Timer3.
	TIMER2->TCR |= (1<<1);
	TIMER3->TCR |= (1<<1);
	
	// Change PR Register values for 1 microsecond incrementing
	TIMER2->PR = PERIPHERAL_CLOCK_FREQUENCY / 1000000 - 1;
	TIMER3->PR = PERIPHERAL_CLOCK_FREQUENCY / 1000000 - 1;
	
	// Capture Rising and Falling Edges on CAP0s
	TIMER2->CCR |= (func);
	TIMER3->CCR |= (func);
	
	// Remove the reset on counters of Timer2 and Timer3.
	TIMER2->TCR &= ~(1<<1);
	TIMER3->TCR &= ~(1<<1);
	
	// Enable Timer2 and Timer3 Counter and Prescale Counter for counting.	
	TIMER2->TCR |= (1<<0);
	TIMER3->TCR |= (1<<0);
}
