#pragma once

#include "ArduinoFake.h"
#include "StreamFake.h"
#include "arduino/Client.h"

struct ClientFake : public StreamFake
{
    virtual int connect(IPAddress ip, uint16_t port) = 0;

    virtual int connect(const char *host, uint16_t port) = 0;

    virtual size_t write(uint8_t) = 0;

    virtual size_t write(const uint8_t *buf, size_t size) = 0;

    virtual int available() = 0;

    virtual int read() = 0;

    virtual int read(uint8_t *buf, size_t size) = 0;

    virtual int peek() = 0;

    virtual void flush() = 0;

    virtual void stop() = 0;

    virtual uint8_t connected() = 0;
};

class ClientFakeProxy : public StreamFakeProxy, public Client
{
    private:
        ClientFake* clientFake;

    public:
        ClientFakeProxy(ClientFake* fake) : StreamFakeProxy(fake)
        {
            clientFake = fake;
        }

        int connect(IPAddress ip, uint16_t port)
        {
            return clientFake->connect(ip, port);
        }

        int connect(const char *host, uint16_t port)
        {
            return clientFake->connect(host, port);
        }

        size_t write(uint8_t value)
        {
            return clientFake->write(value);
        }

        size_t write(const uint8_t *buf, size_t size)
        {
            return clientFake->write(buf, size);
        }

        int available()
        {
            return clientFake->available();
        }

        int read()
        {
            return clientFake->read();
        }

        int read(uint8_t *buf, size_t size)
        {
            return clientFake->read(buf, size);
        }

        int peek()
        {
            return clientFake->peek();
        }

        void flush()
        {
            clientFake->flush();
        }

        void stop()
        {
            clientFake->stop();
        }

        uint8_t connected()
        {
            return clientFake->connected();
        }

        virtual operator bool();

        ClientFake* getClientFake()
        {
            return clientFake;
        }
};
