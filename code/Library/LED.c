#include "LED.h"
#include "Parameters.h"

// Initilaze all led pin directions as out and close all led
void LED_Init()
{
	LED_Front_Right_Init();
	LED_Front_Left_Init();
	LED_Back_Right_Init();
	LED_Back_Left_Init();
	LED_OFF();
	LED3_Init();
	LED3_Off();
	Reset_Flags();
}
// Initiliaze front right led pin direction as out
void LED_Front_Right_Init()
{
	GPIO_DIR_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, OUTPUT);
}
// Initiliaze front left led pin direction as out
void LED_Front_Left_Init()
{
	GPIO_DIR_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, OUTPUT);
}
// Initiliaze back right led pin direction as out
void LED_Back_Right_Init()
{
	GPIO_DIR_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, OUTPUT);
}
// Initiliaze back left led pin direction as out
void LED_Back_Left_Init()
{
	GPIO_DIR_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, OUTPUT);
}
// Turn on all led
void LED_ON()
{
	LED_Front_Right_On();
	LED_Front_Left_On();
	LED_Back_Right_On();
	LED_Back_Left_On();
}
// Turn on front right led
void LED_Front_Right_On()
{
	GPIO_PIN_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, HIGH);
}
// Turn on front left led
void LED_Front_Left_On()
{
	GPIO_PIN_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, HIGH);
}
// Turn on back right led
void LED_Back_Right_On()
{
	GPIO_PIN_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, HIGH);
}
// Turn on back left led
void LED_Back_Left_On()
{
	GPIO_PIN_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, HIGH);
}

void LED_OFF()
{
	LED_Front_Right_Off();
	LED_Front_Left_Off();
	LED_Back_Right_Off();
	LED_Back_Left_Off();
}

void LED_Front_Right_Off()
{
	GPIO_PIN_Write(LED_Front_Right_PORT, LED_Front_Right_MASK, LOW);
}

void LED_Front_Left_Off()
{
	GPIO_PIN_Write(LED_Front_Left_PORT, LED_Front_Left_MASK, LOW);
}

void LED_Back_Right_Off()
{
	GPIO_PIN_Write(LED_Back_Right_PORT, LED_Back_Right_MASK, LOW);
}

void LED_Back_Left_Off()
{
	GPIO_PIN_Write(LED_Back_Left_PORT, LED_Back_Left_MASK, LOW);
}
// Turn on forward led turned off other
void LED_Forward(void)
{
	LED_Front_Right_On();
	LED_Front_Left_On();
	LED_Back_Right_Off();
	LED_Back_Left_Off();
}
// Turn on backward led turned off other
void LED_Backward(void)
{
	LED_Front_Right_Off();
	LED_Front_Left_Off();
	LED_Back_Right_On();
	LED_Back_Left_On();
}
// Turn on right led turned off other
void LED_Right(void)
{
	LED_Front_Right_On();
	LED_Front_Left_Off();
	LED_Back_Right_On();
	LED_Back_Left_Off();
}
// Turn on left led turned off other
void LED_Left(void)
{
	LED_Front_Right_Off();
	LED_Front_Left_On();
	LED_Back_Right_Off();
	LED_Back_Left_On();
}

void LED3_Init() {
	GPIO_DIR_Write(LED3_PORT,LED3_MASK,OUTPUT);
}

void LED3_On() {
	GPIO_PIN_Write(LED3_PORT,LED3_MASK,HIGH);
}

void LED3_Off() {
	GPIO_PIN_Write(LED3_PORT,LED3_MASK,LOW);
}
