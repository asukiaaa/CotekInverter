# CotekInverter
A library to controll cotek inverter with using arduino in RS232 serial communication.

# Connection between Cotek Inverter and Arduino

Role of modular pins from Cotek Inverter is like this.

| Pins   | Role         |
| ------ | ------------ |
| 1      | Not used     |
| 2      | GND          |
| 3      | RXD          |
| 4      | TXD          |
| 5      | Remo Control |
| 6      | VCC          |

You can connect the pins to arduino like this.
- RXD -> RS232 level converter -> Arduino D8(SoftwareSerial TX)
- TXD -> RS232 level converter -> Arduino D9(SoftwareSerial RX)
- Remo Control -> Arduino GND
- GND -> Arduino GND

# Useage
## Include
```c
#include <SoftwareSerial.h>
#include "CotekInverter.h"
```
This library uses SoftwareSerial, so please include also that.

## Definition
```c
CotekInverter inverter(8, 9); // RX, TX
```
Please define with rx and tx pins.

## Power off
```c
inverter.power_off();
```
You can trun off the inverter.

## Power on
```c
inverter.power_off();
```
You can turn on the inverter.

# Example
```c
#include <SoftwareSerial.h>
#include "CotekInverter.h"

int SWITCH_PIN = 14;

CotekInverter inverter(8, 9); // RX, TX

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  inverter.power_off();
}

void loop() {
  if ( digitalRead(SWITCH_PIN) == HIGH ) {
    inverter.power_on();
  } else {
    inverter.power_off();
  }

  delay(1000);
}
```

# License
MIT

# References
Cotek Inverter manuals: https://github.com/asukiaaa/CotekInverterDocuments
