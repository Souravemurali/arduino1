# NodeMCU Web Server with DHT11 Sensor

This project demonstrates how to create a web server using NodeMCU that connects to a WiFi network and displays temperature data from a DHT11 sensor in both Fahrenheit and Celsius.

## Project Structure

```
nodemcu-webserver-dht11
├── src
│   ├── main.ino          # Main entry point for the NodeMCU application
│   ├── wifi_config.h     # WiFi configuration settings
│   ├── dht11_sensor.h    # Functions and constants for the DHT11 sensor
│   └── web_server.h      # Web server functionality and routes
├── lib
│   └── README.md         # Documentation for libraries used
└── README.md             # Project documentation
```

## Setup Instructions

1. **Install the Arduino IDE**: Make sure you have the Arduino IDE installed on your computer.

2. **Install the ESP8266 Board Package**: In the Arduino IDE, go to `File` -> `Preferences`, and add the following URL to the "Additional Board Manager URLs":
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
   Then, go to `Tools` -> `Board` -> `Boards Manager`, search for "ESP8266", and install the package.

3. **Install Required Libraries**: You will need the following libraries:
   - DHT sensor library
   - Adafruit Unified Sensor library

   You can install these libraries via the Library Manager in the Arduino IDE (`Sketch` -> `Include Library` -> `Manage Libraries`).

4. **Configure WiFi Settings**: Open `src/wifi_config.h` and enter your WiFi SSID and password.

5. **Upload the Code**: Connect your NodeMCU to your computer and select the correct board and port in the Arduino IDE. Upload the `src/main.ino` file.

6. **Access the Web Server**: Once uploaded, open the Serial Monitor to find the IP address assigned to your NodeMCU. Open a web browser and enter the IP address to view the temperature data.

## Usage

The web server will display the current temperature readings from the DHT11 sensor in both Fahrenheit and Celsius. Refresh the page to get the latest readings.

## License

This project is open-source and available for anyone to use and modify.