#**Code**

#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;

void setup() {
}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 250);

  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100);
  }
}

Practical link
https://www.tinkercad.com/things/a4NafrJhHXH-stepper-motor?sharecode=QG01ijDYDN6NoEYKeIqbL0vYEXeIs2VXXLtQno2QLE8
