#include <Wire.h>   
#include <LiquidCrystal_I2C.h>  
 LiquidCrystal_I2C lcd(0x3F, 16, 2);   
 // IF IN LCD IS NOT PRINTED ANY THING THEN CHANGE THIS VALUE 0x3F TO 0x27  
 #include <DHT.h>  
 DHT dht(3, DHT11); // DHT11 Sensor pin D3   
 void setup()   
 {  
  Serial.begin(9600); // See the connection status in Serial Monitor  
  lcd.init();  
  lcd.backlight();  
  dht.begin();  
  // Setup a function to be called every second  
  pinMode(5,OUTPUT); // LED pin  
 }  
 void loop()  
 {  
  float h = dht.readHumidity();  
  float t = dht.readTemperature();  
  int r = analogRead(A0);    // Rain Drop Sensor Pin A0  
  bool l = digitalRead(4);    // LDR sor Pin D4  
  delay(100);  
  r = map(r, 0, 1023, 100, 0);  
  if (l == 0)  
  {  
   lcd.setCursor(9, 1);  
   lcd.print("L :");  
   lcd.print("High");  
   lcd.print(" ");  
   Serial.print("LDR Sensor : ");  
   Serial.println("High");  
   digitalWrite(5, HIGH);    // LED ON  
  }  
  else if (l == 1)   
  {  
   lcd.setCursor(9, 1);  
   lcd.print("L :");  
   lcd.print("Low");  
   lcd.print(" ");  
   Serial.print("LDR Sensor : ");  
   Serial.println("Low");  
   digitalWrite(5, LOW);     // LED OFF  
  }  
  lcd.setCursor(0, 0);  
  lcd.print("T :");  
  lcd.print(t);  
   Serial.print("Temperature : ");  
  Serial.println(t);  
  lcd.setCursor(0, 1);  
  lcd.print("H :");  
  lcd.print(h);  
  Serial.print("Humidity : ");  
   Serial.println(h);  
  lcd.setCursor(9, 0);  
  lcd.print("R :");  
  lcd.print(r);  
  lcd.print(" ");  
  Serial.print("Rain Sensor : ");  
  Serial.println(r);  
  Serial.println("   " );  
 }
