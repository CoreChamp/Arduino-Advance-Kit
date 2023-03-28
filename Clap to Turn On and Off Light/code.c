int sensor = 8; 
int LED   = 13; 
int ledState = LOW;     
int previoussensorState;    
int presentsensorState; 

void setup() {
  Serial.begin(9600);              
  pinMode(sensor, INPUT_PULLUP); 
  pinMode(LED, OUTPUT);  
          
  presentsensorState = digitalRead(sensor);
}

void loop() {
  previoussensorState    = presentsensorState;      
  presentsensorState = digitalRead(sensor); 
  
  if(previoussensorState == HIGH && presentsensorState == LOW) {
    Serial.println("Clap Detected");
    ledState = !ledState; 
    digitalWrite(LED, ledState); 
    digitalRead(ledState);
    
    if (ledState == HIGH){
      Serial.println("Light On ");
    }
    else{
      Serial.println("Light Off");
    }
  }
}
