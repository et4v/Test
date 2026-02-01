#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("BOOT: setup() is running");
}

void loop() {
  static uint32_t t = 0;
  if (millis() - t > 1000) {
    t = millis();
    Serial.println("loop() alive");
  }
}