/*
  LiquidCrystal Library - Hello World
  http://www.arduino.cc/en/Tutorial/LiquidCrystal
  by David A. Mellis, Limor Fried, Tom Igo

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("Tweet @dansoffice!");
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String s = "";
    while (Serial.available() > 0) {
      delay(3);
      char c = Serial.read();
      s += c;
    }

    String line1 = "";
    String line2 = "";
    String line3 = "";
    String line4 = "";
    if (s.length() <= 20) {
      line1 = s;
    } else if (s.length() <= 40) {
      line1 = s.substring(0, 20);
      line2 = s.substring(20);
    } else if (s.length() <= 60) {
      line1 = s.substring(0, 20);
      line2 = s.substring(20, 40);
      line3 = s.substring(40);
    } else {
      line1 = s.substring(0, 20);
      line2 = s.substring(20, 40);
      line3 = s.substring(40, 60);
      line4 = s.substring(60);
    }

    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print(line1);
    
    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print(line2);
    
    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,2);
    lcd.print(line3);
    
    lcd.setCursor(0,3);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print(line4);
  }
}

