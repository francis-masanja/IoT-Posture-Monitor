/**
 * @file tilt_sensor_posture_monitor.ino
 * @brief Arduino sketch for a simple posture monitor using a tilt sensor.
 *
 * This sketch detects poor sitting posture by reading the state of a tilt sensor.
 * When bad posture is detected (tilt sensor is LOW), an LED is turned ON to alert the user.
 *
 * @author Francis Masanja (https://github.com/francis-masanja)
 * @date 2025-12-12
 * @license MIT License
 */

// --- Pin Definitions ---
// Define the digital pin connected to the tilt sensor.
// Uses INPUT_PULLUP, so connect one side to GND and the other to this pin.
const int tiltSensorPin = 14; 
// Define the digital pin connected to the alert LED.
// Connect one side to this pin (with a current limiting resistor) and the other to GND.
const int ledPin = 12;      

void setup() {
  // Configure the tilt sensor pin as an input with an internal pull-up resistor.
  // This means the pin will read HIGH by default, and LOW when the sensor tilts (closes the circuit to GND).
  pinMode(tiltSensorPin, INPUT_PULLUP); 
  
  // Configure the LED pin as an output.
  // This pin will be used to control the alert LED.
  pinMode(ledPin, OUTPUT);
  
  // Initialize Serial communication for debugging and status messages.
  // Set to 115200 baud rate for faster communication.
  Serial.begin(115200);
  Serial.println("Tilt Sensor Posture Monitor Initialized and Ready!");
}

void loop() {
  // Read the current state of the tilt sensor.
  // 'LOW' indicates a tilt (e.g., bad posture), 'HIGH' indicates no tilt (e.g., good posture).
  int tiltState = digitalRead(tiltSensorPin);

  // Check if the tilt sensor detects bad posture.
  // The sensor output is typically LOW when tilted (indicating a closed circuit).
  if (tiltState == LOW) {
    // Bad posture detected: turn the alert LED ON.
    digitalWrite(ledPin, HIGH);
    // Print a message to the Serial Monitor.
    Serial.println("Bad posture detected! Adjust your position.");
  } else {
    // Good posture: turn the alert LED OFF.
    digitalWrite(ledPin, LOW);
  }

  // A small delay to debounce the sensor and prevent rapid flickering of the LED.
  // Adjust this value if needed.
  delay(100);
}
