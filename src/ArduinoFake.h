#ifndef ARDUINO_FAKE_H
#define ARDUINO_FAKE_H

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <HardwareSerialFake.h>
#include <FunctionFake.h>
#include <StreamFake.h>
#include <SerialFake.h>
#include <PrintFake.h>

#define ArduinoFakeGetHardwareSerial() ArduinoFakeGetter(HardwareSerial)
#define ArduinoFakeGetFunction() ArduinoFakeGetter(Function)
#define ArduinoFakeGetSerial() ArduinoFakeGetter(Serial)
#define ArduinoFakeGetStream() ArduinoFakeGetter(Stream)
#define ArduinoFakeGetPrint() ArduinoFakeGetter(Print)
#define ArduinoFakeGet() ArduinoFakeGetter(Function)

#define ArduinoFake(mock) ArduinoFakeGet##mock()

#define ArduinoFakeGetter(mock) \
    getArduinoFakeContext()->Mocks->mock

#define ArduinoFakeReset() \
    getArduinoFakeContext()->reset()

#define ArduinoFakeInstance(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeReturnInstaceOf(var, mock) \
    if (std::strstr(typeid(*var).name(), #mock)) { \
        return this->mock(); \
    }

#define ArduinoFakeSingleInstanceGetter(mock) \
    mock##Fake* mock() \
    { \
        if (!this->Instances->mock){ \
            this->Instances->mock = &this->Mocks->mock.get(); \
        } \
        return this->Instances->mock; \
    }

struct ArduinoFakeMocks
{
    fakeit::Mock<HardwareSerialFake> HardwareSerial;
    fakeit::Mock<FunctionFake> Function;
    fakeit::Mock<SerialFake> Serial;
    fakeit::Mock<StreamFake> Stream;
    fakeit::Mock<PrintFake> Print;
};

struct ArduinoFakeInstances
{
    HardwareSerialFake* HardwareSerial;
    FunctionFake* Function;
    SerialFake* Serial;
    StreamFake* Stream;
    PrintFake* Print;
};

class ArduinoFakeContext
{
    public:
        ArduinoFakeMocks* Mocks = new ArduinoFakeMocks();
        ArduinoFakeInstances* Instances = new ArduinoFakeInstances();

        ArduinoFakeSingleInstanceGetter(Print)
        ArduinoFakeSingleInstanceGetter(Stream)
        ArduinoFakeSingleInstanceGetter(Serial)
        ArduinoFakeSingleInstanceGetter(Function)
        ArduinoFakeSingleInstanceGetter(HardwareSerial)

        PrintFake* Print(class Print* p)
        {
            ArduinoFakeReturnInstaceOf(p, HardwareSerial)
            ArduinoFakeReturnInstaceOf(p, Serial)
            ArduinoFakeReturnInstaceOf(p, Stream)

            return this->Print();
        }

        StreamFake* Stream(class Stream* s)
        {
            ArduinoFakeReturnInstaceOf(s, HardwareSerial)
            ArduinoFakeReturnInstaceOf(s, Serial)

            return this->Stream();
        }

        void reset(void)
        {
            this->Instances = new ArduinoFakeInstances();

            this->Mocks->HardwareSerial.Reset();
            this->Mocks->Function.Reset();
            this->Mocks->Stream.Reset();
            this->Mocks->Serial.Reset();
            this->Mocks->Print.Reset();
        }
};

ArduinoFakeContext* getArduinoFakeContext();

#endif // ARDUINO_FAKE_H
