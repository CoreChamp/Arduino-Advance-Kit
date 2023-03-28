int sensor = 8; 
int FAN   = 13; 
int FANState = LOW;     
int previoussensorState;    
int presentsensorState; 

void setup() {
  Serial.begin(9600);              
  pinMode(sensor, INPUT_PULLUP); 
  pinMode(FAN, OUTPUT);  
          
  presentsensorState = digitalRead(sensor);
}

void loop() {
  previoussensorState    = presentsensorState;      
  presentsensorState = digitalRead(sensor); 
  
  if(previoussensorState == HIGH && presentsensorState == LOW) {
    Serial.println("Clap Detected");
    FANState = !FANState; 
    digitalWrite(FAN, FANState); 
    digitalRead(FANState);
    
    if (FANState == HIGH){
      Serial.println("Light On ");
    }
    else{
      Serial.println("Light Off");
    }
  }
}
