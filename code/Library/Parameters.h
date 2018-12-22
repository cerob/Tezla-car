#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "LPC407x_8x_177x_8x.h"


static uint32_t ROBOT_SPEED =20;
static uint32_t TURN_LEFT_FLAG = 0;
static uint32_t TURN_RIGHT_FLAG = 0;
static uint32_t FORWARD_FLAG = 0;
static uint32_t BACKWARD_FLAG = 0;
static uint32_t ROTATION_NUMBER_FOR_90_DEGREE = 600;

void Set_Turn_Left_Flag(void);
void Set_Turn_Right_Flag(void);
void Set_Forward_Flag(void);
void Set_Backward_Flag(void);
void Reset_Flags(void);


#endif
