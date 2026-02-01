#include "lora_receiver.h"
#include "board_pins.h"
#include <SPI.h>

LoRaReceiver::LoRaReceiver()
: _module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY, SPI),
  _radio(&_module) {
}

bool LoRaReceiver::begin(float freqMHz) {
  // Make sure the SPI pins are correct for this board
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);

  int state = _radio.begin(freqMHz);
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print("Radio begin failed, code=");
    Serial.println(state);
    return false;
  }

  // Optional: safer defaults (you can tune later)
  // _radio.setSpreadingFactor(7);
  // _radio.setBandwidth(125.0);
  // _radio.setCodingRate(5);
  // _radio.setOutputPower(10);

  Serial.println("Radio begin OK");
  return true;
}

bool LoRaReceiver::receive(uint8_t &value) {
  String msg;
  int state = _radio.receive(msg);

  if (state == RADIOLIB_ERR_NONE) {
    if (msg.length() > 0) {
      value = static_cast<uint8_t>(msg[0]);
    } else {
      value = 0;
    }
    return true;
  }

  // No packet is not an error, it is normal
  if (state == RADIOLIB_ERR_RX_TIMEOUT) {
    return false;
  }

  // Real error
  Serial.print("RX error, code=");
  Serial.println(state);
  return false;
}