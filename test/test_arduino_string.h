#ifdef UNIT_TEST

namespace ArduinoStringTest
{
    void test_constructors(void)
    {
        String string01 = "Hello String";
        String string02 = String('a');
        String string03 = String("This is a string");
        String string04 = String(string03 + " with more");
        String string05 = String(13);
        String string06 = String(1000, DEC);
        String string07 = String(45, HEX);
        String string08 = String(255, BIN);
        String string09 = String(20000L, DEC);
        String string10 = String(5.698, 3);

        TEST_ASSERT_EQUAL_STRING("Hello String", string01.c_str());
        TEST_ASSERT_EQUAL_STRING("a", string02.c_str());
        TEST_ASSERT_EQUAL_STRING("This is a string", string03.c_str());
        TEST_ASSERT_EQUAL_STRING("This is a string with more", string04.c_str());

        TEST_ASSERT_EQUAL_STRING("13", string05.c_str());
        TEST_ASSERT_EQUAL_STRING("1000", string06.c_str());
        TEST_ASSERT_EQUAL_STRING("2d", string07.c_str());
        TEST_ASSERT_EQUAL_STRING("11111111", string08.c_str());
        TEST_ASSERT_EQUAL_STRING("20000", string09.c_str());
        TEST_ASSERT_EQUAL_STRING("5.698", string10.c_str());
    }

    void run_tests()
    {
        RUN_TEST(ArduinoStringTest::test_constructors);
    }
}

#endif
