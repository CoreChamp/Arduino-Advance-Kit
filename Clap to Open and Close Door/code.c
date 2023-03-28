#include <Servo.h>
Servo myservo;

int sensorState = 0;
int led = 13; 
int soundPin = 8;

int soundVal = 0;

void setup ()
{
  myservo.attach(7);
  pinMode (soundPin, INPUT);  
  pinMode(led,OUTPUT);
  Serial.begin (9600);
}
 
void loop ()
{
  soundVal = digitalRead(soundPin);
  if (soundVal == HIGH)
  {
    digitalWrite(led, HIGH);
    Serial.println("Clap detected");
    Serial.println("Door Opening");    
    myservo.write(180);   
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("No sound detected");
    Serial.println("Door Close");
    myservo.write(0);
    delay(1000);
  }
 }
