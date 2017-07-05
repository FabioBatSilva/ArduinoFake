#pragma once

#include "ArduinoFake.h"
#include "StreamFake.h"
#include "arduino/USBAPI.h"

struct SerialFake : public StreamFake
{
    virtual void begin(unsigned long) = 0;
    virtual void begin(unsigned long, uint8_t) = 0;
    virtual void end(void) = 0;

    virtual int available(void) = 0;
    virtual int peek(void) = 0;
    virtual int read(void) = 0;
    virtual int availableForWrite(void) = 0;
    virtual void flush(void) = 0;
    virtual size_t write(uint8_t) = 0;
    virtual size_t write(const uint8_t*, size_t) = 0;

    //operator bool();

    virtual int32_t readBreak() = 0;

    virtual uint32_t baud() = 0;
    virtual uint8_t stopbits() = 0;
    virtual uint8_t paritytype() = 0;
    virtual uint8_t numbits() = 0;
    virtual bool dtr() = 0;
    virtual bool rts() = 0;
};

class SerialFakeProxy : public StreamFakeProxy, public Serial_
{
    private:
        SerialFake* serialFake;

    public:
        SerialFakeProxy(SerialFake* fake) : StreamFakeProxy(fake)
        {
            serialFake = fake;
        }

        SerialFake* getSerialFake()
        {
            return serialFake;
        }
};