/*
 * Includes the following libraries:
 * Adafruit BNO055
 * Adafruit Unified Sensor
 * Adafruit BusIO
 */
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void) 
{
  pinMode(4,INPUT);
  pinMode(23,OUTPUT);
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  int8_t temp = bno.getTemp();
  String pos="";
  String tem="";
  String dis="";
  String l="";
  sensors_event_t event; 
  bno.getEvent(&event);
  
  /* Display the floating point data */
  String X = String(event.orientation.x,4);
  String Y = String(event.orientation.y,4);
  String Z = String(event.orientation.z,4);

  
  if(digitalRead(4)== HIGH)
  {
    l="lejos";
    digitalWrite(23,LOW);
    
  }
  else 
  {
    l="cerca";
    digitalWrite(23,HIGH);
  }

  pos="Current Orientation X: "+X+"\tY: "+Y+"\tZ: "+Z;
  tem="Current Temperature: "+String(temp)+" C";
  dis="el objeto esta "+l;
  
  Serial.println(pos);
  Serial.println(tem);
  Serial.println(dis);

  Serial.println("");
    
  delay(500);
}
