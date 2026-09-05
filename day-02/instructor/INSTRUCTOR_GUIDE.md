# Day 2 Instructor Pack — Motors and Differential Drive

## Outcomes

Students should be able to:

- explain why an L298N sits between the Uno and DC motors;
- predict the left-pair and right-pair directions for forward, backward, and in-place turns;
- call a function with a speed argument;
- calibrate time using evidence rather than guessing repeatedly; and
- arrange commands that drive a four-sided route.

## Materials and setup

- Pre-checked Uno/L298N cars, batteries, USB cables, and one computer per team
- Stable blocks for wheels-up testing
- Masking-tape straight lane, 90° guides, and square routes
- Metre rule/tape measure and timer
- Student guide, function reference, and starter sketch
- Instructor solution and diagnostic sketch

Verify every car against `shared/PRE_CLASS_CHECKLIST.md`. Keep the floor test area closed until the instructor authorizes a team.

## Three-hour flow

| Time | Activity |
| --- | --- |
| 0:00–0:15 | Hook: manually rotate wheels to predict forward and spin turns. Demonstrate one square. |
| 0:15–0:40 | Actuators, motor current, L298N, H-bridge idea, differential drive, and PWM. |
| 0:40–1:00 | Trace one friendly helper into direction pins and `analogWrite`; model a timed sequence. |
| 1:00–1:10 | Break. |
| 1:10–1:35 | Wheels-up test of forward, backward, left, right, and stop. |
| 1:35–2:30 | Straight and turn calibration; build and iterate on the square. |
| 2:30–2:50 | One controlled run per team and short logic explanation. |
| 2:50–3:00 | Exit questions, stop/power-down check, and cleanup. |

## Demo script

1. Ask students to predict the direction of the two left wheels and two right wheels needed to spin left.
2. Explain that Uno pins send instructions; the motor supply/L298N handles motor power.
3. Show `moveForward(140)` and ask what the argument might control.
4. Point out that the function does not know time and will continue until stopped.
5. Demonstrate `move → delay → stop` with wheels raised.
6. Compare `RobotHelpers.ino` with the function reference: friendly name outside, pin details inside.
7. Run one deliberately under-turned corner and ask which single value should change.

## Teaching notes

- Describe an H-bridge with direction arrows; transistor-level detail is out of scope.
- `turnLeft` and `turnRight` are in-place spins, not gentle curves.
- Do not introduce a misleading `turn(90)` function. Without encoders, the car measures time, not angle.
- Battery voltage, motor differences, tyre grip, weight, and floor material change calibration.
- Require one-variable-at-a-time experiments and written observations.

## Completed solution

The instructor sketch executes four identical straight/left-turn pairs once in `setup()`. Replace its starting estimates with a tested car’s values before demonstrating.

A right-turn solution is equally valid when it uses `turnRight` and `RIGHT_90_TIME_MS`. The stretch figure eight should be assessed on logical sequencing and safe iteration, not geometric perfection.

## Checkpoints and expected evidence

1. **Wheels raised:** both motors on each side agree, all named movement functions match physical direction, and `stopRobot()` stops all four wheels.
2. **Straight calibration:** at least two recorded trials and one justified change.
3. **Turn calibration:** separate left/right evidence; students can say why values may differ.
4. **Square:** four side-turn pairs, a stop after every movement, safe speed, and finish within about one car length of the start.

## Troubleshooting

| Symptom | Response |
| --- | --- |
| One motor fights its partner | Reverse that motor's leads so both motors on the side agree; do not compensate in code. |
| An entire side is reversed | Correct the paired side wiring consistently during instructor maintenance; do not reverse one team’s helper code. |
| Motor does not change speed | Confirm ENA/ENB jumpers are removed and pins 5/6 are connected. |
| Car curves on straight | Check battery/tyres and friction; reduce speed. Do not add advanced trim until the core lab works. |
| Car never stops | Check for missing `stopRobot()` and confirm the correct sketch uploaded. Lift the wheels first. |
| Route repeats unexpectedly | Ensure movement is in `setup()`, not `loop()`. |
| Reset occurs when motors start | Inspect power supply, shared ground, loose wiring, and battery condition. Remove the car from student use if unstable. |
| Compile error on a helper call | Check spelling, capital letters, parentheses, argument, and semicolon. |

## Safety

- Upload and first-run with wheels raised.
- One team at a time per marked driving lane.
- Carry a robot only when stopped; switch off motor power before handling wiring.
- Keep faces, fingers, hair, clothing, and cables away from wheels.
- Never use a person’s hand or foot as a target or barrier.
- The instructor stops any car that behaves differently from its command name.

## Assessment rubric (10 points)

| Evidence | Points |
| --- | ---: |
| Explains motor-driver purpose and differential drive | 2 |
| Completes safe wheels-up function tests | 2 |
| Records and uses calibration evidence | 2 |
| Square has four sides/turns and explicit stops | 2 |
| Safe run finishes within about one car length; team explains its sequence | 2 |

## Stretch activities

- Build a figure-eight-style route.
- Compare the same route at two battery states and explain the difference.
- Read `setLeftSide` and `setRightSide`, then identify which lines select direction and speed for each two-motor pair.
