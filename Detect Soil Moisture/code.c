int sensorvalue = 0; // 0 means Soil having moisture

void setup() {
  pinMode(10,INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorvalue = digitalRead(10);
  Serial.print('\n');
  delay(1000);
  
  if(sensorvalue == 1){
  Serial.println("Soil needs water");
  delay(100);
  }
  else{
    Serial.println("Soil is moisturized");
      delay(100);
  }
}
