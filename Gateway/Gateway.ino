/*
 * Includes the following libraries:
 * Adafruit SSD1306
 * Adafruit GFX Library
 * Adafruit BusIO
 */
#include "WiFi.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels



// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void Nodo1() {
  oled.setCursor(0, 10);       // set position to display
  oled.println("a"); // set text 

  oled.setCursor(0, 20);       // set position to display
  oled.println("a"); // set text  

  oled.setCursor(0, 30);       // set position to display
  oled.println("a"); // set text 

  oled.setCursor(0, 40);       // set position to display
  oled.println("a"); // set text

  oled.setCursor(0, 50);       // set position to display
  oled.println("a"); // set text
}

void Nodo2(){
  
  oled.setCursor(0, 10);       // set position to display
  oled.println("b"); // set text 

  oled.setCursor(0, 20);       // set position to display
  oled.println("b"); // set text  

  oled.setCursor(0, 30);       // set position to display
  oled.println("b"); // set text 

  oled.setCursor(0, 40);       // set position to display
  oled.println("b"); // set text

  oled.setCursor(0, 50);       // set position to display
  oled.println("b"); // set text
}

void setup() {
   pinMode(4,INPUT);
   Serial.begin(9600);

   WiFi.mode(WIFI_STA);
   Serial.println(WiFi.macAddress());
   
  // put your setup code here, to run once:
  
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  oled.clearDisplay(); // clear display
  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color

  if(digitalRead(4)== HIGH)
  {
    oled.setCursor(0, 0);       // set position to display
    oled.println("Nodo 1"); // set text
    Nodo1();
  }
  else 
  {
    oled.setCursor(0, 0);       // set position to display
    oled.println("Nodo 2"); // set text
    Nodo2();
  }
  
  oled.display();  
}
