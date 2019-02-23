void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  for (int i=0; i<100; i++) {
  analogWrite(5,i); delay(100); analogWrite(5,0);
  analogWrite(6,i); delay(100); analogWrite(6,0);
  analogWrite(9,i); delay(100); analogWrite(9,0);
  analogWrite(10,i); delay(100); analogWrite(10,0);
  delay(100);
  }
}
