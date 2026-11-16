# User controls and status indication

Reads the onboard blue push button and drives the onboard green LED. The button is active low: holding it turns the LED on, and releasing it turns the LED off.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PC13 | GPIO input | Onboard push button |
| PA5 | GPIO output | Onboard green LED |

## Operation

The input is polled continuously. This implementation uses hold-to-light behavior rather than a latched toggle.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](User_Controls_and_Status_Indication.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
