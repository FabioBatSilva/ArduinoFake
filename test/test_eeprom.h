#ifdef UNIT_TEST

namespace EEPROMTest {

#include "arduino/EEPROM.h"

void test_basics(void) {
  When(OverloadedMethod(ArduinoFake(EEPROM), read, uint8_t(int)))
      .AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(EEPROM), write, void(int, uint8_t)))
      .AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(EEPROM), update, void(int, uint8_t)))
      .AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(EEPROM), length, uint16_t(void)))
      .AlwaysReturn();

  EEPROM.read(1);
  EEPROM.write(1, 1);
  EEPROM.update(1, 2);
  EEPROM.length();

  Verify(OverloadedMethod(ArduinoFake(EEPROM), read, uint8_t(int))).Once();
  Verify(OverloadedMethod(ArduinoFake(EEPROM), write, void(int, uint8_t)))
      .Once();
  Verify(OverloadedMethod(ArduinoFake(EEPROM), update, void(int, uint8_t)))
      .Once();
  Verify(OverloadedMethod(ArduinoFake(EEPROM), length, uint16_t(void))).Once();
}

void run_tests() { RUN_TEST(EEPROMTest::test_basics); }
} // namespace EEPROMTest

#endif