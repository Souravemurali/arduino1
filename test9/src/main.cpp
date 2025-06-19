#include <Arduino.h>
#define IR_SENSOR_PIN D2
#define LED_PIN D4

bool ledState = false;
bool prevSensorState = HIGH;  // Start with no detection (HIGH)

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Start with LED OFF
  Serial.begin(115200);
}

void loop() {
  int currentSensorState = digitalRead(IR_SENSOR_PIN);

  // Detect falling edge: HIGH to LOW means object just detected
  if (prevSensorState == HIGH && currentSensorState == LOW) {
    ledState = !ledState;  // Toggle LED state
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "Object Detected - LED ON" : "Object Detected - LED OFF");

    // Wait until object moves away (to avoid repeated toggles)
    while (digitalRead(IR_SENSOR_PIN) == LOW) {
      delay(10);
    }
  }

  prevSensorState = currentSensorState;
}