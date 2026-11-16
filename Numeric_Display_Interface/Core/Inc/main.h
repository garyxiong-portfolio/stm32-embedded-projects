/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* USER CODE BEGIN EM */

/* USER CODE END EM */

void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#define DIGIT_B0_Pin GPIO_PIN_0
#define DIGIT_B0_GPIO_Port GPIOC
#define DIGIT_B1_Pin GPIO_PIN_1
#define DIGIT_B1_GPIO_Port GPIOC
#define DIGIT_B2_Pin GPIO_PIN_2
#define DIGIT_B2_GPIO_Port GPIOC
#define DIGIT_B3_Pin GPIO_PIN_3
#define DIGIT_B3_GPIO_Port GPIOC
#define DIGIT_A0_Pin GPIO_PIN_12
#define DIGIT_A0_GPIO_Port GPIOB
#define DIGIT_A1_Pin GPIO_PIN_13
#define DIGIT_A1_GPIO_Port GPIOB
#define DIGIT_A2_Pin GPIO_PIN_14
#define DIGIT_A2_GPIO_Port GPIOB
#define DIGIT_A3_Pin GPIO_PIN_15
#define DIGIT_A3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
