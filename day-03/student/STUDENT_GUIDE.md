# Day 3 Student Lab — Give the Robot a Sense of Distance

## Today’s mission

Read the distance in front of the robot and complete a decision that moves only when the path is clear. The safe response to a close obstacle or an unreliable reading is always to stop.

## How ultrasonic sensing works

The HC-SR04 sends a short burst of sound that people cannot hear. It measures how long the echo takes to return.

**Distance = (speed of sound × travel time) ÷ 2**

We divide by two because the sound travels to the object and back again. The supplied function performs this calculation so you can focus on using the result.

## Words to know

| Word           | Meaning                                                              |
| -------------- | -------------------------------------------------------------------- |
| Sensor         | A component that measures something in the environment.              |
| Echo           | The returning signal used to measure travel time.                    |
| Threshold      | A value used as the boundary for a decision.                         |
| Condition      | A question that is either true or false.                             |
| `if/else`      | Run one block when a condition is true and another when it is false. |
| Serial Monitor | A window that displays messages sent by the Arduino.                 |

## Safety setup

1. Begin with all four drive wheels raised.
2. Open `Day03_Student.ino`; do not edit `RobotHelpers.ino`.
3. Verify that `CRUISE_SPEED` is 130 and `STOP_DISTANCE_CM` is 20.
4. Upload the untouched starter. It prints readings but remains stopped.
5. Open Serial Monitor.

## Checkpoint 1 — Observe distance

Hold flat cardboard in front of the sensor. Do not use your hand as the obstacle during a moving test.

| Actual position | Reading | Reasonable? |
| --------------- | ------: | ----------- |
| About 10 cm     |         |             |
| About 20 cm     |         |             |
| About 50 cm     |         |             |

What happens when the sensor points into open space or cannot receive an echo? **********************************\_\_**********************************

## Checkpoint 2 — Predict the decisions

The stopping condition is:

```cpp
distanceCm <= STOP_DISTANCE_CM
```

`||` means **OR**. Predict each result before testing.

| Reading | Stop or move? | Why? |
| ------: | ------------- | ---- |
|    0 cm |               |      |
|   12 cm |               |      |
|   20 cm |               |      |
|   35 cm |               |      |

## Checkpoint 3 — Complete the TODO

In the **STUDENT CHALLENGE AREA**, replace:

```cpp
bool shouldStop = true;
```

with the condition shown in the nearby TODO comment. Then change the safe placeholder inside `else` so the robot moves forward at `CRUISE_SPEED` when the path is clear.

1. Verify and upload with wheels raised.
2. Move the cardboard nearer and farther while watching the wheels.
3. Confirm that reading `0` stops the wheels.
4. Ask the instructor for permission before placing the robot on the floor.

## Team challenge — Three safe stops

Place cardboard across the marked lane. Begin farther than 50 cm away.

| Trial | Speed | Threshold | Did it touch? | Final gap | Change for next trial |
| ----- | ----: | --------: | ------------- | --------- | --------------------- |
| 1     |       |           |               |           |                       |
| 2     |       |           |               |           |                       |
| 3     |       |           |               |           |                       |

Success means three consecutive trials with no contact. With instructor approval, increase `STOP_DISTANCE_CM` or reduce `CRUISE_SPEED` if needed. Never reduce the threshold merely to make the run look faster.

## Optional extension — Look around while stopped

With motor power stopped, use `lookLeft()`, `lookForward()`, and `lookRight()`. Call `readDistanceCm()` after each direction and print the results. This extension gathers information only; do not program autonomous turning today.

## Exit questions

1. Why is ultrasonic travel time divided by two? ************\_\_\_************
2. What decision does the threshold help the robot make? ********\_\_********
3. Why does an invalid reading cause a stop? **************\_\_**************
4. What happens in the `else` block? ******************\_\_******************
5. Give one reason two consecutive readings may differ: ********\_\_\_********
