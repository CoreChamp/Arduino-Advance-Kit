int vibmotor = 10;
int toggleSwitch = 6;
int value =0;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(toggleSwitch,INPUT);
}

void loop()
{
  value = digitalRead(toggleSwitch);
  if(value == HIGH){
  digitalWrite(vibmotor,HIGH);
  delay(10);
  }else{
  digitalWrite(vibmotor,LOW);
  delay(10);
  }  
}
