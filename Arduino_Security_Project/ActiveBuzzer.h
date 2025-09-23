#pragma once

#include <Arduino.h>

class ActiveBuzzer {
    private:
        int pin;
        bool on = false;
    public:
        ActiveBuzzer(int pin) : pin(pin) {
            pinMode(pin, OUTPUT);
        };
        ~ActiveBuzzer();
        void makeNoise();
        void toggle();
        void turnOn();
        void turnOff();
};