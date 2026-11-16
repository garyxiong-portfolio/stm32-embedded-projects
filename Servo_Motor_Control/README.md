# Servo motor control

Generates a 50 Hz PWM signal using TIM2 channel 1. A 16 MHz timer clock, divide-by-16 prescaler, and 20000-count period produce a 20 ms frame. The application sweeps the pulse width between 500 and 2500 microseconds in 20-microsecond steps, waiting 500 ms at each step.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PA0 | TIM2 channel 1 | Servo control signal through the 3.3 V to 5 V buffer |

## Operation

The pulse-width sweep reverses at each endpoint. Use the separate servo power supply and shared ground from the demonstrated setup.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](Servo_Motor_Control.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
