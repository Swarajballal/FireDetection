 #include<SoftwareSerial.h>
 #include <LiquidCrystal.h>
 
  LiquidCrystal lcd(12, 11, 7, 6, 5, 4);        /* LCD digital ports defined */
  int flame_pin = 10;
  int smoke_pin = A1;
  int relay = 13; 
  
void setup() 
{  
   Serial.begin(9600);
   pinMode(smoke_pin, INPUT);
   pinMode(flame_pin, INPUT);
   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("Swaraj Ballal");
   lcd.setCursor(0, 1);
   lcd.print("Roll No 20104B2001");
   delay(4000); // allow the MQ-6 to warm up
   Serial.println("Gas sensor warming up!");
   Serial.println("Reading From the Flame and smoke Sensor ...");
   lcd.clear();
   pinMode(relay, OUTPUT);
}

void loop() 
{  
   
   int flame_value = digitalRead(flame_pin); 
   int smoke_value = analogRead(smoke_pin);  
   Serial.print("gasPin Value:");
   Serial.println(smoke_value);
   Serial.print("flamePin Value: ");
   Serial.println(flame_value);  
   delay(1000); 
    
  if (smoke_value>15 && flame_value==LOW)
  {  
    lcd.setCursor(0, 0);
    lcd.print("Fire detected");
    digitalWrite(relay, LOW);
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("smoke detected");
    Serial.println("Fire Detected");
    lcd.clear();
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("Water started"); 
    delay(3000); 
    lcd.clear(); 
 
  }
  else if(smoke_value>15 && flame_value == HIGH)
   {  
     lcd.setCursor(0, 0);
     lcd.print("Smoke detected");
     Serial.println("Smoke Detected");
     digitalWrite(relay, LOW);
     delay(3000); 
     lcd.clear(); 
     lcd.setCursor(0, 0);
     lcd.print("Water started"); 
     delay(1000); 
     lcd.clear();
    }
  else if(smoke_value<15 && flame_value == LOW)
   {  
     lcd.setCursor(0, 0);
     lcd.print("Flame  detected");
     Serial.println("Flame Detected");
     digitalWrite(relay, LOW); 
     delay(3000); 
     lcd.clear(); 
     lcd.setCursor(0, 0);
     lcd.print("Water started"); 
     delay(1000); 
     lcd.clear();
  }
  else if(smoke_value<15 && flame_value == HIGH)
   { 
     digitalWrite(relay, HIGH); 
//     lcd.clear();  
     lcd.setCursor(0, 0);
     lcd.print("All Good  Normal");
     delay(1000);
     Serial.println("Everything is NORMAL");
     delay(1000); 
   }

   delay(1000); 
   lcd.print(" "); 
   lcd.clear();/*for removing unnecessary characters */
   delay(2000);            /* try 1000 swa */
  }
