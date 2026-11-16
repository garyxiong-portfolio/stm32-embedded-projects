/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"

/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* USER CODE BEGIN PV */
/* USER CODE END PV */

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void DIGITS_Display(uint8_t digit_A, uint8_t digit_B)
{
  /* Digit A: tens */
  HAL_GPIO_WritePin(GPIOB, DIGIT_A0_Pin,
                   (digit_A & 0x01U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOB, DIGIT_A1_Pin,
                   (digit_A & 0x02U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOB, DIGIT_A2_Pin,
                   (digit_A & 0x04U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOB, DIGIT_A3_Pin,
                   (digit_A & 0x08U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  /* Digit B: ones */
  HAL_GPIO_WritePin(GPIOC, DIGIT_B0_Pin,
                   (digit_B & 0x01U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOC, DIGIT_B1_Pin,
                   (digit_B & 0x02U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOC, DIGIT_B2_Pin,
                   (digit_B & 0x04U) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOC, DIGIT_B3_Pin,
                   (digit_B & 0x08U) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
/* USER CODE END 0 */

int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  uint8_t count = 0;
  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    uint8_t digit_A = count / 10U;
    uint8_t digit_B = count % 10U;

    DIGITS_Display(digit_A, digit_B);

    HAL_Delay(500);

    count++;

    if (count >= 100U)
    {
      count = 0;
    }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK
                             | RCC_CLOCKTYPE_SYSCLK
                             | RCC_CLOCKTYPE_PCLK1
                             | RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct,
                         FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  HAL_GPIO_WritePin(
      GPIOC,
      DIGIT_B0_Pin | DIGIT_B1_Pin | DIGIT_B2_Pin | DIGIT_B3_Pin,
      GPIO_PIN_RESET
  );

  HAL_GPIO_WritePin(
      GPIOB,
      DIGIT_A0_Pin | DIGIT_A1_Pin | DIGIT_A2_Pin | DIGIT_A3_Pin,
      GPIO_PIN_RESET
  );

  GPIO_InitStruct.Pin = DIGIT_B0_Pin | DIGIT_B1_Pin
                      | DIGIT_B2_Pin | DIGIT_B3_Pin;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DIGIT_A0_Pin | DIGIT_A1_Pin
                      | DIGIT_A2_Pin | DIGIT_A3_Pin;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  __disable_irq();

  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
