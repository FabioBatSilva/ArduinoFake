#include "ArduinoFake.h"

ArduinoFakeContext* arduinoFakeContext;

ArduinoFakeContext* getArduinoFakeContext()
{
    if (!arduinoFakeContext) {
        arduinoFakeContext = new ArduinoFakeContext();
    }

    return arduinoFakeContext;
}
