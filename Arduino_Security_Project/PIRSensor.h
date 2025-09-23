#pragma once

#include <Arduino.h>

class PIRSensor
{
private:
    int pirPin; // Input for HC-S501
    int pirValue; // Place to store read PIR Value
    bool on = false;
public:
    PIRSensor(int pirPin);
    ~PIRSensor();
    void begin();
    int getPirValue() const;
    void updatePirValue();
    void toggle();

};


