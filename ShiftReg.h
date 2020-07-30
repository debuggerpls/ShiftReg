/*
	ShiftReg.h - Library for the SN74xx164 Serial In/Parallel Out Shift Registers
	Created by Deividas Puplauskas, July 30, 2020
	Released into the public domain.
*/

#ifndef SHIFTREG_H
#define SHIFTREG_H

class ShiftReg{
  public:
    ShiftReg(int pinOut, int pinClock, int pinClear);
    ShiftReg(int pinOut, int pinClock, int pinClear, int delay_ns);

    void clear();
    void tick();
    void bitOut(int b);
    void byteOut(char c);
    void init();
  private:    
    int _pinClear;
    int _pinClock;
    int _pinOut;
    int _delay;
};

#endif