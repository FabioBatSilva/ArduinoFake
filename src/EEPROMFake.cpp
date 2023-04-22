// clang-format off
#include "ArduinoFake.h"
#include "EEPROMFake.h"
// clang-format on

uint8_t EEPROMClass::read(int idx) {
  return ArduinoFakeInstance(EEPROM)->read(idx);
};
void EEPROMClass::write(int idx, uint8_t val) {
  ArduinoFakeInstance(EEPROM)->write(idx, val);
};
void EEPROMClass::update(int idx, uint8_t val) {
  ArduinoFakeInstance(EEPROM)->update(idx, val);
};
uint16_t EEPROMClass::length() { return ArduinoFakeInstance(EEPROM)->length(); }

EEPROMClass EEPROM = EEPROMFakeProxy(ArduinoFakeInstance(EEPROM));
