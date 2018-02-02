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
typedef enum{
	WAITING,
	MORSE_SIGNAL,
	MORSE_BREAK,
	SENDING
}STATES;

typedef enum {
	SIGNAL0,
	SIGNAL1,
	SIGNAL_TOO_SHORT,
	SIGNAL_TOO_LONG,
	WAITING_2_SIGNAL,
	BREAK_2_SENDING,
	SENDING_2_WAITING
}TRANSITION;

/*
 * WAITING:
 * 		- the tickstart, tickfin, startflag variables are set to default (0) and the morse_char is set to 1.
 * 		- transition only allowed to RECEIVING state
 * MORSE_SIGNAL:
 * 		- we enter this state as the first interrupt arrives from the button
 * 		- tickstart: stores the initial clocktime (rising edge - pushing the button)
 * 		- tickfin: empty ..
 * 		- startflag: set to 1 with the first interrupt and back to 0 with the next one (helps to control which of the two above should be written)
 * 		- morse_char: the value of one "morse-bit" is shifted into it after the "evaluate()" function evaluated which value should be given to it
 *
 * MORSE_BREAK:
 * 		- tickfin: stores the second clocktime (falling edge - releasing the button)
 * SENDING:
 * 		- morse_char: this value should be used to look up the char which should be sent to the serial port
 * 		- if the character cannot be evaluated (not in the list) it should just shift to the next state (WAITING) without sending..
 * 		- sending the character (printf())..
 * 		- after it goes to the next state (WAITING)
 *
 */

typedef struct{
	STATES state;
	uint16_t tickstart;
	uint8_t startflag; // if 'tickstart' is set it must be 1 else 0.
	uint16_t tickfin;
	uint8_t morse_char;
}STATE;
/* Private define ------------------------------------------------------------*/
#define PERIODE		10000
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef tim_handle;
GPIO_InitTypeDef gpio_init_structure;
STATE st;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void Peripherials_Config(void);
static void UART_Config(void);
void interrupt_timer();
void second_timer();
uint16_t get_tick_tim2();
uint8_t evaluate();


/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
    Peripherials_Config();
    init_state_machine();

    while (1) {
    	switch (st.state) {
    	case WAITING:

    		break;
    	case MORSE_SIGNAL:

    		break;
    	case MORSE_BREAK:

    		break;
    	case SENDING:

    		break;
    	default:
    		break;
    	}

    }
}

void interrupt_timer() {
	__HAL_RCC_TIM2_CLK_ENABLE();

	tim_handle.Instance               = TIM2;
	tim_handle.Init.Period            = PERIODE;
	tim_handle.Init.Prescaler         = 54000;
	tim_handle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode 		 = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle);
	HAL_TIM_Base_Start_IT(&tim_handle);

}

void second_timer() {
	__HAL_RCC_TIM3_CLK_ENABLE();

	tim_handle.Instance               = TIM3;
	tim_handle.Init.Period            = 750;
	tim_handle.Init.Prescaler         = 54000;
	tim_handle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle.Init.CounterMode 		 = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle);
	HAL_TIM_Base_Start_IT(&tim_handle);

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
     * TIM2 init
     */
    interrupt_timer();

	HAL_NVIC_SetPriority(TIM2_IRQn, 0xf, 0x0);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0xe, 0x0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	/*
	 *  LED init
	 */
	BSP_LED_Init(LED_GREEN);

	/*
	 * BUTTTON init for interrupt
	 */
	__HAL_RCC_GPIOI_CLK_ENABLE();         				// enable the GPIOI clock


	gpio_init_structure.Pin = GPIO_PIN_11;              // the pin is the 11

	gpio_init_structure.Pull = GPIO_NOPULL;
	gpio_init_structure.Speed = GPIO_SPEED_FAST;        // port speed to fast

	/* Here is the trick: our mode is interrupt on rising and falling edge */

	gpio_init_structure.Mode = GPIO_MODE_IT_RISING_FALLING;

	HAL_GPIO_Init(GPIOI, &gpio_init_structure);


    /*
     * SETTING UP NVIC FOR INTERRUPT HANDLING ON I11 BUTTON
     */
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0F, 0x00);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void init_state_machine()
{
	/* SETTING UP STATE LIKE IN "WAITING" */
    st.state = WAITING;
    st.tickstart = 0;
    st.startflag = 0;
    st.tickfin = 0;
    st.morse_char = 1;
}

