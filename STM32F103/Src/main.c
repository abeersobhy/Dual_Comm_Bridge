#include <stdlib.h>
#include <stdint.h>

#include "LCD.h"
#include "UART.h"
#include "SPI.h"

void UART_ISR();
uint16_t rd_UART = 0;

int main(void)
{
	USARTx_Config_t uart =
	{
		.USART_BaudRate = 9600,
		.USART_DataLength = USART_8BIT_DATA,
		.USART_Interrupt_Status = USART_RX_withInterrupt_Enable,
		.USART_Polling_Status = USART_Poliing_Disable,
		.USART_StopBits = USART_1_STOP_BIT,
		.USART_TX_RX_Mode = USART_RX_TX,
		.USARTx_IRQ_CallBack = UART_ISR,
		.USARTx = USART1,
	};

	SPIx_Config_t spi =
	{
		.SPI_CLK_Idle = SPI_CLK_POL_Idle_LOW,
		.SPI_Sampling = SPI_PHA_Sample_first_transition,

		.SPI_Communication_Mode = SPI_RX_TX_2LINE,
		.SPI_Data_Frame_Format = SPI_8_Frame_Format,
		.SPI_First_Bit = SPI_LSB_FIRST,
		.SPI_Interrupt = SPI_Interrupt_Disable,
		.SPI_MASTER_CLK_PRESCALER = SPIx_M_CLK_256,
		.SPI_Mode = SPI_Mode_Master,
		.SPI_NSS_Mangement = SPI_NSS_SW,
		.SPIx = SPI1,
	};

	LCD_Init();
	SPIx_Init(&spi);
	USARTx_Init(&uart);

	uint16_t rdata = 0;

	while (1)
    {
		if((rd_UART != 0x0A) && (rd_UART != 0x0D) && (rd_UART != 0)) /**/
		{
			LCD_Write_Char((uint8_t)rd_UART); /*Display the data from PC to LCD .*/
			USARTx_Write(USART1, rd_UART); /*Send this data to the PC again via UART using USB/TTL.*/
			SPIx_Send_Receive(SPI1,&rd_UART, &rdata, SPI_Interrupt_Disable); /*send the received data via SPI to slave.*/
			delay_ms(5);
			rd_UART = 0;
		}
		else if(rd_UART == 0x0A || rd_UART == 0x0D) /*Clear the LCD with Enter Click - where Enter = 0x0D or 0X0A.*/
		{
			LCD_Write_Command(LCD_Clear); /*Clear the LCD*/
			rd_UART = 0; /*reset the received data*/
			rdata = 0;
		}
		else{}

		SPIx_Send_Receive(SPI1,&rd_UART, &rdata, SPI_Interrupt_Disable); /*Receive data from the slave Via SPI.*/
		delay_ms(5);
		if(rdata != 0)
		{
			USARTx_Write(USART1, rdata); /*Send data to via UART to PC using USB/TTL.*/
		}
    }
}
void UART_ISR() /*Read data from PC, immediately via Interrupt.*/
{
	rd_UART = USARTx_Read(USART1);
}
