void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(1);
}

int sig = 0;
bool inc = true;
bool sequential = false;

void loop() {
  // put your main code here, to run repeatedly:

  int i=0;

  Serial.print("p\t");

  for(;i<31;i++)
  {
    int pno = 0;
    if (sequential)
    {
      pno= max(0,sig + i*2);
      
      if (pno>255)
      {
        pno -= 2*(pno-255);
      }
    }
    else
    {
      pno = random(0,255);
    }
    
    Serial.print(pno);
    Serial.print("\t");
  }

  Serial.print("\n");

  if (sig == 255)
  {
    inc = false;
  }
  else if (sig == 0)
  {
    inc = true;
  }

  if (inc)
  {
    sig++;
  }
  else
  {
    sig--;
  }
}
