const int TOUCH_SENSOR_PIN  = 4; 
const int vibmotor_PIN = 2; 

int vibmotorState = LOW;    
int lastTouchState;   
int currentTouchState; 

void setup() {
  Serial.begin(9600);               
  pinMode(TOUCH_SENSOR_PIN, INPUT); 
  pinMode(vibmotor_PIN, OUTPUT);         

  currentTouchState = digitalRead(TOUCH_SENSOR_PIN);
}

void loop() {
  lastTouchState    = currentTouchState;             // save the last state
  currentTouchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if(lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("The sensor is touched");

   
    vibmotorState = !vibmotorState;

    
    digitalWrite(vibmotor_PIN, vibmotorState); 
  }
}
