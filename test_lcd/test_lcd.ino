#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int plante = A0;
//const int led = 8;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  // Capteur d'hygrométrie
  pinMode(plante, INPUT);
//  pinMode(led, OUTPUT);
}

void loop() {
  int humide = analogRead(plante);
  int chk = DHT.read11(DHT11_PIN);
  int temper = DHT.temperature;
  // converti les varriable int en string
  String humdv = "humidite : ";
  if (humide <= 50 ){
    String humd = "Arrosez";
    lcd.setCursor(0, 0);
    lcd.print(humd);
  }
  else {
    String humd = humdv + humide ;
    lcd.setCursor(0, 0);
    lcd.print(humd);
  }

  if (temper >= 28) {
    //ouvrir serre
    digitalWrite(8, HIGH);
  }
  else{
    //fermer la serre
    digitalWrite(8, LOW);
  }
  String tempv = "Temperature : ";
  String temp = tempv + temper ;

  lcd.setCursor(0, 1);
  lcd.print(temp);
  delay(2000);
  // Turn on the display:
  lcd.clear();
 
}
