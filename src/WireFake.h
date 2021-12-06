#pragma once
#include "ArduinoFake.h"
#include "StreamFake.h"
#include "arduino/Wire.h"

struct WireFake : public StreamFake {
  virtual void begin() = 0;
  virtual void begin(uint8_t) = 0;
  virtual void begin(int) = 0;
  virtual void end() = 0;
  virtual void setClock(uint32_t) = 0;
  virtual void setWireTimeout(uint32_t timeout = 25000,
                              bool reset_with_timeout = false) = 0;
  virtual bool getWireTimeoutFlag(void) = 0;
  virtual void clearWireTimeoutFlag(void) = 0;
  virtual void beginTransmission(uint8_t) = 0;
  virtual void beginTransmission(int) = 0;
  virtual uint8_t endTransmission(void) = 0;
  virtual uint8_t endTransmission(bool) = 0;
  virtual uint8_t requestFrom(uint8_t, uint8_t) = 0;
  virtual uint8_t requestFrom(uint8_t, uint8_t, uint8_t) = 0;
  virtual uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t) = 0;
  virtual size_t write(uint8_t) = 0;
  virtual size_t write(const uint8_t *, size_t) = 0;
  virtual int available(void) = 0;
  virtual int read(void) = 0;
  virtual int peek(void) = 0;
  virtual void flush(void) = 0;
  virtual void onReceive(void (*)(int)) = 0;
  virtual void onRequest(void (*)(void)) = 0;
};

class WireFakeProxy : public StreamFakeProxy, public TwoWire {
private:
  WireFake *wireFake;

public:
  WireFakeProxy(WireFake *fake) : StreamFakeProxy(fake) { wireFake = fake; }

  WireFake *getWireFake() { return wireFake; }
};