#include <Arduino.h>
#define SOIL_PIN A0        // Analog pin A0
#define LED_PIN D4        // Optional LED on D5

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int moistureValue = analogRead(SOIL_PIN); // 0 to 1023
  int moisturePercent = map(moistureValue, 1023, 0, 0, 100); // Dry to Wet

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Turn LED ON if soil is dry (moisture < 30%)
  if (moisturePercent < 50) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Soil is DRY! LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Soil is OK. LED OFF");
  }

  delay(2000);
}
