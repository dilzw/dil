hhtps://raw.githubusercontent.com/sachini25/any/main/c.txt


#include <LiquidCrystal.h>

#include <Bounce2.h>


LiquidCrystal lcd(2,3,4,5,6,7);

Bounce btn1= Bounce(0,1);
Bounce btn2= Bounce(1,1);

int in,out,total;

void setup() {
 
lcd.begin(16,2);
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {
 
  if (btn1.update()) {
  if (btn1.risingEdge()) {
  digitalWrite(13,HIGH);
  in++;


  }
  }


  if (btn2.update()) {
    if (btn2.risingEdge()) {
      digitalWrite(13,LOW);
    out++;
    }
  }

  total=in-out;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(String("In:")+ String(in));
  //lcd.print("En:"+in);
  lcd.setCursor(8,0);
  lcd.print(String("Leav:")+ String(out));
  lcd.setCursor(0,1);
  //lcd.print("Stay:"+total);
  lcd.print(String("Stay:")+ String(total));
  delay(1000);
}
