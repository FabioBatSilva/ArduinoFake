#ifdef UNIT_TEST

namespace ClientTest
{
    const char * localhost = "localhost";

    class MyService
    {
        public:
            MyService(Client* client)
            {
                _client = client;
            }

            size_t send(uint16_t value)
            {
                return _client->write(value);
            }

        private:
            Client* _client;
    };

    void test_basics(void)
    {
        When(Method(ArduinoFake(Client), stop)).Return();
        When(Method(ArduinoFake(Client), peek)).Return(2);
        When(Method(ArduinoFake(Client), flush)).Return();
        When(Method(ArduinoFake(Client), connected)).Return(0, 1);
        When(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t))).Return(1);

        Client* client = ArduinoFakeMock(Client);

        TEST_ASSERT_EQUAL(0, client->connected());
        TEST_ASSERT_EQUAL(1, client->connect(localhost, 8080));
        TEST_ASSERT_EQUAL(1, client->connected());
        TEST_ASSERT_EQUAL(2, client->peek());

        client->flush();
        client->stop();

        Verify(Method(ArduinoFake(Client), stop)).Once();
        Verify(Method(ArduinoFake(Client), peek)).Once();
        Verify(Method(ArduinoFake(Client), flush)).Once();
        Verify(Method(ArduinoFake(Client), connected)).Exactly(2_Times);
        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t)).Using(localhost, 8080)).Once();
    }

    void test_connect(void)
    {
        When(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t))).Return(1, 0);
        When(OverloadedMethod(ArduinoFake(Client), connect, int(IPAddress, uint16_t))).Return(0, 1);

        IPAddress ipAddress1(62, 145, 182, 225);
        IPAddress ipAddress2(221, 155, 131, 19);

        Client* client = ArduinoFakeMock(Client);

        TEST_ASSERT_EQUAL(1, client->connect(localhost, 8080));
        TEST_ASSERT_EQUAL(0, client->connect(localhost, 80));

        TEST_ASSERT_EQUAL(0, client->connect(ipAddress1, 8080));
        TEST_ASSERT_EQUAL(1, client->connect(ipAddress2, 8080));

        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t)).Using(localhost, 8080)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(const char*, uint16_t)).Using(localhost, 80)).Once();

        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(IPAddress, uint16_t)).Using(ipAddress1, 8080)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), connect, int(IPAddress, uint16_t)).Using(ipAddress2, 8080)).Once();
    }

    void test_write(void)
    {
        uint8_t val1 = 0x0;
        uint8_t val2 = 0x1;

        const uint8_t* ptr1 = &val1;
        const uint8_t* ptr2 = &val2;

        When(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t))).Return(1, 0);
        When(OverloadedMethod(ArduinoFake(Client), write, size_t(const uint8_t*, size_t))).Return(0, 1);

        Client* client = ArduinoFakeMock(Client);

        TEST_ASSERT_EQUAL(1, client->write(val1));
        TEST_ASSERT_EQUAL(0, client->write(val2));

        TEST_ASSERT_EQUAL(0, client->write(ptr1, 2));
        TEST_ASSERT_EQUAL(1, client->write(ptr2, 3));

        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t)).Using(val1)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t)).Using(val2)).Once();

        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(const uint8_t*, size_t)).Using(ptr1, 2)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(const uint8_t*, size_t)).Using(ptr2, 3)).Once();
    }

    void test_read(void)
    {
        uint8_t val1 = 0x0;
        uint8_t val2 = 0x1;

        uint8_t* ptr1 = &val1;
        uint8_t* ptr2 = &val2;

        When(OverloadedMethod(ArduinoFake(Client), read, int())).Return(10, 20);
        When(OverloadedMethod(ArduinoFake(Client), read, int(uint8_t*, size_t))).Return(30, 400);

        Client* client = ArduinoFakeMock(Client);

        TEST_ASSERT_EQUAL(10, client->read());
        TEST_ASSERT_EQUAL(20, client->read());

        TEST_ASSERT_EQUAL(30, client->read(ptr1, 2));
        TEST_ASSERT_EQUAL(400, client->read(ptr2, 3));

        Verify(OverloadedMethod(ArduinoFake(Client), read, int())).Exactly(2_Times);

        Verify(OverloadedMethod(ArduinoFake(Client), read, int(uint8_t*, size_t)).Using(ptr1, 2)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), read, int(uint8_t*, size_t)).Using(ptr2, 3)).Once();
    }

    void test_inject_instance(void)
    {
        uint8_t val1 = 0x0;
        uint8_t val2 = 0x1;

        When(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t))).Return(11, 22);

        Client* client = ArduinoFakeMock(Client);

        MyService service(client);

        TEST_ASSERT_EQUAL(11, service.send(val1));
        TEST_ASSERT_EQUAL(22, service.send(val2));

        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t)).Using(val1)).Once();
        Verify(OverloadedMethod(ArduinoFake(Client), write, size_t(uint8_t)).Using(val2)).Once();
    }

    void run_tests()
    {
        RUN_TEST(ClientTest::test_basics);
        RUN_TEST(ClientTest::test_connect);
        RUN_TEST(ClientTest::test_write);
        RUN_TEST(ClientTest::test_read);
        RUN_TEST(ClientTest::test_inject_instance);
    }
}

#endif
