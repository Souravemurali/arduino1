Here’s a clear *side-by-side instruction guide* for using the *DHT11 sensor project* on both *Arduino IDE* and *PlatformIO (VS Code)*.

---

## 🔧 Project: DHT11 Temperature and Humidity Sensor

---

## 🧰 COMMON HARDWARE SETUP:

| DHT11 Pin | Arduino UNO | NodeMCU |
| --------- | ----------- | ------- |
| VCC       | 5V          | 3.3V    |
| DATA      | D2          | D4      |
| GND       | GND         | GND     |

---

## ✅ Using *Arduino IDE* (Beginner-Friendly)

### Step 1: Install Arduino IDE

* Download from: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

### Step 2: Install Required Libraries

* Open IDE → Sketch → Include Library → Manage Libraries
* Search for:

  * DHT sensor library by Adafruit
  * Adafruit Unified Sensor

### Step 3: Write or Paste Code

cpp
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

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

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  delay(2000);
}


### Step 4: Upload Code

* Tools → Board → Select your board (Arduino Uno or NodeMCU)
* Tools → Port → Select correct COM port
* Click the *Upload* button

### Step 5: View Output

* Tools → Serial Monitor → Set baud rate to *9600*

---

## ⚙️ Using *PlatformIO (VS Code)* (Advanced/Pro)

### Step 1: Install PlatformIO Extension

* Open VS Code → Extensions → Search: “PlatformIO IDE” → Install

### Step 2: Create New Project

* PlatformIO Home → New Project
* Name: DHT11Project
* Board: Select *Arduino Uno* or *NodeMCU 1.0 (ESP-12E)*
* Framework: Arduino
* Click “Finish”

### Step 3: Add Libraries

In platformio.ini, add:

ini
lib_deps =
  adafruit/DHT sensor library
  adafruit/Adafruit Unified Sensor


### Step 4: Write Code in src/main.cpp

cpp
#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

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

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  delay(2000);
}


### Step 5: Upload and Monitor

* Click ✓ to *Build*
* Click → (right arrow) to *Upload*
* Click 🔍 (plug icon) to open *Serial Monitor* (set baud to 9600)

---

## ✅ Summary: Key Differences

| Feature         | Arduino IDE             | PlatformIO (VS Code)                      |
| --------------- | ----------------------- | ----------------------------------------- |
| Best For        | Beginners               | Advanced users, version control, teamwork |
| Library Install | Through Library Manager | Via platformio.ini file                 |
| Serial Monitor  | Built-in                | Needs to be opened via toolbar            |
| Project Format  | Simple .ino files       | Full folder structure with src, lib   |

---