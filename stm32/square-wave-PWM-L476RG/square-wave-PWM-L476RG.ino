#include <Arduino.h>

const int pwmPin = PA1; // Change this to the PWM-capable pin you want to use
const long frequency = 10000000; // Hz
const int resolution = 8; // 8-bit resolution
const int dutyCycle = 128; // 50% duty cycle for 8-bit resolution (128 out of 256)

void setup() {
  // Configure the PWM pin
  pinMode(pwmPin, OUTPUT);

  // Set PWM frequency (applies to all PWM pins)
  analogWriteFrequency(frequency);

  // Set PWM resolution
  analogWriteResolution(resolution);

  // Start PWM on the pin with the specified duty cycle
  analogWrite(pwmPin, dutyCycle);
}

void loop() {
  // Nothing to do here
}
