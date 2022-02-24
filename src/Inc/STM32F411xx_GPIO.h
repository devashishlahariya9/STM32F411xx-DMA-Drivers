/*
 * STM32F411xx_GPIO.h
 *
 * Created on: 03-Nov-2021
 * Author: Devashish Lahariya
*/


#ifndef STM32F411XX_GPIO_H_
#define STM32F411XX_GPIO_H_

#include <stdint.h>
#include "STM32F411xx.h"

#define LOW_SPEED    0U
#define MEDIUM_SPEED 1U
#define FAST_SPEED   2U
#define HIGH_SPEED   3U

#define PUSH_PULL    0U
#define OPEN_DRAIN   1U

#define INPUT  		 0U
#define GPIO  		 1U
#define AFIO   		 2U
#define ANALOG 		 3U

#define PORTA 		 0U
#define PORTB 		 1U
#define PORTC 		 2U
#define PORTD 		 3U
#define PORTE		 4U

#define LOW			 0U
#define HIGH		 1U

#define FPU 			((FPU_PERIPHERALS_t*)      0xE000ED88)

#define RCC 			((RCC_PERIPHERALS_t*)      0x40023800)

#define GPIOA 			((GPIO_PERIPHERALS_t*)     0x40020000)
#define GPIOB 			((GPIO_PERIPHERALS_t*)     0x40020400)
#define GPIOC 			((GPIO_PERIPHERALS_t*)	   0x40020800)
#define GPIOD 			((GPIO_PERIPHERALS_t*)	   0x40020C00)
#define GPIOE 			((GPIO_PERIPHERALS_t*)	   0x40021000)

#define SPI1 			((SPI_PERIPHERALS_t*)	   0x40013000)

#define I2C1 			((I2C_PERIPHERALS_t*)	   0x40005400)

#define EXTI 			((EXTI_PERIPHERALS_t*)	   0x40013C00)

#define NVIC_ISER 		((NVIC_ISER_PERIPHERALS_t*)0xE000E100)
#define NVIC_ICER 		((NVIC_ICER_PERIPHERALS_t*)0xE000E180)
#define NVIC_ISPR 		((NVIC_ISPR_PERIPHERALS_t*)0xE000E200)
#define NVIC_ICPR 		((NVIC_ICPR_PERIPHERALS_t*)0xE000E280)
#define NVIC_IABR 		((NVIC_IABR_PERIPHERALS_t*)0xE000E300)
#define NVIC_IPR 		((NVIC_IPR_PERIPHERALS_t*) 0xE000E400)

#define SYSCFG 			((SYSCFG_PERIPHERALS_t*)   0x40013800)

#define DMA1			((DMA_PERIPHERALS_t*)	   0x40026000)
#define DMA1_STREAM0	((DMA_STREAM_t*)		   0x40026010)
#define DMA1_STREAM1	((DMA_STREAM_t*)		   0x40026028)
#define DMA1_STREAM2	((DMA_STREAM_t*)		   0x40026040)
#define DMA1_STREAM3	((DMA_STREAM_t*)		   0x40026058)
#define DMA1_STREAM4	((DMA_STREAM_t*)		   0x40026070)
#define DMA1_STREAM5	((DMA_STREAM_t*)		   0x40026088)
#define DMA1_STREAM6	((DMA_STREAM_t*)		   0x400260A0)
#define DMA1_STREAM7	((DMA_STREAM_t*)		   0x400260B8)

#define DMA2			((DMA_PERIPHERALS_t*)	   0x40026400)
#define DMA2_STREAM0	((DMA_STREAM_t*)		   0x40026410)
#define DMA2_STREAM1	((DMA_STREAM_t*)		   0x40026428)
#define DMA2_STREAM2	((DMA_STREAM_t*)		   0x40026440)
#define DMA2_STREAM3	((DMA_STREAM_t*)		   0x40026458)
#define DMA2_STREAM4	((DMA_STREAM_t*)		   0x40026470)
#define DMA2_STREAM5	((DMA_STREAM_t*)		   0x40026488)
#define DMA2_STREAM6	((DMA_STREAM_t*)		   0x400264A0)
#define DMA2_STREAM7	((DMA_STREAM_t*)		   0x400264B8)

enum AF
{
	AF0 = 0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
};

void GPIO_setMode(uint8_t _port, uint8_t _pin, uint8_t _speed, uint8_t _type, uint8_t _mode);
void GPIO_pin(uint8_t _port, uint8_t _pin, uint8_t _state);
void GPIO_toggle(uint8_t _port, uint8_t _pin);

#endif /* STM32F411XX_GPIO_H_ */
