#define GPIO_OUTPUT_PIN 7

void setup() {
  // Configure the GPIO pin as output
  pinMode(GPIO_OUTPUT_PIN, OUTPUT);
  
  // Direct register manipulation for faster toggling
  uint32_t pinMask = digitalPinToBitMask(GPIO_OUTPUT_PIN);
  uint32_t port = digitalPinToPort(GPIO_OUTPUT_PIN);
  volatile uint32_t *outPort = portOutputRegister(port);

  while (true) {
    *outPort |= pinMask;  // Set pin high
    *outPort &= ~pinMask; // Set pin low
  }
}

void loop() {
  // Intentionally left empty
}