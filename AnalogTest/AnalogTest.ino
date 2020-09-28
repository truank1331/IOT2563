#define ANALOG_PIN A0       // Analog input at pin A0.
int analogValue = 0;        // Variable for store analog value

#include <Wire.h>                   // Include library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup()
{
  Serial.begin(115200);       // set serial port at 115200 bps
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }  
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  analogValue = analogRead(ANALOG_PIN);   // Read analog input at pin An 0.
  Serial.print("Analog input0 = ");       // Send string to serial port.
  Serial.println(analogValue);            // Send analog value to serial port.
  display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);

    display.print("Analog input0 = ");       // Send string to serial port.
  display.println(analogValue);  
    display.display();
  delay(200);                            // Delay 0.3 second.
}
