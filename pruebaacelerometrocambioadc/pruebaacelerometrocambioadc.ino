
#include "MspFlash.h"

const unsigned char data[2*SEGMENT_SIZE] = {0};
#define flash SEGPTR(data)

const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A3;                  // y-axis
const int zpin = A4;                  // z-axis (only on 3-axis models)
int xvalue[60] = {0};        // value read from xpin
int yvalue[60] = {0};        // value read from ypin
int zvalue[60] = {0};        // value read from zpin

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{  
   for (int x = 0; x <50; x++){
      xvalue[x] = analogRead(xpin);
      yvalue[x] = analogRead(ypin);
      zvalue[x]= analogRead(zpin);
      delay(10);
   }
   
 Serial.println(zvalue[0]);
 delay(5000);
}
