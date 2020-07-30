#include <ShiftReg.h>

// pin defines, can be any digital pin
#define PIN_OUT 5
#define PIN_CLOCK 6
#define PIN_CLEAR 4

// creates object to control shift register 
ShiftReg reg = ShiftReg(5, 6, 4);
int count = 0;

void setup() {
  // initializes arduino pins and clears shift register outputs
  reg.init();
}

void loop() {
  // shift outs the count value (MSB first)
  reg.byteOut(count++);
  delay(500);
}
