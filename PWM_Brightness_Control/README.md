# PWM brightness control

Fades the onboard green LED by increasing and decreasing the TIM2 channel 1 compare value from 0 to 60000 in steps of 50, with a 1 ms delay between updates. The application sets the prescaler to 0 and the auto-reload register to 60000 after timer initialization.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PA5 | TIM2 channel 1 | Onboard green LED PWM |

## Operation

The loop repeats continuously. No external LED or UART terminal is required.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](PWM_Brightness_Control.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
