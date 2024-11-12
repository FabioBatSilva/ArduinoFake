#ifdef UNIT_TEST

namespace SerialTest
{
    void test_extends_stream(void)
    {
        TEST_ASSERT_NOT_EQUAL(
            ArduinoFakeInstance(Stream),
            ArduinoFakeInstance(Serial)
        );

        char print_char_var = 'A';
        char stream_char_var = 'B';

        int print_int_var = 123;
        int stream_int_var = 321;

        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int))).AlwaysReturn();

        When(OverloadedMethod(ArduinoFake(Serial), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Serial), print, size_t(int, int))).AlwaysReturn();

        Stream* stream = ArduinoFakeMock(Stream);
        Serial_* serial = ArduinoFakeMock(Serial);

        stream->print(stream_char_var);
        stream->print(stream_int_var, DEC);

        serial->print(print_char_var);
        serial->print(print_int_var, DEC);

        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(char)).Using(stream_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int)).Using(stream_int_var, DEC)).Once();

        Verify(OverloadedMethod(ArduinoFake(Serial), print, size_t(char)).Using(print_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Serial), print, size_t(int, int)).Using(print_int_var, DEC)).Once();
    }

    void test_global_serial(void)
    {
        When(Method(ArduinoFake(Serial), available)).Return(1);
        When(OverloadedMethod(ArduinoFake(Serial), print, size_t(char))).Return(1);

        TEST_ASSERT_EQUAL(1, Serial.available());
        TEST_ASSERT_EQUAL(1, Serial.print('A'));

        Verify(Method(ArduinoFake(Serial), available)).Once();
        Verify(OverloadedMethod(ArduinoFake(Serial), print, size_t(char)).Using('A')).Once();
    }

    void test_basics(void)
    {
        When(Method(ArduinoFake(Serial), end)).AlwaysReturn();
        When(Method(ArduinoFake(Serial), flush)).AlwaysReturn();
        When(Method(ArduinoFake(Serial), available)).Return(0, 1);
        When(OverloadedMethod(ArduinoFake(Serial), write, size_t(uint8_t))).Return(1);
        When(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long))).AlwaysReturn();

        Serial.begin(9600);

        TEST_ASSERT_EQUAL(0, Serial.available());
        TEST_ASSERT_EQUAL(1, Serial.available());
        TEST_ASSERT_EQUAL(1, Serial.write(5));

        Serial.flush();
        Serial.end();
        Serial.setDebugOutput(true);

        Verify(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long)).Using(9600)).Once();
        Verify(Method(ArduinoFake(Serial), available)).Exactly(2_Times);

        Verify(OverloadedMethod(ArduinoFake(Serial), write, size_t(uint8_t)).Using(5)).Once();

        Verify(Method(ArduinoFake(Serial), flush)).Once();
        Verify(Method(ArduinoFake(Serial), end)).Once();

        Verify(OverloadedMethod(ArduinoFake(Serial), setDebugOutput, void(bool)).Using(true)).Once();
    }

    void run_tests()
    {
        RUN_TEST(SerialTest::test_extends_stream);
        RUN_TEST(SerialTest::test_global_serial);
        RUN_TEST(SerialTest::test_basics);
    }
}

#endif
