#define motor_PIN 10
#define POTENTIOMETER_PIN A1
void setup()
{
  pinMode(motor_PIN, OUTPUT);
}
void loop()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = potentiometerValue / 4;
  analogWrite(motor_PIN, brightness);
}
