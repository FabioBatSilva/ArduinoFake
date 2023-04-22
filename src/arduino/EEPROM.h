#pragma once
#include <inttypes.h>

struct EEPROMClass {
  virtual uint8_t read(int idx);
  virtual void write(int idx, uint8_t val);
  virtual void update(int idx, uint8_t val);
  virtual uint16_t length();
  /*
  EERef operator[](const int idx);

  // TODO: How to implement this functionality??
  // https://docs.arduino.cc/learn/built-in-libraries/eeprom
  template <typename T> T &get(int idx, T &t);

  template <typename T> const T &put(int idx, const T &t);
  */
};

extern EEPROMClass EEPROM;