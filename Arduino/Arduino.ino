#include <SPI.h>
uint16_t newDataFromUART;
uint16_t spiToSend;
uint16_t spiReceived;

void setup() {
  Serial.begin(9600);
  while (!Serial); 

  pinMode(MISO, OUTPUT);
  pinMode(SS, OUTPUT);
  digitalWrite(SS, LOW); 

  // تهيئة SPI كـ Slave
  SPCR &= ~_BV(MSTR);  // Slave Mode
  SPCR |= _BV(SPE);    // SPI Enable
  SPI.setDataMode(SPI_MODE0);  // CPOL = 0, CPHA = 0 (Same as STM32)
  SPI.setBitOrder(LSBFIRST);   // Same as STM32
}


void loop() 
{
  if (SPSR & _BV(SPIF)) 
  {
    spiReceived = SPDR;  // read data received via SPI from STM32F103
    if (newDataFromUART)  // if it was available data from the PC to send to STM32F103 
    {
      SPDR = spiToSend; // send data from Arduino to STM via SPI
      newDataFromUART = false; // Reset the reading state
    } 
    else 
    {
      SPDR = 0;  // send zero via spi if there is no data to send
    }
    if (spiReceived != 0)  // if STM32F103 Send data 
    {
      Serial.write(spiReceived); // write the data on the terminal, via UART
      spiReceived = 0;
    }
  }

  if (Serial.available() > 0) // PC send data to Arduino via UART
  {
    spiToSend = Serial.read(); // Read the data 
    Serial.write(spiToSend);  // Display it on the screen
    newDataFromUART = true; // available data flag is true
  }
}
