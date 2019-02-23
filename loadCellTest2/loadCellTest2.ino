                                                  /*
 Example using the SparkFun HX711 breakout board with a scale
 By: Nathan Seidle
 SparkFun Electronics
 Date: November 19th, 2014
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 This example demonstrates basic scale output. See the calibration sketch to get the calibration_factor for your
 specific load cell setup.

 This example code uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE

 The HX711 does one thing well: read load cells. The breakout board is compatible with any wheat-stone bridge
 based load cell which should allow a user to measure everything from a few grams to tens of tons.
 Arduino pin 2 -> HX711 CLK
 3 -> DAT
 5V -> VCC
 GND -> GND

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.

*/

#include "HX711N.h"

#define CLK  2

#define LC3OUT 3
#define LC4OUT 4
#define LC5OUT 5
#define LC9OUT 9
#define LC10OUT 10
#define LC11OUT 11

#define calibfac 0.0004

//HX711N LC3(3, CLK);
//HX711N LC4(4, CLK);
//HX711N LC5(5, CLK);
HX711N LC9;
HX711N LC10;
HX711N LC11;
HX711N LC12;
HX711N LC13;

bool isLC9  = 0;
bool isLC10 = 1;
bool isLC11 = 0;
bool isLC12 = 0;
bool isLC13 = 0           ;

void read_and_write(HX711N &LC)
{
  float val = calibfac*LC.read();
  Serial.print(val, 1); Serial.print("\t");
}

void initialize_loadcell(HX711N &LC, int LCNo)
{
  Serial.print("Initialize LC ");
  Serial.print(LCNo);
  LC.begin(LCNo, CLK);
  LC.set_scale(1.0);
  LC.tare();
  Serial.println(" - OK");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Load Cell Array Measurement:");

  // initialize_loadcell(LC3, 3);
  if (isLC9) initialize_loadcell(LC9, 9);
  if (isLC10) initialize_loadcell(LC10, 10);
  if (isLC11) initialize_loadcell(LC11, 11);
  if (isLC12) initialize_loadcell(LC12, 12);
  if (isLC13) initialize_loadcell(LC13, 13);

  Serial.println("Readings:");
}

void loop() {
  // read_and_write(LC3);
  if (isLC9)  read_and_write(LC9);
  if (isLC10) read_and_write(LC10);
  if (isLC11) read_and_write(LC11);
  if (isLC12) read_and_write(LC12);
  if (isLC13) read_and_write(LC13);

  Serial.println();
}

