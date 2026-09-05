# Day 1 Instructor Pack — Foundations and Onboard LED

## Outcomes

Students should be able to:

- identify the controller and actuator in the demonstration;
- locate `setup()` and `loop()`;
- explain that `setup()` runs once and `loop()` repeats;
- change a timing constant, verify, and upload; and
- create a repeating onboard LED pattern.

## Materials

- One computer and Arduino Uno per team
- USB cables
- Student guide and student sketch
- Projected Arduino IDE
- Instructor solution sketch and untouched recovery copies

No breadboard, external LED, or robot movement is needed today.

## Flow

-> Hook: demonstrate an LED signal and introduce Sense → Think → Act.

-> Uno anatomy and the edit → verify → upload → observe cycle.

-> Project the sketch; trace setup(), loop(), HIGH, LOW, and delay.

-> Timing prediction and team-signal challenge.

-> Team demonstrations; audience describes each pattern.

-> Exit questions, save work, disconnect by the plug, and tidy.

Use short explanation cycles. After introducing one idea, have teams point to it in their own sketch.

## Demo script

1. Show the unpowered Uno. Ask, “What can it sense, think, and make happen today?”
2. Connect USB and upload the instructor sketch without discussing every toolbar button.
3. Reset the Uno and point out that the same pattern starts again.
4. Trace one on/off pair: set `HIGH`, wait, set `LOW`, wait.
5. Change one timing value, ask for predictions, then upload.
6. Deliberately remove one semicolon, verify, read the first useful error line, and restore it.

## Questions to ask

- What would happen if `pinMode` were moved into `loop()`?
- Why use the name `SHORT_FLASH_MS` instead of writing `200` everywhere?
- Does Verify send the program to the board?
- How can a person tell where a repeated signal ends?

Expected ideas: `setup()` is for one-time preparation; names communicate meaning; Verify compiles but Upload transfers; a longer repeat pause separates patterns.

## Solution and checkpoints

The instructor sketch implements short-short-long, followed by a repeat pause. Other patterns are valid when they have three or more flashes, two distinguishable durations, and a clear repeat gap.

Check each team for:

1. Correct Uno and port selection.
2. Successful untouched upload.
3. A written prediction before changing a constant.
4. A working custom pattern.
5. An explanation of `setup()` versus `loop()` from a student who was not doing all the typing.

## Troubleshooting

| Symptom                         | Check                                                                           |
| ------------------------------- | ------------------------------------------------------------------------------- |
| No port                         | USB cable may be charge-only; reconnect and reopen Tools → Port.                |
| Upload failure                  | Confirm Uno, correct port, firmly seated cable, and close Serial Monitor.       |
| Compile error                   | Read the first error; check semicolons, parentheses, braces, and spelling/case. |
| LED seems always on             | On/off delays may be too short, or the final `LOW` is missing.                  |
| Pattern does not repeat clearly | Increase `REPEAT_PAUSE_MS`.                                                     |

Do not take over the keyboard immediately. Ask the team to compare the error line with the projected working example.

## Safety and classroom notes

- Handle the Uno by its edges and keep drinks away.
- Disconnect by holding the USB plug, not pulling the cable.
- Teams self-organize, but invite quieter students to predict, explain, or perform an upload.
- Save the team sketch with a team identifier; restore from the clean copy when debugging exceeds five minutes.
