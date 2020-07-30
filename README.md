## ShiftReg.h - Library for the SN74xx164 Serial In/Parallel Out Shift Registers

#### Simple Counter example is available!

#### Extra wiring for Shift register:
* Connect Pin 2 (Serial input B) using 1k resistor to VCC

#### Wiring Shift register to Arduino:
* Connect shift register's Pin 1 (Serial input A) ---> to any of Arduino's digital pins
* Connect shift register's Pin 8 (Clock) ---> to any of Arduino's digital pins
* Connect shift register's Pin 9 (Clear) ---> to any of Arduino's digital pins

#### Constructors:
* ShiftReg(int pinOut, int pinClock, int pinClear);
* ShiftReg(int pinOut, int pinClock, int pinClear, int delay_ns);

#### 
* void clear(); // sets all register pins to LOW
* void tick(); // one clock tick
* void bitOut(int b); // puts out the *b* value (1 or 0) to the shift register
* void byteOut(char c); // puts out the *c* value (8 bits, MSB first) to the shift register
* void init(); // initializes Arduino pins and clears register output pins