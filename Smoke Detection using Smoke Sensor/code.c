int smokeA0 = A0;
// Your threshold value
int sensorThres = 100;
 
void setup() {

  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  int analogSensor = analogRead(smokeA0);
 
  Serial.print("Smoke Level: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    Serial.println("Smoke Detected!");
  }
  else
  {
    Serial.println("Normal");    
  }
  delay(500);
}
