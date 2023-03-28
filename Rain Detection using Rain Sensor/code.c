int sensorState = 0;
void setup()
{
  pinMode(4, INPUT); 
  Serial.begin(9600);
}
void loop()
{
  
  sensorState = digitalRead(4);
   
  if (sensorState == HIGH) {
    Serial.println("Raining");
  } 
  else {
    Serial.println("No Rain");
  }
  delay(10); 
}
