# Ultrasonic ranging

Sends a short trigger pulse to the HC-SR04 and captures both echo edges with TIM3 channel 1 interrupts. The timer counts in microseconds. The program accounts for the 16-bit counter wrapping and divides the measured pulse width by 58 to obtain whole-centimetre distance, then prints the pulse width and distance over USART2.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PB8 | GPIO output | HC-SR04 TRIG |
| PA6 | TIM3 channel 1 input capture | HC-SR04 ECHO after voltage-level conversion |
| PA2 | USART2 TX | Serial distance output |
| PA3 | USART2 RX | Configured serial receive input |

## Operation

The trigger uses the calibrated 13-iteration software delay in the supplied implementation. The program waits for both echo edges without a timeout and delays 60 ms after a completed measurement. Use an MCU-compatible ECHO level and a common ground. UART uses 115200 baud, 8 data bits, no parity, 1 stop bit, and no flow control.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](Ultrasonic_Ranging.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
