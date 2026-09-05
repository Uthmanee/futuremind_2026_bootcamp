# Day 2 Student Lab — Make the Robot Move

## Today’s mission

Use friendly movement functions, speed values, and measured times to make a four-wheel robot drive a square.

## How the robot turns

The car uses **differential drive**. Its two left motors are connected and controlled as one side, while its two right motors are connected and controlled as the other side. It changes direction by driving the two sides differently.

| Robot action | Left side: two wheels | Right side: two wheels |
| ------------ | --------------------- | ---------------------- |
| Forward      | Forward               | Forward                |
| Backward     | Backward              | Backward               |
| Spin left    | Backward              | Forward                |
| Spin right   | Forward               | Backward               |
| Stop         | Stop                  | Stop                   |

The Arduino sends control signals, but the L298N and motor battery provide the motor power. Never connect a DC motor directly to an Arduino output pin.

## Words to know

| Word         | Meaning                                                                                     |
| ------------ | ------------------------------------------------------------------------------------------- |
| Actuator     | A component that creates a physical action.                                                 |
| Circuit      | A complete path of connected electrical components through which electric current can flow. |
| Motor driver | A circuit that controls power to motors.                                                    |
| Function     | A named block of instructions.                                                              |
| Argument     | Information placed inside a function’s parentheses.                                         |
| Calibration  | Measuring and adjusting for the real robot and environment.                                 |

## Safety checkpoint — wheels raised

Do not place the robot on the floor yet.

1. Put the chassis on a stable block so all four drive wheels can spin freely.
2. Open `Day02_Student.ino`; do not edit `RobotHelpers.ino`.
3. Ask the instructor to approve the test area.
4. Uncomment only the Checkpoint 1 commands.
5. Upload and identify the direction of both wheels on each side.
6. If “forward” is physically backward—or two motors on one side fight each other—stop and tell the instructor.

## Checkpoint 1 — Test movement

Try one function at a time:

```cpp
moveForward(DRIVE_SPEED);
delay(700);
stopRobot();
```

Repeat safely for `moveBackward`, `turnLeft`, and `turnRight`. A movement call continues until `stopRobot()` or another movement command.

What does the value inside the parentheses control? **********\_\_\_**********

## Checkpoint 2 — Straight-line calibration

After instructor approval, place the robot at the floor start line.

1. The goal is to measure the speed and time the car needs to move at to reach the marked distance from the start position.
2. You may need to perform multiple trials to get this right. Record your results after each trial.
3. Begin with `DRIVE_SPEED = 140` and `STRAIGHT_TIME_MS = 1200`.
4. Measure the distance covered and record.
5. Edit one of `DRIVE_SPEED` or `STRAIGHT_TIME_MS` and repeat the process till you get to the marked distance.
6. You should only change one of `DRIVE_SPEED` or `STRAIGHT_TIME_MS` per reading.

| Trial | Time (ms) | Speed | Distance reached | What will we change? |
| ----- | --------: | ----: | ---------------- | -------------------- |
| 1     |       700 |       |                  |                      |
| 2     |       700 |       |                  |                      |
| 3     |       700 |       |                  |                      |

At what speed covered does the car cover the requered distance?: ****\_\_****

## Checkpoint 3 — Turn calibration

Use the taped 90° guide. Left and right times may differ.

1. The goal is to measure the speed and time the car needs to make a left or right turn.
2. You may need to perform multiple trials to get this right. Record your results after each trial.
3. You should start with left turn, and only do for right turn after getting it right.
4. Begin with `DRIVE_SPEED = 140` and `STRAIGHT_TIME_MS = 1200`.
5. Measure the distance covered and record.
6. Edit one of `DRIVE_SPEED` or `STRAIGHT_TIME_MS` and repeat the process till you get to the marked distance.
7. You should only change one of `DRIVE_SPEED` or `STRAIGHT_TIME_MS` per reading.

| Trial | Direction | Speed | Time (ms) | Too little / correct / too far |
| ----- | --------- | ----: | --------: | ------------------------------ |
| 1     | Left      |       |           |                                |
| 2     | Left      |       |           |                                |
| 3     | Right     |       |           |                                |
| 4     | Right     |       |           |                                |

Chosen left 90° time: ****\_\_**** ms  
Chosen right 90° time: ****\_\_**** ms

## Team challenge — Drive a square

Edit the calibration constants and the **STUDENT CHALLENGE AREA** in the main tab.

1. Choose either left or right turns.
2. Add a straight movement and a 90° turn.
3. Stop after each movement before the short pause.
4. Repeat the pair four times.
5. Upload with wheels raised, then request permission for a floor run.
6. Change only one calibration value between trials.

Success means the robot completes four sides, stays in the test area, and ends within approximately one car length of its starting point.

## Stretch challenge

Create a figure-eight-style route from movement commands. Accuracy matters more than speed. Explain why the route changes as the battery loses charge.

## Exit questions

1. Why do we need a motor driver? ********************\_********************
2. What does `moveForward(140);` do? ******************\_\_******************
3. Why must it be followed later by `stopRobot()`? ************\_************
4. Why might two cars need different turn times? ************\_\_************
5. Would a timed turn always equal exactly 90°? Why? **********\_\_\_**********
