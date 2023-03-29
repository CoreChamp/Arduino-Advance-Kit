const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

#define RED 7 
#define GREEN 9
#define BLUE 6

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  Serial.begin(9600);

  pinMode(RED , OUTPUT);
  pinMode(GREEN , OUTPUT);
  pinMode(BLUE , OUTPUT);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  
  delay(500);


  if(analogRead(X_pin) == 1023){
    digitalWrite(RED , HIGH);
    digitalWrite(BLUE , HIGH);
    }
    else if(analogRead(X_pin) == 0){
    digitalWrite(BLUE , HIGH);
    }
    else if(analogRead(Y_pin) == 1023){
    digitalWrite(RED , HIGH);
    }
    else if(analogRead(Y_pin) == 0){
    digitalWrite(GREEN , HIGH);
    }
    else if(digitalRead(SW_pin) == 0){
    digitalWrite(GREEN , HIGH);
    digitalWrite(RED , HIGH);
    digitalWrite(BLUE , HIGH);
    }
    else{
      digitalWrite(GREEN , LOW);
      digitalWrite(RED , LOW);
      digitalWrite(BLUE , LOW);  
      }
}
