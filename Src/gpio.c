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
 *    @brief       GPIO configuration
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /* GPIO pin Output for RS_Pin and E_Pin */
    HAL_GPIO_WritePin(GPIOA, RS_Pin | E_Pin, GPIO_PIN_RESET);

    /* GPIO pin Output for D0_Pin to D7_Pin */
    HAL_GPIO_WritePin(GPIOD, D0_Pin | D1_Pin | D2_Pin | D4_Pin
                                | D3_Pin | D5_Pin | D6_Pin | D7_Pin, GPIO_PIN_RESET);

    /* GPIO pins : RS_Pin, E_Pin */
    GPIO_InitStruct.Pin = RS_Pin | E_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // PE9 for TIM1_CH1
    GPIO_InitStruct.Pin = TIM1_CH1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    // PA5 for TIM2_CH1
    GPIO_InitStruct.Pin = TIM2_CH1_Pin;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // PD12 for TIM4_CH1
    GPIO_InitStruct.Pin = TIM4_CH1_Pin;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // GPIO pins : D0_Pin, D1_Pin, D2_Pin, D4_Pin, D3_Pin, D5_Pin, D6_Pin, D7_Pin
    GPIO_InitStruct.Pin = D0_Pin | D1_Pin | D2_Pin | D4_Pin
                                 | D3_Pin | D5_Pin | D6_Pin | D7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
