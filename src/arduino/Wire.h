#ifndef TwoWire_h
#define TwoWire_h

#include "Stream.h"
#include <inttypes.h>

class TwoWire : public Stream {
public:
  void begin();
  void begin(uint8_t);
  void begin(int);
  void end();
  void setClock(uint32_t);
  void setWireTimeout(uint32_t timeout = 25000,
                      bool reset_with_timeout = false);
  bool getWireTimeoutFlag(void);
  void clearWireTimeoutFlag(void);
  void beginTransmission(uint8_t);
  void beginTransmission(int);
  uint8_t endTransmission(void);
  uint8_t endTransmission(bool);
  uint8_t requestFrom(uint8_t, uint8_t);
  uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
  uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *, size_t);
  virtual int available(void);
  virtual int read(void);
  virtual int peek(void);
  virtual void flush(void);
  void onReceive(void (*)(int));
  void onRequest(void (*)(void));

  inline size_t write(unsigned long n) { return write((uint8_t)n); }
  inline size_t write(long n) { return write((uint8_t)n); }
  inline size_t write(unsigned int n) { return write((uint8_t)n); }
  inline size_t write(int n) { return write((uint8_t)n); }
  using Print::write;
};

extern TwoWire Wire;

#endif
