#pragma once

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <map>
#include <cstring>
#include <cstdint>
#include <stdexcept>
#include "fakeit/fakeit.hpp"

#include "arduino/Arduino.h"

#include "FunctionFake.h"
#include "StreamFake.h"
#include "SerialFake.h"
#include "ClientFake.h"
#include "PrintFake.h"

#define ArduinoFake(mock) _ArduinoFakeGet##mock()

#define ArduinoFakeReset() \
    getArduinoFakeContext()->reset()

#define ArduinoFakeInstance(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeMock(mock) \
    new mock##FakeProxy(ArduinoFakeInstance(mock))

#define _ArduinoFakeGetMock(mock) \
    getArduinoFakeContext()->Mocks->mock

#define _ArduinoFakeGetFunction() _ArduinoFakeGetMock(Function)
#define _ArduinoFakeGetSerial() _ArduinoFakeGetMock(Serial)
#define _ArduinoFakeGetStream() _ArduinoFakeGetMock(Stream)
#define _ArduinoFakeGetClient() _ArduinoFakeGetMock(Client)
#define _ArduinoFakeGetPrint() _ArduinoFakeGetMock(Print)
#define _ArduinoFakeGet() _ArduinoFakeGetMock(Function)

#define _ArduinoFakeInstanceGetter1(mock) \
    mock##Fake* mock() \
    { \
        if (!this->Instances->mock){ \
            this->Instances->mock = &this->Mocks->mock.get(); \
        } \
        return this->Instances->mock; \
    }

#define _ArduinoFakeInstanceGetter2(name, clazz) \
    name##Fake* name(class clazz* instance) \
    { \
        if (Mapping[instance]) { \
            return (name##Fake*) Mapping[instance]; \
        } \
        if (dynamic_cast<name##FakeProxy*>(instance)) { \
            return dynamic_cast<name##FakeProxy*>(instance)->get##name##Fake(); \
        } \
        throw std::runtime_error("Unknown instance"); \
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
        ArduinoFakeInstances* Instances = new ArduinoFakeInstances();
        ArduinoFakeMocks* Mocks = new ArduinoFakeMocks();
        std::map<void*, void*> Mapping;

        _ArduinoFakeInstanceGetter1(Print)
        _ArduinoFakeInstanceGetter1(Stream)
        _ArduinoFakeInstanceGetter1(Serial)
        _ArduinoFakeInstanceGetter1(Client)
        _ArduinoFakeInstanceGetter1(Function)

        _ArduinoFakeInstanceGetter2(Print, Print)
        _ArduinoFakeInstanceGetter2(Client, Client)
        _ArduinoFakeInstanceGetter2(Stream, Stream)
        _ArduinoFakeInstanceGetter2(Serial, Serial_)

        ArduinoFakeContext()
        {
            this->reset();
        }

        void reset(void)
        {
            this->Instances = new ArduinoFakeInstances();

            this->Mocks->Function.Reset();
            this->Mocks->Stream.Reset();
            this->Mocks->Serial.Reset();
            this->Mocks->Client.Reset();
            this->Mocks->Print.Reset();

            Mapping[&::Serial] = this->Serial();
        }
};

ArduinoFakeContext* getArduinoFakeContext();
