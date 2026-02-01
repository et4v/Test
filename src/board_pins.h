#ifndef BOARD_PINS_H
#define BOARD_PINS_H

#include <Arduino.h>

// T-Watch S3 SX1262 pin map (from your board header)
static constexpr int LORA_SCK  = 3;
static constexpr int LORA_MISO = 4;
static constexpr int LORA_MOSI = 1;
static constexpr int LORA_CS   = 5;

static constexpr int LORA_DIO1 = 9;  // IRQ
static constexpr int LORA_RST  = 8;
static constexpr int LORA_BUSY = 7;

// Pick the frequency that matches your transmitter.
// Common: 915.0 (US), 868.0 (EU)
static constexpr float LORA_FREQ_MHZ = 915.0;

#endif