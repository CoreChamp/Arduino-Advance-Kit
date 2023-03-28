const int ledPin = 13;
const int soundPin = 8;

int soundVal = 0;

void setup ()
{
  pinMode (ledPin, OUTPUT);
  pinMode (soundPin, INPUT);
  Serial.begin (9600);
}
 
void loop ()
{
  soundVal = digitalRead(soundPin);
  if (soundVal == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Clap detected");
    Serial.println("Lights On");
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin,LOW); 
    Serial.println("Lights Off");   
  }
 }
