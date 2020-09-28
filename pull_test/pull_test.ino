#define sw1 D3
#define red D0
int sw1_status=0;

void setup() {
  pinMode(sw1,INPUT);
  pinMode(red,OUTPUT);
}

void loop() {
  sw1_status = digitalRead(sw1);
  digitalWrite(red,!sw1_status);

}
