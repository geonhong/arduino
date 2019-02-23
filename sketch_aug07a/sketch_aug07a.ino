const int ch4pin = 4;
const int ch5pin = 5;
const int ch6pin = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ch4pin, OUTPUT);
  pinMode(ch5pin, OUTPUT);
  pinMode(ch6pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int sig=0; sig<256; sig++)
  {
    analogWrite(ch4pin, sig);
    analogWrite(ch5pin, sig);
    analogWrite(ch6pin, sig);
    Serial.println(sig);
    delay(100);
  }

  for (int sig=255; sig>0; sig--)
  {
    analogWrite(ch4pin, sig);
    analogWrite(ch5pin, sig);
    analogWrite(ch6pin, sig);
    Serial.println(sig);
    delay(100);
  }
  delay(1000);
}
