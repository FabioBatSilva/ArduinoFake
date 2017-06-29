#pragma once

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <cstring>
#include <stdint.h>
#include "fakeit/fakeit.hpp"

#include "FunctionFake.h"
#include "StreamFake.h"
#include "SerialFake.h"
#include "ClientFake.h"
#include "PrintFake.h"

#include "arduino/Arduino.h"

#define ArduinoFakeGetFunction() ArduinoFakeGetter(Function)
#define ArduinoFakeGetSerial() ArduinoFakeGetter(Serial)
#define ArduinoFakeGetStream() ArduinoFakeGetter(Stream)
#define ArduinoFakeGetClient() ArduinoFakeGetter(Client)
#define ArduinoFakeGetPrint() ArduinoFakeGetter(Print)
#define ArduinoFakeGet() ArduinoFakeGetter(Function)

#define ArduinoFake(mock) ArduinoFakeGet##mock()

#define ArduinoFakeGetter(mock) \
    getArduinoFakeContext()->Mocks->mock

#define ArduinoFakeReset() \
    getArduinoFakeContext()->reset()

#define ArduinoFakeInstance(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeInstanceFake(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeMock(mock, ...) \
    new mock##FakeProxy(ArduinoFakeInstance(mock, __VA_ARGS__))

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
    fakeit::Mock<FunctionFake> Function;
    fakeit::Mock<SerialFake> Serial;
    fakeit::Mock<StreamFake> Stream;
    fakeit::Mock<ClientFake> Client;
    fakeit::Mock<PrintFake> Print;
};

struct ArduinoFakeInstances
{
    FunctionFake* Function;
    SerialFake* Serial;
    StreamFake* Stream;
    ClientFake* Client;
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
        ArduinoFakeSingleInstanceGetter(Client)
        ArduinoFakeSingleInstanceGetter(Function)

        PrintFake* Print(class Print* p)
        {
            ArduinoFakeReturnInstaceOf(p, Serial)
            ArduinoFakeReturnInstaceOf(p, Stream)

            return this->Print();
        }

        StreamFake* Stream(class Stream* s)
        {
            ArduinoFakeReturnInstaceOf(s, Serial)

            return this->Stream();
        }

        ClientFake* Client(class Client* c)
        {
            return this->Client();
        }

        void reset(void)
        {
            this->Instances = new ArduinoFakeInstances();

            this->Mocks->Function.Reset();
            this->Mocks->Stream.Reset();
            this->Mocks->Serial.Reset();
            this->Mocks->Client.Reset();
            this->Mocks->Print.Reset();
        }
};

ArduinoFakeContext* getArduinoFakeContext();
