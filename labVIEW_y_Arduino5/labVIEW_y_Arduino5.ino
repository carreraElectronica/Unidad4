#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
String st = "";
bool stringComplete = false;
String as, bs, cs, ds, es, fs, gs, hs;
int a, b, c, d, e, f, g, h;
void setup() {
  lcd.clear();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("HOLA MUNDO");
  delay(200);
  Serial.begin(9600);
}  
void loop() {
  evento();
  lcd.setCursor(0, 1);
  lcd.print(f);
  lcd.print(":");
  lcd.print(g);
  lcd.print(":");
  lcd.print(h);
  lcd.print("  ");
  if (stringComplete) {
    for (int i = 0; i < 30; i++) {
      if (st.substring(i, i + 1) == "A") {
        for (int j = 0; j < 30; j++) {
          if (st.substring(j, j + 1) == "B") {
            as = st.substring(i + 1, j);
            a = as.toInt();
          }
        }
      }
    st = "";
    stringComplete = false;
    }
  }
}  
void evento(){
  while (Serial.available()) {
    char inchar = (char)Serial.read();
    st += inchar;
    if (inchar == '\n') {
      stringComplete = true; 
    }
  }  
}
