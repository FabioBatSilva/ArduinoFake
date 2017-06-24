#include "ArduinoFake.h"
#include "PrintFake.h"

PrintFake* getPrintFakeProxy(Print* print)
{
    if (PrintFakeProxy* p = dynamic_cast<PrintFakeProxy*>(print)) {
        return p->printFake;
    }

    return ArduinoFakeInstance(Print, print);
}

size_t Print::write(const uint8_t *buffer, size_t size)
{
    return getPrintFakeProxy(this)->write(buffer, size);
}

size_t Print::print(const __FlashStringHelper *ifsh)
{
    return getPrintFakeProxy(this)->print(ifsh);
}

size_t Print::print(const String &s)
{
    return getPrintFakeProxy(this)->print(s);
}

size_t Print::print(const char str[])
{
    return getPrintFakeProxy(this)->print(str);
}

size_t Print::write(uint8_t u)
{
    return getPrintFakeProxy(this)->write(u);
}

size_t Print::print(char c)
{
    return getPrintFakeProxy(this)->print(c);
}

size_t Print::print(unsigned char b, int base)
{
    return getPrintFakeProxy(this)->print(b, base);
}

size_t Print::print(int n, int base)
{
    return getPrintFakeProxy(this)->print(n, base);
}

size_t Print::print(unsigned int n, int base)
{
    return getPrintFakeProxy(this)->print(n, base);
}

size_t Print::print(long n, int base)
{
    return getPrintFakeProxy(this)->print(n, base);
}

size_t Print::print(unsigned long n, int base)
{
    return getPrintFakeProxy(this)->print(n, base);
}

size_t Print::print(double n, int digits)
{
    return getPrintFakeProxy(this)->print(n, digits);
}

size_t Print::print(const Printable& x)
{
    return getPrintFakeProxy(this)->print(x);
}

size_t Print::println(const __FlashStringHelper *ifsh)
{
    return getPrintFakeProxy(this)->println(ifsh);
}

size_t Print::println(void)
{
    return getPrintFakeProxy(this)->println();
}

size_t Print::println(const String &s)
{
    return getPrintFakeProxy(this)->println(s);
}

size_t Print::println(const char c[])
{
    return getPrintFakeProxy(this)->println(c);
}

size_t Print::println(char c)
{
    return getPrintFakeProxy(this)->println(c);
}

size_t Print::println(unsigned char b, int base)
{
    return getPrintFakeProxy(this)->println(b, base);
}

size_t Print::println(int num, int base)
{
    return getPrintFakeProxy(this)->println(num, base);
}

size_t Print::println(unsigned int num, int base)
{
    return getPrintFakeProxy(this)->println(num, base);
}

size_t Print::println(long num, int base)
{
    return getPrintFakeProxy(this)->println(num, base);
}

size_t Print::println(unsigned long num, int base)
{
    return getPrintFakeProxy(this)->println(num, base);
}

size_t Print::println(double num, int digits)
{
    return getPrintFakeProxy(this)->println(num, digits);
}

size_t Print::println(const Printable& x)
{
    return getPrintFakeProxy(this)->println(x);
}
