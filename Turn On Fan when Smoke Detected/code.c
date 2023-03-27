
int smokeA0 = A0;
int fan = 7;
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
    digitalWrite(fan,HIGH);
  }
  else
  {
    Serial.println("Normal");
    digitalWrite(fan,LOW);   
  }
  delay(500);

}
