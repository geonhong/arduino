// Inter-arduino serial communication test
// Receiver

#include <SoftwareSerial.h>

SoftwareSerial cSerial(0,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  cSerial.write(1);
  delay(100);
}
