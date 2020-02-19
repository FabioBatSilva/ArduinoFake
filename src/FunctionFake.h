#pragma once

#include "fakeit/fakeit.hpp"

struct FunctionFake
{
    virtual void init(void) = 0;
    virtual void loop(void) = 0;
    virtual void setup(void) = 0;

    virtual void pinMode(uint8_t, uint8_t) = 0;
    virtual void digitalWrite(uint8_t, uint8_t) = 0;
    virtual int digitalRead(uint8_t) = 0;

    virtual int analogRead(uint8_t) = 0;
    virtual void analogReference(uint8_t) = 0;
    virtual void analogWrite(uint8_t, int) = 0;

    virtual unsigned long millis(void) = 0;
    virtual unsigned long micros(void) = 0;

    virtual void delay(unsigned long) = 0;
    virtual void delayMicroseconds(unsigned int) = 0;

    virtual unsigned long pulseIn(uint8_t, uint8_t, unsigned long) = 0;
    virtual unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout) = 0;

    virtual void shiftOut(uint8_t, uint8_t, uint8_t, uint8_t) = 0;
    virtual uint8_t shiftIn(uint8_t, uint8_t, uint8_t) = 0;

    virtual void detachInterrupt(uint8_t) = 0;
    virtual void attachInterrupt(uint8_t, void (*)(void), int mode) = 0;
    virtual void cli() = 0;
    virtual void sei() = 0;

    virtual void tone(uint8_t _pin, unsigned int frequency, unsigned long duration) = 0;
    virtual void noTone(uint8_t _pin) = 0;

    virtual long random(long) = 0;
    virtual long random(long, long) = 0;
    virtual void randomSeed(unsigned long) = 0;

    virtual long map(long, long, long, long, long) = 0;

    virtual void yield() = 0;
};
