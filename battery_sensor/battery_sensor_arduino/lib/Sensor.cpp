#include "Arduino.h"
#include "Sensor.h"


Sensor::Sensor(int pinVoltage, int pinCurrent)
{
  _pinVoltage = pinVoltage;
  _pinCurrent = pinCurrent;
}

float Sensor::getVoltage()
{
  return _voltage;
}

float Sensor::getCurrent()
{
  return _current;
}

int Sensor::getSOC()
{
  return _SOC;
}


int Sensor::averageAnalog(int pin)
{
  int v=0;
  for(int i=0; i<4; i++) v+= analogRead(pin);
  return v/4;
}

float Sensor::realVoltage(int analogValue)
{
  float realValue = analogValue/13.8; //Sensor 0-50V -> 0-3.3V ; Arduino 0-5V -> 0-1023
  return realValue;                   //1023/5*3.3/50=13.5 V-1 ; through experience 13.8 V-1
}

float Sensor::realCurrent(int analogValue)
{
  float realValue = analogValue/7.5; //Sensor 0-90A -> 0-3.3V ; Arduino 0-5V -> 0-1023
  return realValue;                  //1023/5*3.3/90=7.5 A/V ; no experience
}


void Sensor::estimateSOC() //TODO
{
  _SOC=100;
}


void Sensor::updateMeasures()
{
  _voltage = realVoltage(averageAnalog(_pinVoltage));
  _current = realCurrent(averageAnalog(_pinCurrent));
  this->estimateSOC();
}


