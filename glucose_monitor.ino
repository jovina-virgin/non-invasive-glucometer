#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ct = 9;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);
const int sensorPin = A0;  // Analog input pin for the MH series sensor

void setup() {
  analogWrite(ct, 50);
  mylcd.begin(16, 2);
  mylcd.print("hello world");
  Serial.begin(9600);  // Initialize Serial Monitor for debugging
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the sensor value
  //float glucoseLevel = -23.302 * sensorValue + 15779.363;  // Calculate glucose level using the equation
float eqnValue = -23.302 * sensorValue + 15779.363;  
float glucoseLevel = map(eqnValue, 0, 15779, 0, 500);
  // Display the output on the Serial Monitor console
  Serial.print("Glucose: ");
  Serial.print(glucoseLevel);
  Serial.println(" mg/dL");

  // Display the output on the LCD
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print("Glucose: ");
  mylcd.print(glucoseLevel);
  mylcd.print(" mg/dL");

  delay(10);  // Optional delay between readings
}
