#include "DotOutput.h"


const byte DotOutput::digits[10][5] = {
    {B01111110, B10000001, B10000001, B10000001, B01111110}, // 0
    {B00000000, B00000010, B11111111, B00000000, B00000000}, // 1
    {B11100010, B10010001, B10001001, B10000101, B10000010}, // 2
    {B01000010, B10000001, B10001001, B10001001, B01110110}, // 3
    {B00011111, B00010000, B00010000, B00010000, B11111111}, // 4
    {B10011111, B10010001, B10010001, B10010001, B11110001}, // 5
    {B11111111, B10010001, B10010001, B10010001, B11110001}, // 6
    {B00000001, B00000001, B00000001, B00000001, B11111111}, // 7
    {B01111110, B10010001, B10010001, B10010001, B01111110}, // 8
    {B00011110, B00100001, B00100001, B00100001, B11111111}  // 9
};


DotOutput::DotOutput(int pin_data_in, int pin_CLK, int pin_load) : detectionCounter(0), lc(pin_data_in, pin_CLK, pin_load, 1), digitPause(millis())
{
       
}

void DotOutput::begin() 
{
  // LED Dot Matrix
    lc.shutdown(0, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0, 8);
    /* and clear the display */
    lc.clearDisplay(0);

    writeNumber();
}

DotOutput::~DotOutput()
{
}


int DotOutput::getDetectionCounter() const
{
    return this->detectionCounter;
}

void DotOutput::writeNumber()
{
  
  if (on) {
    if (detectionCounter <= 9) {
      displayDigit(detectionCounter);
      return;
    } 

    unsigned long currentMillis = millis();
    
    if (detectionCounter <= 99) {
      int firstDigit = detectionCounter / 10;
      int secondDigit = detectionCounter % 10;
      int digitDelay = 400;

      // first digit
      if (displayDigitHolder == 0 && currentMillis - digitPause >= 1200) {
        displayDigit(firstDigit);
        digitPause = currentMillis;
        displayDigitHolder = 1;
      
      } else if (displayDigitHolder == 1 && currentMillis - digitPause >= digitDelay) {
        lc.clearDisplay(0);
        digitPause = currentMillis;
        displayDigitHolder = 2; 
        
      } else if (displayDigitHolder == 2 && currentMillis - digitPause >= digitDelay) {
        // second digit
        displayDigit(secondDigit);
        digitPause = currentMillis;
        displayDigitHolder = 3;  

      } else if (displayDigitHolder == 3 && currentMillis - digitPause >= digitDelay) {
        lc.clearDisplay(0);
        digitPause = currentMillis;
        displayDigitHolder = 0; 
      }
    }
  }
}

void DotOutput::displayDigit(int num) {
  // dislpay digit
  for (int row = 0; row <= 4; row++) {
    lc.setRow(0, row, digits[num][row]);  
  }
}

void DotOutput::incrementDetectionCounter()
{
    if (detectionCounter < 99) detectionCounter++;
}

void DotOutput::resetCounter()
{
  detectionCounter = 0;
  writeNumber();
}


void DotOutput::toggle() 
{
  on = !on;

  if (on) {
    writeNumber();
  } else {
    lc.clearDisplay(0);
  }
}