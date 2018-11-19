#ifndef LED_H
#define LED_H

#include "LPC407x_8x_177x_8x.h"
#include "GPIO.h"
#include "PWM.h"

 //#define LED_Front_Right_PORT PORT1
 #define LED_Front_Right_MASK ((uint32_t) 1 << 28)

// #define LED_Front_Left_PORT PORT1
 #define LED_Front_Left_MASK ((uint32_t) 1 << 27)

// #define LED_Back_Right_PORT PORT1
 #define LED_Back_Right_MASK ((uint32_t) 1 << 26)

// #define LED_Back_Left_PORT PORT0
 #define LED_Back_Left_MASK ((uint32_t) 1 << 25)


void LED_Init(void);
void LED_Front_Right_Init(void);
void LED_Front_Left_Init(void);
void LED_Back_Right_Init(void);
void LED_Back_Left_Init(void);

void LED_ON(void);
void LED_Front_Right_On(void);
void LED_Front_Left_On(void);
void LED_Back_Right_On(void);
void LED_Back_Left_On(void);

void LED_Front_Right_On_Blink(void);
void LED_Front_Left_On_Blink(void);
void LED_Back_Right_On_Blink(void);
void LED_Back_Left_On_Blink(void);

void LED_OFF(void);
void LED_Front_Right_Off(void);
void LED_Front_Left_Off(void);
void LED_Back_Right_Off(void);
void LED_Back_Left_Off(void);

void LED_Forward(void);
void LED_Backward(void);
void LED_Right(void);
void LED_Left(void);

void TIMER0_Init(void);


#endif
