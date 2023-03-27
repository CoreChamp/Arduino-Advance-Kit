int sensorState = 0;
int led = 13;
void setup()
{
  pinMode(12, INPUT); 
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  sensorState = digitalRead(12);
   
  if (sensorState == HIGH) {
    digitalWrite(13, HIGH);
    Serial.println("Motion Detected");
  } else {
    digitalWrite(13, LOW);
    Serial.println("No Motion");
  }
  delay(10); 
}
