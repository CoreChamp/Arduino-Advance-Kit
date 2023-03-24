int led = 10;
int button = 6;
int value =0;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  value = digitalRead(button);
  if(value == HIGH){
  digitalWrite(led,HIGH);
  delay(10);
  }else{
  digitalWrite(led,LOW);
  delay(10);
  }  
}
