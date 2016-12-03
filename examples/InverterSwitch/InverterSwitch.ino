#include "CotekInverter.h"

int SWITCH_PIN = 14;

CotekInverter inverter(&Serial);

// For Lonardo HardwareSerial
// CotekInverter inverter(&Serial1);

// With SoftwareSerial
// CotekInverter inverter(8, 9); // RX, TX

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  inverter.powerOff();
}

void loop() {
  if ( digitalRead(SWITCH_PIN) == HIGH ) {
    inverter.powerOn();
  } else {
    inverter.powerOff();
  }

  delay(1000);
}
