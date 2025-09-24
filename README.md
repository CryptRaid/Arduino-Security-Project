# Arduino-Security-Project

## Overview
#### This project is a custom Arduino device that I planned, designed, programmed, and soldered entirely myself. It demonstrates hardware-software integration, C++ programming, and problem-solving in building a fully functional electronic project. 
#### When the PIR sensor detects movement, the device:
- Triggers an alarm (active buzzer)
- Increments a digital counter displayed on a dot matrix module
#### The project was developed with a strong focus on object-oriented programming in C++, efficient hardware control, and systematic debugging of both electrical and software issues.
## Features
- Works with multiple components connected to an Arduino via a perfboard (or breadboard)
- Displays two-digit numbers on a dot matrix module
- Uses IR receiver and PIR sensor modules for input detection
- Fully programmed in C++ using object-oriented principles

## Components / Hardware Required
- Arduino nano (or compatible board)
- Dot Matrix Display Module
- IR Receiver Module
- PIR Sensor
- Active Buzzer
- Red and Green LEDs
- Perfboard, wires, resistors
- Soldering tools

## Software / Libraries Required
- Arduino IDE
- Libraries: LedControl, IRremote, Arduino
  
## How to Run
- Connect all components to the Arduino
- Open the Arduino IDE and load the Motion_Sensor_Project.ino file
- Install all required libraries
- Upload the code to the Arduino board

## How to Use
- Press power button on remote to turn on device
- Press 0 to reset counter on display
- Press VOL- to mute the buzzer
- Press VOL+ to unmute the buzzer
- Press power button to turn off device

## Skills Demonstrated / Learned
- Circuit building with complex electronic components
- Assembling circuit with microscope and tweezers
- Hardware control via Arduino programming
- Soldering and assembly of electronic components
- Debugging both hardware and software issues
- Independent planning, design, and implementation of a working project

## Problems Solved
- IR receiver module malfunction: Diagnosed with a multimeter, desoldered faulty connection, and resoldered.
- Two-digit display issue on dot matrix module: Implemented timed switching between digits.
- Incorrect PIR sensor header pins: Replaced with longer pins for proper soldering.
- LED connected to invalid analog pin: Resoldered to a correct output pin.

