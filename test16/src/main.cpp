#include <Arduino.h>
#define trigL 4    // D1 on NodeMCU is GPIO5
#define echoL 5    // D2 on NodeMCU is GPIO4
#define trigR 2    // D3 on NodeMCU is GPIO0
#define echoR 3    // D4 on NodeMCU is GPIO2

// Motor driver pin definitions
#define IN1 6     // D5 on NodeMCU is GPIO14
#define IN2 7     // D6 on NodeMCU is GPIO12
#define IN3 8     // D7 on NodeMCU is GPIO13
#define IN4 9    // D8 on NodeMCU is GPIO15
#define ENA 10     // D9 is not standard; set to GPIO3 or change as needed
#define ENB 11      // D10 is not standard; set to GPIO1 or change as needed

// Motor speed definitions
#define LSPEED 100
#define RSPEED 100

void forward();
void turnLeft();
void turnRight();
void stop();


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
    stop(); // Example action: stop if both sides are blocked
  } else if (leftDist < threshold) {
    Serial.println("Turn Right - Obstacle on Left\n");
    turnRight(); // Example action: turn right if left side is blocked
  } else if (rightDist < threshold) {
    Serial.println("Turn Left - Obstacle on Right\n");
    turnLeft(); // Example action: turn left if right side is blocked
  } else {
    Serial.println("Go Forward - Path is Clear\n");
    forward(); // Example action: go forward if path is clear
  }

  delay(500);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, LSPEED);
  analogWrite(ENB, RSPEED);
}

void turnLeft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, LSPEED);
  analogWrite(ENB, RSPEED);
}

void turnRight()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, LSPEED);
  analogWrite(ENB, RSPEED);
}
void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, LSPEED);
  analogWrite(ENB, RSPEED);
}
