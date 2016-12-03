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

int CotekInverter::read_serial_to_put_buff() {
  int read = 0;
  for ( int i = 0; i < 255; i++ ) {
    if (my_serial->available()) {
      buff[read] = my_serial->read();
      read++;
    }
  }
  return read;
}

int CotekInverter::send_signal(char* command) {
  my_serial->begin(my_serial_speed);
  my_serial->println(command);

  int read = read_serial_to_put_buff();

  my_serial->end();

  return read;
}

int CotekInverter::send_signal(String command) {
  my_serial->begin(my_serial_speed);
  my_serial->println(command);

  int read = read_serial_to_put_buff();

  my_serial->end();

  return read;
}

boolean CotekInverter::is_error() {
  send_signal("ERR?");
}

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
