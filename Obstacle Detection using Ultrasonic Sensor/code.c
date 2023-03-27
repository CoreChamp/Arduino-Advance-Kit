#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // attach pin D3 Arduino to pin Trig of HC-SR04                                          
#define led 11
#define buzzer 5
#define vibmotor 6
int range = 10;
  
long duration; // Variable to store time taken to the pulse
               // to reach receiver 
int distance; // Variable to store distance calculated using
              // formula
void setup()
{
    pinMode(trigPin,OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(led,OUTPUT);
    pinMode(buzzer,OUTPUT);
    pinMode(vibmotor,OUTPUT);
 
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
  
    if(distance>range){
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
      digitalWrite(vibmotor,HIGH);
    } 
    else if(distance<range){
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      digitalWrite(vibmotor,LOW);
    }
}
