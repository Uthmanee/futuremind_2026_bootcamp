# Robot Function Reference

Keep this sheet beside the computer on Days 2 and 3.

## Movement

| Command | Meaning | Example |
| --- | --- | --- |
| `robotBegin();` | Prepare the robot pins and stop the motors. Use once in `setup()`. | `robotBegin();` |
| `moveForward(speed);` | Run all four wheels forward continuously. | `moveForward(140);` |
| `moveBackward(speed);` | Run all four wheels backward continuously. | `moveBackward(120);` |
| `turnLeft(speed);` | Spin left by driving the two sides in opposite directions. | `turnLeft(130);` |
| `turnRight(speed);` | Spin right by driving the two sides in opposite directions. | `turnRight(130);` |
| `stopRobot();` | Stop all four drive motors. | `stopRobot();` |

`speed` is a PWM value from 0 (off) to 255 (maximum). Classroom driving should normally stay between 110 and 180.

Movement commands do not include time. For timed movement:

```cpp
moveForward(140);
delay(1000);       // move for 1,000 ms = 1 second
stopRobot();
```

## Sensor and servo

| Command | Meaning |
| --- | --- |
| `lookLeft();` | Point the ultrasonic sensor left and wait for the servo to settle. |
| `lookForward();` | Point the sensor forward and wait for the servo to settle. |
| `lookRight();` | Point the sensor right and wait for the servo to settle. |
| `readDistanceCm();` | Measure and return distance in centimetres. Returns `0` when no trustworthy echo is received. |

Safe decision pattern:

```cpp
int distanceCm = readDistanceCm();

if (distanceCm == 0 || distanceCm <= 20) {
  stopRobot();
} else {
  moveForward(130);
}
```

## Remember

- Arduino is case-sensitive: `moveForward` is not the same as `moveforward`.
- Every command ends with a semicolon.
- Parentheses hold information given to a function.
- `delay()` uses milliseconds: 1,000 ms equals 1 second.
- Lift the wheels before testing a new motor command.
- An invalid distance (`0`) means **stop**, not “the path is clear.”
