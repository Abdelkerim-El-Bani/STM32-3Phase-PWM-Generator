/**
 *    PWM 3 phase shift 120° example for STM32F4 Discovery
 *
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
 *    @brief       Main program body
 */

#include "main.h"

int main(void) {
    HAL_Init();
    SystemClock_Config();
	MX_ADC1_Init();
    GPIO_Init();
    TIM1_Init();
    TIM2_Init();
    TIM4_Init();

    uint16_t dutyCycle = 0;
    uint32_t adcValue = 0;
    uint8_t percentage = 0;

    // Set counter values for phase shift
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    __HAL_TIM_SET_COUNTER(&htim2, htim2.Init.Period / 3);
    __HAL_TIM_SET_COUNTER(&htim4, 2 * htim4.Init.Period / 3);

    // Start PWM for all timers
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

    // Initialize the LCD
    lcd16x2_init_4bits(RS_GPIO_Port, RS_Pin, E_Pin,
                       D4_GPIO_Port, D4_Pin, D5_Pin, D6_Pin, D7_Pin);
    lcd16x2_cursorShow(false);

    // Startup Animation
    for (int i = 0; i < 16; i++)
    {
      lcd16x2_setCursor(0, i);
      lcd16x2_printf("\xFF");
      lcd16x2_setCursor(1, i);
      lcd16x2_printf("\xFF");
      HAL_Delay(50);
    }

    lcd16x2_clear();
    lcd16x2_setCursor(0, 3);
    lcd16x2_printf("Project by:");
    HAL_Delay(1000);

    lcd16x2_clear();
    lcd16x2_setCursor(0, 3);
    lcd16x2_printf("Abdelkerim");
    lcd16x2_setCursor(1, 5);
    lcd16x2_printf("El Bani");
    HAL_Delay(1000);

    lcd16x2_clear();
    lcd16x2_setCursor(0, 8);
    lcd16x2_printf("&");
    lcd16x2_setCursor(1, 2);
    lcd16x2_printf("Fedi Mezghani");
    HAL_Delay(1000);

    lcd16x2_clear();
    lcd16x2_setCursor(0, 5);
    lcd16x2_printf("2AGE1");
    lcd16x2_setCursor(1, 3);
    lcd16x2_printf("2024/2025");
    HAL_Delay(1000);

    lcd16x2_clear();

    while (1) {

        // ADC conversion
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK) {

            // Read ADC value
            adcValue = HAL_ADC_GetValue(&hadc1);

            percentage = (adcValue * 100) / 4095;

            lcd16x2_clear();
            lcd16x2_setCursor(0, 2);
            lcd16x2_printf("Duty Cycle:");
            lcd16x2_setCursor(1, 6);
            lcd16x2_printf("%u%%", percentage);

            dutyCycle = (uint16_t)((percentage * htim1.Init.Period) / 100);

            // Set the duty cycle for PWM pins
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, dutyCycle);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, dutyCycle);
            __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, dutyCycle);

            HAL_Delay(100);
        }
    }
}
