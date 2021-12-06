#include "ArduinoFake.h"
#include "WireFake.h"

void TwoWire::begin(void) { ArduinoFakeInstance(Wire, this)->begin(); }

void TwoWire::begin(uint8_t address) {

  ArduinoFakeInstance(Wire, this)->begin(address);
}

void TwoWire::begin(int address) {
  ArduinoFakeInstance(Wire, this)->begin(address);
}

void TwoWire::end(void) { ArduinoFakeInstance(Wire, this)->end(); }

void TwoWire::setClock(uint32_t clock) {
  ArduinoFakeInstance(Wire, this)->setClock(clock);
}

void TwoWire::setWireTimeout(uint32_t timeout, bool reset_with_timeout) {
  ArduinoFakeInstance(Wire, this)->setWireTimeout(timeout, reset_with_timeout);
}

bool TwoWire::getWireTimeoutFlag(void) {
  return ArduinoFakeInstance(Wire, this)->getWireTimeoutFlag();
}

void TwoWire::clearWireTimeoutFlag(void) {
  ArduinoFakeInstance(Wire, this)->clearWireTimeoutFlag();
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity,
                             uint32_t iaddress, uint8_t isize,
                             uint8_t sendStop) {
  return ArduinoFakeInstance(Wire, this)
      ->requestFrom(address, quantity, iaddress, isize, sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity,
                             uint8_t sendStop) {
  return ArduinoFakeInstance(Wire, this)
      ->requestFrom(address, quantity, sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity) {
  return ArduinoFakeInstance(Wire, this)->requestFrom(address, quantity);
}

void TwoWire::beginTransmission(uint8_t address) {
  ArduinoFakeInstance(Wire, this)->beginTransmission(address);
}

void TwoWire::beginTransmission(int address) {
  ArduinoFakeInstance(Wire, this)->beginTransmission(address);
}

uint8_t TwoWire::endTransmission(bool sendStop) {

  return ArduinoFakeInstance(Wire, this)->endTransmission(sendStop);
}

uint8_t TwoWire::endTransmission(void) {
  return ArduinoFakeInstance(Wire, this)->endTransmission();
}

size_t TwoWire::write(uint8_t data) {
  return ArduinoFakeInstance(Wire, this)->write(data);
}

size_t TwoWire::write(const uint8_t *data, size_t quantity) {
  return ArduinoFakeInstance(Wire, this)->write(data, quantity);
}

int TwoWire::available(void) {
  return ArduinoFakeInstance(Wire, this)->available();
}

int TwoWire::read(void) { return ArduinoFakeInstance(Wire, this)->read(); }

int TwoWire::peek(void) { return ArduinoFakeInstance(Wire, this)->peek(); }

void TwoWire::flush(void) { ArduinoFakeInstance(Wire, this)->flush(); }

void TwoWire::onReceive(void (*function)(int)) {
  ArduinoFakeInstance(Wire, this)->onReceive(function);
}

void TwoWire::onRequest(void (*function)(void)) {
  ArduinoFakeInstance(Wire, this)->onRequest(function);
}

TwoWire Wire = WireFakeProxy(ArduinoFakeInstance(Wire));