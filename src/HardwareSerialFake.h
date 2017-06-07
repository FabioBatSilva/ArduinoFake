#ifndef HARDWARE_SERIAL_FAKE_H
#define HARDWARE_SERIAL_FAKE_H

#include "ArduinoFake.h"
#include "StreamFake.h"
#include "arduino/HardwareSerial.h"

struct HardwareSerialFake : public StreamFake
{
    virtual void begin(unsigned long, uint8_t) = 0;
    virtual void end() = 0;
    virtual int available(void) = 0;
    virtual int peek(void) = 0;
    virtual int read(void) = 0;
    virtual int availableForWrite(void) = 0;
    virtual void flush(void) = 0;
    virtual size_t write(uint8_t) = 0;
};

#endif // HARDWARE_SERIAL_FAKE_H