#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <stdlib.h>

//Variables acc y rpm
char text[255] = {0};
short xvec[99] = {0};
short yvec[99] = {0};
short zvec[99] = {0};
char *rpm ;
short x = 0;

RF24 radio(6, 8);

const uint64_t pipes[2] = {0xE7D3F035FF,  0xE7D3F035C2 }; 
void setup()
{
   while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(76);
  radio.setPALevel(RF24_PA_MAX);  
  radio.enableDynamicPayloads();  
  radio.setCRCLength(RF24_CRC_16);  
  
  radio.openReadingPipe(1, pipes[0]);
  radio.openReadingPipe(2, pipes[1]);
  
  radio.startListening();
}

void loop()
{
  Serial.print("tiempo:");
  Serial.println(millis());
  if (radio.available()){
          radio.read(&text, sizeof(text));  
          if (text[0] == 'a'){
               do{
                 if (radio.available()){
                    radio.read(&text, sizeof(text));   
                    Serial.println(text);
                     if (text[0] == 'a'){
                      Serial.println("cayo aca acc");
                       String str(text);
                       xvec[x*3] = str.substring(1, 4).toInt();
                       yvec[x*3] = str.substring(4, 7).toInt();
                       zvec[x*3] = str.substring(7, 10).toInt();
                       xvec[(x*3)+1] = str.substring(10, 13).toInt();
                       yvec[(x*3)+1] = str.substring(13, 16).toInt();
                       zvec[(x*3)+1] = str.substring(16, 19).toInt();
                       xvec[(x*3)+2] = str.substring(19, 22).toInt();
                       yvec[(x*3)+2] = str.substring(22, 25).toInt();
                       zvec[(x*3)+2] = str.substring(25, 28).toInt();
                       x = x+1;
                     } else if(text[0] == 'r')
                     {  
                        Serial.println("cayo aca rpm1");
                        String str(text);
                        rpm = strtok(text, "r");
                        Serial.println(rpm);
                      }
                   delay(50);
                 }
               }while (x < 30);
               x = 0;
               xvec[99] = {0};
               yvec[99] = {0};
               zvec[99] = {0};
          } else if(text[0] == 'r') { 
                Serial.println(text);
                Serial.println("cayo lejos"); 
                String str(text);
                rpm = strtok(text, "r");
                Serial.println(rpm);
            }    
         }
        Serial.print("tiempo");
        Serial.println(millis());
       delay(50000);

}


