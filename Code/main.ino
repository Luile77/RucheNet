#include <MKRWAN.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DFRobot_SHT20.h>
#include "Wire.h"
#include "SHT31.h"

#include <Wire.h>


#define address 0x23

SHT31 sht;


// Définition des broches pour les capteurs DHT22
#define DHTPIN_sensor_int 2

#define DHTTYPE DHT22 // Type DHT22


//Initialisation SHT20
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR); // Déclaration de l'objet sht20

//constantes pour la lecture de la batterie
const int analogPin = A0;
const int numReadings = 100; // Nombre de lectures pour la moyenne

// Def des sensors DS
#define ONE_WIRE_BUS A3 // Broche de données pour les capteurs DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Initialisation des objets DHT
DHT DHT22_Temp_int(DHTPIN_sensor_int, DHTTYPE);



//TPL
#define TPL5110_DELAY_PIN  2
#define TPL5110_DONE_PIN  4

//Constantes Poids
#include "HX711.h"
#define LOADCELL_DOUT_PIN  6
#define LOADCELL_SCK_PIN  7
HX711 scale;
float calibration_factor = 13660; // Ce facteur doit être ajusté selon votre balance



//Constantes Lora
LoRaModem modem;
bool connected;
int err_count;
short con;
String appEui = "0000000000000101";                   //IDs connexions Lora
String appKey = "19F232EB81BF5C677FC2A5095FFC7142";

void setup() {

  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println("Init");

    
  
  Wire.begin();
  Wire.setClock(100000);
  sht.begin(); // Appel de la fonction begin() sans arguments
  sht20.initSHT20(); // Initialisation du capteur SHT20
  delay(100);
  sht20.checkSHT20();
Serial.println("Capteur sht20 initialisé.");

// Initialisation des capteurs DS18B20
  sensors.begin();
 Serial.println("Capteurs DS18B20 initialisés.");

  //Initialisation des catpeurs DHT
  DHT22_Temp_int.begin();
  //DHT22_Temp_ext.begin();
Serial.println("Capteur DHT22 INTERNE initialisé.");
 


  //Initsialisation capteur poids

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
 scale.set_scale(calibration_factor);
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.println(zero_factor);
  Serial.println("Capteure POIDS initialisé.");
  //Initialisation pour LoRa
  modem.begin(EU868);
  delay(1000);
  connected = false;
  err_count = 0;
  con = 0;
  Serial.println("Initialisation POIDS terminée.");
}

