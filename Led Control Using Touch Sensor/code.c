const int TOUCH_SENSOR_PIN  = 4; // Arduino pin connected to touch sensor's pin
const int LED_PIN           = 2; // Arduino pin connected to LED's pin

int ledState = LOW;    
int lastTouchState;   
int currentTouchState; 

void setup() {
  Serial.begin(9600);               
  pinMode(TOUCH_SENSOR_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT);         

  currentTouchState = digitalRead(TOUCH_SENSOR_PIN);
}

void loop() {
  lastTouchState    = currentTouchState;             // save the last state
  currentTouchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if(lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("The sensor is touched");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, ledState); 
  }
}
