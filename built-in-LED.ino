#include "Arduino_LED_Matrix.h"
#include <Modulino.h>

ArduinoLEDMatrix matrix;
ModulinoDistance distance;

// 8x12 LED frame buffer
uint8_t frame[8][12] = {0};

void setup() {
  Serial.begin(9600);

  matrix.begin();
  Modulino.begin();
  distance.begin();
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

// Updated step logic
void updateLEDsSimple(int d) {

  clearFrame();

  int columnsOn = 0;

  if (d < 40)        columnsOn = 1;
  else if (d < 80)   columnsOn = 2;
  else if (d < 120)  columnsOn = 3;
  else if (d < 160)  columnsOn = 4;
  else if (d < 200)  columnsOn = 5;
  else if (d < 240)  columnsOn = 6;
  else if (d < 280)  columnsOn = 7;
  else if (d < 300)  columnsOn = 8;
  else if (d < 340)  columnsOn = 9;
  else if (d < 380)  columnsOn = 10;
  else if (d < 420)  columnsOn = 11;
  else               columnsOn = 12;  // Full bar

  // Light LEDs on TOP ROW (row 0)
  for (int x = 0; x < columnsOn; x++) {
    frame[0][x] = 1;
  }

  matrix.renderBitmap(frame, 8, 12);
}

void clearFrame() {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 12; x++) {
      frame[y][x] = 0;
    }
  }
}
