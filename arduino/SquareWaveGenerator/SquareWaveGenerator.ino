#include <Arduino.h>

#define PINOUT D8

unsigned long freq = 20000000; // 20 MHz
unsigned long cycle_time = 1000000 / freq;
unsigned long half_cycle = cycle_time / 2;

void setup() {
  // Set IO pin mode
  pinMode(PINOUT, OUTPUT);


  // Generate square wave
  while (true) {
    digitalWrite(PINOUT, HIGH);
    //delayMicroseconds(half_cycle);
    digitalWrite(PINOUT, LOW);
    //delayMicroseconds(half_cycle);
  }
}

void loop() {
  // Empty
}
