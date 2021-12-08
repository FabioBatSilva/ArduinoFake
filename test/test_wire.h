#ifdef UNIT_TEST

namespace WireTest {
void test_extends_stream(void) {
  TEST_ASSERT_NOT_EQUAL(ArduinoFakeInstance(Stream), ArduinoFakeInstance(Wire));

  char print_char_var = 'A';
  char stream_char_var = 'B';

  int print_int_var = 123;
  int stream_int_var = 321;

  When(OverloadedMethod(ArduinoFake(Stream), print, size_t(char)))
      .AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int)))
      .AlwaysReturn();

  When(OverloadedMethod(ArduinoFake(Wire), print, size_t(char))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(Wire), print, size_t(int, int)))
      .AlwaysReturn();

  Stream *stream = ArduinoFakeMock(Stream);
  TwoWire *wire = ArduinoFakeMock(Wire);

  stream->print(stream_char_var);
  stream->print(stream_int_var, DEC);

  wire->print(print_char_var);
  wire->print(print_int_var, DEC);

  Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(char))
             .Using(stream_char_var))
      .Once();
  Verify(OverloadedMethod(ArduinoFake(Stream), print, size_t(int, int))
             .Using(stream_int_var, DEC))
      .Once();

  Verify(OverloadedMethod(ArduinoFake(Wire), print, size_t(char))
             .Using(print_char_var))
      .Once();
  Verify(OverloadedMethod(ArduinoFake(Wire), print, size_t(int, int))
             .Using(print_int_var, DEC))
      .Once();
}

void test_global_wire(void) {
  When(Method(ArduinoFake(Wire), available)).Return(1);
  When(OverloadedMethod(ArduinoFake(Wire), print, size_t(char))).Return(1);

  TEST_ASSERT_EQUAL(1, Wire.available());
  TEST_ASSERT_EQUAL(1, Wire.print('A'));

  Verify(Method(ArduinoFake(Wire), available)).Once();
  Verify(OverloadedMethod(ArduinoFake(Wire), print, size_t(char)).Using('A'))
      .Once();
}

void test_basics(void) {

  uint8_t device_addr = 0xab;
  uint8_t register_addr = 0xcd;
  int num_bytes_to_read = 1;
  bool send_stop = false;
  When(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t)))
      .AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t)))
      .Return(true);
  When(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(bool)))
      .Return(0);
  When(OverloadedMethod(ArduinoFake(Wire), requestFrom, uint8_t(uint8_t, uint8_t)))
      .Return(0);
  When(OverloadedMethod(ArduinoFake(Wire), available, int(void))).Return(1);
  When(OverloadedMethod(ArduinoFake(Wire), read, int(void))).Return(1);

  Wire.begin();
  Wire.beginTransmission(device_addr);
  Wire.write(register_addr);
  Wire.endTransmission(send_stop);
  Wire.requestFrom(device_addr, num_bytes_to_read);
  if (Wire.available()) {
    Wire.read();
  }

  Verify(OverloadedMethod(ArduinoFake(Wire), begin, void(void))).Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), beginTransmission, void(uint8_t))
             .Using(device_addr))
      .Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), write, size_t(uint8_t))
             .Using(register_addr))
      .Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), endTransmission, uint8_t(bool))
             .Using(send_stop))
      .Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), requestFrom, uint8_t(uint8_t, uint8_t))
             .Using(device_addr, num_bytes_to_read))
      .Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), available, int(void))).Exactly(1);
  Verify(OverloadedMethod(ArduinoFake(Wire), read, int(void))).Exactly(1);
}

void run_tests() {
  RUN_TEST(WireTest::test_extends_stream);
  RUN_TEST(WireTest::test_global_wire);
  RUN_TEST(WireTest::test_basics);
}
} // namespace WireTest

#endif
