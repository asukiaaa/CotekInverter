#ifndef CotekInverter_h
#define CotekInverter_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class CotekInverter {
  public:
  CotekInverter(uint8_t rx, uint8_t tx);
  void powerOn();
  void powerOff();

  private:
  SoftwareSerial* mySerial;
  mySerialSpeed;
};

#endif
