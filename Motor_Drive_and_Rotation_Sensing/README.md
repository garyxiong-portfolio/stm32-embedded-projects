# Motor drive and rotation sensing

Drives a brushed DC motor through an L9110 driver with TIM4 channels 1 and 2. The 16 MHz timer clock, divide-by-16 prescaler, and 2000-count period produce 500 Hz PWM. Duty cycle ramps between 60% and 100% in ten-percentage-point steps held for five seconds, with both outputs disabled for five seconds before changing direction.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PB6 | TIM4 channel 1 | L9110 direction 1 PWM input |
| PB7 | TIM4 channel 2 | L9110 direction 2 PWM input |
| PB2 | EXTI2 rising-edge input | Optical rotation-sensor pulse output |
| PA2 | USART2 TX | Serial pulse-count output |
| PA3 | USART2 RX | Configured serial receive input |

## Operation

The GPIO interrupt callback increments `rpm_tick_count`; the main loop reports that cumulative count over UART as `RPM ticks`. This is a pulse counter, not a calculated RPM value or closed-loop speed controller. UART uses 115200 baud, 8 data bits, no parity, 1 stop bit, and no flow control. Use the L9110 motor supply and shared ground from the demonstrated hardware.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](Motor_Drive_and_Rotation_Sensing.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
