#ifndef LORA_RECEIVER_H
#define LORA_RECEIVER_H

#include <Arduino.h>
#include <RadioLib.h>

class LoRaReceiver {
public:
    explicit LoRaReceiver(float freqMHz);

    bool begin();                 // init radio + start RX
    bool receive(uint8_t &value); // returns true if byte received

private:
    float _freq;

    Module _module;
    SX1262 _radio;
};

#endif // LORA_RECEIVER_H