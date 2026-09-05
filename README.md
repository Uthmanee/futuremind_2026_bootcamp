# FutureMinds 2.0 Robotics Track — Days 1–3

This package contains classroom-ready Arduino lessons for two batches of about 27 first-time programmers. Each batch uses six pre-assembled, four-wheel differential-drive robots, with one computer and one robot per team. The two motors on the left are connected and controlled as one side; the two motors on the right are connected and controlled as the other side.

Days 4 and 5 are intentionally reserved. No line-sensor or hackathon material is included.

## Package map

| Day | Student lab | Instructor pack | Arduino sketches |
| --- | --- | --- | --- |
| 1 — Foundations | `day-01/student/STUDENT_GUIDE.md` | `day-01/instructor/INSTRUCTOR_GUIDE.md` | `Day01_Student` / `Day01_Instructor` |
| 2 — Movement | `day-02/student/STUDENT_GUIDE.md` | `day-02/instructor/INSTRUCTOR_GUIDE.md` | `Day02_Student` / `Day02_Instructor` |
| 3 — Sensing | `day-03/student/STUDENT_GUIDE.md` | `day-03/instructor/INSTRUCTOR_GUIDE.md` | `Day03_Student` / `Day03_Instructor` |

Shared material:

- `shared/PRE_CLASS_CHECKLIST.md` — wiring, power, IDE, safety, and six-car verification.
- `shared/FUNCTION_REFERENCE.md` — printable student helper-function sheet.
- `shared/Robot_Diagnostic/` — safe, Serial-controlled hardware test sketch.

## Standard hardware map

All six cars should use this map before class. Change the constants at the top of each `RobotHelpers.ino` only if the physical wiring must differ.

| Device | Arduino Uno pin |
| --- | --- |
| L298N ENA (left motor pair PWM) | 5 |
| L298N IN1 / IN2 (left motor pair direction) | 7 / 8 |
| L298N ENB (right motor pair PWM) | 6 |
| L298N IN3 / IN4 (right motor pair direction) | 11 / 12 |
| HC-SR04 TRIG / ECHO | 4 / 2 |
| Servo signal | 3 |
| Onboard LED | `LED_BUILTIN` (13) |

Pins 5 and 6 are deliberately used for motor PWM. On an Uno, attaching the Servo library disables PWM on pins 9 and 10.

## Classroom code model

- Day 1 uses one ordinary Arduino sketch.
- Day 2 and Day 3 use a main tab plus `RobotHelpers.ino`.
- Students edit only the main tab's clearly labelled challenge area.
- Helpers remain visible so the instructor can connect each friendly command to `digitalWrite`, `analogWrite`, servo positioning, and pulse timing.
- Movement calls continue until another movement call or `stopRobot()` occurs. Day 2 therefore pairs movement with `delay()` and `stopRobot()`; Day 3 can repeatedly sense while moving.

## Using the package

1. Complete the pre-class checklist on every robot.
2. Copy the three student sketch folders and the diagnostic folder to every classroom computer.
3. Keep instructor folders out of the student workspace.
4. Open sketches by opening the `.ino` file whose name matches its containing folder.
5. Select **Arduino Uno**, select the correct port, verify, and upload.
6. For Day 3 and the diagnostic, install the official **Servo by Arduino** library through Library Manager before class. Some older IDE installations include it already, but do not assume every computer does.

Student starter sketches compile into a safe state: Day 2 does not move until commands are uncommented, and Day 3 stops until its TODO is completed.
