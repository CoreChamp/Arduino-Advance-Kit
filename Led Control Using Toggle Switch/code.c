int led = 10;
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
  digitalWrite(led,HIGH);
  delay(10);
  }else{
  digitalWrite(led,LOW);
  delay(10);
  }  
}
