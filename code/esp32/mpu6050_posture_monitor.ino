#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Create an MPU6050 object
Adafruit_MPU6050 mpu;

// Define the pin for the alert LED
const int ledPin = 12;

// Set your desired posture threshold in degrees.
// A larger value means you can lean back more before an alert.
// Start with 20 and adjust as needed.
const int postureThreshold = 20;

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);

  // Initialize the MPU6050 sensor
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  // Set accelerometer range
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  // Set up the LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Start with the LED off
}

void loop() {
  // Get new sensor events with the readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate the angle of lean (pitch) from the accelerometer data.
  // This calculation gives the angle in degrees from the horizontal plane.
  float angle = atan2(a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180.0 / PI;

  // Print the angle to the Serial Monitor for debugging and calibration
  Serial.print("Lean Angle: ");
  Serial.println(angle);

  // Check if the absolute angle exceeds the posture threshold
  if (abs(angle) > postureThreshold) {
    // Bad posture detected: turn the LED ON
    digitalWrite(ledPin, HIGH);
    Serial.println("Bad posture detected!");
  } else {
    // Good posture: turn the LED OFF
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short period before the next reading
  delay(200);
}