void next_state()
{
	switch (st.state) {
	case WAITING:
		st.state = MORSE_SIGNAL;
		break;
	case MORSE_SIGNAL:
		st.state = MORSE_BREAK;
		break;
	case MORSE_BREAK:
		st.state = SENDING;
		break;
	case SENDING:
	    st.state = WAITING;
	    st.tickstart = 0;
	    st.startflag = 0;
	    st.tickfin = 0;
	    st.morse_char = 1;
		break;
	default:
		break;
	}
}

void morse_switch()
{
	switch (st.state) {
	case MORSE_SIGNAL:
		st.state = MORSE_BREAK;
		break;
	case MORSE_BREAK:
		st.state = MORSE_SIGNAL;
		break;
	default:
		break;
	}
}

char look_up(uint8_t morse_char)
{
	switch (morse_char) {
	case 0b101:
		return 'a';
	case 0b11010:
		return 'c';
	case 0b100:
		return 'i';
	case 0b1111:
		return 'o';
	case 0b1000:
		return 's';
	}
}

uint16_t get_tick_tim2()
{
	return TIM2->CNT;
}

uint8_t evaluate()
{
	/*

	switch(st.state) {
	case WAITING:
		next_state();
		return evaluate();
		break;
	case MORSE_SIGNAL:
		// in case the timer would have been overflown
		if (st.tickstart >= st.tickfin) {
			if ((10000 - st.tickstart + st.tickfin) > 25 && (10000 - st.tickstart + st.tickfin) < 250)
				return 0;
			else if ((10000 - st.tickstart + st.tickfin) > 250 && (10000 - st.tickstart + st.tickfin) < 750)
				return 1;
			else if ((10000 - st.tickstart + st.tickfin) > 750)
				return 2; // too long signal
			else
				return 3; // too short signal
		} else {
			if ((st.tickfin - st.tickstart) > 25 && (st.tickfin - st.tickstart) < 250)
				return 0;
			else if ((st.tickfin - st.tickstart) > 250 && (st.tickfin - st.tickstart) < 750)
				return 1;
			else if ((st.tickfin - st.tickstart) > 750)
				return 2; // too long signal
			else
				return 3; // too short signal
		}
		break;
	case MORSE_BREAK:
		st.state = SENDING;
		break;
	case SENDING:
	    st.state = WAITING;
	    st.tickstart = 0;
	    st.startflag = 0;
	    st.tickfin = 0;
	    st.morse_char = 1;
		break;
	default:
		break;
		*/
	return 0;
}

/***** INTERRUPTS ******/

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	// need to be filled
		BSP_LED_Toggle(LED_GREEN);
		second_timer();
}

void TIM3_IRQHandler() {
	HAL_TIM_IRQHandler(&tim_handle);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	/*switch (st.state) {
	case WAITING:
		st.tickstart = get_tick_tim2();
		st.startflag = 1;
		next_state();
		break;
	case MORSE_SIGNAL:
		if(st.startflag == 0 && evaluate(&st.tickstart, &st.tickfin) ) {
			st.tickstart = get_tick_tim2();
			st.startflag = 1;
			morse_switch();
		} else {
			st.tickfin = get_tick_tim2();
			st.startflag = 0;
			if (evaluate(&st.tickstart, &st.tickfin) == 0 || evaluate(&st.tickstart, &st.tickfin) == 1) {
				st.morse_char <<= 1;
				st.morse_char  |= evaluate(&st.tickstart, &st.tickfin);
			}
			// lookup function must be called
		}
		break;
	case MORSE_BREAK:

		break;
	case SENDING:

		break;
	default:
		break;
	}
	*/
	/*
	 * interrupt is thrown when button pressed
	 */


}

static void UART_Config(void) {
    /* Enable GPIO clock */
  	  __HAL_RCC_GPIOA_CLK_ENABLE();
  	  __HAL_RCC_GPIOB_CLK_ENABLE();

    /* Enable USART clock */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* Configure USART Tx as alternate function */
    gpio_init_structure.Pin = GPIO_PIN_9;
    gpio_init_structure.Mode = GPIO_MODE_AF_PP;
    gpio_init_structure.Speed = GPIO_SPEED_FAST;
    gpio_init_structure.Pull = GPIO_PULLUP;
    gpio_init_structure.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &gpio_init_structure);

    /* Configure USART Rx as alternate function */
    gpio_init_structure.Pin = GPIO_PIN_7;
    gpio_init_structure.Mode = GPIO_MODE_AF_PP;
    gpio_init_structure.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &gpio_init_structure);

    /* USART configuration */
    uart_handle.Init.BaudRate   = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits   = UART_STOPBITS_1;
    uart_handle.Init.Parity     = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode       = UART_MODE_TX_RX;

    uart_handle.Instance = USART1;
    HAL_UART_Init(&uart_handle);
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
