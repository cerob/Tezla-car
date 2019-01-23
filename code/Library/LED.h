#ifndef LED_H
#define LED_H

#include "LPC407x_8x_177x_8x.h"
#include "GPIO.h"
#include "PWM.h"

#define LED_Front_Right_PORT PORT1
//Front Right Led
#define LED_Front_Right_MASK ((uint32_t)1 << 24)
//Front Left Led
#define LED_Front_Left_PORT PORT1
#define LED_Front_Left_MASK ((uint32_t)1 << 23)
//Back Right Led
#define LED_Back_Right_PORT PORT1
#define LED_Back_Right_MASK ((uint32_t)1 << 20)
//Back Left Led
#define LED_Back_Left_PORT PORT0
#define LED_Back_Left_MASK ((uint32_t)1 << 21)

#define LED1_PORT			PORT1
#define LED1_MASK			((uint32_t) 1 << 18)

#define LED2_PORT			PORT0
#define LED2_MASK			((uint32_t) 1 << 13)

#define LED3_PORT			PORT1
#define LED3_MASK			((uint32_t) 1 << 13)

#define LED4_PORT			PORT2
#define LED4_MASK			((uint32_t) 1 << 19)


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

void LED_OFF(void);
void LED_Front_Right_Off(void);
void LED_Front_Left_Off(void);
void LED_Back_Right_Off(void);
void LED_Back_Left_Off(void);

void LED_Forward(void);
void LED_Backward(void);
void LED_Right(void);
void LED_Left(void);

//void LED1_Init(void);
//void LED2_Init(void);
void LED3_Init(void);
//void LED4_Init(void);

//void LED_ON(void);
//void LED1_On(void);
//void LED2_On(void);
void LED3_On(void);
//void LED4_On(void);

//void LED_OFF(void);
//void LED1_Off(void);
//void LED2_Off(void);
void LED3_Off(void);
//void LED4_Off(void);

void TIMER0_Init(void);

#endif
