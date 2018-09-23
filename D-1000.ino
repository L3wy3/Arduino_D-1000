// Arduino pin numbers
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

Stepper leftwheel(stepsPerRevolution, 4, 5, 6, 7);
Stepper rightwheel(stepsPerRevolution, 8, 9, 10, 11);
Stepper shoulder(stepsPerRevolution, 22, 23, 24, 25);
Stepper myStepper2(stepsPerRevolution, 26, 27, 28, 29);
Stepper myStepper1(stepsPerRevolution, 30, 31, 32, 33);

int shoulderact = 2;    // potentiometer attachedto shoulder
int shoulderaim = 500;
int val;
void setup() {
  leftwheel.setSpeed(60);
  rightwheel.setSpeed(60);
  shoulder.setSpeed(40);
  myStepper2.setSpeed(60);
  myStepper1.setSpeed(60);
  pinMode(shoulderact, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(shoulderact);
 // Serial.print("Pot:  ");
  Serial.print(val);
  if(val > shoulderaim+50){
      shoulder.step(1);
        Serial.print("up");
  }
  if(val < shoulderaim-50){
      shoulder.step(-1);
        Serial.print("down");
  }
  Serial.print("\n");
  delay(1);
}
