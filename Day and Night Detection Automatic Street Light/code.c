int sensorvalue = 0; 
int led =11;

void setup() {
  pinMode(7,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  sensorvalue = digitalRead(7);
  Serial.print("Sensor value =");
  Serial.print(sensorvalue);
  Serial.print('\n');
  delay(1000);
  
  if(sensorvalue == 1){
  Serial.println("Day Detected\nStreet Light Off");
  digitalWrite(led,LOW);  
  delay(100);
  }
  else{
    Serial.println("Night Detected\nStreet Light On");
    digitalWrite(led,HIGH);
    delay(100);
  }
}
