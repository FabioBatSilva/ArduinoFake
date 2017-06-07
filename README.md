# ArduinoFake

`ArduinoFake` is a simple mocking framework for Arduino.
`ArduinoFake` is based on [FakeIt](https://github.com/eranpeer/FakeIt) and can be used for testing both your arduino project natively.


## Quickstart

### Includes

You should include the following header in your test file:

```c++
#include <ArduinoFake.h>
```

### Stubbing

Assuming we have the following arduino code:

```c++
void setup()
{

}
```