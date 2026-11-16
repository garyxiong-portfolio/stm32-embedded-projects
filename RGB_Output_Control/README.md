# RGB output control

Controls the three channels of a common-cathode RGB LED with separate GPIO outputs. The sequence is red, green, blue, and all channels off, with each state held for one second.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PA12 | GPIO output | Red channel |
| PA11 | GPIO output | Green channel |
| PA8 | GPIO output | Blue channel |

## Operation

Connect the channels through the signal buffers and individual current-limiting resistors used in the demonstrated hardware. The sequence repeats continuously.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](RGB_Output_Control.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
