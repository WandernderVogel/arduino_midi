
# Arduino Midi Controller for Mixxx
This is an Arduino/Esp8266 Based Programmable Midi Controller for usage with ttymidi

## Table of contents
  * [General info](#general-info)
  * [Dependencies](#dependencies)
  * [Setup](#setup)
  * [Usage](#usage)
  * [Project Status](#project-status)
  * [To do](#to-do)
  * [Author](#author)



## General Information
- As there is no really good beginner Documentation for ttymidi I tried to solve this issue here
- This is an Arduino Based Midi Device that can be programmed in the source code and is fully compatible with ttymidi on Linux Devices

## Dependencies
* [ttymidi](https://github.com/okyeron/ttymidi)
* [Arduino IDE](https://www.arduino.cc/en/software/) or a similar programm

## Setup
Upload this code with you preffered IDE to your Microcontroller than start ttymidi with your Serial Port(Argument -s <your Port>) selected and start sending midi codes to your Laptop/Pc

## Usage
You can use this with the provided XML file for the DJ Programm [Mixxx](https://github.com/mixxxdj/mixxx)


## Project Status
Project is: _in progress_ 

The easiest to use Version is in the Easy Branch of this Project


## To do
- Make it easier to implement new buttons
- Make it easier to implement Potentiometers


## Author
Created by [@WandernderVogel](https://github.com/WandernderVogel) 
