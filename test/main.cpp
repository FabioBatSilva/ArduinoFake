#include <ArduinoFake.h>
#include <cstdlib>
#include <unity.h>

using namespace fakeit;

#include "test_context.h"
#include "test_function.h"
#include "test_print.h"
#include "test_stream.h"
#include "test_serial.h"
#include "test_hardware_serial.h"

#ifdef UNIT_TEST

#define RUN_TEST_GROUP(TEST) \
    if (!std::getenv("TEST_GROUP") || (strcmp(#TEST, std::getenv("TEST_GROUP")) == 0)) { \
        TEST::run_tests(); \
    }

void setUp(void)
{
    ArduinoFakeReset();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST_GROUP(ArduinoContextTest);
    RUN_TEST_GROUP(FunctionTest);
    RUN_TEST_GROUP(PrintTest);
    RUN_TEST_GROUP(StreamTest);
    RUN_TEST_GROUP(SerialTest);
    RUN_TEST_GROUP(HardwareSerialTest);

    UNITY_END();

    return 0;
}

#endif
