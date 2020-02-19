#include "FunctionFake.h"
#include "ArduinoFake.h"

void pinMode(uint8_t pin, uint8_t mode)
{
    ArduinoFakeInstance(Function)->pinMode(pin, mode);
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    ArduinoFakeInstance(Function)->digitalWrite(pin, val);
}

int digitalRead(uint8_t pin)
{
    return ArduinoFakeInstance(Function)->digitalRead(pin);
}

int analogRead(uint8_t pin)
{
    return ArduinoFakeInstance(Function)->analogRead(pin);
}

void analogWrite(uint8_t pin, int val)
{
    ArduinoFakeInstance(Function)->analogWrite(pin, val);
}

void analogReference(uint8_t mode)
{
    ArduinoFakeInstance(Function)->analogReference(mode);
}

unsigned long millis(void)
{
    return ArduinoFakeInstance(Function)->millis();
}

unsigned long micros(void)
{
    return ArduinoFakeInstance(Function)->micros();
}

void delay(unsigned long value)
{
    ArduinoFakeInstance(Function)->delay(value);
}

void delayMicroseconds(unsigned int us)
{
    ArduinoFakeInstance(Function)->delayMicroseconds(us);
}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance(Function)->pulseIn(pin, state, timeout);
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance(Function)->pulseInLong(pin, state, timeout);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    ArduinoFakeInstance(Function)->shiftOut(dataPin, clockPin, bitOrder, val);
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    return ArduinoFakeInstance(Function)->shiftIn(dataPin, clockPin, bitOrder);
}

void detachInterrupt(uint8_t interruptNum) {
    ArduinoFakeInstance(Function)->detachInterrupt(interruptNum);
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
	ArduinoFakeInstance(Function)->attachInterrupt(interruptNum, userFunc, mode);
}

void cli(void) {
    ArduinoFakeInstance(Function)->cli();
}

void sei(void) {
    ArduinoFakeInstance(Function)->sei();
}

void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
    ArduinoFakeInstance(Function)->tone(pin, frequency, duration);
}

void noTone(uint8_t pin)
{
    ArduinoFakeInstance(Function)->noTone(pin);
}

long random(long max)
{
    return ArduinoFakeInstance(Function)->random(max);
}

long random(long min, long max)
{
    return ArduinoFakeInstance(Function)->random(min, max);
}

void randomSeed(unsigned long seed)
{
    return ArduinoFakeInstance(Function)->randomSeed(seed);
}

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
    return ArduinoFakeInstance(Function)->map(value, fromLow, fromHigh, toLow, toHigh);
}

void yield()
{
    ArduinoFakeInstance(Function)->yield();
}
