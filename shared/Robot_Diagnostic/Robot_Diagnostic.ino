/*
  FutureMinds Robot Diagnostic

  Safe by default: the motors do not move until an instructor sends a command
  through Serial Monitor at 9600 baud. Perform all motor tests wheels-up first.

  Commands:
    f = forward 500 ms
    b = backward 500 ms
    l = spin left 400 ms
    r = spin right 400 ms
    s = stop now
    c = scan left, forward, right and print distances
    h = print help
*/

#include <Servo.h>

const int DIAGNOSTIC_DRIVE_SPEED = 140;
const int DIAGNOSTIC_TURN_SPEED = 130;

void setup() {
  Serial.begin(9600);
  robotBegin();
  lookForward();
  printHelp();
}

void loop() {
  if (Serial.available() == 0) {
    return;
  }

  char command = Serial.read();

  // Ignore line endings sent by Serial Monitor.
  if (command == '\n' || command == '\r') {
    return;
  }

  switch (command) {
    case 'f':
      Serial.println("Forward for 500 ms");
      moveForward(DIAGNOSTIC_DRIVE_SPEED);
      delay(500);
      stopRobot();
      break;

    case 'b':
      Serial.println("Backward for 500 ms");
      moveBackward(DIAGNOSTIC_DRIVE_SPEED);
      delay(500);
      stopRobot();
      break;

    case 'l':
      Serial.println("Spin left for 400 ms");
      turnLeft(DIAGNOSTIC_TURN_SPEED);
      delay(400);
      stopRobot();
      break;

    case 'r':
      Serial.println("Spin right for 400 ms");
      turnRight(DIAGNOSTIC_TURN_SPEED);
      delay(400);
      stopRobot();
      break;

    case 's':
      stopRobot();
      Serial.println("Stopped");
      break;

    case 'c':
      stopRobot();
      scanAndPrint();
      break;

    case 'h':
      printHelp();
      break;

    default:
      stopRobot();
      Serial.println("Unknown command; robot stopped. Send h for help.");
      break;
  }
}

void printHelp() {
  Serial.println();
  Serial.println("FutureMinds robot diagnostic ready.");
  Serial.println("Use 9600 baud. Raise wheels before motor tests.");
  Serial.println("f=forward, b=backward, l=left, r=right, s=stop, c=scan, h=help");
}

void printReading(const char label[]) {
  int distanceCm = readDistanceCm();
  Serial.print(label);
  Serial.print(": ");
  if (distanceCm == 0) {
    Serial.println("INVALID");
  } else {
    Serial.print(distanceCm);
    Serial.println(" cm");
  }
}

void scanAndPrint() {
  Serial.println("Scanning while motors are stopped...");
  lookLeft();
  printReading("Left");
  lookForward();
  printReading("Forward");
  lookRight();
  printReading("Right");
  lookForward();
  Serial.println("Scan complete; sensor centered.");
}
