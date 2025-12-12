/**
 * @file mpu6050_posture_monitor.ino
 * @brief ESP32 sketch for a posture monitor using an MPU6050 accelerometer/gyroscope.
 *
 * This sketch calculates the lean angle from MPU6050 data to detect poor sitting posture.
 * When the absolute lean angle exceeds a predefined threshold, an LED is turned ON to alert the user.
 *
 * @author Francis Masanja (https://github.com/francis-masanja)
 * @date 2025-12-12
 * @license MIT License
 */

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h> // Required for I2C communication with MPU6050

// --- Sensor Object ---
// Create an MPU6050 object. This assumes the MPU6050 is connected via I2C.
// Default I2C address for MPU6050 is 0x68.
Adafruit_MPU6050 mpu;

// --- Pin Definitions ---
// Define the digital pin connected to the alert LED.
// Connect one side to this pin (with a current limiting resistor) and the other to GND.
const int ledPin = 12;

// --- Posture Threshold ---
// Set your desired posture threshold in degrees.
// If the absolute lean angle (pitch) exceeds this value, bad posture is detected.
// A larger value means you can lean more before an alert.
// Start with 20 degrees and adjust as needed for your specific setup and sensitivity.
const int postureThreshold = 20;

void setup() {
  // Initialize Serial communication for debugging and calibration output.
  // Set to 115200 baud rate.
  Serial.begin(115200);

  // Initialize the MPU6050 sensor.
  // This checks if the sensor is connected and responsive via I2C.
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip. Check wiring and I2C address!");
    // Loop indefinitely if the sensor is not found to indicate a critical error.
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found and Initialized!");

  // Configure the accelerometer range.
  // Options: MPU6050_RANGE_2_G, MPU6050_RANGE_4_G, MPU6050_RANGE_8_G, MPU6050_RANGE_16_G.
  // 8_G is a good starting point for general posture monitoring.
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  // Set up the LED pin as an output.
  pinMode(ledPin, OUTPUT);
  // Ensure the LED is OFF at the start.
  digitalWrite(ledPin, LOW); 
}

void loop() {
  // Get new sensor events (accelerometer, gyroscope, and temperature readings).
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate the angle of lean (pitch) from the accelerometer data.
  // This calculation uses the x-acceleration and the combined y and z acceleration
  // to determine the angle relative to the horizontal plane.
  // The atan2 function provides a full 360-degree range.
  float angle = atan2(a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180.0 / PI;

  // Print the calculated angle to the Serial Monitor for debugging and calibration.
  Serial.print("Lean Angle: ");
  Serial.println(angle);

  // Check if the absolute lean angle exceeds the predefined posture threshold.
  if (abs(angle) > postureThreshold) {
    // Bad posture detected: turn the alert LED ON.
    digitalWrite(ledPin, HIGH);
    Serial.println("Bad posture detected! Straighten up!");
  } else {
    // Good posture: turn the alert LED OFF.
    digitalWrite(ledPin, LOW);
  }

  // A short delay before taking the next reading to avoid excessive data and stabilize.
  // Adjust this value if rapid response is needed.
  delay(200);
}
