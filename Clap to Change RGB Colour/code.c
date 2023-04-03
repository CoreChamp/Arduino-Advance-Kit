#define sensor 7         //RGB LED type - Common Cathode
#define redLED 10
#define greenLED 8
#define blueLED 9
int state = 0;
int old = 0;
int sensorState = 0;

void setup() {
 pinMode(sensor,INPUT);
 //RGB LED set as output
 pinMode(redLED,OUTPUT);
 pinMode(greenLED,OUTPUT);
 pinMode(blueLED,OUTPUT);

 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
}

void loop() {
 sensorState = digitalRead(sensor);
 if(sensorState == 1) {
 delay(50);
 sensorState = digitalRead(sensor);
 if(sensorState == 0) {
 state = old + 1;
 }
 }
 else {
 delay(100);
}

switch (state) {
 case 1: //Red color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
 old = state;
 break;
 case 2: //Green color
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,LOW);
 old = state;
 break;
 case 3: //Blue color
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 case 4: //Purple color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 case 5: //White color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 default:
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
 old = 0;
 break;
 }
}
