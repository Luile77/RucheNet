#include "HX711.h"

#define DOUT  11
#define CLK   12

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); // Réinitialiser la balance à zéro
}

void loop() {
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.println(" kg");

  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a') {
      scale.set_scale(scale.get_scale() * 1.1); // Augmenter le facteur de calibration
    } else if (temp == '-' || temp == 'z') {
      scale.set_scale(scale.get_scale() * 0.9); // Diminuer le facteur de calibration
}
}
}