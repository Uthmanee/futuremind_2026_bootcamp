/*
  FutureMinds Robotics — Day 2 Instructor Solution
  This sketch drives a calibrated square once.

  Test with wheels raised before every floor demonstration.
*/

const int DRIVE_SPEED = 140;
const int TURN_SPEED = 130;

// Starting estimates only. Replace with values measured for the demonstration car.
const unsigned long STRAIGHT_TIME_MS = 1200;
const unsigned long LEFT_90_TIME_MS = 600;
const unsigned long PAUSE_BETWEEN_MOVES_MS = 300;

void setup() {
  robotBegin();
  delay(2000);

  // Side 1 and turn 1
  moveForward(DRIVE_SPEED);
  delay(STRAIGHT_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);
  turnLeft(TURN_SPEED);
  delay(LEFT_90_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);

  // Side 2 and turn 2
  moveForward(DRIVE_SPEED);
  delay(STRAIGHT_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);
  turnLeft(TURN_SPEED);
  delay(LEFT_90_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);

  // Side 3 and turn 3
  moveForward(DRIVE_SPEED);
  delay(STRAIGHT_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);
  turnLeft(TURN_SPEED);
  delay(LEFT_90_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);

  // Side 4 and final turn
  moveForward(DRIVE_SPEED);
  delay(STRAIGHT_TIME_MS);
  stopRobot();
  delay(PAUSE_BETWEEN_MOVES_MS);
  turnLeft(TURN_SPEED);
  delay(LEFT_90_TIME_MS);
  stopRobot();
}

void loop() {
  stopRobot();
}
