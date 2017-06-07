#ifdef UNIT_TEST

namespace HardwareSerialTest
{
    void test_extends_stream(void)
    {
        TEST_ASSERT_NOT_EQUAL(
            ArduinoFakeInstance(Stream),
            ArduinoFakeInstance(HardwareSerial)
        );

        char print_char_var = 'A';
        char stream_char_var = 'B';

        int print_int_var = 123;
        int stream_int_var = 321;

        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int))).AlwaysReturn();

        When(OverloadedMethod(ArduinoFake(HardwareSerial), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(HardwareSerial), print, size_t(int, int))).AlwaysReturn();

        ArduinoFakeInstance(Stream)->print(stream_char_var);
        ArduinoFakeInstance(Stream)->print(stream_int_var, DEC);

        ArduinoFakeInstance(HardwareSerial)->print(print_char_var);
        ArduinoFakeInstance(HardwareSerial)->print(print_int_var, DEC);

        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(char)).Using(stream_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int)).Using(stream_int_var, DEC)).Once();

        Verify(OverloadedMethod(ArduinoFake(HardwareSerial), print, size_t(char)).Using(print_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(HardwareSerial), print, size_t(int, int)).Using(print_int_var, DEC)).Once();
    }

    void test_hardware_basics(void)
    {
        When(Method(ArduinoFake(HardwareSerial), availableForWrite)).Return(1, 0, 0);
        When(Method(ArduinoFake(HardwareSerial), available)).Return(0, 0, 1);
        When(Method(ArduinoFake(HardwareSerial), begin)).AlwaysReturn();
        When(Method(ArduinoFake(HardwareSerial), flush)).AlwaysReturn();
        When(Method(ArduinoFake(HardwareSerial), end)).AlwaysReturn();

        When(Method(ArduinoFake(HardwareSerial), read)).Return(11, 12, 13);
        When(Method(ArduinoFake(HardwareSerial), peek)).Return(21, 22, 23);

        TEST_ASSERT_EQUAL(1, ArduinoFakeInstance(HardwareSerial)->availableForWrite());
        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(HardwareSerial)->availableForWrite());
        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(HardwareSerial)->availableForWrite());

        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(HardwareSerial)->available());
        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(HardwareSerial)->available());
        TEST_ASSERT_EQUAL(1, ArduinoFakeInstance(HardwareSerial)->available());

        TEST_ASSERT_EQUAL(11, ArduinoFakeInstance(HardwareSerial)->read());
        TEST_ASSERT_EQUAL(12, ArduinoFakeInstance(HardwareSerial)->read());
        TEST_ASSERT_EQUAL(13, ArduinoFakeInstance(HardwareSerial)->read());

        TEST_ASSERT_EQUAL(21, ArduinoFakeInstance(HardwareSerial)->peek());
        TEST_ASSERT_EQUAL(22, ArduinoFakeInstance(HardwareSerial)->peek());
        TEST_ASSERT_EQUAL(23, ArduinoFakeInstance(HardwareSerial)->peek());

        ArduinoFakeInstance(HardwareSerial)->begin(9600, 10);
        ArduinoFakeInstance(HardwareSerial)->flush();
        ArduinoFakeInstance(HardwareSerial)->end();

        Verify(Method(ArduinoFake(HardwareSerial), availableForWrite)).Exactly(3_Times);
        Verify(Method(ArduinoFake(HardwareSerial), available)).Exactly(3_Times);
        Verify(Method(ArduinoFake(HardwareSerial), read)).Exactly(3_Times);
        Verify(Method(ArduinoFake(HardwareSerial), peek)).Exactly(3_Times);

        Verify(Method(ArduinoFake(HardwareSerial), begin).Using(9600, 10)).Once();
        Verify(Method(ArduinoFake(HardwareSerial), flush)).Once();
        Verify(Method(ArduinoFake(HardwareSerial), end)).Once();
    }

    void run_tests(void)
    {
        RUN_TEST(HardwareSerialTest::test_extends_stream);
        RUN_TEST(HardwareSerialTest::test_hardware_basics);
    }
}

#endif
