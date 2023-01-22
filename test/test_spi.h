#ifdef UNIT_TEST

namespace SpiTest {

#include "arduino/SPI.h"

void test_basics(void) {
  SPISettings settings(4000000, MSBFIRST, SPI_MODE0);
  uint8_t data = 0x01;
  uint8_t buffer[] = {0x02, 0x03, 0x04};
  uint8_t *ptr = buffer;

  When(OverloadedMethod(ArduinoFake(SPI), begin, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), end, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), beginTransaction, void(SPISettings)).Using(settings)).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), endTransaction, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), transfer, uint8_t(uint8_t)).Using(data)).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), transfer, void(void*, size_t)).Using(ptr, sizeof(buffer))).AlwaysReturn();

  SPI.begin();
  SPI.beginTransaction(settings);
  SPI.transfer(data);
  SPI.transfer(buffer, sizeof(buffer));
  SPI.endTransaction();
  SPI.end();

  Verify(OverloadedMethod(ArduinoFake(SPI), begin, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), end, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), beginTransaction, void(SPISettings))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), endTransaction, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), transfer, uint8_t(uint8_t))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), transfer, void(void*, size_t))).Once();
}

void run_tests() { RUN_TEST(SpiTest::test_basics); }
}  // namespace SpiTest

#endif