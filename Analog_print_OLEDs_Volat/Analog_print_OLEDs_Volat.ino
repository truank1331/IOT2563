#include <stdio.h>      // include file stdio.h for function sprintf()
#define ANALOG_PIN A0   // Analog input at pin An 0.
int analogValue = 0;    // variable to store analog value

#include <Wire.h>                   // Include library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup()
{
  Serial.begin(115200);   // set serial port at 9600 bps
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }  
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  String text = "Analog = ";
  char str[5];                            // Declare string variable
  int temp;                               // Temporary variable.
  analogValue = analogRead(ANALOG_PIN);   // Read analog input at pin An 0.
  temp = analogValue * 3.3 / 1023 * 1000; // convert to volt and scale *1000
  sprintf(str, "%4d", temp);              // convert interger to string

  if (str[0] == ' ')  text +="0";
  else  text +=str[0];                   // print voltage in first digit
  text +=".";
  if (str[1] == ' ')  text +="0";
  else   text +=str[1];             // print voltage in 3rd digit (0.1 volt)
  if (str[2] == ' ')  text +="0";
  else   text +=str[2];             // print voltage in 4th digit (0.01 volt)
   text +=str[3];                   // print voltage in 5th digit (0.001 volt)
   text +=" V";
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);

    display.print(text);
    display.display();
  delay(200);                             // wait 0.2 second
}
