int sensorvalue = 0; 

void setup() {
  pinMode(12,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  sensorvalue = digitalRead(12);
  Serial.print("Sensor value =");
  Serial.print(sensorvalue);
  Serial.print('\n');
  delay(1000);
  
  if(sensorvalue == 1){
  Serial.println("Day Detected");
  delay(100);
  }
  else{
    Serial.println("Night Detected");
    delay(100);
  }
}
