# arduino1
### 🧩 1. *Include the DHT Library*

cpp
#include "DHT.h"


* This line includes the library needed to work with the DHT11 sensor.
* It contains pre-written functions to read data easily.

---

### 📍 2. *Define Sensor Pin and Type*

cpp
#define DHTPIN 2       // Data pin connected to D2
#define DHTTYPE DHT11  // Specify the sensor model


* DHTPIN is the digital pin where the *data pin* of the DHT11 is connected (here, pin 2).
* DHTTYPE defines which sensor we are using — *DHT11*.

---

### 🔧 3. *Create a DHT Sensor Object*

cpp
DHT dht(DHTPIN, DHTTYPE);


* This creates an o…
[10:50 AM, 6/18/2025] Sourave Murali: Here’s a *step-by-step instruction guide* to complete a basic *Temperature and Humidity Monitoring Project* using the *DHT11 sensor* with *Arduino Uno* (same logic applies to NodeMCU as well).

---

## 🔧 PROJECT: Temperature & Humidity Monitor Using DHT11

---

### ✅ *Step 1: Gather Components*

You’ll need:

* 1× Arduino Uno (or NodeMCU ESP8266)
* 1× DHT11 Sensor Module
* Jumper Wires
* USB cable (for uploading code)
* Computer with Arduino IDE installed

---

### 🔌 *Step 2: Connect the DHT11 Sensor*

Connect the sensor to Arduino like this:

| DHT11 Pin | Arduino Uno Pin |
| --------- | --------------- |
| VCC       | 5V              |
| DATA      | D2              |
| GND       | GND             |

> For NodeMCU, connect *VCC to 3.3V* and *DATA to D4 (GPIO2)*.

---

### 💻 *Step 3: Install Arduino IDE (if not already)*

Download from: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

---

### 📦 *Step 4: Install Required Libraries*

Open Arduino IDE:

* Go to *Sketch → Include Library → Manage Libraries*
* Search for and install:

  * *DHT sensor library by Adafruit*
  * *Adafruit Unified Sensor*

---

### 🧑‍💻 *Step 5: Write or Paste the Code*

Paste this into the Arduino IDE:

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


---

### ⬆️ *Step 6: Upload the Code*

* Connect Arduino via USB.
* Select the board: *Tools → Board → Arduino Uno*
* Select the correct port: *Tools → Port → COMX*
* Click the *Upload* button (right arrow).

---

### 📟 *Step 7: View Output*

* Go to *Tools → Serial Monitor*
* Set baud rate to *9600*
* You’ll see readings like:


Humidity: 60.00 %	Temperature: 27.50 *C
