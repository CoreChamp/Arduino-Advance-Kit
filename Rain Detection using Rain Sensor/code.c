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
    Serial.println("Raining");
  } 
  else {
    Serial.println("No Rain");
  }
  delay(10); 
}
