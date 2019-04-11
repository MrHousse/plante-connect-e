#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int plante = A0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  // Capteur d'hygrométrie
  pinMode(plante, INPUT);
}

void loop() {
  int humide = analogRead(plante);
  // Turn off the display:
  String humdv = "humidée : ";
  String humd = humdv + humide ;
  lcd.print(humd);
  delay(500);
  // Turn on the display:
  lcd.clear();
 
}
