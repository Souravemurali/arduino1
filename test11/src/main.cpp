#include <Arduino.h>
#define ECHOPIN D5
#define TRIGPIN D6
void setup() {
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("ultrasonic sensor test");
  digitalWrite(TRIGPIN,LOW);
}

void loop() {
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);

  float duration = pulseIn(ECHOPIN, HIGH);
  float distance = (duration * 0.034) / 2;
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println(" cm");

  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println("Looping...");
}
