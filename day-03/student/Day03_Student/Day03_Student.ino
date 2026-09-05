/*
  FutureMinds Robotics — Day 3 Student Sketch
  Goal: complete a safe automatic collision preventer.

  IMPORTANT:
  - Edit only the classroom settings and the STUDENT CHALLENGE AREA.
  - Upload and test first with all four drive wheels raised.
  - A distance of 0 means the sensor has no trustworthy reading: STOP.
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

  // ===== STUDENT CHALLENGE AREA =====

  // TODO 1: Replace true with this safe condition:
  // distanceCm <= STOP_DISTANCE_CM
  bool shouldStop = true;

  if (shouldStop) {
    stopRobot();
  } else {
    // TODO 2: Replace this safe placeholder with moveForward(CRUISE_SPEED);
    stopRobot();
  }

  // ===== END STUDENT CHALLENGE AREA =====

  // A short pause keeps the readings stable and the Serial Monitor readable.
  delay(READING_PAUSE_MS);
}
