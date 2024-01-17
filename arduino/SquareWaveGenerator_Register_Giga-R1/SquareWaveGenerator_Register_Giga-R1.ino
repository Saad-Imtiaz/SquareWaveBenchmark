void setup(){
  pinMode(7, OUTPUT);
}

void loop(){
  GPIOB->ODR |= 1UL<<4; //set pin 7 high, PortB4
  if((GPIOB->IDR & 1UL<<4) == 1UL<<4){ //check if pin 7 is high, PortB4
  }
  GPIOB->ODR &= ~1UL<<4; //set pin 7 low, PortB4
}