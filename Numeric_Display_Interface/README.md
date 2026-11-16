# Numeric display interface

Displays an incrementing count from 0 to 99 on the assembled digital timer PCB. Integer division selects the tens digit, modulo selects the ones digit, and each digit is sent as four BCD bits. The count advances every 500 ms before wrapping to zero.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PB12 | GPIO output | Tens bit 0 |
| PB13 | GPIO output | Tens bit 1 |
| PB14 | GPIO output | Tens bit 2 |
| PB15 | GPIO output | Tens bit 3 |
| PC0 | GPIO output | Ones bit 0 |
| PC1 | GPIO output | Ones bit 1 |
| PC2 | GPIO output | Ones bit 2 |
| PC3 | GPIO output | Ones bit 3 |

## Operation

Route the eight signals through the voltage-translation buffers to the timer board inputs. Power the display board at 5 V and hold it in LOAD mode so its existing decoders display the MCU-supplied digits.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](Numeric_Display_Interface.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
