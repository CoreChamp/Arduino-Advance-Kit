#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(7);  // attaches the servo on pin 7 to the servo object
  myservo.write(0);
  delay(1000);
}

void loop() {
  myservo.write(180);
  delay(1000);
  }
