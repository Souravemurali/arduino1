#include <Arduino.h>
#define IR_SENSOR_PIN D2     // IR Sensor output pin
#define LED_PIN D4         // LED connected to D5 (GPIO14)

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}


void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  if (sensorValue == LOW) { // Object detected
    digitalWrite(LED_PIN, HIGH); // Turn ON LED
    Serial.println("Object Detected - LED ON");
  } else {
    digitalWrite(LED_PIN, LOW); // Turn OFF LED
    Serial.println("No Object - LED OFF");
  }

  delay(200);
}
