#include <MKRWAN.h>
#include <DHT22.h>

// Remplacez par vos valeurs d'AppEUI et AppKey de TTN
String appEui = "0000000000000101";
String appKey = "19F232EB81BF5C677FC2A5095FFC7142";

LoRaModem modem;
bool connected = false;
int err_count = 0;
short con = 0;
DHT22 dht22(2);       // La broche de données du DHT22

//#define DHTTYPE DHT22 // Type de capteur DHT utilisé (DHT11, DHT21, DHT22)
//DHT dht22(DHTPIN, DHTTYPE); // Utilisation de DHT22

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Starting LoRa with DHT22");

  // Initialisation du modem LoRa
  modem.begin(EU868);

  // Initialisation du capteur DHT22
  //dht22.begin();

  delay(1000);
}

void loop() {
  if (!connected) {
    Serial.print("Joining LoRa network: ");
    Serial.println(++con);
    if (modem.joinOTAA(appEui, appKey)) {
      connected = true;
      modem.minPollInterval(60); // Set the minimum polling interval
      Serial.println("Connected to LoRa network");
      modem.dataRate(5); // Use SF7
      delay(100);
      err_count = 0;
    } else {
      Serial.println("Failed to join LoRa network. Retrying...");
      delay(10000); // Wait before retrying
      return;
    }
  }

  if (connected) {
    // Read humidity and temperature values
    //float humidity = dht22.readHumidity(); // Utilisation de dht22 au lieu de dht
    //float temperature = dht22.readTemperature(); // Utilisation de dht22 au lieu de dht

     float t = dht22.getTemperature();
  float h = dht22.getHumidity();
   

    // Convert the values to integers for transmission
    int16_t hum = (int16_t)(h * 100);
    int16_t temp = (int16_t)(t * 100);

    // Send data via LoRaWAN
    modem.beginPacket();
    modem.write((uint8_t*)&hum, sizeof(hum));
    modem.write((uint8_t*)&temp, sizeof(temp));

    err_count = modem.endPacket(true); // true to send as confirmed uplink
    if (err_count <= 0) {
      Serial.println("Failed to send message");
      connected = false; // Reset the connection if there is an error
    } else {
      Serial.println("Message sent successfully");
      delay(20000); // Wait for the duty cycle
    }
  }
}
