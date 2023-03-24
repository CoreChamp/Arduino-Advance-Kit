int led = 10;
int button = 8;
int value =0;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  value = digitalRead(6);
  if(value == HIGH){
  digitalWrite(led,HIGH);
  delay(10);
  }else{
  digitalWrite(led,LOW);
  delay(10);
  }  
}
