#include "ArduinoFake.h"
#include "ClientFake.h"

ClientFake* getClientFakeProxy(Client* client)
{
    if (ClientFakeProxy* p = dynamic_cast<ClientFakeProxy*>(client)) {
        return p->clientFake;
    }

    return ArduinoFakeInstance(Client, client);
}

int Client::connect(IPAddress ip, uint16_t port)
{
    return getClientFakeProxy(this)->connect(ip, port);
}

int Client::connect(const char *host, uint16_t port)
{
    return getClientFakeProxy(this)->connect(host, port);
}

size_t Client::write(uint8_t value)
{
    return getClientFakeProxy(this)->write(value);
}

size_t Client::write(const uint8_t *buf, size_t size)
{
    return getClientFakeProxy(this)->write(buf, size);
}

int Client::available()
{
    return getClientFakeProxy(this)->available();
}

int Client::read()
{
    return getClientFakeProxy(this)->read();
}

int Client::read(uint8_t *buf, size_t size)
{
    return getClientFakeProxy(this)->read(buf, size);
}

int Client::peek()
{
    return getClientFakeProxy(this)->peek();
}

void Client::flush()
{
    return getClientFakeProxy(this)->flush();
}

void Client::stop()
{
    return getClientFakeProxy(this)->stop();
}

uint8_t Client::connected()
{
    return getClientFakeProxy(this)->connected();
}

Client::operator bool()
{
    return 1 == 1;
}

ClientFakeProxy::operator bool()
{
    return 1 == 1;
}
