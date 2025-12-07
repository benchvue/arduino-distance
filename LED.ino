#include <Modulino.h>

// Modules
ModulinoDistance distance;
ModulinoPixels leds;

// LED config
const int NUM_LEDS = 8;
const int BRIGHTNESS = 20;

// Distance thresholds
const int MIN_DIST = 40;   // mm
const int MAX_DIST = 300;  // mm

void setup() {
  // Initialize Modulino I2C modules
  Modulino.begin();
  distance.begin();
  leds.begin();
}

void loop() {
  // Check if distance is available
  if (distance.available()) {
    int d = distance.get();
    updateLEDsByDistance(d);
  }
  delay(20);
}


// Turn on LEDs based on distance
void updateLEDsByDistance(int d) {
  leds.clear();   // Turn off all LEDs

  int ledsToTurnOn = 0;

  if (d < MIN_DIST) {
    // Only the leftmost LED
    ledsToTurnOn = 1;

  } else if (d > MAX_DIST) {
    // Turn all LEDs on
    ledsToTurnOn = NUM_LEDS;

  } else {
    // Map distance proportionally between MIN_DIST → MAX_DIST
    ledsToTurnOn = map(d, MIN_DIST, MAX_DIST, 1, NUM_LEDS);
  }

  // Light LEDs from left to right
  for (int i = 0; i < ledsToTurnOn; i++) {
    leds.set(i, GREEN, BRIGHTNESS);
  }

  leds.show();
}
