const int soundPin = 8;

int soundVal = 0;

void setup ()
{
  pinMode (soundPin, INPUT);
  Serial.begin (9600);
}
 
void loop ()
{
  soundVal = digitalRead(soundPin);
  if (soundVal == HIGH)
  {
    Serial.println("Clap detected");
    delay(1000);
  }
  else
  {
    Serial.println("No sound detected");
    
  }
 }
