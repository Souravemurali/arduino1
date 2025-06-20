#include <Arduino.h>
#include <ESP8266WiFi.h>

// Motor Pins
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENA D5 // Enable pin for motor A
#define ENB D6 // Enable pin for motor B
const char *ssid = "RobotCar";
const char *password = "12345678";

// HTML Page
String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>Web Controlled Robot</title></head>
<body>
  <h2>Robot Control</h2>
  <button onclick="sendCmd('F')">Forward</button>
  <button onclick="sendCmd('B')">Backward</button>
  <button onclick="sendCmd('L')">Left</button>
  <button onclick="sendCmd('R')">Right</button>
  <button onclick="sendCmd('S')">Stop</button>
  <script>
    function sendCmd(cmd) {
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/?cmd=" + cmd, true);
      xhttp.send();
    }
  </script>
</body>
</html>
)rawliteral";

void forward();
void backward();
void left();
void right();
void stop();


WiFiServer server(80);

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, 100); // Set speed for motor A
  analogWrite(ENB, 100); // Set speed for motor B
  Serial.begin(115200);
  
  WiFi.softAP(ssid, password);
  Serial.println("AP started: Connect to WiFi and go to 192.168.4.1");

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  while (!client.available()) delay(1);

  String request = client.readStringUntil('\r');
  client.flush();

  // Handle command
  if (request.indexOf("cmd=F") != -1) forward();
  else if (request.indexOf("cmd=B") != -1) backward();
  else if (request.indexOf("cmd=L") != -1) left();
  else if (request.indexOf("cmd=R") != -1) right();
  else if (request.indexOf("cmd=S") != -1) stop();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.print(htmlPage);
  client.println();
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}