#pragma once

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <map>
#include <cstring>
#include <cstdint>
#include <stdexcept>
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
        ArduinoFakeInstances* Instances = new ArduinoFakeInstances();
        ArduinoFakeMocks* Mocks = new ArduinoFakeMocks();
        std::map<void*, void*> Mapping;

        ArduinoFakeSingleInstanceGetter(Print)
        ArduinoFakeSingleInstanceGetter(Stream)
        ArduinoFakeSingleInstanceGetter(Serial)
        ArduinoFakeSingleInstanceGetter(Client)
        ArduinoFakeSingleInstanceGetter(Function)

        ArduinoFakeContext()
        {
            Mapping[&::Serial] = this->Serial();
        }

        PrintFake* Print(class Print* p)
        {
            if (!Mapping[p]) {
                throw std::runtime_error("Unknown Print instance");
            }

            return (PrintFake*) Mapping[p];
        }

        StreamFake* Stream(class Stream* s)
        {
            if (!Mapping[s]) {
                throw std::runtime_error("Unknown Stream instance");
            }

            return (StreamFake*) Mapping[s];
        }

        SerialFake* Serial(class Serial_* s)
        {
            if (!Mapping[s]) {
                throw std::runtime_error("Unknown Serial instance");
            }

            return (SerialFake*) Mapping[s];
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
