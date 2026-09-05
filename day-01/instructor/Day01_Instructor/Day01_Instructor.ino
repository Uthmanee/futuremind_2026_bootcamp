/*
  FutureMinds Robotics — Day 1 Instructor Solution
  Pattern: short, short, long, then a clear repeat pause.
*/

const int LED_PIN = LED_BUILTIN;
const unsigned long SHORT_FLASH_MS = 200;
const unsigned long LONG_FLASH_MS = 600;
const unsigned long REPEAT_PAUSE_MS = 1200;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Short flash 1
  digitalWrite(LED_PIN, HIGH);
  delay(SHORT_FLASH_MS);
  digitalWrite(LED_PIN, LOW);
  delay(SHORT_FLASH_MS);

  // Short flash 2
  digitalWrite(LED_PIN, HIGH);
  delay(SHORT_FLASH_MS);
  digitalWrite(LED_PIN, LOW);
  delay(SHORT_FLASH_MS);

  // Long flash
  digitalWrite(LED_PIN, HIGH);
  delay(LONG_FLASH_MS);
  digitalWrite(LED_PIN, LOW);

  delay(REPEAT_PAUSE_MS);
}
