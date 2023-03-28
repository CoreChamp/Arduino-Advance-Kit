#include <Servo.h>
Servo myservo;

int sensorState = 0;
int led = 13;
int pos = 0; 


void setup()
{
  myservo.attach(9);
  pinMode(12, INPUT); 
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
}
void loop()
{
  
  sensorState = digitalRead(12);
   
  if (sensorState == HIGH) {
    digitalWrite(13, HIGH);
    Serial.println("Door Opening");    
    myservo.write(180);                       
  
  } else {
    digitalWrite(13, LOW);
    Serial.println("Door Closing");
    myservo.write(0);
  }
  delay(15); 
}
