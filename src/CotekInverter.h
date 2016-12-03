#ifndef CotekInverter_h
#define CotekInverter_h
#include "Arduino.h"
#include <SomeSerial.h>

class CotekInverter {
  public:
  CotekInverter(HardwareSerial* hardSerial);
  CotekInverter(uint8_t rx, uint8_t tx);
  void begin(int speed);
  void powerOn();
  void powerOff();

  private:
  SomeSerial* mySerial;
};

#endif
