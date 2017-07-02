// set pin numbers:
const int buttonPin = 5;  // the number of the pushbutton pin
volatile unsigned int rpmcount = 0;
int rpm = 0;
unsigned long timeold = 0;
unsigned long prpm = 0;
int x = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:     
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);   
  attachInterrupt(buttonPin, rpm_fun, RISING);
  Serial.print("Inicio del Programa");
}

void loop(){
   x= 0;
   const unsigned long oneSecond = 1 * 1000UL;
   static unsigned long lastSampleTime = 0 - oneSecond;  
   while(x<120){
      Serial.println(x);
      unsigned long now = millis();
      if (now - lastSampleTime >= oneSecond){
       lastSampleTime += oneSecond;
       Serial.println("warmbloodddd");
       detachInterrupt(buttonPin);
       rpm = rpm + (60*rpmcount);
       rpmcount = 0;  
       attachInterrupt(buttonPin, rpm_fun, RISING); 
       x++;           
     }if(x == 59){
         prpm = prpm + (rpm/60);
         rpm = 0;   
     } 
   }
   prpm = prpm + (rpm/60); 
   rpm= 0;
 // if (millis() - timeold == 1000){
 //   detachInterrupt(buttonPin);
  //  rpm = 60*rpmcount;
    Serial.print("this is rpm");
    Serial.print(prpm/2);     
    Serial.println("\t");
    prpm = 0;

    sleep(5000);
}

void rpm_fun(){
  rpmcount++;  
}



