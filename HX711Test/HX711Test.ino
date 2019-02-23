// HX711 Test

#include "HX711N.h"

#define CLK 2
#define DAT 3
#define BTNIN 5

#define BYTES 16

HX711N LC;

float W0_ = 0.0;
float W_ = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Setup()");
  LC.begin(DAT, CLK);
  LC.set_scale(-0.0036 );
  LC.tare(2*BYTES);

  Serial.println("Initialization - OK");

  Serial.println("Initial tare...");
  LC.tare(2*BYTES);

  Serial.println("Second tare...");
  LC.tare(2*BYTES);

  W0_ = LC.get_units(BYTES);
  W_ = LC.get_units(BYTES);
}

void loop() {
  // put your main code here, to run repeatedly:
  W_ = LC.get_units(BYTES);
  Serial.println(W_, 1);

  float diff = W_ - W0_;

  Serial.print("Difference: ");
  Serial.println(diff);

  W0_ = W_;
}
