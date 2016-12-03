#include "CotekInverter.h"

CotekInverter::CotekInverter(uint8_t rx_pin, uint8_t tx_pin) {
  my_serial = new SoftwareSerial(rx_pin, tx_pin);
  my_serial_speed = 4800;
};

// Found the following commands for SK-1500
// *RST    // reset
// Power 0 // power OFF
// Power 1 // power ON
// Power 2 // unknown
// Power 3 // received value
//         // 0: off
//         // 2: on
// Power 4 // unknown
// Power 5 // unknown
// Power 6 // unknown
// Power 7 // unknown
// Power 8 // unknown
// Power 9 // unknown

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
