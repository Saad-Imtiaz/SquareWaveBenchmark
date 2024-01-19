// Define the GPIO and pin number
#define GPIO_PORT GPIOA
#define GPIO_PIN GPIO_PIN_9

void setup() {
  // Enable the clock for GPIOA
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Configure PA9 as output
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Push-pull output mode
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH; // Very high speed
  HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

  // Endless loop to toggle the pin as fast as possible
  while (true) {
    GPIO_PORT->ODR ^= GPIO_PIN; // Toggle the pin
  }
}

void loop() {
  // Not used in this example
}
