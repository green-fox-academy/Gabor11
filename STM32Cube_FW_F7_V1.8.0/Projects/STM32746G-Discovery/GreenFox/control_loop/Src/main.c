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
#include <string.h>

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
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef PBup;
GPIO_InitTypeDef PBdown;
GPIO_InitTypeDef feedback;
volatile uint32_t fb_val = 0;
volatile uint32_t fb_tick;
TIM_HandleTypeDef timh;
TIM_HandleTypeDef timh2;
TIM_OC_InitTypeDef output_compare_config;
TIM_IC_InitTypeDef input_capture_config;
GPIO_InitTypeDef gate;

volatile uint32_t timIntPeriod;

/* Private function prototypes -----------------------------------------------*/

void init_buttons(GPIO_InitTypeDef *PBup, GPIO_InitTypeDef *PBdown);
void init_feedback(GPIO_InitTypeDef *feedback);
void timer_1_initialize_start(TIM_HandleTypeDef *timh, TIM_OC_InitTypeDef *output_compare_config);
void timer_2_initialize_start(TIM_HandleTypeDef *timh2, TIM_IC_InitTypeDef *input_capture_config);
void init_gate(GPIO_InitTypeDef *gate);

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

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
int main(void) {
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


	/* INPUT INITIALIZATIONS */

	init_buttons(&PBup, &PBdown);
	timer_2_initialize_start(&timh2, &input_capture_config);
	init_feedback(&feedback);

	/* OUTPUT INITIALIZATIONS */

	timer_1_initialize_start(&timh, &output_compare_config);
	init_gate(&gate);

	/* SETTING UP INTERRUPTS */
	/* assign the lowest priority to our interrupt line */
	/* tell the interrupt handling unit to process our interrupts */
	/* A1 (PF10) and A2 (PF9) are initialized */
	HAL_NVIC_SetPriority(EXTI9_5_IRQn , 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn , 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(TIM2_IRQn , 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0x0e, 0x00);

	/* Add your application code here
	 */


	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);


	printf("\n-----------------WELCOME-----------------\r\n");
	printf("**********in STATIC interrupts WS**********\r\n\n");


	while (1) {
		HAL_Delay(5000);
		printf("%d\n", HAL_TIM_ReadCapturedValue(&timh2, TIM_CHANNEL_1));
	}
}

void init_buttons(GPIO_InitTypeDef *PBup, GPIO_InitTypeDef *PBdown)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	PBup->Pin = GPIO_PIN_10;
	PBup->Mode = GPIO_MODE_IT_FALLING;
	PBup->Pull = GPIO_PULLUP;
	PBup->Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, PBup);

	PBdown->Pin = GPIO_PIN_9;
	PBdown->Mode = GPIO_MODE_IT_FALLING;
	PBdown->Pull = GPIO_PULLUP;
	PBdown->Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, PBdown);
}

void init_feedback(GPIO_InitTypeDef *feedback)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	feedback->Pin = GPIO_PIN_15;
	feedback->Mode = GPIO_MODE_IT_FALLING;
	feedback->Pull = GPIO_PULLUP;
	feedback->Speed = GPIO_SPEED_FAST;
	feedback->Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, feedback);

}

void init_gate(GPIO_InitTypeDef *gate)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gate->Pin = GPIO_PIN_8;
	gate->Mode = GPIO_MODE_AF_PP;
	gate->Pull = GPIO_PULLDOWN;
	gate->Speed = GPIO_SPEED_FAST;
	gate->Alternate = GPIO_AF1_TIM1;
	HAL_GPIO_Init(GPIOA, gate);
}

void timer_1_initialize_start(TIM_HandleTypeDef *timh, TIM_OC_InitTypeDef *output_compare_config)
{
	__HAL_RCC_TIM1_CLK_ENABLE();              // enable TIM1 clock



	timh->Instance               = TIM1;
	timh->Init.Period            = 1000;
	timh->Init.Prescaler         = 50000;
	timh->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	timh->Init.CounterMode       = TIM_COUNTERMODE_UP;
	//timh.Init.RepetitionCounter = 0;

	HAL_TIM_Base_Init(timh);            //Configure the timer

	HAL_TIM_Base_Start(timh);

	// PWM Mode
	HAL_TIM_PWM_Init(timh);

	output_compare_config->OCMode      = TIM_OCMODE_PWM1;
	output_compare_config->Pulse		= 200;
	HAL_TIM_PWM_ConfigChannel(timh, output_compare_config, TIM_CHANNEL_1);

	//HAL_TIM_PWM_Start_IT(timh, TIM_CHANNEL_1);  // -> start it with interrupt

	HAL_TIM_PWM_Start(timh, TIM_CHANNEL_1); // -> start it without interrupts
}

void timer_2_initialize_start(TIM_HandleTypeDef *timh2, TIM_IC_InitTypeDef *input_capture_config)
{
	__HAL_RCC_TIM1_CLK_ENABLE();              // enable TIM1 clock



	timh2->Instance               = TIM2;
	timh2->Init.Period            = 0xffff;
	timh2->Init.Prescaler         = 0;
	timh2->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	timh2->Init.CounterMode       = TIM_COUNTERMODE_UP;
	timh2->Init.RepetitionCounter = 0;
	timh2->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_IC_Init(timh2);            //Configure the timer

	/*##-2- Configure the Input Capture channel ################################*/
	/* Configure the Input Capture of channel 2 */
	input_capture_config->ICPolarity  = TIM_ICPOLARITY_RISING;
	input_capture_config->ICSelection = TIM_ICSELECTION_DIRECTTI;
	input_capture_config->ICPrescaler = TIM_ICPSC_DIV1;
	input_capture_config->ICFilter    = 0;
	HAL_TIM_IC_ConfigChannel(timh2, input_capture_config, TIM_CHANNEL_1);

	HAL_TIM_IC_Start_IT(timh2, TIM_CHANNEL_1); // -> start it with interrupts
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if (GPIO_Pin == GPIO_PIN_9 && TIM1->CCR1 >= 100)
		TIM1->CCR1 -= 100;
	else if (GPIO_Pin == GPIO_PIN_10 && TIM1->CCR1 <= 900)
		TIM1->CCR1 += 100;
	printf("pulse set: %d\n", (int)TIM1->CCR1);
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timh2);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *timh2)
{
	if (fb_val != 0)
		fb_val = 60000 / ((HAL_GetTick() - fb_tick) * 2);
	fb_tick = HAL_GetTick();
	printf("%d\n", (int)fb_val);
}
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

	return ch;
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
static void SystemClock_Config(void) {
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
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
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
static void CPU_CACHE_Enable(void) {
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
