#pragma once

#include "ArduinoFake.h"
#include "arduino/Print.h"

struct PrintFake
{
    virtual size_t write(const uint8_t *buffer, size_t size) = 0;
    virtual size_t write(uint8_t) = 0;

    virtual size_t print(const __FlashStringHelper *) = 0;
    virtual size_t print(const String &) = 0;
    virtual size_t print(const char[]) = 0;
    virtual size_t print(char) = 0;
    virtual size_t print(unsigned char, int = DEC) = 0;
    virtual size_t print(int, int = DEC) = 0;
    virtual size_t print(unsigned int, int = DEC) = 0;
    virtual size_t print(long, int = DEC) = 0;
    virtual size_t print(unsigned long, int = DEC) = 0;
    virtual size_t print(double, int = 2) = 0;
    virtual size_t print(const Printable&) = 0;

    virtual size_t println(const __FlashStringHelper *) = 0;
    virtual size_t println(const String &s) = 0;
    virtual size_t println(const char[]) = 0;
    virtual size_t println(char) = 0;
    virtual size_t println(unsigned char, int = DEC) = 0;
    virtual size_t println(int, int = DEC) = 0;
    virtual size_t println(unsigned int, int = DEC) = 0;
    virtual size_t println(long, int = DEC) = 0;
    virtual size_t println(unsigned long, int = DEC) = 0;
    virtual size_t println(double, int = 2) = 0;
    virtual size_t println(const Printable&) = 0;
    virtual size_t println(void) = 0;
};

class PrintFakeProxy : public Print
{
    private:
        PrintFake* printFake;

    public:
        PrintFakeProxy(PrintFake* fake)
        {
            printFake = fake;
        }

        size_t write(const uint8_t *buffer, size_t size)
        {
            return printFake->write(buffer, size);
        }

        size_t write(uint8_t value)
        {
            return printFake->write(value);
        }

        PrintFake* getPrintFake()
        {
            return printFake;
        }
};
