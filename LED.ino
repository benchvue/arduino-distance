#include <Modulino.h>

// Modules
ModulinoDistance distance;
ModulinoPixels leds;

const int BRIGHTNESS = 20;

void setup() {
  Serial.begin(9600);

  Modulino.begin();
  distance.begin();
  leds.begin();
}

void loop() {
  if (distance.available()) {

    int d = distance.get();
    Serial.print("Distance: ");
    Serial.println(d);

    updateLEDsSimple(d);

  } else {
    Serial.println("distance not available");
  }

  delay(20);
}

// SIMPLE STEP-BASED LED LOGIC
void updateLEDsSimple(int d) {
  leds.clear();

  int ledsToTurnOn = 0;

  if (d < 40)
    ledsToTurnOn = 1;
  else if (d < 80)
    ledsToTurnOn = 2;
  else if (d < 120)
    ledsToTurnOn = 3;
  else if (d < 160) 
    ledsToTurnOn = 4;
  else if (d < 200)
    ledsToTurnOn = 5;
  else if (d < 240)
    ledsToTurnOn = 6;
  else if (d < 280)
    ledsToTurnOn = 7;
  else
    ledsToTurnOn = 8;

  for (int i = 0; i < ledsToTurnOn; i++) {
    leds.set(i, GREEN, BRIGHTNESS);
  }

  leds.show();
}
