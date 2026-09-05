# Pre-Class Hardware and Software Checklist

Complete this checklist for **Robot 1–6** before either student batch arrives.

## 1. Standardize the cars

- Label each Uno, chassis, USB cable, and battery pack with the same robot number.
- Confirm the two left motors are connected as one matched pair on L298N channel A, and the two right motors are connected as one matched pair on channel B.
- Confirm ENA → D5 and ENB → D6, with the L298N enable jumpers removed.
- Confirm left-pair direction pins IN1/IN2 → D7/D8.
- Confirm right-pair direction pins IN3/IN4 → D11/D12.
- Confirm HC-SR04 TRIG → D4 and ECHO → D2.
- Confirm servo signal → D3.
- Confirm a common ground between Uno, L298N, sensor, servo supply, and motor supply.
- Never power the DC motors from the Uno 5 V pin.
- Use a regulated supply suitable for the servo; do not assume a computer USB port can safely power the motors and servo.
- Verify that the combined current of each two-motor side is safe for the motor driver and supply; reject any car whose L298N overheats during testing.
- Secure loose wires and ensure the ultrasonic sensor cannot strike the chassis at 30° or 150°.

## 2. Check software

- Install Arduino IDE and confirm the Arduino Uno board support is available.
- In Library Manager, install the official **Servo by Arduino** library and confirm that it compiles. Some older IDE versions bundle it, while newer installations may require this one-time setup.
- Copy student sketch folders and `Robot_Diagnostic` to every computer.
- Select **Arduino Uno**, then identify and label the correct USB port on each computer.
- Disable any automatic formatting or cloud-sync behavior that could overwrite student sketches.
- Keep untouched recovery copies of all student sketches.

## 3. Run the diagnostic

Upload `Robot_Diagnostic.ino`, open Serial Monitor at **9600 baud**, and test with the wheels raised first.

| Check | Pass condition |
| --- | --- |
| `f` | All four wheels drive the car forward for 500 ms. |
| `b` | All four wheels drive backward for 500 ms. |
| `l` | The car spins left for 400 ms. |
| `r` | The car spins right for 400 ms. |
| `s` | All four drive motors stop immediately. |
| `c` | Servo scans left/forward/right and prints plausible distances. |

If one motor fights the other motor on the same side, correct that motor's leads before further testing. If an entire side is reversed, correct the paired wiring consistently; do not maintain different code for different cars.

## 4. Record each car's baseline

Use masking tape on the floor and a charged battery.

| Robot | Straight speed | 1 m time (ms) | Left 90° (ms) | Right 90° (ms) | 10/20/50 cm readings pass? | Stop test ×3 | Notes |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| 1 | | | | | | | |
| 2 | | | | | | | |
| 3 | | | | | | | |
| 4 | | | | | | | |
| 5 | | | | | | | |
| 6 | | | | | | | |

Use 140 as the starting drive speed and 130 as the starting turn speed. Record measured times instead of promising exact angles: timed open-loop cars vary with battery charge, tyres, motors, and floor surface.

## 5. Prepare the room

- Mark a wheels-up bench-test area and a separate floor driving area.
- Tape one straight lane and six square courses with generous spacing.
- Provide lightweight cardboard obstacles; do not use people as obstacles.
- Keep long hair, fingers, clothes, and USB cables away from wheels.
- Assign one instructor to authorize floor tests while the other assists with code and uploads.
- Charge or replace batteries between batches.

## 6. Final go/no-go check

Do not release a robot to students unless it:

- uploads reliably;
- stops on reset and at the end of the diagnostic;
- shows a visible low/high PWM speed difference;
- moves in the same named directions as the other five cars;
- reads approximately 10, 20, and 50 cm;
- treats a missing echo as `0`;
- has clear servo travel; and
- stops before a cardboard obstacle in three consecutive low-speed trials.
