// Test of arduino I2C communication
// Leonardo : Sender

#include <Wire.h>

#define SDA 2
#define SCL 3

int x = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly

  char s[] = "I2C Test\n";
  char *ps;
  ps = s;

  while(true) {
    if (*ps == '\0') break;
    Wire.beginTransmission(9);
    Wire.write(*ps);
    Wire.endTransmission();
    ps++;
  }

  x++;
  
  delay(1000);
}
