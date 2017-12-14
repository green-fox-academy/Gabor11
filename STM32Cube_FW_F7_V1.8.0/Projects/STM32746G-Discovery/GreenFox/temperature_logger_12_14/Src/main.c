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

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ADDRESS 		0b1001000
#define I2C_ADDRESS 	ADDRESS << 1
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef UartHandle;
RTC_HandleTypeDef RtcHandle;
I2C_HandleTypeDef i2ch;
GPIO_InitTypeDef gpio_init;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void Peripherials_Config(void);
static void UART_Config(void);
static void RTC_Config(void);
static void RTC_SetDateTime(uint8_t year, uint8_t month, uint8_t day, uint8_t weekday, uint8_t hour, uint8_t minute, uint8_t second);
void i2c_init();

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
    Peripherials_Config();

    RTC_SetDateTime(
            17,                         // 2017
            12,                         // december
            12,                         // 12th
            RTC_WEEKDAY_TUESDAY,        // tuesday
            13,                         // hour: 13
            11,                         // minute: 11
            0                           // second: 0
    );

    /**
     * Demo for sending date and time in every second
     */
    RTC_DateTypeDef dDate;
    RTC_TimeTypeDef dTime;
    uint8_t data = 0;
	uint8_t Rx;
    while (1) {
        HAL_RTC_GetTime(&RtcHandle, &dTime, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&RtcHandle, &dDate, RTC_FORMAT_BIN);

        HAL_I2C_Master_Transmit(&i2ch, I2C_ADDRESS, &data, 1, 100);
        HAL_I2C_Master_Receive(&i2ch, I2C_ADDRESS, &Rx, 1, 10000);


        printf("%d.%d.%d. %d:%d:%d", (dDate.Year + 2000), dDate.Month,
                dDate.Date, dTime.Hours, dTime.Minutes, dTime.Seconds);
        printf("\t  %d\n", Rx);

        HAL_Delay(1000);
    }
}

/**
 * Configuring the RTC (real time clock) on the device, this setup results in correct time measurement,
 * so a second passes exactly under 1 second.
 *
 * Hint 1: the HAL_RTC_Init() calls the HAL_RTC_MspInit() function in stm32f7xx_hal_msp.c file. In that
 * function we configure the internal 32kHz oscillator and assign it to the RTC peripherial. Read
 * and understand that code!
 *
 * Hint 2: from the documentation it turns out that you need to adjust the AsynchPrediv and SynchPrediv
 * values to the oscillator to get exact time measurement (just like when you're configuring timers).
 * The current values guarantees to tick in every second:
 *
 * (AsynchPrediv+1)*(SynchPrediv+1) = 32000
 */
static void RTC_Config(void) {
    RtcHandle.Instance = RTC;
    RtcHandle.Init.HourFormat = RTC_HOURFORMAT_24;
    RtcHandle.Init.AsynchPrediv = 124;                  // 124 for 1 second
    RtcHandle.Init.SynchPrediv = 255;                   // 255 for 1 second
    RtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
    RtcHandle.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    RtcHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    HAL_RTC_Init(&RtcHandle);
}

/**
 * This functions configures the RTC date and time to the values specified in the parameters.
 */
static void RTC_SetDateTime(uint8_t year, uint8_t month, uint8_t day, uint8_t weekday,
        uint8_t hour, uint8_t minute, uint8_t second) {
    RTC_DateTypeDef sDate;
    RTC_TimeTypeDef sTime;

    sDate.Year = year;
    sDate.Month = month;
    sDate.Date = day;
    sDate.WeekDay = weekday;
    HAL_RTC_SetDate(&RtcHandle, &sDate, RTC_FORMAT_BIN);

    sTime.Hours = hour;
    sTime.Minutes = minute;
    sTime.Seconds = second;
    sTime.TimeFormat = RTC_HOURFORMAT_24;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    HAL_RTC_SetTime(&RtcHandle, &sTime, RTC_FORMAT_BIN);
}

void i2c_init()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();                           // enable GPIO clock
	__HAL_RCC_I2C1_CLK_ENABLE();                          // enable the clock of the used peripheral

    // configure GPIOs for I2C data and clock lines
    gpio_init.Speed 	 	 = GPIO_SPEED_FAST;
    gpio_init.Pull			 = GPIO_PULLUP;
	gpio_init.Pin 			 = GPIO_PIN_8 | GPIO_PIN_9;
	gpio_init.Mode           = GPIO_MODE_AF_OD;      //configure in open drain mode
	gpio_init.Alternate      = GPIO_AF4_I2C1;


	HAL_GPIO_Init(GPIOB, &gpio_init);

	// defining the I2C configuration structure

	i2ch.Instance             = I2C1;
	i2ch.Init.Timing          = 0x40912732;
	i2ch.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	//i2ch.Init.OwnAddress1     = 0b1001000;
	//i2ch.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	//i2ch.Init.OwnAddress2     = 0xFF;
	//i2ch.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	//i2ch.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

	HAL_I2C_Init(&i2ch);

}

static void Peripherials_Config(void) {
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

    /*
     * Configure UART
     */
    UART_Config();

    /*
     * RTC init
     */
    RTC_Config();

    /*
     * I2C init
     */
    i2c_init();
}

static void UART_Config(void) {
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);

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
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1
            | RCC_CLOCKTYPE_PCLK2);
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
