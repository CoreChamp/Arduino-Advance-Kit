int motor = 10;
int button = 8;
int value =0;
void setup()
{
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  value = digitalRead(6);
  if(value == HIGH){
  digitalWrite(motor,HIGH);
  delay(10);
  }else{
  digitalWrite(motor,LOW);
  delay(10);
  }
  
}
