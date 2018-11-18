#include "PWM.h"

/*
Right Motor, ENA: PORT1_2 (PIN30) PWM0_1
Left Motor,  ENB: PORT1_3 (PIN29) PWM0_2
*/

void PWM_Init() {
	// Enable PWM0
	PCONP |= 1 << 5;
	
	
	
	// Set FUNC
	
uint32_t func =IOCON_MOTOR_RIGHT_SPEED;
 func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
IOCON_MOTOR_RIGHT_SPEED=func;



func =IOCON_MOTOR_LEFT_SPEED;
 func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
IOCON_MOTOR_LEFT_SPEED=func;


 func =LED_Front_Right_PORT;
 func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
LED_Front_Right_PORT=func;



 func =LED_Front_Left_PORT;
 func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
 LED_Front_Left_PORT=func;

 
 func =LED_Back_Left_PORT;
func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
 LED_Back_Left_PORT=func;


 func =LED_Back_Right_PORT;
func|=1<<0;
 func|=1<<1;
 func &= ~(1<<2);
LED_Back_Right_PORT=func;



	
	
	
	// Enable PWM output for corresponding pins.
	PWM0 -> PCR |= (1 << 9 | 1 << 10 | 1 << 11 | 1 << 12 | 1 << 13 | 1 << 14);
	
	// Reset The PWM Timer Counter and The PWM Prescale Counter on the Next Positive Edge of PCLK
	PWM0->TCR |= (1<<1);
	
	// Set frequency
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * 20 * 1000;
	
	// Reset TC, when corresponding MRs matches TC.
	PWM0 -> MCR |= (1 << 1);
	
	// Enable PWM Match 0 Latches.
	PWM0 -> LER |= (1 << 0);
	
	// Enable Counter
	PWM0->TCR |= (1<<0);
	
	// Enable PWM
	PWM0->TCR |= (1<<3);
	
	// Clear Reset on the PWM
	PWM0->TCR &= ~(1<<1);
	

	PWM_Write(0, 1);
	PWM_Write(0, 2);
	
	PWM_Write(0, 3);
	PWM_Write(0, 4);
	PWM_Write(0, 5);
	PWM_Write(0, 6);
	
}

void PWM_Cycle_Rate(uint32_t period_In_Cycles) {
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * period_In_Cycles * 1000;
	
	// Enable PWM Match 0/1/2 Latches.
	// TODO: inspect
	PWM0 -> LER |= (1 << 0);
}




void PWM_Write(uint32_t T_ON, uint32_t section) {	
	uint32_t dutyCycle;

    //Checked the validity of time on b/w 0 - 100 
	 if(T_ON > 100) {
		T_ON = 100;
	}
	
	dutyCycle = (uint32_t)((PWM0 -> MR0 * T_ON) / 100);
	
	if (dutyCycle == PWM0->MR0) {
		dutyCycle++;
	}
	


   if (section==1){PWM0 -> MR1 = dutyCycle;}
   else if (section==2){PWM0 -> MR2 = dutyCycle;}
   else if (section==3){PWM0 -> MR3 = dutyCycle;}
   else if (section==4){PWM0 -> MR4 = dutyCycle;}
   else if (section==5){PWM0 -> MR5 = dutyCycle;}
   else if (section==6){PWM0 -> MR6 = dutyCycle;}

	PWM0 -> LER |= (1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6);
}
