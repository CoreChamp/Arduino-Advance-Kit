#include <Wire.h> 
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <Servo.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
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
lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear();  
}

void loop(){ 

if(digitalRead (IR1) == LOW && flag1==0){
if(Slot>0){flag1=1;
if(flag2==0){myservo1.write(0); Slot = Slot-1;}
}else{
lcd.setCursor (0,0);
lcd.print("    SORRY :(    ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay (3000);
lcd.clear(); 
}
}

if(digitalRead (IR2) == LOW && flag2==0){flag2=1;
if(flag1==0){myservo1.write(0); Slot = Slot+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservo1.write(100);
flag1=0, flag2=0;
}

lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("Slot Left: ");
lcd.print(Slot);
}
