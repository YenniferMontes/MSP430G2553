
// set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
volatile int rpmcount = 0;
float rpm = 0;
unsigned long timeold = 0;


void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:     
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);  
  attachInterrupt(buttonPin, rpm_fun, FALLING);
}

void loop(){
  //Update RPM every 20 revs
  if (rpmcount >= 20){
    //Interruptions happening once per revolution
    rpm = 60.0*1000.0/(millis()-timeold)*rpmcount;
    timeold = millis();    
    rpmcount = 0;
    //mostrar los valores rpm
    Serial.print(rpm);     
    Serial.println("\t");
}

}

void rpm_fun(){
  rpmcount++;  
}

