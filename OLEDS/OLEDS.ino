#include <Wire.h>                   // Include library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup(){
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }  
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);

    display.print("AAA");
    display.display();
} 
