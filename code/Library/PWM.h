#ifndef PWM_H
#define PWM_H

#include "LPC407x_8x_177x_8x.h"
#include "SystemStructures.h"

typedef struct
{
  volatile	uint32_t IR;
  volatile	uint32_t TCR;
  volatile	uint32_t TC;
  volatile	uint32_t PR;
  volatile	uint32_t PC;
  volatile	uint32_t MCR;
  volatile	uint32_t MR0;
  volatile	uint32_t MR1;
  volatile	uint32_t MR2;
  volatile	uint32_t MR3;
  volatile	uint32_t CCR;
  volatile  uint32_t CR0;
  volatile  uint32_t CR1;
						uint32_t RESERVED0[3];
  volatile	uint32_t MR4;
  volatile	uint32_t MR5;
  volatile	uint32_t MR6;
  volatile	uint32_t PCR;
  volatile	uint32_t LER;
						uint32_t RESERVED1[7];
  volatile	uint32_t CTCR;
} PWM_TypeDef;




#define IOCON_LED_ADDRESS_1	0x4002C094	//P1.5(P28)
#define IOCON_LED_ADDRESS_2	0x4002C098	//P1.6(P27)
#define IOCON_LED_ADDRESS_3	0x4002C09C	//P1.7(P26)
#define IOCON_LED_ADDRESS_4	0x4002C0AC	//P1.11(P25)

#define LED_Front_Right_PORT	*((volatile uint32_t*)(IOCON_LED_ADDRESS_1))
#define LED_Front_Left_PORT	*((volatile uint32_t*)(IOCON_LED_ADDRESS_2))
#define LED_Back_Left_PORT	*((volatile uint32_t*)(IOCON_LED_ADDRESS_3))
#define LED_Back_Right_PORT	*((volatile uint32_t*)(IOCON_LED_ADDRESS_4))




// Right Motor, ENA: PORT1_2 (PIN30) PWM0_1
#define IOCON_MOTOR_RIGHT_SPEED_ADDRESS 0x4002C088
#define IOCON_MOTOR_RIGHT_SPEED *((volatile uint32_t*)(IOCON_MOTOR_RIGHT_SPEED_ADDRESS))

// Left Motor, ENB: PORT1_3 (PIN29) PWM0_2
#define IOCON_MOTOR_LEFT_SPEED_ADDRESS 0x4002C08C
#define IOCON_MOTOR_LEFT_SPEED *((volatile uint32_t*)(IOCON_MOTOR_LEFT_SPEED_ADDRESS))



#define PWM0_BASE	0x40014000
#define PWM1_BASE	0x40018000

#define PWM0 ((PWM_TypeDef*) PWM0_BASE)
#define PWM1 ((PWM_TypeDef*) PWM1_BASE)

void PWM_Init(void);
void PWM_Cycle_Rate(uint32_t period_In_Cycles);
void PWM_Write(uint32_t T_ON, uint32_t section);

#endif