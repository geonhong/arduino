#include <Wire.h>

#define SDA 4
#define SCL 5

char c = '\0';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Wire.begin(9)");
  Wire.begin(9);
  Serial.println("Wire.onReceive(receiveEvent)");
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  c = Wire.read();
  Serial.print(c);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Do nothing
}
