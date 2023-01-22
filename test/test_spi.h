#ifdef UNIT_TEST

namespace SpiTest {

#include "arduino/SPI.h"

void test_basics(void) {
  SPISettings settings(4000000, MSBFIRST, SPI_MODE0);
  uint8_t buffer1=0x01;
  uint8_t buffer2[]={0x02};

  When(OverloadedMethod(ArduinoFake(SPI), begin, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), end, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), beginTransaction, void(SPISettings)).Using(settings)).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), endTransaction, void(void))).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(SPI), transfer, uint8_t(uint8_t)).Using(buffer1)).AlwaysReturn();
//  When(OverloadedMethod(ArduinoFake(SPI), transfer, void(void*, size_t)).Using(buffer2,sizeof(buffer2))).AlwaysReturn();

  SPI.begin();
  SPI.beginTransaction(settings);
  SPI.transfer(0x01);
//  SPI.transfer(buffer2, sizeof(buffer2));
  SPI.endTransaction();
  SPI.end();

  Verify(OverloadedMethod(ArduinoFake(SPI), begin, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), end, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), beginTransaction, void(SPISettings))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), endTransaction, void(void))).Once();
  Verify(OverloadedMethod(ArduinoFake(SPI), transfer, uint8_t(uint8_t))).Once();
//  Verify(OverloadedMethod(ArduinoFake(SPI), transfer, void(void*, size_t))).Once();
}

void run_tests() { RUN_TEST(SpiTest::test_basics); }
}  // namespace SpiTest

#endif