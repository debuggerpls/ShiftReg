/*
	ShiftReg.cpp - Library for the SN74xx164 Serial In/Parallel Out Shift Registers
	Created by Deividas Puplauskas, July 30, 2020
	Released into the public domain.
*/

#include "Arduino.h"
#include "ShiftReg.h"

ShiftReg::ShiftReg(int pinOut, int pinClock, int pinClear)
{
  _pinOut = pinOut;
  _pinClock = pinClock;
  _pinClear = pinClear;
  _delay = -1;
}

ShiftReg::ShiftReg(int pinOut, int pinClock, int pinClear, int delay_ns)
{
  _pinOut = pinOut;
  _pinClock = pinClock;
  _pinClear = pinClear;
  _delay = delay_ns;
}

void ShiftReg::init()
{
  pinMode(_pinOut, OUTPUT);
  pinMode(_pinClock, OUTPUT);
  pinMode(_pinClear, OUTPUT);
  clear();
}

void ShiftReg::clear()
{
  digitalWrite(_pinClear, LOW);
  tick();
  digitalWrite(_pinClear, HIGH);
  tick();
}

void ShiftReg::tick()
{
  digitalWrite(_pinClock, LOW);
  if (_delay > 0)
    delayMicroseconds(_delay);
  digitalWrite(_pinClock, HIGH);
}

void ShiftReg::bitOut(int b)
{
  digitalWrite(_pinOut, b == 0 ? LOW : HIGH);
  tick();
}

void ShiftReg::byteOut(char c)
{
  for (int i = 7; i >= 0; i--)
    bitOut((c>>i)&1); 
}