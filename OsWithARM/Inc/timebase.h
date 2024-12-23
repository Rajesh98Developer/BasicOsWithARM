/*
 * timebase.h
 *
 *  Created on: Dec 5, 2024
 *      Author: malli
 */

#ifndef TIMEBASE_H_
#define TIMEBASE_H_

#include <stdint.h>

uint32_t get_tick(void);
void delay(uint32_t delay_s);
void timebase_init();

#endif /* TIMEBASE_H_ */
