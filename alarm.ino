#include <dht.h>

dht DHT;

#define DHT11_PIN 7

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on
}

void loop() {
int chk = DHT.read11(DHT11_PIN);
Serial.println(DHT.temperature);
Serial.println(DHT.humidity);
if(DHT.temperature >=33){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("High temperature");
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  delay(1000);
  if(DHT.humidity >=80){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("High humidity   ");
    lcd.print("High temperature");
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
    delay(1000);
    }
  }

else if(DHT.humidity >=80){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("High humidity");
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  delay(1000);
  }
else{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");//Set cursor to character 2 on line 0
  lcd.setCursor(5, 0);  //Move cursor to character 2 on line 1
  lcd.print(DHT.temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(9, 1);  //Move cursor to character 2 on line 1
  lcd.print(DHT.humidity);
  delay(1000);
  }
}
