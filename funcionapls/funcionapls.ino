const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A4;                  // y-axis
const int zpin = A5;                  // z-axis (only on 3-axis models)
const int reedpin = 3;
const int ledpin = 2;

int xvalue = 0;        // value read from xpin
int yvalue = 0;        // value read from ypin
int zvalue = 0;        // value read from zpin
float xvolt = 0.0;        // voltage read from xpin
float yvolt = 0;        // voltage read from ypin
float zvolt = 0;        // voltage read from zpin
int state = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);      // sets the digital pin as output 
  pinMode(reedpin, INPUT_PULLUP);
  // attachInterrupt(reedpin, blink, FALLING); // Interrupt is fired whenever button is pressed    // sets the digital pin as output
}

void loop()
{  
   state = digitalRead(reedpin);
     if (state == HIGH) {     
     // turn LED on:    
     digitalWrite(ledpin, HIGH);  
    } 
    else {
     // turn LED off:
      digitalWrite(ledpin, LOW); 
    }

  // put your main code here, to run repeatedly:
  xvalue = analogRead(xpin);
  yvalue = analogRead(ypin);
  zvalue = analogRead(zpin);
  xvolt = ((((float)xvalue * 3.6)/1024.0)- 1.8)*2.0; // adc array 0 copied to the variable X_Axis
  yvolt = ((((float)yvalue * 3.6)/1024.0)- 1.8)*2.0; // adc array 1 copied to the variable Y_Axis
  zvolt = ((((float)zvalue * 3.6)/1024.0)- 1.8)*2.0; // adc array 2 copied to the variable Z_Axis

  Serial.print(xvolt);     
  Serial.print("\t");
  Serial.print(yvolt);
  Serial.print("\t");   
  Serial.print(zvolt);
  Serial.println("\t");
  // delay before next reading:
  delay(3000);
}





