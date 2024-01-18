#include <Servo.h>

Servo servo1;
Servo servo2;

int servo1Pos = 90;
int servo2Pos = 70;

void setup() {

  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
}

void loop() {

  int ldr1 = map(analogRead(A0), 0, 1023, 1, 10);
  int ldr2 = map(analogRead(A1), 0, 1023, 1, 10);
  int ldr3 = map(analogRead(A2), 0, 1023, 1, 10);
  int ldr4 = map(analogRead(A3), 0, 1023, 1, 10);

  if (ldr1 < 6) {
    if (servo1Pos <180) {
      servo1Pos++;
    }
    if (servo2Pos < 180) {
      servo2Pos++;
    }
  }
  if (ldr2 < 6) {
    if (servo1Pos >0) {
      servo1Pos--;
    }
    if (servo2Pos < 180) {
      servo2Pos++;
    }
  }
  if (ldr3 < 6) {
    if (servo1Pos>0) {
      servo1Pos--;
    }
    if (servo2Pos > 0) {
      servo2Pos--;
    }
  }
  if (ldr4 < 6) {
    if (servo1Pos <180) {
      servo1Pos++;
    }
    if (servo2Pos > 0) {
      servo2Pos--;
    }
  }

  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  delay(5);
}
