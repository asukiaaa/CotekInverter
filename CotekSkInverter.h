#ifndef CotekSkInverter_h
#define CotekSkInverter_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class CotekSkInverter {
  private:
  SoftwareSerial* my_serial;
  int my_serial_speed;

  public:
  CotekSkInverter(uint8_t tx_pin, uint8_t rx_pin);
  void power_on();
  void power_off();
};

#endif
