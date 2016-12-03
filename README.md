# CotekInverter
A library to controll cotek inverter with using arduino in RS232 serial communication.

# Requirement

Please install SomeSerial library via library manager.

https://github.com/asukiaaa/SomeSerial

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
- RXD -> RS232 level converter -> Arduino TX
- TXD -> RS232 level converter -> Arduino RX
- Remo Control -> Arduino GND
- GND -> Arduino GND

# Useage
## Include
```c
#include "CotekInverter.h"
```

## Definition
### With HardwareSerial
```c
CotekInverter intevter(&Serial);
```

For Lonardo HardwareSerial
``` c
CotekInverter inverter(&Serial1);
```

### With SoftwareSerial
```c
CotekInverter inverter(8, 9); // RX, TX
```
Please define with rx and tx pins.

## Power off
```c
inverter.powerOff();
```
You can trun off the inverter.

## Power on
```c
inverter.powerOn();
```
You can turn on the inverter.

# Example
```c
#include "CotekInverter.h"

int SWITCH_PIN = 14;

CotekInverter inverter(&Seral);

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
```

# License
MIT

# References
Cotek Inverter manuals: https://github.com/asukiaaa/CotekInverterDocuments
