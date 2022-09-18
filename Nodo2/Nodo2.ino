#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
DHT dht(4, DHT11);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 test!"));
  
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1) {}
  }
}

void loop() {

float h = dht.readHumidity();
float t = dht.readTemperature();

float pres_b = bmp.readPressure();
float alt_b = bmp.readAltitude();

Serial.print(F("Humedad: "));
Serial.print(h);
Serial.print(F("% \nTemperatura: "));
Serial.print(t);
Serial.println(F("°C "));


Serial.print("Presion = ");
Serial.println(pres_b);
Serial.print("Altitude = ");
Serial.println(alt_b);
delay(1000);
}
