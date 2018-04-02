# Contribution Guidelines
This is a step-by-step guide for contributors.

## Adding missing function
I was missing `sei()`, `cli()` and `attachInterrupt()` in `ArduinoFake`, here is list of steps I did.


1. add definitions of new functions in [src/arduino/Arduino.h](/src/arduino/Arduino.h), check if your function is in [Arduino.h](/src/arduino/Arduino.h). There are two situations: 
    * `attachInterrupt()` was already in [Arduino.h](/src/arduino/Arduino.h) so we are done. 
    * `sei()` was not defined in [Arduino.h](/src/arduino/Arduino.h) so
       * create a new header file [avr/interrupt.h](/src/arduino/avr/interrupt.h) to cover interrupt related definitions with a content
          ```c++
          /**
           * Fake version of avr/interrupt.h
           */
          void cli(void);
          void sei(void);          
       * add `#include "avr/interrupt.h"` in [Arduino.h](/src/arduino/Arduino.h)
1. Find approriate place for your functions, in my case I extended [src/FunctionFake.h](/src/FunctionFake.h) for new functions
	```c++
	struct FunctionFake
	{
		...
		virtual void attachInterrupt(uint8_t, void (*)(void), int mode) = 0;
		virtual void cli() = 0;
		virtual void sei() = 0;
		...
	}
    ```    
1. add default implementations into corresponding cpp file, in my case [src/FunctionFake.cpp](/src/FunctionFake.cpp).
	```c++
    void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
        ArduinoFakeInstance(Function)->attachInterrupt(interruptNum, userFunc, mode);
    }

    void cli(void) {
        ArduinoFakeInstance(Function)->cli();
    }

    void sei(void) {
        ArduinoFakeInstance(Function)->sei();
    }
	```
1. **don't forget to add TESTs** for new functionality, at least test if a function can be executed, in my case [test/test_function.h](/test/test_function.h)
	```c++
    void test_attach(void)
    {
        When(Method(ArduinoFake(), attachInterrupt)).AlwaysReturn();

        attachInterrupt(1, (void (*)(void))NULL, FALLING);
        attachInterrupt(2, (void (*)(void))NULL, CHANGE);
        attachInterrupt(3, (void (*)(void))NULL, RISING);

        Verify(Method(ArduinoFake(), attachInterrupt)).Exactly(3);
    }

    void test_cli(void)
    {
        When(Method(ArduinoFake(), cli)).AlwaysReturn();

        cli();

        Verify(Method(ArduinoFake(), cli)).Once();
    }

    void test_sei(void)
    {
        When(Method(ArduinoFake(), sei)).AlwaysReturn();

        sei();

        Verify(Method(ArduinoFake(), sei)).Once();
    }
    ```
    and add tests to test list
    ```c
    void run_tests(void)
    {
		...
		RUN_TEST(FunctionTest::test_attach);
		RUN_TEST(FunctionTest::test_cli);        
		RUN_TEST(FunctionTest::test_sei);
		...
    }
1. excersice tests from command line, there are two ways based on your Makefile
   * default project [Makefile](/Makefile), 
     * execute `make`  
     * verify
   ```
	Running tests...
	Test project /home/vlcvi01/Dropbox/git/ArduinoFake/build
	    Start 1: main
	1/1 Test #1: main .............................   Passed    0.01 sec

	100% tests passed, 0 tests failed out of 1
   ```
   * [eclipse based Makefile](https://www.mantidproject.org/Setting_up_Eclipse_projects_with_CMake) generated via `cmake -G "Eclipse CDT4 - Unix Makefiles"`.
     * execute `make clean all && test/main`
     * verify PASS of all tests	
   ```
    ...
    .../ArduinoFake/test/main.cpp:184:FunctionTest::test_attach:PASS
    .../ArduinoFake/test/main.cpp:185:FunctionTest::test_sei:PASS
    .../ArduinoFake/test/main.cpp:186:FunctionTest::test_cli:PASS
    ...
    
    -----------------------
    39 Tests 0 Failures 0 Ignored 
    OK
   ```
