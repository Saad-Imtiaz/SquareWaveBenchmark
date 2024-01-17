#include "stm32h7xx_hal.h"

volatile uint32_t* gpio_a_mode_reg = (volatile uint32_t*) 0x58020000;
volatile uint32_t* gpio_a_output_data_reg = (volatile uint32_t*) (0x58020000 + 0x18);

void setup() {
  // Set LED pin to output mode
  *gpio_a_mode_reg |= (1 << (2*5));
}

void loop() {
  while (true) {
    // Turn LED on
    *gpio_a_output_data_reg |= (1 << 5);
    delay(0.01);
    // Turn LED off
    *gpio_a_output_data_reg &= ~(1 << 5);
  }
}