#include "ArduinoFake.h"
#include "PrintFake.h"

size_t Print::write(const uint8_t *buffer, size_t size)
{
    return ArduinoFakeInstance(Print, this)->write(buffer, size);
}

size_t Print::print(const __FlashStringHelper *ifsh)
{
    return ArduinoFakeInstance(Print, this)->print(ifsh);
}

size_t Print::print(const String &s)
{
    return ArduinoFakeInstance(Print, this)->print(s);
}

size_t Print::print(const char str[])
{
    return ArduinoFakeInstance(Print, this)->print(str);
}

size_t Print::write(uint8_t u)
{
    return ArduinoFakeInstance(Print, this)->write(u);
}

size_t Print::print(char c)
{
    return ArduinoFakeInstance(Print, this)->print(c);
}

size_t Print::print(unsigned char b, int base)
{
    return ArduinoFakeInstance(Print, this)->print(b, base);
}

size_t Print::print(int n, int base)
{
    return ArduinoFakeInstance(Print, this)->print(n, base);
}

size_t Print::print(unsigned int n, int base)
{
    return ArduinoFakeInstance(Print, this)->print(n, base);
}

size_t Print::print(long n, int base)
{
    return ArduinoFakeInstance(Print, this)->print(n, base);
}

size_t Print::print(unsigned long n, int base)
{
    return ArduinoFakeInstance(Print, this)->print(n, base);
}

size_t Print::print(double n, int digits)
{
    return ArduinoFakeInstance(Print, this)->print(n, digits);
}

size_t Print::print(const Printable& x)
{
    return ArduinoFakeInstance(Print, this)->print(x);
}

size_t Print::println(const __FlashStringHelper *ifsh)
{
    return ArduinoFakeInstance(Print, this)->println(ifsh);
}

size_t Print::println(void)
{
    return ArduinoFakeInstance(Print, this)->println();
}

size_t Print::println(const String &s)
{
    return ArduinoFakeInstance(Print, this)->println(s);
}

size_t Print::println(const char c[])
{
    return ArduinoFakeInstance(Print, this)->println(c);
}

size_t Print::println(char c)
{
    return ArduinoFakeInstance(Print, this)->println(c);
}

size_t Print::println(unsigned char b, int base)
{
    return ArduinoFakeInstance(Print, this)->println(b, base);
}

size_t Print::println(int num, int base)
{
    return ArduinoFakeInstance(Print, this)->println(num, base);
}

size_t Print::println(unsigned int num, int base)
{
    return ArduinoFakeInstance(Print, this)->println(num, base);
}

size_t Print::println(long num, int base)
{
    return ArduinoFakeInstance(Print, this)->println(num, base);
}

size_t Print::println(unsigned long num, int base)
{
    return ArduinoFakeInstance(Print, this)->println(num, base);
}

size_t Print::println(double num, int digits)
{
    return ArduinoFakeInstance(Print, this)->println(num, digits);
}

size_t Print::println(const Printable& x)
{
    return ArduinoFakeInstance(Print, this)->println(x);
}
