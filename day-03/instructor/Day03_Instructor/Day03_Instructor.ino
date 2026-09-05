/*
  FutureMinds Robotics — Day 3 Instructor Solution
  A safe automatic collision preventer using an HC-SR04.

  Test with wheels raised before every floor demonstration.
*/

#include <Servo.h>

const int CRUISE_SPEED = 130;
const int STOP_DISTANCE_CM = 20;
const unsigned long READING_PAUSE_MS = 60;

void setup() {
  Serial.begin(9600);
  robotBegin();
  lookForward();

  Serial.println("Day 3 collision preventer ready.");
  Serial.println("Keep the wheels raised for the first test.");
}

void loop() {
  int distanceCm = readDistanceCm();

  Serial.print("Distance: ");
  if (distanceCm == 0) {
    Serial.println("INVALID - STOP");
  } else {
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  bool shouldStop = distanceCm == 0 || distanceCm <= STOP_DISTANCE_CM;

  if (shouldStop) {
    stopRobot();
  } else {
    moveForward(CRUISE_SPEED);
  }

  delay(READING_PAUSE_MS);
}
