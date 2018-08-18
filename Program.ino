#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int c=0;
void setup() {
  lcd.begin(16,2);
  lcd.print(" Welcome Team");
  lcd.setCursor(0,2);
  delay(1000);
  lcd.print(" Visitor Counter");
  delay(1000);
   pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if(digitalRead(6)==0){
    c++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(c);
    delay(1000);
  }
  else if(digitalRead(7)==0 && c>0){
    c--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(c);
    delay(1000);
  }
  else if(c==0){
    lcd.clear();
    //digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print(" Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("  Light Is Off");
    digitalWrite(13,LOW);
    delay(100);
  }
  if(c>0) digitalWrite(13,HIGH);
}
