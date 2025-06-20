#include <Arduino.h>
#include <DHT.h>

// DHT11 config
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Pin config
const int soilPin = A0;
const int pumpPin = 8;

void setup() {
  Serial.begin(115200); // Start serial communication at 115200 baud
  dht.begin();
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // pump initially off
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soilValue = analogRead(soilPin);
  int moisturePercent = map(soilValue, 452, 233, 0, 100); // calibrate as needed

  Serial.print("Temperature: "); Serial.print(temp); Serial.print(" °C, ");
  Serial.print("Humidity: "); Serial.print(hum); Serial.print(" %, ");
  Serial.print("Soil Moisture: "); Serial.print(moisturePercent); Serial.println(" %");
  
  // Control pump based on soil moisture
  if (moisturePercent < 30) {
    digitalWrite(pumpPin, LOW);
    Serial.println("Pump: ON (Moisture LOW)");
  } else {
    digitalWrite(pumpPin, HIGH);
    Serial.println("Pump: OFF (Moisture OK)");
  }

  delay(2000); // Delay 2 seconds before next read
}