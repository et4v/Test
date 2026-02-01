#ifndef LORA_RECEIVER_H
#define LORA_RECEIVER_H

#include <Arduino.h>
#include <RadioLib.h>

class LoRaReceiver {
public:
  LoRaReceiver();

  bool begin(float freqMHz);
  bool receive(uint8_t &value);

private:
  Module _module;
  SX1262 _radio;
};

#endif