/*
  FutureMinds Robotics — Day 2 Student Sketch
  Goal: calibrate movement and arrange commands to drive a square.

  IMPORTANT:
  - Edit only the calibration constants and the STUDENT CHALLENGE AREA.
  - First tests must be performed with all four drive wheels raised.
  - Movement continues until stopRobot() or another movement command.
*/

const int DRIVE_SPEED = 140;       // Safe starting value: 0 to 255
const int TURN_SPEED = 130;        // Safe starting value: 0 to 255

// Replace these starting estimates with measurements for your team's car.
const unsigned long STRAIGHT_TIME_MS = 1200;
const unsigned long LEFT_90_TIME_MS = 600;
const unsigned long RIGHT_90_TIME_MS = 600;
const unsigned long PAUSE_BETWEEN_MOVES_MS = 300;

void setup() {
  robotBegin();

  // Give the team time to place the robot safely after an upload.
  delay(2000);

  // ===== STUDENT CHALLENGE AREA =====

  // CHECKPOINT 1: Remove // from these three lines for a wheels-up test.
  // Test only one movement function at a time.
  // moveForward(DRIVE_SPEED);
  // delay(700);
  // stopRobot();

  // TODO: After calibration, arrange straight and turn commands four times.
  // One side-and-turn example is shown below. Keep it commented until the
  // instructor approves a floor test.

  // moveForward(DRIVE_SPEED);
  // delay(STRAIGHT_TIME_MS);
  // stopRobot();
  // delay(PAUSE_BETWEEN_MOVES_MS);

  // turnLeft(TURN_SPEED);
  // delay(LEFT_90_TIME_MS);
  // stopRobot();
  // delay(PAUSE_BETWEEN_MOVES_MS);

  // ===== END STUDENT CHALLENGE AREA =====

  // Always finish the one-time route in a stopped state.
  stopRobot();
}

void loop() {
  // The route is in setup() so it runs only once after upload or reset.
  stopRobot();
}
