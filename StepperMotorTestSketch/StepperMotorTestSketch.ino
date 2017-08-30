#include "SpeedyStepper.h" 

SpeedyStepper stepper1; 

const int microStep = 8;
const float accelInRPSPS = .5;
const float speedInRPS = .5;
const float transmissionRatio = 2;


void setup() {

  stepper1.connectToPort(2);
  stepper1.setStepsPerRevolution( 200 * microStep * transmissionRatio );
  stepper1.setSpeedInRevolutionsPerSecond(speedInRPS);
  stepper1.setAccelerationInRevolutionsPerSecondPerSecond(accelInRPSPS);

  Homing();
}

void loop() {

  Homing();
  delay(1000);
  MoveToHighTower();
  delay(1000);
  Homing();
  delay(1000);
  MoveToLowTower();
  delay(1000);
}

void MoveToHighTower(){
  
  stepper1.moveToPositionInRevolutions(-.75);
}

void MoveToLowTower(){
  
  stepper1.moveToPositionInRevolutions(-.59);
}

void Homing(){
  
  const long directionTowardHome = 1;
  const float speedInRevolutionsPerSecond = .25;
  const float maxDistanceToMoveInMillimeters = 1.5;
  const byte homeSwitchPin = A0;

  stepper1.moveToHomeInRevolutions(directionTowardHome,speedInRevolutionsPerSecond,maxDistanceToMoveInMillimeters,homeSwitchPin);
}

