const int red = D0;

void setup() {
  pinMode(red, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  for(int i=0;i<=1023;i++){
    analogWrite(red,i);
    delay(1);
  }
  for(int i=1023;i>=0;i--){
    analogWrite(red,i);
    delay(1);
  }
}
