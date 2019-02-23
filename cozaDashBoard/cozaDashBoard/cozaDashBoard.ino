#include <SimpleDHT.h>
#include <Time.h>
#include "HX711N.h"

#define DHTIN 10
#define WCLK 15
#define WDAT 14

int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;
int En0 = 6;
int En1 = 7;
byte b[4];
time_t mprev = 0;
time_t mcurr = 0;
time_t sprev = 0;
time_t scurr = 0;

SimpleDHT11 dht(DHTIN);
HX711N LC;

void setup() {
  Serial.begin(9600);

  Serial.println("Initialization");

  // Setup for pressure sensor
  Serial.println("  - pressure sensor array");
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(En0, OUTPUT);
  pinMode(En1, OUTPUT);
  //Serial.println("Let's start");
  Serial.println("done\n");

  // Setup for weigth measuring
  Serial.println("  - Load cells");
  LC.begin(WDAT, WCLK);
  LC.set_scale(0.0036);
  LC.tare(16);
  Serial.println("done\n");
  
  // put your setup code here, to run once:
}


void loop() {
  // getPressureSensorData();

  mcurr = minute();

  if(mcurr != mprev) {
    getDHTData();
  }

  mprev = mcurr;

  scurr = second();
  if (scurr != sprev) {
    float weight = LC.get_units();
    Serial.print("W\t");
    Serial.println(weight, 1);
  }
  sprev = scurr;
}


void getPressureSensorData() {
  Serial.print("p\t");
  
  for (int isns=0; isns<32; isns++)
  {
    int den = 1;
    for (int i=0; i<4; i++) {
      if ((isns/den)%2 == 1) b[i] = 1;
      else b[i] = 0;
      den *= 2;
    }
    
    digitalWrite(S0, b[0]);
    digitalWrite(S1, b[1]);
    digitalWrite(S2, b[2]);
    digitalWrite(S3, b[3]);
    
    if (isns<16) {
      digitalWrite(En0,HIGH);
      digitalWrite(En1,LOW);
    }
    else {
      digitalWrite(En0,LOW);
      digitalWrite(En1,HIGH);
    }
    
    Serial.print(analogRead(A3));
    Serial.print("\t");
  }
    
  Serial.println();
}

void getDHTData() {
  byte temp = 0;
  byte humid = 0; 
  int err = SimpleDHTErrSuccess;

  if ((err=dht.read(&temp, &humid, NULL)) != SimpleDHTErrSuccess) {
    return;
  }

  // Print out the results
  Serial.print("T\t");
  Serial.println((int)temp);

  Serial.print("H\t");
  Serial.println((int)humid);
}

