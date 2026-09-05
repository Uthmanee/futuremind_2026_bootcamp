# Day 1 Student Lab — Make the Arduino Speak With Light

## Today’s mission

By the end of the lab, your team will be able to change an Arduino program, verify it, upload it, and use the onboard LED to send a repeating signal.

## The big idea

A robot can be described as:

**Sense → Think → Act**

- A sensor collects information.
- The program makes a decision.
- An actuator does something.

Today the onboard LED is our simple actuator. The Uno is the controller—the robot’s “brain.”

## Words to know

| Word           | Meaning                                                      |
| -------------- | ------------------------------------------------------------ |
| Sketch         | An Arduino program.                                          |
| `setup()`      | Runs once when the Arduino starts or resets.                 |
| `loop()`       | Repeats while the Arduino has power.                         |
| Constant       | A named value that should not change while the program runs. |
| `HIGH` / `LOW` | Turn a digital output on / off.                              |
| Millisecond    | One-thousandth of a second; 1,000 ms = 1 second.             |

## Before uploading

1. Connect the Arduino with USB.
2. Open `Day01_Student.ino` (Already opened for you).
3. Select **Tools → Board → Arduino Uno**.
4. Select the port shown by your instructor.
5. Find `setup()` and `loop()`.
6. Predict: will the first flash be short or long? Write your answer: \***\*\_\_\*\***

## Checkpoint 1 — Upload the starter heartbeat

1. Click **Verify**. Fix missing semicolons or brackets if the IDE reports an error.
2. Click **Upload**.
3. Watch the small onboard LED marked **L**.
4. Describe the pattern you see: **\*\*\*\***\*\*\*\***\*\*\*\***\_\_**\*\*\*\***\*\*\*\***\*\*\*\***

## Checkpoint 2 — Change its speed

Find the constants near the top of the sketch.

1. Change `SHORT_FLASH_MS` to a different safe value between 100 and 500.
2. Predict how the pattern will change: **\*\***\*\*\*\***\*\***\_\_\_**\*\***\*\*\*\***\*\***
3. Verify and upload.
4. Was your prediction correct? Why? **\*\*\*\***\*\***\*\*\*\***\_**\*\*\*\***\*\***\*\*\*\***

## Team challenge — Design a signal

Edit only the section labelled **STUDENT CHALLENGE AREA**.

- Include at least one short and one long flash.
- Ask another team to describe your pattern without seeing your code.

Draw your signal. Use `—` for LED on and a blank space for LED off:

`__________________________________________________________________`

<!-- ## Stretch challenge

Use short and long flashes to represent your team number or a simple message. Add a comment explaining what the signal means. -->

## Exit questions

1. Which function runs only once? **\*\*\*\***\*\*\*\***\*\*\*\***\_**\*\*\*\***\*\*\*\***\*\*\*\***
2. Which function repeats? \***\*\*\*\*\***\*\*\***\*\*\*\*\***\_\_\_\_\***\*\*\*\*\***\*\*\***\*\*\*\*\***
3. How many milliseconds are in two seconds? **\*\***\*\***\*\***\_\_**\*\***\*\***\*\***
4. Name one step between editing code and seeing it run: **\*\*\*\***\_\_\_**\*\*\*\***
5. Circle the part that acts today: **Arduino / LED / USB cable**
