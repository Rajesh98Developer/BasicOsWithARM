#include "led.h"

#define GPIOD_EN			(1U<<3)
#define GREEN_LED_PIN		(1U<<12)
#define ORANGE_LED_PIN		(1U<<13)
#define RED_LED_PIN			(1U<<14)
#define BLUE_LED_PIN		(1U<<15)

void led_init(void){
	RCC->AHB1ENR |= GPIOD_EN;

	GPIOD->MODER |= (1U << 24);	// Green Led
	GPIOD->MODER &= ~(1U << 25);
	GPIOD->MODER |= (1U << 26);	// Orange Led
    GPIOD->MODER &= ~(1U << 27);
    GPIOD->MODER |= (1U << 28);	// Red Led
	GPIOD->MODER &= ~(1U << 29);
	GPIOD->MODER |= (1U << 30);	// Blue Led
    GPIOD->MODER &= ~(1U << 31);
}

void led_on(){
	GPIOD->ODR |= GREEN_LED_PIN;
	GPIOD->ODR |= ORANGE_LED_PIN;
	GPIOD->ODR |= RED_LED_PIN;
	GPIOD->ODR |= BLUE_LED_PIN;
}

void led_off(){
	GPIOD->ODR &= ~GREEN_LED_PIN;
	GPIOD->ODR &= ~ORANGE_LED_PIN;
	GPIOD->ODR &= ~RED_LED_PIN;
	GPIOD->ODR &= ~BLUE_LED_PIN;
}
