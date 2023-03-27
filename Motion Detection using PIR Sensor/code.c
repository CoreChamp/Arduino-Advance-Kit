int sensorState = 0;
void setup()
{
  pinMode(12, INPUT); 
  Serial.begin(9600);
}
void loop()
{
  
  sensorState = digitalRead(12);
   
  if (sensorState == HIGH) {
    Serial.println("Motion Detected");
  } 
  else {
    Serial.println("No Motion");
  }
  delay(10); 
}
