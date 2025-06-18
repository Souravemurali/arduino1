# NodeMCU Web Server Project

This project sets up a simple web server on a NodeMCU that connects to a specified WiFi network and responds with "Hello World" when accessed.

## Project Structure

```
nodemcu-webserver
├── src
│   ├── main.ino
│   └── wifi_config.h
├── README.md
```

## Setup Instructions

1. **Install the Arduino IDE**: Make sure you have the Arduino IDE installed on your computer.

2. **Install the ESP8266 Board Package**: 
   - Open the Arduino IDE.
   - Go to `File` -> `Preferences`.
   - In the "Additional Board Manager URLs" field, add: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   - Go to `Tools` -> `Board` -> `Boards Manager`, search for `ESP8266`, and install the package.

3. **Clone the Repository**: Clone this repository to your local machine.

4. **Configure WiFi Credentials**: 
   - Open `src/wifi_config.h` and enter your WiFi SSID and password.

5. **Upload the Code**:
   - Connect your NodeMCU to your computer via USB.
   - Select the correct board and port in the Arduino IDE (`Tools` -> `Board` -> `NodeMCU 1.0 (ESP-12E Module)`).
   - Open `src/main.ino` and click on the upload button.

## Accessing the Web Server

Once the code is uploaded successfully, open the Serial Monitor in the Arduino IDE (set to 115200 baud rate) to see the IP address assigned to your NodeMCU. 

Open a web browser and enter the IP address. You should see the message "Hello World" displayed on the page.