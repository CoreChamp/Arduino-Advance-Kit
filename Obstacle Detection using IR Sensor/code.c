int val = 0 ;  
 void setup()  
 {  
 Serial.begin(9600);  
 pinMode(2,INPUT);  // IR sensor output pin connected  
 pinMode(6,OUTPUT);  // LED  
 pinMode(7,OUTPUT);  // BUZZER 
 pinMode(8,OUTPUT);  //Vibration Motor for deaf people
 }  
 void loop()  
 {  
 val = digitalRead(2);  
 Serial.println(val);  
 delay(500);  
 if(val == 1 )  
 {  
 digitalWrite(6,HIGH);    
 digitalWrite(7,HIGH);    
 digitalWrite(8,HIGH);  
  }  
 else  
 {  
 digitalWrite(6,LOW);   
 digitalWrite(7,LOW); 
 digitalWrite(8,LOW);   
 }  
 }  
