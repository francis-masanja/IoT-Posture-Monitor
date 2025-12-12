// Define the pins for the tilt sensor and the alert LED
const int tiltSensorPin = 14;
const int ledPin = 12;

void setup() {
  // Set the tilt sensor pin as an input
  pinMode(tiltSensorPin, INPUT_PULLUP); // Use internal pull-up resistor
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize Serial communication for debugging
  Serial.begin(115200);
  Serial.println("Tilt Sensor Posture Monitor Initialized");
}

void loop() {
  // Read the state of the tilt sensor
  int tiltState = digitalRead(tiltSensorPin);

  // The sensor output is LOW when tilted (bad posture) 
  // and HIGH when upright (good posture).
  if (tiltState == LOW) {
    // Bad posture detected: turn the LED ON
    digitalWrite(ledPin, HIGH);
    Serial.println("Bad posture detected!");
  } else {
    // Good posture: turn the LED OFF
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short period before the next reading
  delay(100);
}