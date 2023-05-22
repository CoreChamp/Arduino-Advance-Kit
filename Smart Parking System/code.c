#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo1;

int IR1 = 2; //Ir Sensor Pins Define
int IR2 = 4; //Ir Sensor Pins Define
int Slot = 4; //Enter Total number of parking Slots
int flag1 = 0;
int flag2 = 0;

void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
myservo1.attach(3);
myservo1.write(100);
lcd.init();
lcd.backlight();
lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");

delay (2000);
lcd.clear();  
}

void loop(){ 

if(digitalRead (IR1) == LOW){
if(Slot>0){
  myservo1.write(0); 
  Slot = Slot-1;
  delay(1000);
}
else{
lcd.setCursor (0,0);
lcd.print("    SORRY :(    ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
Slot = 0;
delay (3000);
lcd.clear(); 
}
}

if(digitalRead (IR2) == LOW ){
  myservo1.write(0); 
  Slot = Slot+1;
  delay(100);
}

if(digitalRead (IR1) == HIGH && digitalRead (IR2) == HIGH){
delay (100);
myservo1.write(100);
}

lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("Slot Left: ");
lcd.print(Slot);
delay (1000);
}



