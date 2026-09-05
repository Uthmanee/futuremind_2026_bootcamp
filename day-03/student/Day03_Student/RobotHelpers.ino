/*
  INSTRUCTOR-CONTROLLED TAB

  Students may read this file, but should not edit it during the lab.
  It contains the motor, servo, and HC-SR04 hardware details.
*/

// Standard FutureMinds Uno + L298N pin map
const int LEFT_ENABLE_PIN = 5;    // ENA — PWM
const int LEFT_INPUT_1_PIN = 7;   // IN1
const int LEFT_INPUT_2_PIN = 8;   // IN2
const int RIGHT_ENABLE_PIN = 6;   // ENB — PWM
const int RIGHT_INPUT_1_PIN = 11; // IN3
const int RIGHT_INPUT_2_PIN = 12; // IN4

// Standard FutureMinds sensor pin map
const int ULTRASONIC_TRIGGER_PIN = 4;
const int ULTRASONIC_ECHO_PIN = 2;
const int SERVO_SIGNAL_PIN = 3;

const int SERVO_LEFT_DEGREES = 150;
const int SERVO_FORWARD_DEGREES = 90;
const int SERVO_RIGHT_DEGREES = 30;
const unsigned long ECHO_TIMEOUT_US = 25000UL;
const unsigned long SERVO_SETTLE_MS = 350;

Servo sensorServo;

void robotBegin() {
  pinMode(LEFT_ENABLE_PIN, OUTPUT);
  pinMode(LEFT_INPUT_1_PIN, OUTPUT);
  pinMode(LEFT_INPUT_2_PIN, OUTPUT);
  pinMode(RIGHT_ENABLE_PIN, OUTPUT);
  pinMode(RIGHT_INPUT_1_PIN, OUTPUT);
  pinMode(RIGHT_INPUT_2_PIN, OUTPUT);

  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  stopRobot();
  sensorServo.attach(SERVO_SIGNAL_PIN);
  sensorServo.write(SERVO_FORWARD_DEGREES);
  delay(SERVO_SETTLE_MS);
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

void lookLeft() {
  sensorServo.write(SERVO_LEFT_DEGREES);
  delay(SERVO_SETTLE_MS);
}

void lookForward() {
  sensorServo.write(SERVO_FORWARD_DEGREES);
  delay(SERVO_SETTLE_MS);
}

void lookRight() {
  sensorServo.write(SERVO_RIGHT_DEGREES);
  delay(SERVO_SETTLE_MS);
}

int readDistanceCm() {
  // Send a clean 10 microsecond trigger pulse.
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  unsigned long echoTimeUs = pulseIn(
    ULTRASONIC_ECHO_PIN,
    HIGH,
    ECHO_TIMEOUT_US
  );

  if (echoTimeUs == 0) {
    return 0;
  }

  // For room-temperature air, centimetres are approximately microseconds / 58.
  int distanceCm = echoTimeUs / 58UL;

  // Treat measurements outside the useful classroom range as invalid and safe-stop.
  if (distanceCm < 2 || distanceCm > 300) {
    return 0;
  }

  return distanceCm;
}
