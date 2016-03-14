/*
  CotekSkInverter
  2016.03
  Written by Asuki Kono.
  This is a library to controll COTEK SK series Inverter.
 */
#include "CotekSkInverter.h"

CotekSkInverter::CotekSkInverter(uint8_t tx_pin, uint8_t rx_pin) {
  my_serial = new SoftwareSerial(tx_pin, rx_pin);
  my_serial_speed = 4800;
};

void CotekSkInverter::power_on() {
  my_serial->begin(my_serial_speed);
  my_serial->println("Power 1");
  my_serial->end();
};

void CotekSkInverter::power_off() {
  my_serial->begin(my_serial_speed);
  my_serial->println("Power 0");
  my_serial->end();
};
