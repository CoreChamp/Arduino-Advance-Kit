#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // attach pin D3 Arduino to pin Trig of HC-SR04                                          \
  
long duration; // Variable to store time taken to the pulse
               // to reach receiver 
int distance; // Variable to store distance calculated using
              // formula
void setup()
{
    pinMode(trigPin,OUTPUT); 
    pinMode(echoPin, INPUT); 
 
    Serial.begin(9600);
}
 
void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);                          
 
    digitalWrite(trigPin,HIGH); 
    delayMicroseconds(10);
    
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration * 0.0344 / 2; // Expression to calculate
                                 // distance using time
    Serial.print("Distance: ");
    Serial.print(distance); // Print the output in serial monitor
    Serial.println(" cm");
    delay(100);
}
