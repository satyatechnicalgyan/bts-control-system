#include "LiquidCrystal.h"

const int voltageSensor = A0;

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

void setup()
{
//Serial.begin(9600);
lcd.begin(16,2);
lcd.print(" Measure > 48V  ");
delay(2000);
}

void loop()
{
  value = analogRead(voltageSensor);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
  //Serial.print("Input = ");
  //Serial.println(vIN);
  lcd.setCursor(0,1);
  lcd.print(" Experio Tech ");
  
  lcd.setCursor(1,0);
  lcd.print("Input =         ");
  lcd.setCursor(9,0);
  lcd.print(vIN);
  delay(500);
}
