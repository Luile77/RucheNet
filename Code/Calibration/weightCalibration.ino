#include "HX711.h"
#include <MKRWAN.h>

// Paramètres du capteur HX711
#define DOUT  11
#define CLK   12

HX711 scale;

// Remplacez par vos valeurs d'AppEUI et AppKey de TTN// Configuration LoRaWAN
String appEui = "0000000000000101";
String appKey = "19F232EB81BF5C677FC2A5095FFC7142";


LoRaModem modem;

float calibration_factor = 29530; // Ajustez ce paramètre selon votre capteur

bool connected = false;

void setup() {
  Serial.begin(115200);
  while (!Serial); // Attente que le port série soit ouvert

  // Initialisation HX711
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare(); // Remettre le poids à zéro
  
  // Initialisation LoRaWAN
  if (!modem.begin(EU868)) {
    Serial.println("Échec de l'initialisation du modem LoRa");
    while (1);
  }
  connectToLoRaWAN();
}

void loop() {
  if (connected) {
    float weight = scale.get_units(5); // Mesure du poids
    Serial.print("Poids: ");
    Serial.print(weight, 2); // Affichage avec deux décimales
    Serial.println(" kg");

    // Encodage et envoi du poids
    uint8_t dataToSend[4];
    encodeAndSendWeight(weight, dataToSend);

    delay(10000); // Envoi toutes les 10 secondes
  } else {
    connectToLoRaWAN();
  }
}

void connectToLoRaWAN() {
  Serial.print("Tentative de connexion à LoRaWAN...");
  if (modem.joinOTAA(appEui, appKey)) {
    connected = true;
    Serial.println("Connecté à LoRaWAN");
  } else {
    Serial.println("Échec de connexion, réessayer...");
  }
}

void encodeAndSendWeight(float weight, uint8_t *data) {
  int32_t weightInt = (int32_t)(weight * 100); // Convert the weight to an integer form for sending
  data[0] = (weightInt >> 24) & 0xFF;
  data[1] = (weightInt >> 16) & 0xFF;
  data[2] = (weightInt >> 8) & 0xFF;
  data[3] = weightInt & 0xFF;

  modem.beginPacket(); // Begin the LoRa packet
  modem.write(data, 4); // Write the weight data to the packet
  if (modem.endPacket(true)) { // End the packet with an async request
    Serial.println("Weight data sent successfully!");
  } else {
    Serial.println("Failed to send weight data.");
  }
}
