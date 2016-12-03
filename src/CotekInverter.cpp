#include "CotekInverter.h"

CotekInverter::CotekInverter(uint8_t rx, uint8_t tx) {
  mySerial = new SoftwareSerial(rx, tx);
  mySerialSpeed = 4800;
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
  mySerial->begin(mySerialSpeed);
  mySerial->println("Power 1");
  mySerial->end();
};

void CotekInverter::powerOff() {
  mySerial->begin(mySerialSpeed);
  mySerial->println("Power 0");
  mySerial->end();
};
