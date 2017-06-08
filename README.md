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
// src/main.cpp
void loop()
{
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);
    // wait for a second
    delay(100);
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
     // wait for a second
    delay(100);
}
```

It can be tested using `ArduinoFake`:
```c++
#include <ArduinoFake.h>

using namespace fakeit;

// test/test_main.cpp
void test_loop(void)
{
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    loop();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_BUILTIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_BUILTIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(100)).Exactly(2_Times);
}
```

Checkout the [examples](./examples) for many more examples!
Or take a look at the [tests](./test)