# IoT Posture Monitor  
A simple, beginner-friendly IoT system that detects poor sitting posture using a tilt sensor or MPU6050 accelerometer.  
Perfect for students, office users, and makers who want a practical wellness project.

---

## 📌 Overview
This project monitors the leaning angle of a person’s back. When bad posture is detected (slouching or leaning too far), the system alerts the user using an LED or buzzer.  
It can be fully simulated on **Wokwi**, so no physical hardware is required.

---

## 🎯 Features
- Detects posture angle in real-time  
- Alerts through LED or buzzer  
- ESP32-based  
- Works with tilt sensor or MPU6050  
- Clean, simple code  
- 100% online simulation supported  
- Beginner-friendly documentation  

---

## 🧩 Components
You can use either of the two options:

### **Option A (Very Simple)**
- ESP32  
- Tilt sensor module  
- LED or buzzer  

### **Option B (More Accurate)**
- ESP32  
- MPU6050 accelerometer  
- LED or buzzer  

Both versions are provided.

---

## 🗺️ System Diagram (Simplified)

```

User → Back Angle → Sensor → ESP32 → Alert Device (LED/Buzzer)

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
1. The ESP32 reads tilt or accelerometer values.  
2. If the angle is greater than the good-posture range, the system activates an alert.  
3. User adjusts posture.  
4. Alert stops immediately.  

---

## 🛠️ Setup & Usage
1. Upload the provided `.ino` file to ESP32  
2. Adjust the posture angle in the code if needed  
3. Test movement and watch LED/buzzer respond  
4. Use Velcro/tape to attach the sensor to your upper back or chair  

---

## 📦 Included in This Project
- Source code  
- Simulation-ready circuits  
- Documentation  
- README (this file)  
- Cover image (optional)  

---

## 🏷️ License
MIT License. Feel free to use, modify, and extend.

---

## 👤 Author
GitHub: **[@francis-masanja](https://github.com/francis-masanja)**  
Made with curiosity and creativity.
