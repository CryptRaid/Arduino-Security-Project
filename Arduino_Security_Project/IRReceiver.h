#pragma once

#include <Arduino.h>
#include "IRremote.h"

class IRReceiver
{
private:
    IRrecv irrecv;
    decode_results results; 
    unsigned long lastValue = 0;

public:
    IRReceiver(int pin);
    void begin();
    ~IRReceiver();
    int read();
};

