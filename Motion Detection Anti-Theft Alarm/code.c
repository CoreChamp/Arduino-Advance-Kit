int sensorState = 0;
int buzzer = 10;
void setup()
{
  pinMode(12, INPUT); 
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  sensorState = digitalRead(12);
   
  if (sensorState == HIGH) {
    Serial.println("Motion Detected");
    digitalWrite(buzzer,HIGH);
  } 
  else {
    Serial.println("No Motion");
    digitalWrite(buzzer,LOW);
  }
  delay(10); 
}
