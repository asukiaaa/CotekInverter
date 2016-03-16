#ifndef CotekInverter_h
#define CotekInverter_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class CotekInverter {
  private:
  SoftwareSerial* my_serial;
  int my_serial_speed;

  public:
  CotekInverter(uint8_t tx_pin, uint8_t rx_pin);
  void power_on();
  void power_off();
};

#endif
