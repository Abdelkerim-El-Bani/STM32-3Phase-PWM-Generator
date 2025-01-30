#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

void SystemClock_Config(void);
void MX_ADC1_Init(void);
void Error_Handler(void);

#endif // PERIPHERALS_H