void loop() {

  risingEdgeDelay();
  delay(1000);
  uint16_t Poids = round(getPoids() * 100);
  delay(100);
 uint16_t Temp_DHT22_int = round(getTempInt() * 100);
  delay(100);
  uint16_t Hum_DHT22_int = round(getHumInt() * 100);
  delay(100);
  uint16_t temp_DS18B20_N1 = round(getTemp_DS18B20_N1() * 100);
  delay(100);
  uint16_t temp_DS18B20_N2 = round(getTemp_DS18B20_N2() * 100);
  delay(100);
  uint16_t temp_DS18B20_N3 = round(getTemp_DS18B20_N3() * 100);
  delay(100);
  uint16_t batterie = round(getBatterie() * 100);
  delay(100);
  //uint16_t Lum = round(getLum() * 100);
  uint16_t humidity_SHT20 = round(getHumidity_SHT20()*100);
  delay(100);
  uint16_t temp_SHT20 = round(getTemperature_SHT20()*100);
  delay(100);
 sht.read();
  

  
  



  // Tentative de connexion si non connecté
  if (!connected) {
    Serial.print("Join test : ");
    Serial.println(++con);
    if (modem.joinOTAA(appEui, appKey)) {
      connected = true;
      modem.minPollInterval(60);
      Serial.println("Connected");
    } else {
      Serial.println("Connection failed");
      delay(1000);  // Attendre 10 secondes avant de réessayer
      return;  // Sortir de la fonction loop pour réessayer
    }
  }

  // Envoi des données si connecté
  if (connected) {
    modem.dataRate(5);
    modem.beginPacket();
    modem.write(Temp_DHT22_int);
    modem.write(Hum_DHT22_int);
    modem.write(temp_DS18B20_N1);
    modem.write(temp_DS18B20_N2);
    modem.write(temp_DS18B20_N3);
    modem.write(batterie);
    modem.write(Poids);
    modem.write(temp_SHT20);
    modem.write(humidity_SHT20);
    
    


    

    // Affichage des valeurs sur le moniteur série
    Serial.print("Poids : ");
    Serial.println((float)Poids / 100.00);
    Serial.print("Temp int : ");
    Serial.println((float)Temp_DHT22_int / 100.00);
    Serial.print("Hum int : ");
    Serial.println((float)Hum_DHT22_int / 100.00);
    Serial.print("Temperature DS18B20 n°1 : ");
    Serial.println((float)temp_DS18B20_N1 / 100.0);
    Serial.print("Temperature DS18B20 n°2 : ");
    Serial.println((float)temp_DS18B20_N2 / 100.0);
    Serial.print("Temperature DS18B20 n°3 : ");
    Serial.println((float)temp_DS18B20_N3 / 100.0);
    Serial.print("Batterie : ");
    Serial.println((float)batterie / 100.0);
    Serial.print("Humidité SHT20 :");
    Serial.println((float)humidity_SHT20 /100.0);
    Serial.print("Tempearature SHT20 :");
    Serial.println((float)temp_SHT20 /100.0);
    
  
 
  
  

    if (modem.endPacket() <= 0) {
      Serial.println("Error sending message");
      err_count++;
      if (err_count > 50) {
        connected = false;
      }
      delay(1000); // Attendre 1 sec
    } else {
      err_count = 0;
      Serial.println("Message envoyé");
      delay(3000); // Attendre 3 secondes
    }
  }
    risingEdgeDone();
    delay(3000);        //delai de 10 min
}

float getPoids(){
  float weight = scale.get_units() * 0.45 - 3.28;
  return weight;
}
float getHumidity_SHT20() {
  return sht20.readHumidity();
}

float getTemperature_SHT20() {
  return sht20.readTemperature();
}


float getTempInt(){
  float temp = DHT22_Temp_int.readTemperature();
 return temp;
}

float getHumInt(){
  float hum = DHT22_Temp_int.readHumidity();
  return hum;
}


float getTemp_DS18B20_N1() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

float getTemp_DS18B20_N2() {
  sensors.requestTemperatures();
 return sensors.getTempCByIndex(0);
}

float getTemp_DS18B20_N3() {
  sensors.requestTemperatures();
 return sensors.getTempCByIndex(0);
}

float getBatterie(){
 long total = 0; // Pour stocker la somme des lectures
 short value = 0;
 int averageAnalogValue = 0;
 for (int i = 0; i < numReadings; i++) {
    total += analogRead(analogPin);
    delay(10); // Petite pause entre les lectures
 }
  // Calcul de la moyenne
  averageAnalogValue = (total / numReadings);
   //Envoi de la valeur moyenne au moniteur série
  value = map(averageAnalogValue,786, 1023, 0, 100);
  return value;
}



uint8_t readReg(uint8_t reg, const void* pBuf, size_t size) {
  if (pBuf == NULL) {
    Serial.println("pBuf ERROR!! : null pointer");
  }
  uint8_t * _pBuf = (uint8_t *)pBuf;
  Wire.beginTransmission(address);
  Wire.write(&reg, 1);
  if ( Wire.endTransmission() != 0) {
    return 0;
  }
  delay(20);
  Wire.requestFrom(address, (uint8_t) size);
  for (uint16_t i = 0; i < size; i++) {
    _pBuf[i] = Wire.read();
  }
  return size;
}


void risingEdgeDelay(){
  delay(50);
  digitalWrite(TPL5110_DELAY_PIN, HIGH);
  delay(50);
  digitalWrite(TPL5110_DELAY_PIN, LOW);
}

void risingEdgeDone(){
  delay(50);
  digitalWrite(TPL5110_DONE_PIN, HIGH);
  delay(50);
  digitalWrite(TPL5110_DONE_PIN, LOW);
}