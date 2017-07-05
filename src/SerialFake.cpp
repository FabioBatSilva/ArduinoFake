#include "ArduinoFake.h"
#include "SerialFake.h"

#if defined(USBCON)

void Serial_::begin(unsigned long baud_count)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, byte config)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count, config);
}

void Serial_::end(void)
{
    ArduinoFakeInstance(Serial, this)->end();
}

int Serial_::available(void)
{
    return ArduinoFakeInstance(Serial, this)->available();
}

int Serial_::peek(void)
{
    return ArduinoFakeInstance(Serial, this)->peek();
}

int Serial_::read(void)
{
    return ArduinoFakeInstance(Serial, this)->read();
}

int Serial_::availableForWrite(void)
{
    return ArduinoFakeInstance(Serial, this)->availableForWrite();
}

void Serial_::flush(void)
{
    ArduinoFakeInstance(Serial, this)->flush();
}

size_t Serial_::write(uint8_t c)
{
    return ArduinoFakeInstance(Serial, this)->write(c);
}

size_t Serial_::write(const uint8_t *buffer, size_t size)
{
    return ArduinoFakeInstance(Serial, this)->write(buffer, size);
}

uint32_t Serial_::baud()
{
    return ArduinoFakeInstance(Serial, this)->baud();
}

uint8_t Serial_::stopbits()
{
    return ArduinoFakeInstance(Serial, this)->stopbits();
}

uint8_t Serial_::paritytype()
{
    return ArduinoFakeInstance(Serial, this)->paritytype();
}

uint8_t Serial_::numbits()
{
    return ArduinoFakeInstance(Serial, this)->numbits();
}

bool Serial_::dtr()
{
    return ArduinoFakeInstance(Serial, this)->dtr();
}

bool Serial_::rts()
{
    return ArduinoFakeInstance(Serial, this)->rts();
}

int32_t Serial_::readBreak()
{
    return ArduinoFakeInstance(Serial, this)->readBreak();
}

Serial_ Serial = SerialFakeProxy(ArduinoFakeInstance(Serial));

#endif // USBCON