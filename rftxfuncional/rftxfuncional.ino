#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h>
#include <SPI.h>

Enrf24 radio(P2_0, P2_1, P2_2);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
const uint8_t txaddr[] = { 0xE7, 0xD3, 0xF0, 0x35, 0xFF };
 
const char str_on[10] = "oda";
 
void setup() {
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(1); // MSB-first
 
  radio.begin(1000000);  // Defaults 1Mbps, channel 0, max TX power
  radio.setChannel(76);
  radio.setCRC(1,1); 
  radio.setTXaddress((void*)txaddr);
}
 
void loop() {
  radio.print(str_on);
  radio.flush();  // Force transmit (don't wait for any more data)
  delay(1000);
}
