// Arduino communication test UART
// Receiver
// 65

int inByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial1.available()) {
    // inByte = Serial1.read();
    //char c = inByte;
    //Serial.print(inByte); Serial.print("\t"); Serial.print(c);
    char c = Serial1.read();
    Serial.print(c);
/*    char c = Serial1.read();
    Serial.write(c);
    if (c == 'p') {
      char dat[100] = {};
      char *pdat;
      pdat = dat;
      while (*pdat != '\n') {
        *pdat = Serial1.read();
        pdat++;
      }
      Serial.println(dat);
    }*/
  }
}
