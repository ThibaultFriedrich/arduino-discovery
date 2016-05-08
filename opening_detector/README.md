# Opening detector

This system detects a box opening and emit an alarm when the box is opened and stop the alarm only when the box is closed.

This project is using platefrmio (see more [here](http://platformio.org))

## Hardware

* arduino Uno
* active buzzer: HCM1212X-1 Electro-Magnetic Sound Generator (see more [here](http://www.microbuzzer.com/buzzer-magnetic-12vdc-12mm) )
* light sensor: TSL2561 (see more [here](https://www.adafruit.com/products/439) )

## Software

The project need the TSL2561 library available here: https://github.com/adafruit/TSL2561-Arduino-Library
Copy it in the folder lib.

## Help

* https://learn.adafruit.com/tsl2561/wiring
* https://github.com/adafruit/TSL2561-Arduino-Library
* http://www.microbuzzer.com/buzzer-magnetic-12vdc-12mm
