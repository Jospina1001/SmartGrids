/*
 * Includes the following libraries:
 * Adafruit BMP085
 * Adafruit Unified Sensor
 * Adafruit BusIO
 */
#include <DHT.h>
#include <Wire.h>
#include "WiFi.h"
#include <Adafruit_BMP085.h>  

Adafruit_BMP085 bmp;
DHT dht(4, DHT11);

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress());
  
  Serial.println(F("DHT11 test!"));
  
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1) {}
  }
}

void loop() {
  
  String hum="";
  String tem="";
  String pre="";
  String alt="";

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  float pres_b = bmp.readPressure();
  float alt_b = bmp.readAltitude();

  hum="Humedad actual"+String(h);
  tem="Temperatura actual" + String(t) +" C";
  pre="Presion actual" + String(pres_b) +" hPa";
  alt="Altitud actual" + String(alt_b) +" mts";

  Serial.println(hum);
  Serial.println(tem);
  Serial.println(pre);
  Serial.println(alt);
  
  Serial.println("");
  delay(500);
}
