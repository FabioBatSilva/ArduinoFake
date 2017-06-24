#include "ArduinoFake.h"
#include "SerialFake.h"

#if defined(USBCON)

SerialFake* getSerialFake(Serial_* serial)
{
    if (SerialFakeProxy* p = dynamic_cast<SerialFakeProxy*>(serial)) {
        return p->serialFake;
    }

    return ArduinoFakeInstance(Serial);
}

void Serial_::begin(unsigned long baud_count)
{
    getSerialFake(this)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, byte config)
{
    getSerialFake(this)->begin(baud_count, config);
}

void Serial_::end(void)
{
    getSerialFake(this)->end();
}

int Serial_::available(void)
{
    return getSerialFake(this)->available();
}

int Serial_::peek(void)
{
    return getSerialFake(this)->peek();
}

int Serial_::read(void)
{
    return getSerialFake(this)->read();
}

int Serial_::availableForWrite(void)
{
    return getSerialFake(this)->availableForWrite();
}

void Serial_::flush(void)
{
    getSerialFake(this)->flush();
}

size_t Serial_::write(uint8_t c)
{
    return getSerialFake(this)->write(c);
}

size_t Serial_::write(const uint8_t *buffer, size_t size)
{
    return getSerialFake(this)->write(buffer, size);
}

uint32_t Serial_::baud()
{
    return getSerialFake(this)->baud();
}

uint8_t Serial_::stopbits()
{
    return getSerialFake(this)->stopbits();
}

uint8_t Serial_::paritytype()
{
    return getSerialFake(this)->paritytype();
}

uint8_t Serial_::numbits()
{
    return getSerialFake(this)->numbits();
}

bool Serial_::dtr()
{
    return getSerialFake(this)->dtr();
}

bool Serial_::rts()
{
    return getSerialFake(this)->rts();
}

int32_t Serial_::readBreak()
{
    return getSerialFake(this)->readBreak();
}

Serial_ Serial = SerialFakeProxy(ArduinoFakeInstance(Serial));

#endif // USBCON