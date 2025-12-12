# IoT Posture Monitor Documentation

This document provides a comprehensive guide to building, programming, and using the IoT Posture Monitor.

## 1. Project Overview

This project is a simple, beginner-friendly IoT system that detects poor sitting posture. When it senses that the user is slouching or leaning at a bad angle, it provides a real-time alert using an LED or a buzzer. It's an excellent project for students, office workers, and anyone interested in a practical wellness gadget.

The entire system can be simulated on Wokwi, meaning you don't need to purchase physical hardware to try it out.

## 2. Features

- Real-time posture angle detection
- User alerts via LED or buzzer
- Based on the versatile ESP32 microcontroller
- Supports two sensor options: a simple tilt sensor or a more accurate MPU6050 accelerometer
- Clean, simple, and well-documented code
- 100% online simulation supported
- Beginner-friendly

## 3. Hardware Requirements

You have two options for building this project.

### Option A: Simple Version (Tilt Sensor)

- **ESP32 Development Board**: Any common ESP32 board will work.
- **Tilt Sensor Module**: A simple switch-based tilt sensor (like SW-520D).
- **LED or Buzzer**: For providing the alert.
- **Breadboard and Jumper Wires**: For connecting the components.

### Option B: Accurate Version (MPU6050)

- **ESP32 Development Board**: Any common ESP32 board will work.
- **MPU6050 Gyroscope/Accelerometer Module**: This provides more precise angle measurements.
- **LED or Buzzer**: For providing the alert.
- **Breadboard and Jumper Wires**: For connecting the components.

## 4. Software and Installation

To program the ESP32, you will use the Arduino IDE.

### 4.1. Install Arduino IDE

1.  Go to the official Arduino website: [arduino.cc/en/software](https://www.arduino.cc/en/software)
2.  Download and install the Arduino IDE version suitable for your operating system (Windows, macOS, or Linux).

### 4.2. Set Up ESP32 in Arduino IDE

1.  Open the Arduino IDE.
2.  Go to **File > Preferences**.
3.  In the "Additional Board Manager URLs" field, paste the following URL:
    ```
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    ```
4.  Click **OK**.
5.  Go to **Tools > Board > Boards Manager...**.
6.  Search for "esp32" and install the package by Espressif Systems.
7.  Once installed, select your ESP32 board from the **Tools > Board** menu (e.g., "ESP32 Dev Module").

### 4.3. Install Required Libraries

#### For Option A (Tilt Sensor)

No special libraries are needed.

#### For Option B (MPU6050)

You will need the Adafruit MPU6050 library and its dependencies.

1.  Open the Arduino IDE.
2.  Go to **Sketch > Include Library > Manage Libraries...**.
3.  Search for "Adafruit MPU6050" and click **Install**.
4.  The IDE may ask you to install dependencies like "Adafruit Unified Sensor" and "Adafruit BusIO". Click **Install All**.

## 5. Wiring and Assembly

Here are the wiring instructions for both options.

### Option A: Tilt Sensor Wiring

| Tilt Sensor | ESP32 Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| DO (Digital Out) | GPIO 14 |
| **Component** | **ESP32 Pin** |
| LED (Anode) | GPIO 12 |
| LED (Cathode)| GND (via resistor)|

*The LED's longer leg (anode) connects to GPIO 12. The shorter leg (cathode) connects to a resistor (e.g., 220 Ohm), which then connects to GND.*

### Option B: MPU6050 Wiring

The MPU6050 uses the I2C communication protocol.

| MPU6050 Pin | ESP32 Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| SCL (Serial Clock) | GPIO 22 (SCL) |
| SDA (Serial Data) | GPIO 21 (SDA) |
| **Component** | **ESP32 Pin** |
| LED (Anode) | GPIO 12 |
| LED (Cathode)| GND (via resistor)|

*The LED's longer leg (anode) connects to GPIO 12. The shorter leg (cathode) connects to a resistor (e.g., 220 Ohm), which then connects to GND.*


## 6. Code for the Project

You can find the code for both versions in the `code/` directory.

### Code for Option A (Tilt Sensor)

The code for the tilt sensor version can be found in `code/posture.ino`.

### Code for Option B (MPU6050)

The code for the MPU6050 version can be found in `code/Esp32_version.ino`.

## 7. Uploading and Usage

1.  **Open the Code**: Open the appropriate code (Tilt Sensor or MPU6050) in your Arduino IDE.
2.  **Connect the ESP32**: Connect your ESP32 board to your computer via a USB cable.
3.  **Select the Port**: Go to **Tools > Port** and select the correct COM port for your ESP32.
4.  **Upload**: Click the "Upload" button (the right-arrow icon) in the Arduino IDE.
5.  **Test**: Once uploaded, the device will start monitoring your posture.
    *   Attach the sensor to your upper back or the back of your chair using tape or Velcro.
    *   Sit in a good posture. The LED should be OFF.
    *   Slouch or lean back. The LED should turn ON, alerting you to correct your posture.
    *   You can adjust the `postureThreshold` variable in the MPU6050 code to make the detection more or less sensitive.

This concludes the setup and usage guide for the IoT Posture Monitor.