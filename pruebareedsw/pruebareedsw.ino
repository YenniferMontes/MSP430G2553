volatile byte revs;
unsigned int rpm;
unsigned long timepasst;

void setup() {
  // put your setup code here, to run once:
   // inicializa el pin del led como de salida
       pinMode(pinLed, OUTPUT);      
       // inicializa el pin del reed switch como de entrada
       pinMode(pinSwitch, INPUT);     

}

void loop() {
  // put your main code here, to run repeatedly: 
  // lee el valor del estado del reed switch y lo guarda en la variable estadoSwitch
       estadoSwitch = digitalRead(pinSwitch);
       // checa el estado del reed switch con un if
       if (estadoSwitch == HIGH) {     
         // si es HIGH, el reed switch esta cerrado y prendemos el led
         digitalWrite(pinLed, HIGH);  
       } 
       else {
         // entonces es LOW, el reed switch esta abierto y apagamos el led
         digitalWrite(pinLed, LOW); 
       }
  
}
