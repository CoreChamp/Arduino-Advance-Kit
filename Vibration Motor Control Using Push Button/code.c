int vibmotor = 10;
int button = 8;
int value = 0;
void setup()
{
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  value = digitalRead(button);
  if(value == HIGH){
  digitalWrite(vibmotor,HIGH);
  delay(10);
  }else{
  digitalWrite(vibmotor,LOW);
  delay(10);
  }
  
}
