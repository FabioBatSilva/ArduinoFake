#include "ArduinoFake.h"
#include "HardwareSerialFake.h"

void HardwareSerial::begin(unsigned long baud, byte config)
{
    return ArduinoFakeInstance(HardwareSerial)->begin(baud, config);
}

void HardwareSerial::end()
{
    return ArduinoFakeInstance(HardwareSerial)->end();
}

int HardwareSerial::available(void)
{
    return ArduinoFakeInstance(HardwareSerial)->available();
}

int HardwareSerial::peek(void)
{
    return ArduinoFakeInstance(HardwareSerial)->peek();
}

int HardwareSerial::read(void)
{
    return ArduinoFakeInstance(HardwareSerial)->read();
}

int HardwareSerial::availableForWrite(void)
{
    return ArduinoFakeInstance(HardwareSerial)->availableForWrite();
}

void HardwareSerial::flush()
{
    ArduinoFakeInstance(HardwareSerial)->flush();
}

size_t HardwareSerial::write(uint8_t c)
{
    return ArduinoFakeInstance(HardwareSerial)->write(c);
}
