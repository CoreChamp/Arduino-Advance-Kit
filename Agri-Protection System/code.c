#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

#define SoilSensor 12
#define FlameSensor 11
#define SmokeSensor A0
int sensorThres = 70;

LiquidCrystal_I2C lcd(0x27, 16, 2);
bool showcelciusorfarenheit = false;


void setup(){
  Serial.begin(9600);
  pinMode(SoilSensor,INPUT);
  pinMode(FlameSensor,INPUT);
  pinMode(SmokeSensor,INPUT);


  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("AGRI-PROTECTION");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  delay(3000);
  lcd.clear();
  
}

void loop(){
  int ValueSoil = digitalRead(SoilSensor);   // 0 means Soil having moisture
  int ValueFlame = digitalRead(FlameSensor);
  int ValueSmoke = analogRead(SmokeSensor);

  int readData = DHT.read11(dataPin); // DHT11
  int t = DHT.temperature; // Gets the values of the temperature
  int h = DHT.humidity; // Gets the values of the humidity
  int tf = (t * 9.0) / 5.0 + 32.0;
  Serial.println(ValueSmoke);

  if(ValueSoil == HIGH || ValueFlame == HIGH || ValueSmoke > sensorThres){
    if(ValueSoil == HIGH){
      lcd.setCursor(4, 0);
      lcd.print("Warning");
      lcd.setCursor(0, 1);
      lcd.print("Soil Needs Water");
      Serial.println(ValueSoil);
    }
    
    if(ValueFlame == HIGH){
      lcd.setCursor(4, 0);
      lcd.print("Warning");
      lcd.setCursor(1, 1);
      lcd.print("Fire Fire Fire");  
      Serial.println(ValueFlame);
    }
  
    if(ValueSmoke > sensorThres){
      lcd.setCursor(4, 0);
      lcd.print("Warning");
      lcd.setCursor(1, 1);
      lcd.print("Smoke Detected");
      Serial.println(ValueSmoke);
    } 
    delay(1000);
    lcd.clear();
  } 

  else{
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.print((char)223);//shows degrees character
    lcd.print("C  ");
    lcd.print(tf);//print the temperature in Fahrenheit
    lcd.print((char)223);//shows degrees character
    lcd.println("F   ");
    lcd.setCursor(0, 1);
    lcd.print("Humidity = ");
    lcd.print(h);
    lcd.println("%       ");
  }

  delay(1000);
  lcd.clear();
          
}
 
