/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
const int red = D0;
const int yellow = D4;
const int green = D5;

void setup() {
  pinMode(red, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(yellow, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(green, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  while (1){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    delay(5000);    
  
    digitalWrite(red, LOW);// Wait for a second
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(5000); 

    digitalWrite(red, LOW);// Wait for a second
    digitalWrite(yellow, HIGH);  // Turn the LED off by making the voltage HIGH
    digitalWrite(green, LOW);
    delay(3000);      
  }
}
