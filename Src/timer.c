/*
 *	  @supervisor  Khaled Jelassi
 *    @email       khaled.jelassi@enit.utm.tn
 *
 *    @author      Abdelkerim El Bani
 *    @email       abdelkerim.elbani@etudiant-enit.utm.tn
 *
 *    @author      Fedi Mezghani
 *    @email       fedi.mezghani@etudiant-enit.utm.tn
 *
 *    @departement Elictrical departement ENIT
 *    @date 			 16-January-2025
 *    @website     http://www.enit.rnu.tn/
 *    @ide         STM32CubeIDE
 *    @brief       Timer configuration
 */

#include "stm32f4xx_hal.h"
#include "timer.h"

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;

void TIM1_Init(void) {
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 16;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 1000;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_PWM_Init(&htim1);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;  // Initial duty cycle
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
}
void TIM2_Init(void) {
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 16;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 1000;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&htim2);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
}
void TIM4_Init(void) {
    TIM_OC_InitTypeDef sConfigOC = {0};

    htim4.Instance = TIM4;
    htim4.Init.Prescaler = 16;
    htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim4.Init.Period = 1000;
    htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&htim4);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
}
