#pragma once

#include <Arduino.h>
#include "LedControl.h"

class DotOutput {
    private:
        int detectionCounter;
        static const byte digits[10][5];
        LedControl lc;
        void displayDigit(int num);
        unsigned long digitPause;
        int displayDigitHolder = 0;
        bool on = false;
    public:
        DotOutput(int pin_data_in, int pin_load, int pin_CLK);
        ~DotOutput();
        void begin();
        int getDetectionCounter() const;
        void writeNumber();
        void incrementDetectionCounter();
        void resetCounter();
        void toggle();
};


