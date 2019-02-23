void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);

  initMotorSpeed();
}

void loop() {
  // put your main code here, to run repeatedly:
  controlMotorSpeed();
}

#define THROTTLE_MAX 255
#define THROTTLE_MIN 0
#define THROTTLE_INI 5

int throttle = THROTTLE_MIN;

int motorA_pin = 6;
int motorB_pin = 10;
int motorC_pin = 9;
int motorD_pin = 5;

void initMotorSpeed() {
  analogWrite(motorA_pin, THROTTLE_INI); delay(1000);
  analogWrite(motorB_pin, THROTTLE_INI); delay(1000);
  analogWrite(motorC_pin, THROTTLE_INI); delay(1000);
  analogWrite(motorD_pin, THROTTLE_INI); delay(1000);
}

void controlMotorSpeed() {
  //if (isMotorSpeedChanged())
  //  updateMotorSpeed();

  //throttle = 0;
  //updateMotorSpeed();

  for (int i=0; i<100; i++) {
    throttle = i;
    updateMotorSpeed();
    delay(100);
  }
  for (int i=100; i>0; i--) {
    throttle = i;
    updateMotorSpeed();
    delay(100);
  }
}

enum {
  IDLE = 'I',
  THROTTLE = 'T'
};

int inputState = IDLE;

bool isMotorSpeedChanged() {
  bool throttle_changed = false;
  int inputData;

  if (Serial1.available() > 0) {
    inputData = Serial1.read();
    if (inputState == IDLE) {
      if (inputData == THROTTLE)
        Serial1.println(inputData);
        inputState = THROTTLE;
    } else /*if(inputState == THROTTLE)*/ {
      throttle = inputData;
      throttle_changed = true;
      inputState = IDLE;
    }
  }

  return throttle_changed;
}

void updateMotorSpeed() {
  // Serial1.println("Changing motor speed to " + throttle);
  analogWrite(motorA_pin, throttle);
  analogWrite(motorB_pin, throttle);
  analogWrite(motorC_pin, throttle);
  analogWrite(motorD_pin, throttle);
}

