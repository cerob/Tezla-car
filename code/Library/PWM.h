#ifndef PWM_H
#define PWM_H

#include "LPC407x_8x_177x_8x.h"
#include "SystemStructures.h"

typedef struct
{
  volatile uint32_t IR;
  volatile uint32_t TCR;
  volatile uint32_t TC;
  volatile uint32_t PR;
  volatile uint32_t PC;
  volatile uint32_t MCR;
  volatile uint32_t MR0;
  volatile uint32_t MR1;
  volatile uint32_t MR2;
  volatile uint32_t MR3;
  volatile uint32_t CCR;
  volatile uint32_t CR0;
  volatile uint32_t CR1;
  uint32_t RESERVED0[3];
  volatile uint32_t MR4;
  volatile uint32_t MR5;
  volatile uint32_t MR6;
  volatile uint32_t PCR;
  volatile uint32_t LER;
  uint32_t RESERVED1[7];
  volatile uint32_t CTCR;
} PWM_TypeDef;

// Right Motor, ENB: PORT1_2 (PIN30) PWM0_1
#define IOCON_MOTOR_RIGHT_SPEED_ADDRESS 0x4002C088
#define IOCON_MOTOR_RIGHT_SPEED *((volatile uint32_t *)(IOCON_MOTOR_RIGHT_SPEED_ADDRESS))

// Left Motor, ENA: PORT1_3 (PIN29) PWM0_2
#define IOCON_MOTOR_LEFT_SPEED_ADDRESS 0x4002C08C
#define IOCON_MOTOR_LEFT_SPEED *((volatile uint32_t *)(IOCON_MOTOR_LEFT_SPEED_ADDRESS))

#define PWM0_BASE 0x40014000
#define PWM1_BASE 0x40018000

#define PWM0 ((PWM_TypeDef *)PWM0_BASE)
#define PWM1 ((PWM_TypeDef *)PWM1_BASE)

void PWM_Init(void);
void PWM_Cycle_Rate(uint32_t period_In_Cycles);
void PWM_WriteLeft(uint32_t T_ON);
void PWM_WriteRight(uint32_t T_ON);

#endif
