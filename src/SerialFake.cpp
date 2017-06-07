#include "ArduinoFake.h"
#include "SerialFake.h"

#if defined(USBCON)

void Serial_::begin(unsigned long baud_count)
{
    ArduinoFakeInstance(Serial)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, byte config)
{
    ArduinoFakeInstance(Serial)->begin(baud_count, config);
}

void Serial_::end(void)
{
    ArduinoFakeInstance(Serial)->end();
}

int Serial_::available(void)
{
    return ArduinoFakeInstance(Serial)->available();
}

int Serial_::peek(void)
{
    return ArduinoFakeInstance(Serial)->peek();
}

int Serial_::read(void)
{
    return ArduinoFakeInstance(Serial)->read();
}

int Serial_::availableForWrite(void)
{
    return ArduinoFakeInstance(Serial)->availableForWrite();
}

void Serial_::flush(void)
{
    ArduinoFakeInstance(Serial)->flush();
}

size_t Serial_::write(uint8_t c)
{
    return ArduinoFakeInstance(Serial)->write(c);
}

size_t Serial_::write(const uint8_t *buffer, size_t size)
{
    return ArduinoFakeInstance(Serial)->write(buffer, size);
}

uint32_t Serial_::baud()
{
    return ArduinoFakeInstance(Serial)->baud();
}

uint8_t Serial_::stopbits()
{
    return ArduinoFakeInstance(Serial)->stopbits();
}

uint8_t Serial_::paritytype()
{
    return ArduinoFakeInstance(Serial)->paritytype();
}

uint8_t Serial_::numbits()
{
    return ArduinoFakeInstance(Serial)->numbits();
}

bool Serial_::dtr()
{
    return ArduinoFakeInstance(Serial)->dtr();
}

bool Serial_::rts()
{
    return ArduinoFakeInstance(Serial)->rts();
}

int32_t Serial_::readBreak()
{
    return ArduinoFakeInstance(Serial)->readBreak();
}

Serial_ Serial;

#endif // USBCON