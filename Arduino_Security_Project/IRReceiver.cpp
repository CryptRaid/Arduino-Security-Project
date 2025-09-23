#include "IRReceiver.h"

IRReceiver::IRReceiver(int pin) : irrecv(pin)
{
}

void IRReceiver::begin() 
{
    irrecv.enableIRIn();

}

IRReceiver::~IRReceiver()
{
}

int IRReceiver::read()
{
    int return_value = -1;
    if (irrecv.decode(&results)) {

        switch(results.value)
        {      
            case 0xFFFFFFFF: // repeat code
                return_value = 0;
                break;
            
            case 0xFFA25D: // power button
                return_value = 1;
                break;

            case 0xFF6897: // 0 button
                return_value = 2;
                break;

            case 0xFF629D: // volume up button
                return_value = 3;
                break;

            case 0xFFA857: // volume down button
                return_value = 4;
                break;

            default:   
                return_value = -1;
        }
        irrecv.resume();
    }
    return return_value;
}
