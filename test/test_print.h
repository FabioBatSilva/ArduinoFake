#ifdef UNIT_TEST

namespace PrintTest
{
    void test_print_variables(void)
    {
        char char_var = 'A';
        unsigned char unsigned_char_var = 'B';
        const char char_array_var[] = "char_array_var";

        int int_var = 123;
        long long_var = 12345678;
        double double_var = 98765.12;
        unsigned int unsigned_int_var = 321;
        unsigned long unsigned_long_var = 87654321;

        When(OverloadedMethod(ArduinoFake(Print), print, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(const char[]))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned char, int))).AlwaysReturn();

        When(OverloadedMethod(ArduinoFake(Print), print, size_t(int, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(long, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(double, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned int, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned long, int))).AlwaysReturn();

        ArduinoFakeInstance(Print)->print(char_var);
        ArduinoFakeInstance(Print)->print(char_array_var);
        ArduinoFakeInstance(Print)->print(unsigned_char_var, DEC);

        ArduinoFakeInstance(Print)->print(int_var, DEC);
        ArduinoFakeInstance(Print)->print(long_var, DEC);
        ArduinoFakeInstance(Print)->print(double_var, BIN);
        ArduinoFakeInstance(Print)->print(unsigned_int_var, DEC);
        ArduinoFakeInstance(Print)->print(unsigned_long_var, DEC);

        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(char)).Using(char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(const char[])).Using(char_array_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned char, int)).Using(unsigned_char_var, DEC)).Once();

        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(int, int)).Using(int_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(long, int)).Using(long_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(double, int)).Using(double_var, BIN)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned int, int)).Using(unsigned_int_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), print, size_t(unsigned long, int)).Using(unsigned_long_var, DEC)).Once();
    }

    void test_println_variables(void)
    {
        char char_var = 'A';
        unsigned char unsigned_char_var = 'B';
        const char char_array_var[] = "char_array_var";

        int int_var = 123;
        long long_var = 12345678;
        double double_var = 98765.12;
        unsigned int unsigned_int_var = 321;
        unsigned long unsigned_long_var = 87654321;

        When(OverloadedMethod(ArduinoFake(Print), println, size_t())).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(char))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(const char[]))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned char, int))).AlwaysReturn();

        When(OverloadedMethod(ArduinoFake(Print), println, size_t(int, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(long, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(double, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned int, int))).AlwaysReturn();
        When(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned long, int))).AlwaysReturn();

        ArduinoFakeInstance(Print)->println();
        ArduinoFakeInstance(Print)->println(char_var);
        ArduinoFakeInstance(Print)->println(char_array_var);
        ArduinoFakeInstance(Print)->println(unsigned_char_var, DEC);

        ArduinoFakeInstance(Print)->println(int_var, DEC);
        ArduinoFakeInstance(Print)->println(long_var, DEC);
        ArduinoFakeInstance(Print)->println(double_var, BIN);
        ArduinoFakeInstance(Print)->println(unsigned_int_var, DEC);
        ArduinoFakeInstance(Print)->println(unsigned_long_var, DEC);

        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t())).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(char)).Using(char_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(const char[])).Using(char_array_var)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned char, int)).Using(unsigned_char_var, DEC)).Once();

        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(int, int)).Using(int_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(long, int)).Using(long_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(double, int)).Using(double_var, BIN)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned int, int)).Using(unsigned_int_var, DEC)).Once();
        Verify(OverloadedMethod(ArduinoFake(Print), println, size_t(unsigned long, int)).Using(unsigned_long_var, DEC)).Once();
    }

    void run_tests()
    {
        RUN_TEST(PrintTest::test_print_variables);
        RUN_TEST(PrintTest::test_println_variables);
    }
}

#endif
