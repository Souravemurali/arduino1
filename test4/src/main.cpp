#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define SSID "vivek"
#define PASSWORD "20052005"
#include "DHT.h"

ESP8266WebServer server(80);
DHT dht(D4, DHT11); // DHT11 sensor connected to pin D2
void handleRoot();
void setup() {
    Serial.begin(115200);
    WiFi.begin(SSID, PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    dht.begin();

    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}

void handleRoot() {
    float temperatureC = dht.readTemperature();
    float humidity = dht.readHumidity();
    String html = "<html><body><h1>Temperature</h1>";
    html += "<p>Temperature in Celsius: " + String(temperatureC) + " °C</p>";
    html += "<p>Humidity: " + String(humidity) + " %</p>";
    html += "</body></html>";

    server.send(200, "text/html", html);
}