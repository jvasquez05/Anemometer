# Anemometer Library

## Overview
The **Anemometer** library provides a clean and modular interface for measuring wind speed from pulse-based anemometers. It encapsulates the sensor logic, allowing dataloggers and applications to focus on data processing and analysis.

This library was developed as part of the Proagro Technology ecosystem, ensuring compatibility with agricultural dataloggers and modular workflows.

## Features
- Reads wind speed from pulse-based anemometers.
- Configurable conversion factor (`FactorAnem`) to adapt to different sensor specifications.
- Simple API for integration into dataloggers and Arduino projects.
- Lightweight and efficient, designed for continuous field operation.

## Installation
1. Download or clone this repository into your Arduino `libraries` folder.
2. Restart the Arduino IDE.
3. Include the library in your sketch:
   ```cpp
   #include <Anemometer.h>


Usage Example
#include <Anemometer.h>

const int anemometerPin = 4;
Anemometer anemometro(anemometerPin, 2.4f); // pin and default factor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int instWind = anemometro.measureInstantWind();
  Serial.print("Instant wind: ");
  Serial.print(instWind);
  Serial.println(" km/h");
  delay(1000);
}

Configuration

The conversion factor (FactorAnem) can be updated at runtime:
anemometro.setFactor(3.0f); // Example: new specification factor


In advanced setups (such as the Proagro Technology datalogger), this factor can be modified via Bluetooth commands:
- SET_FANEM <value> → Set new factor.
- GET_FANEM → Retrieve current factor.
If you are not using the Proagro datalogger, you can implement your own configuration logic (e.g., via Serial, Bluetooth, or other interfaces) to update FactorAnem.


📖 Note:
The gust threshold (Raf) is not part of this library. It remains configurable in the datalogger or user application, since it is a data analysis parameter rather than a sensor specification.


🏷️ Version
v1.0.0 – First official release.

📧 Author
Proagro Technology
Developed by Jhonny Vásquez Jiménez


