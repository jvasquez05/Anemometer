#include "Anemometer.h"

Anemometer::Anemometer(int pin, float factor) {
  _pin = pin;
  _factor = factor;
  pinMode(_pin, INPUT);
}

int Anemometer::measureInstantWind() {
  unsigned long local_c = 0;
  unsigned long tm = millis();
  int oldstate = digitalRead(_pin);

  while (millis() - tm < 500) {
    int state = digitalRead(_pin);
    if (state != oldstate) {
      local_c++;
      oldstate = state;
    }
  }

  int instWind = local_c * _factor;
  return instWind;
}

void Anemometer::setFactor(float factor) {
  if (factor > 0.0f) {
    _factor = factor;
  }
}

float Anemometer::getFactor() {
  return _factor;
}