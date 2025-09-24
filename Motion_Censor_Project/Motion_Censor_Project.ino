// Active buzzer:
#include "ActiveBuzzer.h"
ActiveBuzzer activeBuzzer(4);


// IR Receiver Module:
#include "IRReceiver.h"
IRReceiver iRReceiver(6);


// MAX7219 LED Dot Matrix:
#include "DotOutput.h"
//  pin 12 is connected to the DataIn 
//  pin 10 is connected to the CLK  
//  pin 11 is connected to LOAD(CS)
DotOutput dotOutput(12, 10, 11);


// HC-SR501 PIR Sensor:
#include "PIRSensor.h"
PIRSensor pIRSensor(2);

int greenLedPin = 3;
void setup() {
  iRReceiver.begin();
  dotOutput.begin();

  pinMode(greenLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
}

void loop() {
  // ensures counter is only incremented once per detection
  static bool incremented = false;
  static bool greenLedOn = 0;

  pIRSensor.updatePirValue(); 

  int receivedValue = iRReceiver.read();

  switch (receivedValue) {
    case 1: 
      // power off
      activeBuzzer.toggle();
      pIRSensor.toggle();
      dotOutput.toggle();
      greenLedOn = !greenLedOn;
      digitalWrite(greenLedPin, greenLedOn);
      break;
    case 2: 
      // reset counter
      dotOutput.resetCounter();
      break;
    case 3:
      // volume on
      activeBuzzer.turnOn();
      break;
    case 4:
      // volume off
      activeBuzzer.turnOff();
      break;
    default:
      break;
  }

  dotOutput.writeNumber();

  if (pIRSensor.getPirValue()) {
    if (!incremented) {
      dotOutput.incrementDetectionCounter();
      incremented = true;
    }
    activeBuzzer.makeNoise();

  } else {
    incremented = false;
  }
    
}














