#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2        // Pin where DHT is connected
#define DHTTYPE DHT11   // Define sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Check for warning conditions
  if (t > 40.0) {
    Serial.println(" WARNING: Temperature too high! System halted.");
    while (true); // Stop loop permanently
  }

  if (h < 20.0) {
    Serial.println(" WARNING: Humidity too low! System halted.");
    while (true); // Stop loop permanently
  }

  // If normal conditions, print values
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  delay(2000); // Wait 2 seconds before next read
}