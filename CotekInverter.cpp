/*
  CotekInverter
  2016.03
  Written by Asuki Kono.
  This is a library to controll COTEK Inverter with using Arduino.
 */
#include "CotekInverter.h"

CotekInverter::CotekInverter(uint8_t rx_pin, uint8_t tx_pin) {
  my_serial = new SoftwareSerial(rx_pin, tx_pin);
  my_serial_speed = 4800;
};

void CotekInverter::power_on() {
  my_serial->begin(my_serial_speed);
  my_serial->println("Power 1");
  my_serial->end();
};

void CotekInverter::power_off() {
  my_serial->begin(my_serial_speed);
  my_serial->println("Power 0");
  my_serial->end();
};
