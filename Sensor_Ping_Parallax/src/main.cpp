#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// put function declarations here:
int myFunction(int, int);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int pingPin = 7;

long microsecondsToInches(long microseconds)
{
  // Convert microseconds to inches
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // Convert microseconds to centimeters
  return microseconds / 29 / 2;
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ngukur Jarak Bolo~~");
}

void loop()
{
  // put your main code here, to run repeatedly:
  long inches, cm, duration;

  // Clear the LCD
  lcd.clear();
  // Send a pulse to the pingPin
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  // Display the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inci:");
  lcd.print(inches);
  lcd.setCursor(0, 1);
  lcd.print("Cm:");
  lcd.print(cm);

  delay(1000);
}

// put function definitions here:
