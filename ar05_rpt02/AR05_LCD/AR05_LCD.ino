/*
 예제 2.3
 컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// 점멸횟수 변수 설정
int blinkNumber = 0;

void setup() {
  // 9600bps로 시리얼 통신 설정  
 Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
  // Arduino LCD, Welcome 표시  
  lcd.setCursor(0,0);
  lcd.print("Arduino LCD");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Welcome");
  delay(250);  
}
void loop() {
// 시리얼 통신으로 입력 받은 데이터가 있는지를 검사하여
// 데이터가 있을 경우에 if문 안의 명령어를 실행
  if(Serial.available()){       
  // val 변수에 시리얼 통신값 읽어오기
    char val = Serial.read();
    // 입력된 값이 0~9의 숫자인지를 판단
    if(isDigit(val)){
     // val은 ASCII 코드값이므로 숫자로 바꿔주기 위하여 
     // '0'의 아스키 코드값을 빼줌
     // blinkNumber에는 실제 숫자가 저장된다.
      blinkNumber = (val - '0');
    }
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Message from PC");
    lcd.setCursor(0,1);
    lcd.print(blinkNumber);
      for(char i=0;i < blinkNumber;i++){
        lcd.noBacklight();
        delay(250);
        lcd.backlight();
        delay(250);
    }

while(Serial.available()>0) {
  lcd.write(Serial.read());
}

        
  }

}
