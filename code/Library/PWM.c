#include "PWM.h"

/*
Right Motor, ENB: PORT1_2 (PIN30) PWM0_1
Left Motor,  ENA: PORT1_3 (PIN29) PWM0_2
*/
//PWM initilaze
void PWM_Init()
{
	//Change IOCON as pwm
	uint32_t value = IOCON_MOTOR_RIGHT_SPEED;
	value |= (1 << 0 | 1 << 1);
	value &= ~(1 << 2);
	IOCON_MOTOR_RIGHT_SPEED = value;

	uint32_t value1 = IOCON_MOTOR_LEFT_SPEED;
	value1 |= (1 << 0 | 1 << 1);
	value1 &= ~(1 << 2);
	IOCON_MOTOR_LEFT_SPEED = value1;

	//Open PWM0
	PCONP |= 1 << 5;

	//Enable PWM output for corresponding pin.
	PWM0->PCR |= (1 << 10);
	PWM0->PCR |= (1 << 9);

	//Reset The PWM Timer Counter and The PWM Prescale Counter on the Next Positive Edge of PCLK
	PWM0->TCR |= (1 << 1);
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * 20 * 1000;

	//Reset TC, when MR0 matches TC.
	PWM0->MCR |= (1 << 1);

	//Enable PWM Match 0 Latch.
	PWM0->LER |= (1 << 0);

	//Enable Counter and PWM and Clear Reset on the PWM
	PWM0->TCR |= (1 << 0 | 1 << 3);
	PWM0->TCR &= ~(1 << 1);

	PWM_WriteLeft(0);
	PWM_WriteRight(0);
}
//Sets MR0
void PWM_Cycle_Rate(uint32_t period_In_Cycles)
{
	PWM0->MR0 = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) * period_In_Cycles * 1000;
	PWM0->LER |= (1 << 0);
}
//Sets left motor speed
void PWM_WriteLeft(uint32_t T_ON)
{
	if (T_ON > 100)
	{
		T_ON = 100;
	}
	T_ON = (uint32_t)(((PWM0->MR0) * T_ON) / 100);
	if (T_ON == PWM0->MR0)
	{
		T_ON++;
	}
	PWM0->MR2 = T_ON;
	PWM0->LER |= (1 << 2);
}
//Sets right motor speed
void PWM_WriteRight(uint32_t T_ON)
{
	if (T_ON > 100)
	{
		T_ON = 100;
	}
	T_ON = (uint32_t)(((PWM0->MR0) * T_ON) / 100);
	if (T_ON == PWM0->MR0)
	{
		T_ON++;
	}
	PWM0->MR1 = T_ON;
	PWM0->LER |= (1 << 1);
}
