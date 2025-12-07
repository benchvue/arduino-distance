#include "Modulino.h"

// Create a ModulinoDistance object
ModulinoDistance distance;

void setup() {
  Serial.begin(9600);
  // Initialize Modulino I2C communication
  Modulino.begin();
  // Detect and connect to distance sensor module
  distance.begin();
}

void loop() {
  // Check if new distance measurement is available
  if (distance.available()) {
    // Get the latest distance measurement in millimeters
    int measure = distance.get();
    Serial.println(measure);
  } else {
    Serial.println("distance not available");
  }
  delay(10);
}
