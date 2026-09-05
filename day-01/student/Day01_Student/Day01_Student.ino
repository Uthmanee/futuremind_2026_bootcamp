/*
  FutureMinds Robotics — Day 1 Student Sketch
  Goal: edit, verify, upload, and create an onboard LED signal.

  Edit only the timing constants and the STUDENT CHALLENGE AREA during the lab.
*/

const int LED_PIN = LED_BUILTIN;
const unsigned long SHORT_FLASH_MS = 200;
const unsigned long LONG_FLASH_MS = 600;
const unsigned long REPEAT_PAUSE_MS = 1200;

void setup() {
  // setup() runs once. It prepares the LED pin to send an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // ===== STUDENT CHALLENGE AREA =====

  // One short flash
  digitalWrite(LED_PIN, HIGH);
  delay(SHORT_FLASH_MS);
  digitalWrite(LED_PIN, LOW);
  delay(SHORT_FLASH_MS);

  // One long flash
  digitalWrite(LED_PIN, HIGH);
  delay(LONG_FLASH_MS);
  digitalWrite(LED_PIN, LOW);

  // TODO 1: Add at least one more short or long flash here.

  // This longer pause makes the end of the repeating signal easy to see.
  delay(REPEAT_PAUSE_MS);

  // ===== END STUDENT CHALLENGE AREA =====
}
