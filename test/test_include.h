#ifdef UNIT_TEST

namespace IncludeTest
{

    void test_empty(void)
    {
        int PROGMEM a = 1;
    }

    void run_tests(void)
    {
        RUN_TEST(IncludeTest::test_empty);
    }
}

#endif
