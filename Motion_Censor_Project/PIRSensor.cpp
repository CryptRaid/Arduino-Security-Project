#include "PIRSensor.h"

PIRSensor::PIRSensor(int pirPin)  : pirPin(pirPin)
{
    
}

void PIRSensor::begin()
{
    pinMode(pirPin, INPUT);
}

PIRSensor::~PIRSensor()
{
}

int PIRSensor::getPirValue() const
{
    return this->pirValue;
}

void PIRSensor::updatePirValue()
{
    if (on) {
        pirValue = digitalRead(pirPin);
    } else {
        pirValue = 0;
    }
    
}

void PIRSensor::toggle()
{
    on = !on;
}