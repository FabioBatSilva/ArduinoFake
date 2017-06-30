#ifdef UNIT_TEST

namespace StreamTest
{
    void test_extends_print(void)
    {
        TEST_ASSERT_NOT_EQUAL(
            ArduinoFakeInstance(Stream),
            ArduinoFakeInstance(Print)
        );

        char print_char_var = 'A';
        char stream_char_var = 'B';

        int print_int_var = 123;
        int stream_int_var = 321;

        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int))).AlwaysReturn();

        When(OverloadedMethod(ArduinoFake(Print), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(int, int))).AlwaysReturn();

        Stream* stream = ArduinoFakeMock(Stream);
        Print* print = ArduinoFakeMock(Print);

        stream->print(stream_char_var);
        stream->print(stream_int_var, DEC);

        print->print(print_char_var);
        print->print(print_int_var, DEC);

        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(char)).Using(stream_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int)).Using(stream_int_var, DEC)).Once();

        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(char)).Using(print_char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(int, int)).Using(print_int_var, DEC)).Once();
    }

    void test_stream_basics(void)
    {
        When(Method(ArduinoFake(Stream), available)).Return(0, 1, 0);
        When(Method(ArduinoFake(Stream), read)).Return(11, 12, 13);
        When(Method(ArduinoFake(Stream), peek)).Return(21, 22, 23);
        When(Method(ArduinoFake(Stream), flush)).AlwaysReturn();

        Stream* stream = ArduinoFakeMock(Stream);

        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(Stream)->available());
        TEST_ASSERT_EQUAL(1, ArduinoFakeInstance(Stream)->available());
        TEST_ASSERT_EQUAL(0, ArduinoFakeInstance(Stream)->available());

        TEST_ASSERT_EQUAL(11, ArduinoFakeInstance(Stream)->read());
        TEST_ASSERT_EQUAL(12, ArduinoFakeInstance(Stream)->read());
        TEST_ASSERT_EQUAL(13, ArduinoFakeInstance(Stream)->read());

        TEST_ASSERT_EQUAL(21, ArduinoFakeInstance(Stream)->peek());
        TEST_ASSERT_EQUAL(22, ArduinoFakeInstance(Stream)->peek());
        TEST_ASSERT_EQUAL(23, ArduinoFakeInstance(Stream)->peek());

        ArduinoFakeInstance(Stream)->flush();

        Verify(Method(ArduinoFake(Stream), available)).Exactly(3_Times);
        Verify(Method(ArduinoFake(Stream), read)).Exactly(3_Times);
        Verify(Method(ArduinoFake(Stream), peek)).Exactly(3_Times);
        Verify(Method(ArduinoFake(Stream), flush)).Once();
    }

    void test_stream_find(void)
    {
        char char_val1 = 'A';
        char char_val2 = 'B';
        char terminator = '*';

        char* char_ptr1 = &char_val1;
        char* char_ptr2 = &char_val2;
        char* terminator_ptr = &terminator;

        When(OverloadedMethod(ArduinoFake(Stream), find, bool(char*))).Return(true, false);
        When(OverloadedMethod(ArduinoFake(Stream), find, bool(char*, size_t))).Return(true, false);

        When(OverloadedMethod(ArduinoFake(Stream), findUntil, bool(char*, char*))).Return(true, false);
        When(OverloadedMethod(ArduinoFake(Stream), findUntil, bool(char*, size_t, char*, size_t))).Return(true, false);

        TEST_ASSERT_EQUAL(true, ArduinoFakeInstance(Stream)->find(char_ptr1));
        TEST_ASSERT_EQUAL(false, ArduinoFakeInstance(Stream)->find(char_ptr2));

        TEST_ASSERT_EQUAL(true, ArduinoFakeInstance(Stream)->find(char_ptr1, 10));
        TEST_ASSERT_EQUAL(false, ArduinoFakeInstance(Stream)->find(char_ptr2, 20));

        TEST_ASSERT_EQUAL(true, ArduinoFakeInstance(Stream)->findUntil(char_ptr1, terminator_ptr));
        TEST_ASSERT_EQUAL(false, ArduinoFakeInstance(Stream)->findUntil(char_ptr2, terminator_ptr));

        TEST_ASSERT_EQUAL(true, ArduinoFakeInstance(Stream)->findUntil(char_ptr1, 10, terminator_ptr, 11));
        TEST_ASSERT_EQUAL(false, ArduinoFakeInstance(Stream)->findUntil(char_ptr2, 20, terminator_ptr, 21));

        Verify(OverloadedMethod(ArduinoFake(Stream), find, bool(char*)).Using(char_ptr1)).Once();
        Verify(OverloadedMethod(ArduinoFake(Stream), find, bool(char*)).Using(char_ptr2)).Once();

        Verify(OverloadedMethod(ArduinoFake(Stream), find, bool(char*, size_t)).Using(char_ptr1, 10)).Once();
        Verify(OverloadedMethod(ArduinoFake(Stream), find, bool(char*, size_t)).Using(char_ptr2, 20)).Once();

        Verify(OverloadedMethod(ArduinoFake(Stream), findUntil, bool(char*, char*))).Exactly(2_Times);
        Verify(OverloadedMethod(ArduinoFake(Stream), findUntil, bool(char*, size_t, char*, size_t))).Exactly(2_Times);
    }

    void test_stream_parse(void)
    {
        When(Method(ArduinoFake(Stream), parseInt)).Return(10, 11);
        When(Method(ArduinoFake(Stream), parseFloat)).Return(2.0, 2.1);

        TEST_ASSERT_INT_WITHIN(0, 10, ArduinoFakeInstance(Stream)->parseInt());
        TEST_ASSERT_INT_WITHIN(0, 11, ArduinoFakeInstance(Stream)->parseInt());

        TEST_ASSERT_FLOAT_WITHIN(0, 2.0, ArduinoFakeInstance(Stream)->parseFloat());
        TEST_ASSERT_FLOAT_WITHIN(0, 2.1, ArduinoFakeInstance(Stream)->parseFloat());

        Verify(Method(ArduinoFake(Stream), parseInt)).Exactly(2_Times);
        Verify(Method(ArduinoFake(Stream), parseFloat)).Exactly(2_Times);
    }

    void test_stream_read(void)
    {
        char char_val1 = 'A';
        char char_val2 = 'B';
        char terminator = '*';
        String str1 = String('X');
        String str2 = String('Z');

        char* char_ptr1 = &char_val1;
        char* char_ptr2 = &char_val2;

        When(Method(ArduinoFake(Stream), readBytes)).Return(1, 2);
        When(Method(ArduinoFake(Stream), readBytesUntil)).Return(3, 4);
        When(Method(ArduinoFake(Stream), readString)).Return(str1, str2);
        When(Method(ArduinoFake(Stream), readStringUntil)).Return(str1, str2);

        TEST_ASSERT_EQUAL_INT(1, ArduinoFakeInstance(Stream)->readBytes(char_ptr1, 10));
        TEST_ASSERT_EQUAL_INT(2, ArduinoFakeInstance(Stream)->readBytes(char_ptr2, 20));

        TEST_ASSERT_EQUAL_INT(3, ArduinoFakeInstance(Stream)->readBytesUntil(terminator, char_ptr1, 10));
        TEST_ASSERT_EQUAL_INT(4, ArduinoFakeInstance(Stream)->readBytesUntil(terminator, char_ptr2, 20));

        TEST_ASSERT_TRUE(str1.equals(ArduinoFakeInstance(Stream)->readString()));
        TEST_ASSERT_TRUE(str2.equals(ArduinoFakeInstance(Stream)->readString()));

        TEST_ASSERT_TRUE(str1.equals(ArduinoFakeInstance(Stream)->readStringUntil(terminator)));
        TEST_ASSERT_TRUE(str2.equals(ArduinoFakeInstance(Stream)->readStringUntil(terminator)));

        Verify(Method(ArduinoFake(Stream), readBytes).Using(char_ptr1, 10)).Once();
        Verify(Method(ArduinoFake(Stream), readBytes).Using(char_ptr2, 20)).Once();

        Verify(Method(ArduinoFake(Stream), readBytesUntil).Using(terminator, char_ptr1, 10)).Once();
        Verify(Method(ArduinoFake(Stream), readBytesUntil).Using(terminator, char_ptr2, 20)).Once();

        Verify(Method(ArduinoFake(Stream), readString)).Exactly(2_Times);
        Verify(Method(ArduinoFake(Stream), readBytesUntil)).Exactly(2_Times);
    }

    void run_tests()
    {
        RUN_TEST(StreamTest::test_extends_print);
        RUN_TEST(StreamTest::test_stream_basics);
        RUN_TEST(StreamTest::test_stream_find);
        RUN_TEST(StreamTest::test_stream_parse);
        RUN_TEST(StreamTest::test_stream_read);
    }
}

#endif
