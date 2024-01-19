from machine import Pin, PWM

# Configure the PWM pin (GPIO 11 is physical pin 11 on the Pico)
pwm_pin = PWM(Pin(11))

# Set the frequency
frequency = 100  # 30 MHz (this is an aspirational target and may not be achievable)
pwm_pin.freq(frequency)

# Set duty cycle to 50% to create a square wave
duty_cycle = int(0.5 * 65535)  # Duty cycle for PWM (ranges from 0 to 65535)
pwm_pin.duty_u16(duty_cycle)

