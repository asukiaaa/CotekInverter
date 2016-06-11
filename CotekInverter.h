#ifndef CotekInverter_h
#define CotekInverter_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class CotekInverter {
  private:
  SoftwareSerial* my_serial;
  int my_serial_speed;
  int read_serial_to_put_buff();

  public:
  uint8_t buff[128];
  CotekInverter(uint8_t rx_pin, uint8_t tx_pin);
  int send_signal(char* command);
  int send_signal(String command);
  boolean is_error();
  void power_on();
  void power_off();
};

#endif
