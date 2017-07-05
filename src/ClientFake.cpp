#include "ArduinoFake.h"
#include "ClientFake.h"
#include <stdexcept>

int Client::connect(IPAddress ip, uint16_t port)
{
    return ArduinoFakeInstance(Client, this)->connect(ip, port);
}

int Client::connect(const char *host, uint16_t port)
{
    return ArduinoFakeInstance(Client, this)->connect(host, port);
}

size_t Client::write(uint8_t value)
{
    return ArduinoFakeInstance(Client, this)->write(value);
}

size_t Client::write(const uint8_t *buf, size_t size)
{
    return ArduinoFakeInstance(Client, this)->write(buf, size);
}

int Client::available()
{
    return ArduinoFakeInstance(Client, this)->available();
}

int Client::read()
{
    return ArduinoFakeInstance(Client, this)->read();
}

int Client::read(uint8_t *buf, size_t size)
{
    return ArduinoFakeInstance(Client, this)->read(buf, size);
}

int Client::peek()
{
    return ArduinoFakeInstance(Client, this)->peek();
}

void Client::flush()
{
    return ArduinoFakeInstance(Client, this)->flush();
}

void Client::stop()
{
    return ArduinoFakeInstance(Client, this)->stop();
}

uint8_t Client::connected()
{
    return ArduinoFakeInstance(Client, this)->connected();
}

Client::operator bool()
{
    return 1 == 1;
}

ClientFakeProxy::operator bool()
{
    return 1 == 1;
}
