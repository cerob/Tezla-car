#include "Ultrasonic.h"
#include "Serial.h"

void Ultrasonic_Trigger_Timer_Init()
{
	//Give the Correct Function Values to IOCON_TRIGGER
	uint32_t value = IOCON_TRIGGER;
	value |= (1 << 0);
	value |= (1 << 1);
	value &= ~(1 << 2);
	IOCON_TRIGGER = value;


	//Enable Timer2.
	PCONP |= (1 << 22);

	//Change the mode of Timer2 to Timer Mode.
	TIMER2->CTCR = 0x00;

	//Reset Timer Counter and Prescale Counter for Timer2.
	TIMER2->TCR |= (1 << 1);

	//Change PR Register value for 1 microsecond incrementing
	TIMER2->PR = (PERIPHERAL_CLOCK_FREQUENCY / 1000000) - 1;

	//Remove the reset on counters of Timer2.
	TIMER2->TCR &= ~(1 << 1);
}

void Ultrasonic_Capture_Timer_Init()
{
	//Give the Correct Function Values to IOCON_ECHO
	uint32_t value = IOCON_ECHO;
	value |= (1 << 0);
	value |= (1 << 1);
	value &= ~(1 << 2);
	IOCON_ECHO = value;


	PCONP |= 1 << 23;

	TIMER3->CTCR = 0x00;

	TIMER3->TCR &= ~(1 << 0);

	TIMER3->TCR |= (1 << 1);

	TIMER3->PR = PERIPHERAL_CLOCK_FREQUENCY / 1000000 - 1;

	//Write the Correct Value to CCR register for getting interrupt when Rising Edge Occur
	TIMER3->CCR = ((1 << 3) | (1 << 5));

	TIMER3->TCR &= ~(1 << 1);

	TIMER3->TCR |= (1 << 0);

	//Clear pendings for Timer3.
	NVIC_ClearPendingIRQ(TIMER3_IRQn);

	//Set Priority Timer3 IRQ as 5.
	NVIC_SetPriority(TIMER3_IRQn, 5);

	//Enable TIMER3_IRQn (Interrupt Request).
	NVIC_EnableIRQ(TIMER3_IRQn);
}

uint32_t escapeCount = 0;

void Ultrasonic_Start_Trigger()
{
	if (ultrasonicSensorEdgeCount == 1 && escapeCount < 7000)
	{
		escapeCount++;
		return;
	}

	escapeCount = 0;

	//Give HIGH value to T2_MAT_3 pin
	TIMER2->EMR |= (1 << 3);

	//Calculate the MR3 register value for giving 10 microsecond HIGH value
	TIMER2->MR3 = 10;

	//Write to correct values to Timer2 EMR register for making LOW output value of Trigger Pin when match occurs.
	TIMER2->EMR |= (1 << 10);

	//Reset TC and Stop (TC and PC), if MR3 register matches the TC.
	TIMER2->MCR |= (1 << 11) | (1 << 10);

	//Enable Timer2 Counter and Prescale Counter for counting.
	TIMER2->TCR |= (1 << 0);

	ultrasonicSensorEdgeCount = 0;
	//Serial_WriteData('-');
}

uint8_t ultrasonicSensorEdgeCount = 0;
uint32_t ultrasonicSensorRisingTime = 0;
uint32_t ultrasonicSensorFallingTime = 0;
uint32_t ultrasonicSensorDuration = 0;
uint32_t ultrasonicSensorDistance = 0;

void TIMER3_IRQHandler()
{
	if (ultrasonicSensorEdgeCount == 0)
	{
		//Store the rising time into ultrasonicSensorRisingTime variable
		ultrasonicSensorRisingTime = TIMER3->CR1;
		
		//Change the CCR register value for getting interrupt when falling edge event is occured.
		TIMER3->CCR = ((1 << 4) | (1 << 5));

		ultrasonicSensorEdgeCount = 1;

		NVIC_ClearPendingIRQ(TIMER3_IRQn);
		
	}
	else if (ultrasonicSensorEdgeCount == 1)
	{

		//Store the falling time into ultrasonicSensorFallingTime variable
		ultrasonicSensorFallingTime = TIMER3->CR1;

		//Change the CCR register value for getting interrupt when rising edge event is occured.
		//TIMER3->CCR |= ((1<<3) | (1<<5));
		TIMER3->CCR = ((1 << 3) | (1 << 5));

		ultrasonicSensorEdgeCount = 2;


		ultrasonicSensorDuration = ultrasonicSensorFallingTime - ultrasonicSensorRisingTime;
		ultrasonicSensorDistance = ultrasonicSensorDuration / 58;
		
		/*Serial_Write("Rising time:");
		Serial_Write_Int(ultrasonicSensorRisingTime);
		Serial_Write("Falling time:");
		Serial_Write_Int(ultrasonicSensorFallingTime);
		Serial_Write("ultrasonicSensorDuration:");
		Serial_Write_Int(ultrasonicSensorDuration);
		Serial_Write("ultrasonicSensorDistance:");
		Serial_Write_Int(ultrasonicSensorDistance);
		*/
		
		NVIC_ClearPendingIRQ(TIMER3_IRQn);
	}

	
	/*Serial_Write("Interrupt handled! Edge count:");
	Serial_Write_Int(ultrasonicSensorEdgeCount);*/
	//Clear the interrupt flag for capture channel 1 event
	TIMER3->IR |= (1 << 5);
}

void Ultrasonic_Stop()
{
	PCONP |= (1 << 22);
	PCONP |= (1 << 23);
}
