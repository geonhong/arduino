// Arduino communication test UART
// Sender
// FA141

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.write("p\t192\t168\t0\t254\n");
  delay(100);
}
