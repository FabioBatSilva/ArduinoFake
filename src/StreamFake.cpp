#include "ArduinoFake.h"
#include "StreamFake.h"

StreamFake* getStreamFake(Stream* stream)
{
    if (StreamFakeProxy* p = dynamic_cast<StreamFakeProxy*>(stream)) {
        return p->streamFake;
    }

    return ArduinoFakeInstance(Stream, stream);
}

void Stream::setTimeout(unsigned long timeout)
{
    getStreamFake(this)->setTimeout(timeout);
}

bool Stream::find(char *target)
{
    return getStreamFake(this)->find(target);
}

bool Stream::find(char *target, size_t length)
{
    return getStreamFake(this)->find(target, length);
}

bool Stream::findUntil(char *target, char *terminator)
{
    return getStreamFake(this)->findUntil(target, terminator);
}

bool Stream::findUntil(char *target, size_t targetLen, char *terminator, size_t termLen)
{
    return getStreamFake(this)->findUntil(target, targetLen, terminator, termLen);
}

long Stream::parseInt(LookaheadMode lookahead, char ignore)
{
    return getStreamFake(this)->parseInt(lookahead, ignore);
}

float Stream::parseFloat(LookaheadMode lookahead, char ignore)
{
    return getStreamFake(this)->parseFloat(lookahead, ignore);
}

size_t Stream::readBytes(char *buffer, size_t length)
{
    return getStreamFake(this)->readBytes(buffer, length);
}

size_t Stream::readBytesUntil(char terminator, char *buffer, size_t length)
{
    return getStreamFake(this)->readBytesUntil(terminator, buffer, length);
}

String Stream::readString()
{
    return getStreamFake(this)->readString();
}

String Stream::readStringUntil(char terminator)
{
    return getStreamFake(this)->readStringUntil(terminator);
}
