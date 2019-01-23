#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "LPC407x_8x_177x_8x.h"

static uint32_t ROBOT_SPEED = 100;
static uint32_t TURN_LEFT_FLAG = 0;
static uint32_t TURN_RIGHT_FLAG = 0;
static uint32_t FORWARD_FLAG = 0;
static uint32_t BACKWARD_FLAG = 0;

static const uint32_t ROTATION_NUMBER_FOR_90_DEGREE = 600;
static const uint32_t OBSTACLE_DISTANCE = 15;
static const uint32_t OBSTACLE_ESCAPE_DISTANCE = 30;

static const char MANUEL = '*';
static const char AUTO = '#';
static const char WIFI_USERNAME[] = "HWLAB";
static const char WIFI_PASSWORD[] = "12345678";
static const char WIFI_GET_URL[] = "http://192.168.0.100:8080/HWLAB_IoT/GetInformation?ID=5";
static const char WIFI_POST_MANUEL[] = "http://192.168.0.100:8080/HWLAB_IoT/SendInformation?ID=5&DATA=MANUEL";
static const char WIFI_POST_AUTO[] = "http://192.168.0.100:8080/HWLAB_IoT/SendInformation?ID=5&DATA=AUTO";
static char START_MODE = MANUEL;
static char DRIVING_MODE = MANUEL;


//const uint32_t LDR_THRESHOLD;
static const uint32_t LDR_ACT = 550;
static const uint32_t LDR_TOLERANCE = 30;


void Set_Turn_Left_Flag(void);
void Set_Turn_Right_Flag(void);
void Set_Forward_Flag(void);
void Set_Backward_Flag(void);
void Reset_Flags(void);

#endif
