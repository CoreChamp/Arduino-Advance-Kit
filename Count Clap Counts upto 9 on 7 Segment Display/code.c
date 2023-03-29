#include "SevSeg.h"
SevSeg sevseg;

const int sensorPin = 4;     // the number of the soundsensor pin

// variables will change:
int sensorState = 0;         // variable for reading the soundsensor status
int count_value =0;
int prestate =0;

void setup() {
  // initialize the soundsensor pin as an input:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  
  //Set to 1 for single digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};

  //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {11, 10, 7, 8, 9, 12, 13, 5};
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
    
}

void loop() {
  // read the state of the soundsensor value:
  sensorState = digitalRead(sensorPin);

  // check if the soundsensor is pressed. If it is, then the sensorState is HIGH:
  if (sensorState == HIGH && prestate == 0) {
    count_value++;
    Serial.print("Clap Count: ");
    Serial.println(count_value);
    sevseg.setNumber(count_value);
    sevseg.refreshDisplay();
    prestate = 1;
    delay(100);
  } else if(sensorState == LOW) {
    prestate = 0;
  }
}
