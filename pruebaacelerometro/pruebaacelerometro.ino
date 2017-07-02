const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A3;                  // y-axis
const int zpin = A4;                  // z-axis (only on 3-axis models)

int xvalue = 0;        // value read from xpin
int yvalue = 0;        // value read from ypin
int zvalue = 0;        // value read from zpin
//float xvolt = 0.0;        // voltage read from xpin
//float yvolt = 0;        // voltage read from ypin
//float zvolt = 0;        // voltage read from zpin

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{  
//for(int x=1; x<101; x++){
  // put your main code here, to run repeatedly:
  xvalue = analogRead(xpin);
  yvalue = analogRead(ypin);
  zvalue = analogRead(zpin);
  //xvolt = ((((float)xvalue * 3.6)/1024.0)); // adc array 0 copied to the variable X_Axis
  //yvolt = ((((float)yvalue * 3.6)/1024.0)); // adc array 1 copied to the variable Y_Axis
  //zvolt = ((((float)zvalue * 3.6)/1024.0)); // adc array 2 copied to the variable Z_Axis

  
  Serial.print(xvalue);     
  Serial.print("\t");
  Serial.print(yvalue);
  Serial.print("\t");   
  Serial.print(zvalue);
  Serial.println("\t");

  delay(10);
  //}
  //delay(50000000);
}

