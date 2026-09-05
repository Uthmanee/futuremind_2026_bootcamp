/* Instructor-controlled hardware helper tab. */

const int LEFT_ENABLE_PIN = 5;
const int LEFT_INPUT_1_PIN = 7;
const int LEFT_INPUT_2_PIN = 8;
const int RIGHT_ENABLE_PIN = 6;
const int RIGHT_INPUT_1_PIN = 11;
const int RIGHT_INPUT_2_PIN = 12;

void robotBegin() {
  pinMode(LEFT_ENABLE_PIN, OUTPUT);
  pinMode(LEFT_INPUT_1_PIN, OUTPUT);
  pinMode(LEFT_INPUT_2_PIN, OUTPUT);
  pinMode(RIGHT_ENABLE_PIN, OUTPUT);
  pinMode(RIGHT_INPUT_1_PIN, OUTPUT);
  pinMode(RIGHT_INPUT_2_PIN, OUTPUT);
  stopRobot();
}

// Each side function controls the two motors wired together on that side.
void setLeftSide(int speed, bool forward) {
  speed = constrain(speed, 0, 255);
  digitalWrite(LEFT_INPUT_1_PIN, forward ? HIGH : LOW);
  digitalWrite(LEFT_INPUT_2_PIN, forward ? LOW : HIGH);
  analogWrite(LEFT_ENABLE_PIN, speed);
}

void setRightSide(int speed, bool forward) {
  speed = constrain(speed, 0, 255);
  digitalWrite(RIGHT_INPUT_1_PIN, forward ? HIGH : LOW);
  digitalWrite(RIGHT_INPUT_2_PIN, forward ? LOW : HIGH);
  analogWrite(RIGHT_ENABLE_PIN, speed);
}

void moveForward(int speed) {
  setLeftSide(speed, true);
  setRightSide(speed, true);
}

void moveBackward(int speed) {
  setLeftSide(speed, false);
  setRightSide(speed, false);
}

void turnLeft(int speed) {
  setLeftSide(speed, false);
  setRightSide(speed, true);
}

void turnRight(int speed) {
  setLeftSide(speed, true);
  setRightSide(speed, false);
}

void stopRobot() {
  analogWrite(LEFT_ENABLE_PIN, 0);
  analogWrite(RIGHT_ENABLE_PIN, 0);
  digitalWrite(LEFT_INPUT_1_PIN, LOW);
  digitalWrite(LEFT_INPUT_2_PIN, LOW);
  digitalWrite(RIGHT_INPUT_1_PIN, LOW);
  digitalWrite(RIGHT_INPUT_2_PIN, LOW);
}
