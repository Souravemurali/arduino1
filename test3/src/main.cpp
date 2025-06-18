#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiGeneric.h>
#define SSID "vivek"
#define PASSWORD "20052005"
ESP8266WebServer server(80);

void setup() {
    Serial.begin(115200);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", []() {
        server.send(200, "text/html", "<h1>Hello World</h1>");
    });

    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}

