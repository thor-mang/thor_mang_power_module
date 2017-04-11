#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"


class Sensor
{

  public:
    Sensor(int pinVoltage, int pinCurrent);

    float getVoltage();
    float getCurrent();
    int getSOC();

    static int averageAnalog(int pin);
    static float realVoltage(int analogValue);
    static float realCurrent(int analogValue);

    void estimateSOC();

    void updateMeasures();



  private:
    int _pinVoltage;
    int _pinCurrent;

    float _voltage;
    float _current;
    int _SOC;

    int _currentSum;
    int _integrationDuration;
};

#endif
