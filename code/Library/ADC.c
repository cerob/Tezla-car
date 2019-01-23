#include "ADC.h"

uint32_t ADC_Last = 0;
uint8_t ADC_New_Data_Available = 0;

void ADC_Init() {
	
	//Change the function value of pin to ADC.
	//Trimpot
	uint32_t v = ANALOG_PIN_IOCON0;
	v |= (1<<0);
	v &= ~((1<<1) | (1<<2));
	ANALOG_PIN_IOCON0 = v;
	
	//ldrs
	v = ANALOG_PIN_IOCON;
	v |= (1<<0);
	v &= ~((1<<1) | (1<<2));
	ANALOG_PIN_IOCON = v;
	
	v = ANALOG_PIN_IOCON2;
	v |= (1<<0);
	v &= ~((1<<1) | (1<<2));
	ANALOG_PIN_IOCON2 = v;
	
	
	//Change the mode value of pin to mode which should be selected if Analog mode is used.
	ANALOG_PIN_IOCON &= ~((1<<4) | (1<<3));
	ANALOG_PIN_IOCON2 &= ~((1<<4) | (1<<3));
	//trimpot
	ANALOG_PIN_IOCON0 &= ~((1<<4) | (1<<3));


	
	//Change Analog/Digital mode of pin to Analog.
	ANALOG_PIN_IOCON &= ~(1<<7);
	ANALOG_PIN_IOCON2 &= ~(1<<7);
	ANALOG_PIN_IOCON0 &= ~(1<<7);

	
	//Turn on ADC.
	PCONP |= (1<<12);
	
	//Set the CLKDIV and make the A/D converter operational without Burst mode.
	uint32_t va = ADC->CR;
	va |= ((1<<14) |(1<<13) |(1<<12) |(1<<9));
	va &= ~((1<<15) |(1<<11) |(1<<10) |(1<<8));
	va |= (1<<21);
	va &= ~(1<<16);
	ADC->CR = va;
}

void ADC_Start() {
	//Write a code for starting A/D conversion
	uint32_t va = ADC->CR;
	va &= ~((1<<26) | (1<<25));
	va |= (1<<24);
	ADC->CR = va;
}



void ADC_Stop() {
	//Write a code for stopping A/D conversio
	ADC->CR &= ~((1<<26) | (1<<25) | (1<<24));
}


uint32_t ADC_Read() {
	uint32_t data;
	
	//Configure CR SEL bits for sampled and converting corresponding pin
	uint32_t v = ADC->CR;
	v |= (1<<2);
	v &= ~((1<<0) | (1<<1) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
	ADC->CR = v;
	
	ADC_Start();
	
	//Wait until A/D conversion completed
	uint32_t mask = 4;
	while(!(ADC->STAT & mask)){};

	//Convert the data RESULT to 0 - 1000 range and return the ADC data
	uint32_t mask1 = 0;
	mask1 |= (ADC_MAX_VALUE<<4);
	
	data = ((ADC->DR[2] & mask1)>>4);
	
		
	data = (data * 1000) / ADC_MAX_VALUE;
		
	ADC_Stop();
	
	return data;
}



uint32_t ADC_Read2() {
	uint32_t data;
	
	//Configure CR SEL bits for sampled and converting corresponding pin
	uint32_t v = ADC->CR;
	v |= (1<<3);
	v &= ~((1<<0) | (1<<1) | (1<<2) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
	ADC->CR = v;
	
	ADC_Start();
	
	//Wait until A/D conversion completed
	uint32_t mask = 8;
	while(!(ADC->STAT & mask)){};

	//Convert the data RESULT to 0 - 1000 range and return the ADC data
	uint32_t mask1 = 0;
	mask1 |= (ADC_MAX_VALUE<<4);
	
	data = ((ADC->DR[3] & mask1)>>4);
	
		
	data = (data * 1000) / ADC_MAX_VALUE;
		
	ADC_Stop();
	
	return data;
}


uint32_t ADC_Read0() {
	//Trimpot
	uint32_t data;
	
	//Configure CR SEL bits for sampled and converting corresponding pin
	uint32_t v = ADC->CR;
	v |= (1<<0);
	v &= ~((1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
	ADC->CR = v;
	
	ADC_Start();
	
	//Wait until A/D conversion completed
	uint32_t mask = 1;
	while(!(ADC->STAT & mask)){};

	//Convert the data RESULT to 0 - 1000 range and return the ADC data
	uint32_t mask1 = 0;
	mask1 |= (ADC_MAX_VALUE<<4);
	
	data = ((ADC->DR[0] & mask1)>>4);
	
		
	data = (data * 100) / ADC_MAX_VALUE;
		
	ADC_Stop();
	
	return data;
}


