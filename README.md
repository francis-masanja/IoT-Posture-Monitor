# IoT Posture Monitor

A simple, beginner-friendly IoT system that detects poor sitting posture using either a tilt sensor (for basic Arduino platforms) or an MPU6050 accelerometer (for more advanced ESP32 platforms). This project is perfect for students, office users, and makers who want a practical wellness project.

---

## 📌 Overview

This project monitors the leaning angle of a person's back. When bad posture is detected (slouching or leaning too far), the system alerts the user using an LED or buzzer. The code is organized by platform (`src/arduino` for general Arduino boards and `src/esp32` for ESP32-specific implementations) and is designed with modularity for easy understanding, maintenance, and scalability. It can be fully simulated on **Wokwi**, so no physical hardware is strictly required.

---

## 🎯 Features

-   **Platform-Specific Code:** Dedicated implementations for both basic Arduino (tilt sensor) and ESP32 (MPU6050).
-   **Modular Design:** Code structured for readability, maintainability, and easy extension.
-   Detects posture angle in real-time.
-   Alerts through LED or buzzer.
-   ESP32-based version with MPU6050 for more accurate readings.
-   Clean, simple code with explanatory comments.
-   100% online simulation supported.
-   Beginner-friendly documentation.

---

## 🧩 Components

You can choose either of the two options:

### **Option A (Basic - for Arduino/ESP32 with Tilt Sensor)**
-   Arduino Uno or ESP32 board
-   Tilt sensor module
-   LED or buzzer

### **Option B (Advanced - for ESP32 with MPU6050)**
-   ESP32 board
-   MPU6050 accelerometer/gyroscope module
-   LED or buzzer

Both versions are provided within their respective platform directories (`src/arduino` and `src/esp32`).

---

## 🗺️ System Diagram (Simplified)

```
User → Back Angle → Sensor → Microcontroller (Arduino/ESP32) → Alert Device (LED/Buzzer)
```

---

## 🧠 Pseudocode

```
initialize sensor
set posture_threshold = 20 degrees

loop:
  read angle
  if angle > posture_threshold:
    turn alert ON
  else:
    turn alert OFF
```

---

## 🧪 Simulation (Wokwi)

A Wokwi simulation link will be included here once uploaded.

---

## 💡 How It Works

1.  The microcontroller (Arduino or ESP32) reads tilt or accelerometer values from the sensor.
2.  If the detected angle is greater than the predefined good-posture range, the system activates an alert (e.g., turns on an LED or sounds a buzzer).
3.  The user adjusts their posture.
4.  The alert stops immediately once good posture is restored.

---

## 🛠️ Setup & Usage

1.  **Hardware Connection:** Connect your chosen components (microcontroller, sensor, alert device) as per the instructions in the respective code files or the included diagrams (`docs/diagrams`).
2.  **Software Setup:**
    *   Open the Arduino IDE or PlatformIO.
    *   Navigate to the relevant code file: `src/arduino/tilt_sensor_posture_monitor.ino` for the tilt sensor version or `src/esp32/mpu6050_posture_monitor.ino` for the MPU6050 version.
    *   Ensure you have the necessary board support packages and libraries installed (e.g., Adafruit MPU6050 library for the ESP32 version).
3.  **Upload Code:** Select your board and port, then upload the `.ino` file to your microcontroller.
4.  **Calibration (Optional):** Adjust the `postureThreshold` variable in the code if needed to fine-tune the sensitivity of the posture detection.
5.  **Deployment:** Attach the sensor to your upper back or chair using Velcro/tape, and test its movement to ensure the alert responds correctly.

---

## 🚀 Development

The project's code is structured to be modular and easy to extend:

*   **`src/`**: Contains all source code.
    *   **`arduino/`**: Code specifically designed for general Arduino boards, typically utilizing simpler sensors.
    *   **`esp32/`**: Code optimized for ESP32 boards, often incorporating more advanced sensors and features like Wi-Fi/Bluetooth.
*   **Modularity:** The primary code files (`.ino`) are designed to be self-contained for their respective platforms.

---

## 📦 Included in This Project

-   **`src/`**: Organized source code for Arduino and ESP32 platforms.
-   **`docs/`**: Project documentation, including diagrams and this README.
-   **`LICENSE`**: Details the project's licensing (MIT License).
-   **`.gitignore`**: Configures Git to ignore unnecessary files.
-   `README.md` (this file): Comprehensive project overview.

---

## 🏷️ License

This project is open-source and licensed under the **MIT License**. See the `LICENSE` file for more details.

---

## 👤 Author

GitHub: **[@francis-masanja](https://github.com/francis-masanja)**
Made with curiosity and creativity.