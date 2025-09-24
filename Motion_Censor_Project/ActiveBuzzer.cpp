#include "ActiveBuzzer.h"

ActiveBuzzer::~ActiveBuzzer()
{
}

void ActiveBuzzer::makeNoise()
{
    if (on) {
        // output a frequency
        for(int i = 0; i < 80; i++)
        {
          digitalWrite(pin, HIGH);
          delay(1); // wait for 1ms
          digitalWrite(pin, LOW);
          delay(1); // wait for 1ms
        }
        // output another frequency
        for(int i = 0; i < 100; i++)
        {
          digitalWrite(pin, HIGH);
          delay(2); // wait for 2ms
          digitalWrite(pin, LOW);
          delay(2); // wait for 2ms
        }
    }
}

void ActiveBuzzer::toggle() {
    on = !on;
}

void ActiveBuzzer::turnOn()
{
  on = true;
}

void ActiveBuzzer::turnOff()
{
  on = false;
}


