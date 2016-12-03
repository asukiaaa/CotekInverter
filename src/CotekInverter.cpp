#include "CotekInverter.h"

CotekInverter::CotekInverter(uint8_t rx, uint8_t tx) {
  mySerial = new SoftwareSerial(rx, tx);
};

void CotekInverter::begin(int speed) {
  mySerial->begin(4800);
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

void CotekInverter::powerOn() {
  mySerial->println("Power 1");
};

void CotekInverter::powerOff() {
  mySerial->println("Power 0");
};
