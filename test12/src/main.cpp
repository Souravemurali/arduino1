#include <Arduino.h>
#define trigL D1
#define echoL D2
#define trigR D3
#define echoR D4

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 20000); // timeout after 20ms
  long distance = duration * 0.034 / 2;
  if (duration == 0) return 999;  // if no echo received
  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
}

void loop() {
  long leftDist = getDistance(trigL, echoL);
  long rightDist = getDistance(trigR, echoR);

  Serial.print("Left: "); Serial.print(leftDist); Serial.print(" cm, ");
  Serial.print("Right: "); Serial.print(rightDist); Serial.println(" cm");

  int threshold = 15;  // obstacle distance limit

  if (leftDist < threshold && rightDist < threshold) {
    Serial.println("Stop - Obstacles on both sides\n");
  } else if (leftDist < threshold) {
    Serial.println("Turn Right - Obstacle on Left\n");
  } else if (rightDist < threshold) {
    Serial.println("Turn Left - Obstacle on Right\n");
  } else {
    Serial.println("Go Forward - Path is Clear\n");
  }

  delay(500);
}