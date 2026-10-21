# STM32 Embedded Projects

Embedded C projects developed by Gary Xiong for ECE 298 at the University of Waterloo. The projects use the NUCLEO-F401RE board, STM32CubeIDE, STM32 HAL, and direct timer-register updates to explore GPIO, PWM, motor control, UART, and ADC peripherals.

## Featured project: PWM DC motor controller

[Watch the hardware demonstration](https://youtube.com/shorts/oLboKMMLnjE)

The [PWM_DC_Motor_Control](PWM_DC_Motor_Control) project drives a brushed DC motor through an L9110 motor driver. TIM3 channels 1 and 3 provide direction-selective PWM on PA6 and PB0. A 16 MHz timer clock, divide-by-16 prescaler, and 2,000-count period produce a nominal 500 Hz signal.

The program ramps duty cycle from 60% to 100% in 10-percentage-point steps, then back to 60%, holding each step for five seconds. Both outputs are set to zero for five seconds before reversing direction. The driver uses a separate 6 V supply with a common ground to the Nucleo. This is open-loop motor control without speed feedback.

## Projects

| Folder | Focus |
| --- | --- |
| [Blink_Test](Blink_Test) | GPIO LED output with 250 ms software delays |
| [Timer_Blink_Test](Timer_Blink_Test) | Hardware-timed LED output using TIM2 |
| [PWM_Blink_Test](PWM_Blink_Test) | LED brightness fading by changing PWM duty cycle |
| [PWM_DC_Motor_Control](PWM_DC_Motor_Control) | Bidirectional brushed DC motor control through an L9110 |
| [UART_Test](UART_Test) | Serial prompts and interrupt-driven character echo |
| [ADC_Test](ADC_Test) | Eight-bit analog sampling with UART reporting |

## Open and build

1. Install STM32CubeIDE with STM32F4 support.
2. Use **File > Import > Existing Projects into Workspace**, select this repository, and import the desired projects.
3. Open a project's `.ioc` file to inspect its pin, clock, and peripheral configuration. The saved configurations use STM32CubeF4 firmware V1.28.3.
4. Build the project. Connect the NUCLEO-F401RE through ST-LINK and create a debug configuration to program the board.

Application code is in `Core/Src/main.c`; headers, startup code, linker scripts, CubeMX settings, and the required vendor drivers are included. Generated Debug/Release outputs, local launch configurations, and Eclipse workspace metadata are excluded. No fresh compilation or hardware test was performed for this repository setup.

## Attribution

These are coursework implementations using STM32-generated scaffolding and vendor libraries. STMicroelectronics and Arm license files are preserved within the `Drivers` directories. Those components retain their original licenses; no blanket license is applied to course or vendor materials.
