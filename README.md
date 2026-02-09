# mikroC Pressure Sensor UART Project

## Project Overview
This repository contains an embedded systems project for pressure measurement using the Pressure 8 Click board from MikroElektronika.  The project is developed in C using mikroC PRO for MCU, utilizes mikroSDK libraries, and communicates sensor data via UART.

This project is intended as an educational and portfolio demonstration of pressure sensor interfacing using mikroC and mikroSDK.  It focuses on sensor communication and data transmission rather than product-level optimization or calibration.

## Hardware Used
- Pressure 8 Click (MikroElektronika)  
  - Digital pressure sensor  
  - I2C communication  
- mikroBUS-compatible microcontroller board  
- CodeGrip programmer/debugger  
- USB-UART Click for serial monitoring

---

## Software Requirements
- mikroC PRO for MCU  
- mikroSDK  
- CodeGrip Suite (for programming and debugging)  
- Serial terminal

---

## Repository Structure

```
mikroc-pressure-sensor-uart/
├── pressure_driver.c        # Pressure sensor driver source
├── pressure_driver.h        # Pressure sensor driver header
├── pressure_main.c          # Main application code
├── Click_Pressure8_*        # Pressure 8 Click library files
├── Click_USB_UART_*         # USB-UART Click library files
├── History/Generated/       # Auto-generated mikroC project files
└── README.md                # Project documentation
```

Most folders (like `Click_*` and `History/Generated/`) include:
- driver code provided by mikroSDK
- example project files
- auto-generated IDE files
You do not need to separately download those to clone or build — they are already included.

---

## How the Project Works
1. The microcontroller initializes I2C and sensor drivers.
2. Pressure 8 Click is configured and reset (if necessary).
3. The system reads pressure sensor values over I2C periodically.
4. Sensor measurements are processed and optionally sent to UART.
5. A host PC/serial monitor can display live sensor data.

---

## Build & Run (on Hardware)
1. Open the project in mikroC PRO for MCU. Make sure the correct MCU/board is selected.
2. Connect Pressure 8 Click to mikroBUS socket.
3. Connect CodeGrip to the development board and PC.
4. Build the project in mikroC: Project → Build
5. Flash the firmware using CodeGrip: Program → Load → Program
6. Open a serial terminal to monitor UART outputs.
