#pragma once

#include "ArduinoFake.h"
#include "arduino/SPI.h"

struct SPIFake {
  virtual uint8_t transfer(uint8_t data) = 0;
  virtual void transfer(void *buf, size_t count) = 0;

  virtual void beginTransaction(SPISettings settings) = 0;
  virtual void endTransaction(void) = 0;

  virtual void begin() = 0;
  virtual void end() = 0;
};

class SPIFakeProxy : public SPIClass {
 private:
  SPIFake *spiFake;

 public:
  SPIFakeProxy(SPIFake *fake) { spiFake = fake; }

  SPIFake *getSPIFake() { return spiFake; }
};
