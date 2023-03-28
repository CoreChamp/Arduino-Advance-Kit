#include <Keypad.h>
#include <Servo.h>

Servo myservo; 
 
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 

 
String password = "1234D";
String mypassword;
 
int counter = 0; 
int attempts = 0; 
int max_attempts = 3; 
 
void setup(){
  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  Serial.begin(9600);
  
  myservo.write(0);
  delay(1000);
  
  Serial.println("enter password");
    
}
  
void loop()
{
  
 keypadfunction();
 
}
 
void keypadfunction()
{
 char key = keypad.getKey();
  
  if (key){
    Serial.print(key);
    counter = counter + 1; 
    
    Serial.println("*");
  }
  if (key == '1')
  {
 
    mypassword = mypassword + 1;   
  }
  
    if (key == '2')
  {
 
    mypassword = mypassword + 2;  
  }
  
  if (key == '3')
  {
 
    mypassword = mypassword + 3; 
  }
  
   if (key == '4')
  {
  
    mypassword = mypassword + 4;  
  }
  
  if (key == '5')
  {
  
    mypassword = mypassword + 5;
  }
  
   if (key == '6')
  {
   
    mypassword = mypassword + 6; 
  }
  
   if (key == '7')
  {
 
    mypassword = mypassword + 7; 
  }
 
   if (key == '8')
  {
 
    mypassword = mypassword + 8; 
  }
  
  if (key == '9')
  {
 
    mypassword = mypassword + 9;
  }
             
                 if (key == '0')
  {
 
    mypassword = mypassword + 0; 
  }

  if (key == 'A')
  {
 
    mypassword = mypassword + 'A';   
  }

  if (key == 'B')
  {
 
    mypassword = mypassword + 'B';   
  }

  if (key == 'C')
  {
 
    mypassword = mypassword + 'C';   
  }

  if (key == 'D')
  {
 
    mypassword = mypassword + 'D';   
  }
  
  
        if (key == '*')
  {
    Serial.println(mypassword); 
    
if ( password == mypassword )
{
 
Serial.println("Door Open");
myservo.write(180);
delay(5000); 
myservo.write(0);
mypassword = ""; 
counter = 0; 
Serial.println("Enter password");
}
else
{
Serial.println("wrong");
attempts = attempts + 1; 
if (attempts >= max_attempts )
{
  Serial.println("Locked Out");
  
delay(5000); 
attempts = 0; 
 
}
mypassword = ""; 
counter = 0; 
Serial.println("Wrong Password");
delay(1000);
 
 
Serial.println("max attempts 3");
delay(1000);
 

Serial.println("Enter password");
 
}
    
  }  
  
  
}
