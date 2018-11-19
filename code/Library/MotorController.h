#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H
#include "Timer.h"
#include "PWM.h"

#include "Parameters.h"

#include "LPC407x_8x_177x_8x.h"
#include "GPIO.h"

#define MC_IN1_MASK ((uint32_t) 1 << 9)
#define MC_IN2_MASK ((uint32_t) 1 << 8)
#define MC_IN3_MASK ((uint32_t) 1 << 7)
#define MC_IN4_MASK ((uint32_t) 1 << 6)

void MotorController_Init(void);
void MC_Set_Direction_Forward(void);
void MC_Set_Direction_Backward(void);
void MC_Set_Direction_Right(void);
void MC_Set_Direction_Left(void);
void MC_Set_Turning(void);

void MC_Stop_Brakes(void);

#endif
