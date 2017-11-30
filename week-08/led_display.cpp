 /**
  ******************************************************************************
* @file    Templates/Src/main.c
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   STM32F7xx HAL API Template project 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

void initialize()
{
	  /* This project template calls firstly two functions in order to configure MPU feature
	     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
	     These functions are provided as template implementation that User may integrate
	     in his application, to enhance the performance in case of use of AXI interface
	     with several masters. */

	  /* Configure the MPU attributes as Write Through */
	  MPU_Config();

	  /* Enable the CPU Cache */
	  CPU_CACHE_Enable();

	  /* STM32F7xx HAL library initialization:
	       - Configure the Flash ART accelerator on ITCM interface
	       - Configure the Systick to generate an interrupt each 1 msec
	       - Set NVIC Group Priority to 4
	       - Low Level Initialization
	     */
	  HAL_Init();

	  /* Configure the System clock to have a frequency of 216 MHz */
	  SystemClock_Config();


	  /* Add your application code here     */
	  //BSP_LED_Init(LED_GREEN);
	  //BSP_LED_On(LED_GREEN);

	  __HAL_RCC_GPIOA_CLK_ENABLE();    // we need to enable the GPIOA port's clock first
	  __HAL_RCC_GPIOF_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOI_CLK_ENABLE();
	  __HAL_RCC_GPIOH_CLK_ENABLE();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOG_CLK_ENABLE();

	  GPIO_InitTypeDef p0;
	 /* GPIO_InitTypeDef p1;
	  GPIO_InitTypeDef p2;
	  GPIO_InitTypeDef p3;
	  GPIO_InitTypeDef p4; */

	  p0.Pin = GPIO_PIN_0;            // this is about PIN 0
	  p0.Mode = GPIO_MODE_OUTPUT_OD;  // Configure as output with push-up-down enabled
	  p0.Pull = GPIO_PULLUP;        // the push-up-down should work as pulldown
	  p0.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

	  HAL_GPIO_Init(GPIOA, &p0);      // initialize the pin on GPIOA port with HAL

	  GPIO_InitTypeDef p1 = p0;
	  p1.Pin = GPIO_PIN_10;            // this is about PIN 1

	  HAL_GPIO_Init(GPIOF, &p1);

	  GPIO_InitTypeDef p2 = p0;
	  p2.Pin = GPIO_PIN_9;            // this is about PIN 2

	  HAL_GPIO_Init(GPIOF, &p2);

	  GPIO_InitTypeDef p3 = p0;
	  p3.Pin = GPIO_PIN_8;            // this is about PIN 3

	  HAL_GPIO_Init(GPIOF, &p3);

	  GPIO_InitTypeDef p4 = p0;
	  p4.Pin = GPIO_PIN_7;            // this is about PIN 4

	  HAL_GPIO_Init(GPIOF, &p4);

	  GPIO_InitTypeDef p5 = p0;
	  p5.Pin = GPIO_PIN_6;            // this is about PIN 5

	  HAL_GPIO_Init(GPIOF, &p5);

	  GPIO_InitTypeDef p6 = p0;
	  p6.Pin = GPIO_PIN_7;            // this is about PIN 6 (D0 on board, PC7 on STM)

	  HAL_GPIO_Init(GPIOC, &p6);

	  GPIO_InitTypeDef p7 = p0;
	  p7.Pin = GPIO_PIN_6;            // this is about PIN 7 (D1 on board, PC6 on STM)

	  HAL_GPIO_Init(GPIOC, &p7);

	  GPIO_InitTypeDef p8 = p0;
	  p8.Pin = GPIO_PIN_6;            // this is about PIN 8 (D2 on board, PG6 on STM)

	  HAL_GPIO_Init(GPIOG, &p8);

	  GPIO_InitTypeDef p9 = p0;
	  p9.Pin = GPIO_PIN_4;            // this is about PIN 9 (D3 on board, PB4 on STM)

	  HAL_GPIO_Init(GPIOB, &p9);

	  GPIO_InitTypeDef p10 = p0;
	  p10.Pin = GPIO_PIN_7;            // this is about PIN 10 (D4 on board, PG7 on STM)

	  HAL_GPIO_Init(GPIOG, &p10);

	  GPIO_InitTypeDef p11 = p0;
	  p11.Pin = GPIO_PIN_0;            // this is about PIN 11 (D5 on board, PI0 on STM)

	  HAL_GPIO_Init(GPIOI, &p11);

	  GPIO_InitTypeDef p12 = p0;
	  p12.Pin = GPIO_PIN_6;            // this is about PIN 12 (D6 on board, PH6 on STM)

	  HAL_GPIO_Init(GPIOH, &p12);

	  GPIO_InitTypeDef p13 = p0;
	  p13.Pin = GPIO_PIN_3;            // this is about PIN 13 (D7 on board, PI3 on STM)

	  HAL_GPIO_Init(GPIOI, &p13);

	  GPIO_InitTypeDef p14 = p0;
	  p14.Pin = GPIO_PIN_2;            // this is about PIN 14 (D8 on board, PI2 on STM)

	  HAL_GPIO_Init(GPIOI, &p14);


}

void light_up(uint8_t pin) {
	switch (pin) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 12:
		HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 13:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	case 14:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);   // setting the pin to 1
		break;
	}
}


void turn_off(uint8_t pin)
{
	switch (pin) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 12:
		HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 13:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);   // setting the pin to 1
		break;
	case 14:
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   // setting the pin to 1
		break;
	}
}

int main()
{

	initialize();

	while (1) {
		light_up(0);
		HAL_Delay(200);
		turn_off(0);

		light_up(1);
		HAL_Delay(200);
		turn_off(1);

		light_up(2);
		HAL_Delay(200);
		turn_off(2);

		light_up(3);
		HAL_Delay(200);
		turn_off(3);

		light_up(4);
		HAL_Delay(200);
		turn_off(4);

		light_up(5);
		HAL_Delay(200);
		turn_off(5);

		light_up(6);
		HAL_Delay(200);
		turn_off(6);

		light_up(7);
		HAL_Delay(200);
		turn_off(7);

		light_up(8);
		HAL_Delay(200);
		turn_off(8);

		light_up(9);
		HAL_Delay(200);
		turn_off(9);

		light_up(10);
		HAL_Delay(200);
		turn_off(10);

		light_up(11);
		HAL_Delay(200);
		turn_off(11);

		light_up(12);
		HAL_Delay(200);
		turn_off(12);

		light_up(13);
		HAL_Delay(200);
		turn_off(13);

		light_up(14);
		HAL_Delay(200);
		turn_off(14);



	}







 /*
  HAL_Delay(1000);                                      // wait a second
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET); // setting the pin to 0


  /* Infinite loop
  while (1)
  {
	  //TODO:
	  //Flash the ledwith 200 ms period time

	  //HAL_Delay(100);
	  //BSP_LED_Toggle(LED_GREEN);

  }
	*/
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
