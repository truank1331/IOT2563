/*
  This example uses only 4 wires to test the BH1750 Light sensor
  
  Connecting the sensor to a NodeMCU ESP8266:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> D2
  SCL  <-> D1

  Connecting the sensor to a Arduino UNO:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> A4/SDA 
  SCL  <-> A5/SCL

  Connecting the sensor to a Arduino DUE:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> D20/SDA
  SCL  <-> D21/SCL
*/
  
#include <Wire.h>                   // Include library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
#include <BH1750FVI.h>

// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

#include <Adafruit_NeoPixel.h>
#define NUMSLEDs  2
#define PINSLEDs  10
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel(NUMSLEDs,PINSLEDs, NEO_GRB + NEO_KHZ800);

void setup() 
{
  SLEDs.begin(); // This initializes the NeoPixel library.
  SLEDs.show(); // Initialize all SLEDs to 'off'
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(5);
  LightSensor.begin();  
}

void loop()
{
  int val = map(analogRead(A0),0,1023,0,255);
  //SLEDs.setPixelColor(0, SLEDs.Color(val, val, 0)); //Adjust brightness, Color red 
  SLEDs.setPixelColor(1, SLEDs.Color(0, 0, val)); //Adjust brightness, Color blue
  SLEDs.show();
  display.clearDisplay();
  display.setTextSize(3);
  display.setCursor(0,0);
  uint16_t lux = LightSensor.GetLightIntensity();
  Serial.print("Light: ");
  Serial.println(lux);
  display.print("Light: ");
  display.println(lux);
  display.display();
  delay(250);
}
