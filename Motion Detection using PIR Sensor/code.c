int sensorState = 0;
void setup()
{
  pinMode(2, INPUT); 
  Serial.begin(9600);
}
void loop()
{
  
  sensorState = digitalRead(2);
   
  if (sensorState == HIGH) {
    digitalWrite(13, HIGH);
    Serial.println("Motion Detected");
  } else {
    digitalWrite(13, LOW);
    Serial.println("No Motion");
  }
  delay(10); 
}
