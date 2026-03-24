#ifndef ANEMOMETER_H
#define ANEMOMETER_H

#include <Arduino.h>

class Anemometer {
  public:
    // Constructor: recibe el pin del anemómetro y el factor de conversión
    Anemometer(int pin, float factor = 2.4);

    // Medir viento instantáneo (bloqueo de 500 ms)
    int measureInstantWind();

    // Configurar factor de conversión (ej. 2.4 km/h por pulso)
    void setFactor(float factor);

    // Obtener factor actual
    float getFactor();

  private:
    int _pin;
    float _factor;
};

#endif