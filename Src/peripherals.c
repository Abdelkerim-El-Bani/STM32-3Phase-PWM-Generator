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
 *    @brief       Peripheral configuration
 */

#include "stm32f4xx_hal.h"
#include "peripherals.h"

ADC_HandleTypeDef hadc1;

void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig = {0};

  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}



void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    // Enable the power controller clock
    __HAL_RCC_PWR_CLK_ENABLE();

    // Set voltage scaling to optimize power consumption
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

    // Configure the HSE Oscillator and PLL
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON; // Use external oscillator
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON; // Enable PLL
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; // Set HSE as PLL source
    RCC_OscInitStruct.PLL.PLLM = 8;  // HSE / PLLM = 1 MHz
    RCC_OscInitStruct.PLL.PLLN = 336; // 1 MHz * PLLN = 336 MHz
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4; // 336 MHz / PLLP = 84 MHz (System Clock)
    RCC_OscInitStruct.PLL.PLLQ = 7; // For USB (48 MHz = 336 MHz / 7)
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    // Configure the AHB and APB buses
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // Use PLL as system clock
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1; // AHB = 84 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2; // APB1 = 42 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1; // APB2 = 84 MHz

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}
void Error_Handler(void)
{

}
