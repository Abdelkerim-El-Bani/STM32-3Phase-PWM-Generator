#ifndef TIMER_H
#define TIMER_H

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;

void TIM1_Init(void);
void TIM2_Init(void);
void TIM4_Init(void);

#endif // TIMER_H
