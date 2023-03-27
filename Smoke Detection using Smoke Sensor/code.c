
int smokeA0 = A0;
int led = 6;
// Your threshold value
int sensorThres = 100;
 
void setup() {

  pinMode(smokeA0, INPUT);
  pinMode(led.HIGH);
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
    digitalWrite(led,HIGH);
  }
  else
  {
    Serial.println("Normal");
    digitalWrite(led,LOW);   
  }
  delay(500);

}
