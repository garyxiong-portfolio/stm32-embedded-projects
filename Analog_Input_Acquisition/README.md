# Analog input acquisition

Samples the potentiometer wiper with ADC1 channel 9 at eight-bit resolution. The program starts a conversion, polls for completion, reads a value from 0 to 255, and sends it over USART2. A 500 ms delay separates samples.

## Connections

| MCU pin | Peripheral | Connection |
| --- | --- | --- |
| PB1 | ADC1 channel 9 | Potentiometer wiper input |
| PA2 | USART2 TX | Serial output through the onboard ST-LINK connection |
| PA3 | USART2 RX | Configured serial receive input |

## Operation

Open the serial port at 115200 baud, 8 data bits, no parity, 1 stop bit, and no flow control. The output is labeled `DIGITIZED ANALOG VALUE FOR CH9`.

## Source and build

- [Application firmware](Core/Src/main.c)
- [Pin definitions](Core/Inc/main.h)
- [CubeMX configuration](Analog_Input_Acquisition.ioc)
- [Build instructions and complete demonstration](../README.md)

This is an independent NUCLEO-F401RE firmware project. Its `.project`, `.cproject`, and `.ioc` use the folder name above so it can be imported directly into STM32CubeIDE.
