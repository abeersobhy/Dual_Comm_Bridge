#ifndef STM32F103XX_H_
#define STM32F103XX_H_

/****************************************
 * Includes
 ***************************************/
#include <stdio.h>
#include <stdlib.h>
/****************************************
* Base addresses for memories
 ***************************************/
#define FLASH_MEMORY_BASE_ADDRESS  			 	0x08000000UL
#define SYSTEM_MEMORY_BASE_ADDRESS  		 	0x1FFFF000UL
#define STM32F103XX_PERIPHERAL_BASE_ADDRESS  	0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERAL  		 	0xE0000000UL


/****************************************
* Base addresses for BUS peripherals
 ***************************************/
// AHB Peripherals
#define RCC_BASE  	     						0x40021000UL

// APB2 Peripherals
#define GPIOA_BASE		 						0x40010800UL
#define GPIOB_BASE	     						0x40010C00UL
#define GPIOC_BASE		 						0x40011000UL

#define EXTI_BASE	     						0x40010400UL

#define AFIO_BASE		 						0x40010000UL

#define NVIC_BASE								0xE000E100UL

#define USART1_BASE								0x40013800UL
#define USART2_BASE								0x40004400UL
#define USART3_BASE								0x40004800UL

#define SPI1_BASE								0x40013000UL
#define SPI2_BASE								0x40003800UL

/****************************************
* Peripherals registers
 ***************************************/
#define	NVIC_ISER0			*(volatile uint32_t*)(NVIC_BASE + 0x000)
#define	NVIC_ISER1			*(volatile uint32_t*)(NVIC_BASE + 0x004)
#define	NVIC_ISER2		    *(volatile uint32_t*)(NVIC_BASE + 0x008)
#define	NVIC_ICER0			*(volatile uint32_t*)(NVIC_BASE + 0x080)
#define	NVIC_ICER1			*(volatile uint32_t*)(NVIC_BASE + 0x084)
#define	NVIC_ICER2			*(volatile uint32_t*)(NVIC_BASE + 0x088)

//* GPIO
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIOx_typedef;
//*RCC registers
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
}RCC_typedef;

//AFIO
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_typedef;

//EXTI
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_typedef;

//USARTx
typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}USART_typedef;

//SPIx
typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;

}SPIx_typedef;

/****************************************
* Peripheral instants
***************************************/

#define GPIOA 			((GPIOx_typedef*)GPIOA_BASE)
#define GPIOB  			((GPIOx_typedef*)GPIOB_BASE)
#define GPIOC 			((GPIOx_typedef*)GPIOC_BASE)

#define RCC 	 		((RCC_typedef*)RCC_BASE)
#define EXTI	 		((EXTI_typedef*)EXTI_BASE)
#define AFIO  			((AFIO_typedef*)AFIO_BASE)

#define USART1  		((USART_typedef*)USART1_BASE)
#define USART2  		((USART_typedef*)USART2_BASE)
#define USART3  		((USART_typedef*)USART3_BASE)

#define SPI1  			((SPIx_typedef*)SPI1_BASE)
#define SPI2  			((SPIx_typedef*)SPI2_BASE)


/****************************************
* Clock enable Macros
***************************************/
#define RCC_GPIOA_CLK_EN()		((RCC->APB2ENR) |= (1 << 2))
#define RCC_GPIOB_CLK_EN()		((RCC->APB2ENR) |= (1 << 3))
#define RCC_GPIOC_CLK_EN()		((RCC->APB2ENR) |= (1 << 4))

#define RCC_AFIO_CLK_EN()		((RCC->APB2ENR) |= (1 << 0))

#define RCC_USART1_CLK_EN()		((RCC->APB2ENR) |= (1 << 14))
#define RCC_USART2_CLK_EN()		((RCC->APB1ENR) |= (1 << 17))
#define RCC_USART3_CLK_EN()		((RCC->APB1ENR) |= (1 << 18))

#define RCC_SPI1_CLK_EN()		((RCC->APB2ENR) |= (1 << 12))
#define RCC_SPI2_CLK_EN()		((RCC->APB1ENR) |= (1 << 14))


/****************************************
* Generic Macro
 ***************************************/
//@Re EXTIx_IRQ
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10

#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23

#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

// @ref USARTx_IRQ
#define USART1_IRQ			37
#define USART2_IRQ			38
#define USART3_IRQ			39

#define SPI1_IRQ			35
#define SPI2_IRQ			36

/*=====================================*/
//NVIC EXTI Enable/Disable MACROs

#define NVIC_EXTI0_Enable			(NVIC_ISER0 |= (1 << 6))
#define NVIC_EXTI1_Enable			(NVIC_ISER0 |= (1 << 7))
#define NVIC_EXTI2_Enable			(NVIC_ISER0 |= (1 << 8))
#define NVIC_EXTI3_Enable			(NVIC_ISER0 |= (1 << 9))
#define NVIC_EXTI4_Enable			(NVIC_ISER0 |= (1 << 10))
#define NVIC_EXTI5_9_Enable			(NVIC_ISER0 |= (1 << 23))
#define NVIC_EXTI10_15_Enable		(NVIC_ISER1 |= (1 << 8)) //40 - 32

#define NVIC_EXTI0_Disable			(NVIC_ICER0 |= (1 << 6))
#define NVIC_EXTI1_Disable			(NVIC_ICER0 |= (1 << 7))
#define NVIC_EXTI2_Disable			(NVIC_ICER0 |= (1 << 8))
#define NVIC_EXTI3_Disable			(NVIC_ICER0 |= (1 << 9))
#define NVIC_EXTI4_Disable			(NVIC_ICER0 |= (1 << 10))
#define NVIC_EXTI5_9_Disable		(NVIC_ICER0 |= (1 << 23))
#define NVIC_EXTI10_15_Disable		(NVIC_ICER1 |= (1 << 8)) //40 - 32

//NVIC USARTx Enable/Disable MACROs

#define NVIC_USART1_Enable			(NVIC_ISER1 |= (1 << 5))  //37-32
#define NVIC_USART2_Enable			(NVIC_ISER1 |= (1 << 6))  //38-32
#define NVIC_USART3_Enable			(NVIC_ISER1 |= (1 << 7))  //39-32

#define NVIC_USART1_Disable			(NVIC_ICER1 |= (1 << 5))
#define NVIC_USART2_Disable			(NVIC_ICER1 |= (1 << 6))
#define NVIC_USART3_Disable			(NVIC_ICER1 |= (1 << 7))

#define NVIC_SPI1_Enable			(NVIC_ISER1 |= (1 << 3))  //35-32
#define NVIC_SPI2_Enable			(NVIC_ISER1 |= (1 << 4))  //36-32

#define NVIC_SPI1_Disable			(NVIC_ICER1 |= (1 << 3))
#define NVIC_SPI2_Disable			(NVIC_ICER1 |= (1 << 4))

#endif
