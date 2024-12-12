/*
 * timebase.c
 *
 *  Created on: Dec 5, 2024
 *      Author: malli
 */


#include "timebase.h"
#include "stm32f4xx.h"

#define MAX_DELAY	0xFFFFFFFF

#define CTRL_EN		(1U<<0)
#define CTRL_TICKINT_EN	(1U<<1)
#define CTRL_CLKSRC		(1U<<2)
#define CTRL_CNT_FLG	(1U<<16)

#define ONE_SEC_CNT		16000000

volatile uint32_t tick_freq = 1;
uint32_t tick_cnt_sec_g = 0;
uint32_t curr_tick_cnt_g = 0;

void tick_increament(void){
	curr_tick_cnt_g += tick_freq;
}

void timebase_init(void){
	/* Timer count value for interrupt */
	SysTick->LOAD = ONE_SEC_CNT-1;
	/* Clear SysTick Current Value */
	SysTick->VAL = 0;
	/* Select internal clock source */
	SysTick->CTRL |= CTRL_CLKSRC;
	/* Enable interrupt */
	SysTick->CTRL |= CTRL_TICKINT_EN;
	/* Enable SysTick */
	SysTick->CTRL |= CTRL_EN;

	__enable_irq();
}

void SysTick_Handler(void){
	tick_increament();
}

uint32_t get_tick(void){
	__disable_irq();
	tick_cnt_sec_g = curr_tick_cnt_g;
	__enable_irq();
	return tick_cnt_sec_g;
}

void delay(uint32_t delay_s){
	uint32_t startCnt = get_tick();
	uint32_t endCnt = (startCnt + delay_s)%MAX_DELAY;

	while(endCnt != get_tick());
}
