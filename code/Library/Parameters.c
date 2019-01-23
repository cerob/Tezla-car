#include "Parameters.h"

void Set_Turn_Left_Flag()
{
	TURN_LEFT_FLAG = 1;
	TURN_RIGHT_FLAG = 0;
	FORWARD_FLAG = 0;
	BACKWARD_FLAG = 0;
}

void Set_Turn_Right_Flag()
{
	TURN_LEFT_FLAG = 0;
	TURN_RIGHT_FLAG = 1;
	FORWARD_FLAG = 0;
	BACKWARD_FLAG = 0;
}

void Set_Forward_Flag()
{
	TURN_LEFT_FLAG = 0;
	TURN_RIGHT_FLAG = 0;
	FORWARD_FLAG = 1;
	BACKWARD_FLAG = 0;
}

void Set_Backward_Flag()
{
	TURN_LEFT_FLAG = 0;
	TURN_RIGHT_FLAG = 0;
	FORWARD_FLAG = 0;
	BACKWARD_FLAG = 1;
}

void Reset_Flags()
{
	TURN_LEFT_FLAG = 0;
	TURN_RIGHT_FLAG = 0;
	FORWARD_FLAG = 0;
	BACKWARD_FLAG = 0;
}
