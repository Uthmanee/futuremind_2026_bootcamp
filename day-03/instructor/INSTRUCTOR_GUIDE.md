# Day 3 Instructor Pack — Ultrasonic Sensing and Decisions

## Outcomes

Students should be able to:

- describe ultrasonic distance measurement as an out-and-back time-of-flight measurement;
- read and interpret Serial Monitor output;
- use a threshold in an `if/else` decision;
- explain why `0` is treated as invalid and unsafe; and
- demonstrate three consecutive no-contact stops.

## Materials and setup

- Pre-checked Uno/L298N cars with mounted HC-SR04 and servo
- Charged batteries, USB cables, and one computer per team
- Flat, lightweight cardboard obstacles
- Marked straight test lanes with 10, 20, and 50 cm reference points
- Student guide, function reference, starter sketch, instructor solution, and diagnostic

Before class, verify the sensor faces straight at 90°, moves freely between 30° and 150°, and cannot catch a wire. Recheck the stopping behavior after charging or replacing batteries.

## Three-hour flow

| Time | Activity |
| --- | --- |
| 0:00–0:15 | Hook: show live distance readings and ask how the robot could avoid contact. |
| 0:15–0:40 | Trigger/echo, out-and-back travel, divide by two, thresholds, and invalid readings. |
| 0:40–1:00 | Trace `readDistanceCm()` at a high level and model the `if/else` decision. |
| 1:00–1:10 | Break. |
| 1:10–1:35 | Stationary 10/20/50 cm readings and prediction table. |
| 1:35–2:30 | Complete TODOs, wheels-up test, then three controlled floor trials. |
| 2:30–2:50 | Team demonstrations and explanations; optional stationary direction scan. |
| 2:50–3:00 | Exit questions, stop/power-down check, and cleanup. |

## Demo script

1. Point the sensor at cardboard and display the Serial Monitor at 9600 baud.
2. Move the cardboard and ask students to predict the next number.
3. Draw the sound path to the obstacle and back; use the drawing to justify dividing by two.
4. Move the target too close, too far, or off-axis to produce an unreliable reading.
5. Ask whether “I do not know” should mean drive or stop. Establish the fail-safe rule.
6. Trace the two branches of the completed solution without introducing nested logic.
7. Demonstrate servo scanning only after the collision preventer passes.

## Teaching notes

- The helper uses a 25,000 µs timeout so a missing echo cannot block forever.
- It accepts roughly 2–300 cm and maps anything else to `0`.
- `0` means invalid, not a physical claim that an object is exactly zero centimetres away.
- The nominal threshold is 20 cm. Raise it or reduce speed if momentum causes contact.
- The 60 ms loop pause reduces rapid ultrasonic retriggering and keeps output readable.
- Servo scanning is an observation extension, not obstacle-avoidance logic for this day.

## Completed solution

The instructor sketch calculates:

```cpp
bool shouldStop = distanceCm == 0 || distanceCm <= STOP_DISTANCE_CM;
```

It calls `stopRobot()` when true and `moveForward(CRUISE_SPEED)` otherwise. This ordering makes invalid readings fail safe.

For the optional scan, stop the robot first, call a look function, then call `readDistanceCm()`. Do not read immediately while the servo is moving; each look helper includes settling time.

One simple extension solution is:

```cpp
stopRobot();
lookLeft();
Serial.println(readDistanceCm());
lookForward();
Serial.println(readDistanceCm());
lookRight();
Serial.println(readDistanceCm());
lookForward();  // leave the sensor centred
```

## Checkpoints and expected evidence

1. **Stationary sensing:** plausible readings near 10, 20, and 50 cm; students identify ordinary variation.
2. **Prediction:** correct outcomes for invalid, below, equal-to, and above-threshold readings.
3. **Wheels raised:** clear distance spins the wheels; close/invalid distance stops them.
4. **Floor test:** three consecutive stops without touching cardboard, recorded in the table.
5. **Explanation:** team describes both branches and the fail-safe choice.

## Troubleshooting

| Symptom | Response |
| --- | --- |
| Always reads 0 | Check 5 V, ground, TRIG D4, ECHO D2, and sensor orientation. Test with flat cardboard. |
| Reading jumps | Use a larger flat target, keep it square to the sensor, remove nearby angled objects, and reduce movement speed. |
| Servo points backward | Check horn mounting first; adjust angle constants only during instructor setup. |
| Servo causes Uno resets | Remove the car from use and inspect power capacity/common ground; do not continue from computer USB alone. |
| Car touches obstacle | Increase threshold, reduce `CRUISE_SPEED`, check loop timing, and recharge the battery before retesting. |
| Car never moves | Confirm the student replaced both safe TODO placeholders and that a valid distance is above threshold. |
| Serial text is unreadable | Set Serial Monitor to 9600 baud. |

## Safety

- Start with wheels raised and use cardboard, not a person, as the obstacle.
- Keep the driving lane clear and test one robot per lane.
- Stop motor power before touching wiring or repositioning the servo horn.
- Treat unexpected motion, reset loops, hot components, or strained servo sounds as a stop-work condition.
- A successful lab prioritizes repeatable stopping over speed.

## Assessment rubric (10 points)

| Evidence | Points |
| --- | ---: |
| Explains echo travel and divide-by-two idea | 2 |
| Collects and interprets 10/20/50 cm readings | 2 |
| Correct safe `if/else` logic, including invalid readings | 2 |
| Completes three recorded no-contact stops | 2 |
| Team explains threshold choice and follows safety procedure | 2 |

## Stretch activities

- Stop the robot and print left, forward, and right measurements.
- Compare a flat target with a narrow or angled target and explain the difference.
- Add a distinct onboard LED indication while stopped, without changing the collision decision.
