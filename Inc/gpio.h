#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx_hal.h"

#define RS_Pin GPIO_PIN_1
#define RS_GPIO_Port GPIOA
#define E_Pin GPIO_PIN_2
#define E_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOD
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOD
#define D4_Pin GPIO_PIN_3
#define D4_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_4
#define D3_GPIO_Port GPIOD
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOD
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOD
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOD
#define TIM1_CH1_Pin GPIO_PIN_9
#define TIM1_CH1_GPIO_Port GPIOE
#define TIM2_CH1_Pin GPIO_PIN_5
#define TIM2_CH1_GPIO_Port GPIOA
#define TIM4_CH1_Pin GPIO_PIN_12
#define TIM4_CH1_GPIO_Port GPIOD

void GPIO_Init(void);

#endif // GPIO_H
