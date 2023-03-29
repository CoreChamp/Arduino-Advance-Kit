const int sensorPin = 4;     // the number of the soundsensor pin

// variables will change:
int sensorState = 0;         // variable for reading the soundsensor status
int count_value =0;
int prestate =0;
void setup() {
  // initialize the soundsensor pin as an input:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the soundsensor value:
  sensorState = digitalRead(sensorPin);

  // check if the soundsensor is pressed. If it is, then the sensorState is HIGH:
  if (sensorState == HIGH && prestate == 0) {
    count_value++;
    Serial.print("Clap Count: ");
    Serial.println(count_value);
    prestate = 1;
  } else if(sensorState == LOW) {
    prestate = 0;
  }
}
