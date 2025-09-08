#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C Lcd(0x27, 20, 4);

const int sensorMin = 0;
const int sensorMax = 1023;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Lcd.init();
  Lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(A3);
  bool dReading = digitalRead(2);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  Lcd.setCursor(0, 0);
  Lcd.print("Analog: ");
  Lcd.print(sensorReading);
  Lcd.print("   ");

  Lcd.setCursor(0, 1);
  Lcd.print("Range: ");
  Lcd.print(range);
  Lcd.print(" ");

  Lcd.setCursor(0, 2);
  Lcd.print("Digital: ");
  Lcd.print(dReading);
  Lcd.print(" ");
}