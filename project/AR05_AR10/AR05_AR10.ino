#include "DHT.h" //DHT 라이브러리 추가
#include <Wire.h> // I2C 통신 라이브러리 설정함
#include <LiquidCrystal_I2C.h> // I2C LCD 라이브러리 설정함
#define DHTPIN 2 // DHT11이 연결된 핀을 설정
#define DHTTYPE DHT11 // 연결된 센서의 종류를 설정

int ledA = 5; //ledA를 5번핀에 설정함
int ledB = 6; //ledB를 6번핀에 설정함

LiquidCrystal_I2C lcd(0x27,16,2); //LCD I2C address 설정

DHT dht(DHTPIN, DHTTYPE); // DHT11이란 이름으로 센서 설정

void setup()
{
  dht.begin(); //DHT11 센서 시작

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  
  lcd.init(); //LCD설정
  lcd.backlight(); //LCD모두지움


  lcd.setCursor(0,0);
  lcd.print("welcome");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("DHT sensor");
  delay(3000);
  //welcome,DHT sensor 표시함
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature ");
  lcd.setCursor(14,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity ");
  lcd.setCursor(11,1);
  lcd.print("%");
  //온도,습도 표시함
}

void loop()
{
  unsigned char t = dht.readTemperature();
  unsigned char h = dht.readHumidity();
// 온도,습도를 읽음

  lcd.setCursor(12,0);
  lcd.print(" ");

  lcd.setCursor(12,0);
  lcd.print(t);

  lcd.setCursor(9,1);
  lcd.print(" ");

  lcd.setCursor(9,1);
  lcd.print(h);
//온도,습도 출력

  delay(1000);
  
  if (t > 30){
    digitalWrite(ledA, HIGH);
    lcd.noBacklight();
  }
  else{
    digitalWrite(ledA, LOW);
  }
// 만약 온도가 30이 넘어가면 ledA가 켜지고 아니라면은 ledA는 꺼진다.

  if (h > 70){
    digitalWrite(ledB, HIGH);
    lcd.noBacklight();
  }
  else{
    digitalWrite(ledB, LOW);
  }
 // 만약 섭씨가 70이 넘어가면 ledB가 켜지고 아니라면은 ledB는 꺼진다.
}
